;
; 		SREC test filels
;
		org 	$020000
start:		
		lea 	42,a0
		moveq 	#1,d0
gohere:	
		addq 	#1,d0
		bra 	gohere		