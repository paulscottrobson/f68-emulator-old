# *******************************************************************************************************************************
# *******************************************************************************************************************************
#
#		Name:		setup.py
#		Purpose:	Configuration analysis script
#		Created:	22nd February 2022
#		Author:		Paul Robson (paul@robsons->org.uk)
#
# *******************************************************************************************************************************
# *******************************************************************************************************************************

import re,sys,os,datetime

# *******************************************************************************************************************************
#
#												Represents a single access of a block 
#
# *******************************************************************************************************************************

class HardwareAccess(object):
	def __init__(self,defn):
		defn = defn.strip().upper().replace(" ","")
		m = re.match("^([A-Z0-9]+)\\:([RWB])\\:([0-9A-F\\-]+)\\:([A-Z]+)\\-\\>([A-Z0-9\\_]+)*$",defn)
		assert m is not None,"Can't process "+defn
		assert m.group(1) in ["GAVIN","VICKY3A","VICKY3B","BEATRIX"],"Unknown hardware "+defn
		assert m.group(4) in ["BYTE","WORD","LONG"],"Unknown data size "+defn
		self.device = m.group(1)
		self.access = m.group(2)
		self.dataSize = m.group(4)[0]
		self.testName = "HW_IS_"+self.device+"_"+m.group(5)
		m2 = re.match("^([0-9A-F]+)$",m.group(3))
		if m2 is not None:
			self.startAddress = int(m2.group(1),16)
			self.endAddress = self.startAddress
		else:
			m2 = re.match("^([0-9A-F]+)\\-([0-9A-F]+)$",m.group(3))
			assert m2 is not None,"Bad range "+defn
			self.startAddress = int(m2.group(1),16)
			self.endAddress = int(m2.group(2),16)
		#print("DEF:{0} {1} {2} ${3:x} ${4:x} {5} {6}".format(self.device,self.access,self.dataSize,self.startAddress,self.endAddress,self.testName,defn))
	#
	def getDevice(self):
		return self.device 
	def getDataSize(self):
		return self.dataSize
	def getTestName(self):
		return self.testName
	def canRead(self):
		return self.access == "R" or self.access == "B"
	def canWrite(self):
		return self.access == "W" or self.access == "B"
	#
	def getTestCode(self):
		stub = "#define "+self.testName+"(a) "
		if self.startAddress == self.endAddress:
			return stub+" ((a) == 0x{0:x})".format(self.startAddress)
		return stub+" (((a) >= 0x{0:x}) && ((a) < 0x{1:x}))".format(self.startAddress,self.endAddress)

# *******************************************************************************************************************************
#
#													Basic analysis
#
# *******************************************************************************************************************************

