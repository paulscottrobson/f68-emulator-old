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
#													Basic analysis
#
# *******************************************************************************************************************************

class BasicConfiguration(object):
	def __init__(self,source):
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

	#
	def getMask(self,start,end):
		count = 0 
		while start % 2 == 0 and end % 2 == 1:
			start = start >> 1
			end = end >> 1
			count += 1
		#print("{0:x} {1:x}".format(start,end))
		return (1 << count)-1


source = open("a2560k.txt").readlines()
source = [x if x.find("//") < 0 else x[:x.find("//")] for x in source]		
source = [x.replace("\t"," ").strip().upper() for x in source if x.strip() != ""]

print("Processing configuration.")
bc = BasicConfiguration(source)
bc.render(open("../include/generated/memorymap.h".replace("/",os.sep),"w"))
