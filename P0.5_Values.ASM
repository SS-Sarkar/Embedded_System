org 00h
l2:jb p0.5,l1
	mov p2,#00h
	mov p3,#22h
	sjmp l2
l1:mov p2,#22h
	mov p3,#00H	
	sjmp l2
NOP
END