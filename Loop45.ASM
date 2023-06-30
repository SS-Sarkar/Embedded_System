ORG 00H
mov A,#45H
mov R0,#20H
mov R2,#6
l1:mov @R0,A
    INC R0
	DJNZ R2,l1
NOP
END