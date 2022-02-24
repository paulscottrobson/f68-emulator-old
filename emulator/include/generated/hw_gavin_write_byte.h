//
//	Automatically generated.
//
if (IS_GAVIN(address)) {
	int a = address-ADDR_GAVIN;
	if (HW_IS_GAVIN_INTERRUPTCTRL(a)) {
		Gavin_Write(a,value,1);
	}
}
