ORG 00H
	l5:mov a,p3
l2:cjne a,#50H,l1
	mov p2,p3
	mov p1,#00h
	mov p0,#00h
	sjmp l5
l1: subb a,#50H
l3: jc l4
		mov p0,p3
		mov p2,#00h
	mov p1,#00h
		sjmp l5
	l4:mov p1,p3
	mov p2,#00h
	mov p0,#00h
	sjmp l5
nop
end
	