class BasicConfiguration(object):
	def __init__(self,source):
		self.accessList = []
		self.setup = { 	"CPU":"68000",
						"ADDRESS_MASK":"FFFFFFFF",
						"FLASH_ROM":None,
						"HARDWARE_START":None,
						"HARDWARE_END":None,
						"BEATRIX":None,
						"GAVIN":None,
						"VICKY3B":None,
						"VICKY3A":None
		}
		for s in source:
			m = re.match("^([A-Z0-9\\_]+)\\s*\\=\\s*(.*)$",s)
			if m is not None:
				assert m.group(1) in self.setup,"Unknown key "+m.group(1)
				self.setup[m.group(1)] = m.group(2).strip()
			else:
				self.accessList.append(HardwareAccess(s))
	#
	def render(self,h):
		time = datetime.datetime.now().strftime("%a %d-%b-%Y %H:%M")

		h.write("//\n//\tAutomatically generated.\n//\n")
		h.write("#define BUILD_TIME (\"{0}\")\n\n".format(time))
		h.write("#define ADDRESS_MASK (0x{0})\n\n".format(self.setup["ADDRESS_MASK"]))
		h.write("#define PROCESSOR_TYPE (M68K_CPU_TYPE_{0})\n\n".format(self.setup["CPU"]))

		assert self.setup["FLASH_ROM"] is not None,"No ROM defined"
		h.write("#define FLASH_ROM (\"{0}\")\n\n".format(self.setup["FLASH_ROM"].lower()))

		hwStart = int(self.setup["HARDWARE_START"],16)
		hwEnd = int(self.setup["HARDWARE_END"],16)
		mask = self.getMask(hwStart,hwEnd)
		topMask = mask ^ 0xFFFFFFFF
		assert (hwStart & topMask) == (hwEnd & topMask),"Start/End don't fit in page"

		h.write("#define HARDWARE_RAM 0x{0:x}\n\n".format(hwEnd-hwStart+1))
		h.write("#define ISHWADDR(a) (((a) & 0x{0:x}) == 0x{1:x})\n\n".format(topMask,hwStart))
		#print("{0:x} {1:x} {2:x}".format(hwStart,hwEnd,mask))

		hwSpace = hwEnd-hwStart + 1
		hwMask = mask 
		while hwSpace != 0x20000:
			hwSpace >>= 1
			hwMask >>= 1

		for chip in ["GAVIN","BEATRIX","VICKY3A","VICKY3B"]:
			if self.setup[chip] is not None:
				addr = int(self.setup[chip],16)
				h.write("#define ADDR_{0}\t(0x{1})\n".format(chip,self.setup[chip]))
				h.write("#define IS_{2}(a)\t(((a) & 0x{0:x}) == 0x{1:x})\n\n".format(hwMask ^ 0xFFFFFFFF,addr,chip))
				assert addr >= hwStart and addr <= hwEnd,chip+" not in hardware area"
		for a in self.accessList:
			h.write(a.getTestCode()+"\n")

	#
	def getMask(self,start,end):
		count = 0 
		while start % 2 == 0 and end % 2 == 1:
			start = start >> 1
			end = end >> 1
			count += 1
		#print("{0:x} {1:x}".format(start,end))
		return (1 << count)-1
	#
	def renderAccessors(self,h,device,direction,size):
		count = 0
		h.write("//\n//\tAutomatically generated.\n//\n")
		for a in self.accessList:
			if a.getDevice() == device and a.getDataSize() == size[0]:
				if (direction == "READ" and a.canRead()) or (direction == "WRITE" and a.canWrite()):
					count += 1
		if count != 0:
			h.write("if (IS_{0}(address)) {{\n".format(device))
			h.write("\tint a = address-ADDR_{0};\n".format(device))
			for a in self.accessList:
				if a.getDevice() == device and a.getDataSize() == size[0]:
					if (direction == "READ" and a.canRead()) or (direction == "WRITE" and a.canWrite()):
						h.write("\tif ({0}(a)) {{\n".format(a.getTestName()))
						s = 2 if size[0] == "W" else 4
						s = 1 if size[0] == "B" else s
						h.write("\t\t{0}_{1}(a,{2}{3});\n".format(self.caps(device),self.caps(direction),"" if direction == "READ" else "value,",s))
						h.write("\t}\n")
			h.write("}\n")
	#
	def caps(self,s):
		return s[0].upper()+s[1:].lower()

source = open("a2560k.txt").readlines()
source = [x if x.find("//") < 0 else x[:x.find("//")] for x in source]		
source = [x.replace("\t"," ").strip().upper() for x in source if x.strip() != ""]

print("Processing configuration.")
bc = BasicConfiguration(source)
bc.render(open("../include/generated/memorymap.h".replace("/",os.sep),"w"))

for size in ["BYTE","WORD","LONG"]:
	for device in ["GAVIN","BEATRIX","VICKY3A","VICKY3B"]:
		for direction in ["READ","WRITE"]:
			fName = ("../include/generated/hw_{0}_{1}_{2}.h".format(device,direction,size)).lower()
			h = open(fName.replace("/",os.sep),"w")
			bc.renderAccessors(h,device,direction,size)