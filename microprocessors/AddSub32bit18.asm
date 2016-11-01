DATA segment
	msg1 db 0dh, 0ah, "ENTER A CHOICE $"
	msg2 db 0dh, 0ah, "1.Addition $"
	msg3 db 0dh, 0ah, "2.Subtraction $"
	msg4 db 0dh, 0ah, "3.Exit $"
	msg5 db 0dh, 0ah, "Enter the first number $"
	msg6 db 0dh, 0ah, "Enter the second number $"
	msg7 db 0dh, 0ah, "Result $"
	onefirst dw ?;
	onesecond dw ?;
	twofirst dw ?;
	twosecond dw ?;
	num db ?
DATA ends

CODE segment
assume CS:CODE,DS:DATA
start:

	menu:
		MOV AX,DATA 
		MOV DS,AX
	   
		MOV DX, OFFSET msg1
		MOV AH, 09H
		INT 21h
		MOV DX, OFFSET msg2
		MOV AH, 09H
		INT 21h
		MOV DX, OFFSET msg3
		MOV AH, 09H
		INT 21h
		MOV DX, OFFSET msg4
		MOV AH, 09H
		INT 21h
		
		
		mov ah,01h
 		int 21h
 		sub al,30h

 		cmp al,03h
 		jz ex

 		cmp al,02h
 		jne n1
 		call subfunc

		n1: 	cmp al,01h 
 			jne menu
 			call addfunc

	 	jmp menu
		
				
	ex: 
		MOV AH,4CH 
		INT 21H 
	
	
	Accept proc
		mov ah,01h
		int 21h
		call AsciiToHex
		rol al,4
		mov num,al
		mov ah,01h
		int 21h
		call AsciiToHex
		add num,al
	ret
	endp

	DispNum proc
		mov dl,bl
		and dl,0f0h
		ror dl,4
		call HexToAscii
		mov ah,02h
		int 21h
		mov dl,bl
		and dl,0fh
		call HexToAscii
		mov ah,02h
		int 21h
	endp

	AsciiToHex proc
		cmp al,41h
		jc sk 
 		sub al,07h
		sk: sub al,30h
 	ret
	endp
	
	HexToAscii proc
 		cmp dl,0ah
 		jc sk2
		add dl,07h
		sk2: add dl,30h
 	ret
	endp

	addfunc proc
		clc
		MOV DX, OFFSET msg5
		MOV AH, 09H
		INT 21h
		call Accept
		mov ch,num
		call Accept
		mov cl,num
		mov onefirst,cx
		call Accept
		mov ch,num
		call Accept
		mov cl,num
		mov onesecond,cx

		MOV DX, OFFSET msg6
		MOV AH, 09H
		INT 21h
		call Accept
		mov ch,num
		call Accept
		mov cl,num
		mov twofirst,cx
		call Accept
		mov ch,num
		call Accept
		mov cl,num
		mov twosecond,cx

		
		adc onefirst,twofirst
		mov cx,onefirst
		MOV DX, OFFSET msg8
		MOV AH, 09H 
		int 21h
		mov bl,ch
 		call DispNum
 		mov bl,cl
 		call DispNum

		adc onesecond,twosecond 
		mov cx,onefirst
		MOV DX, OFFSET msg8
		MOV AH, 09H 
		int 21h
		mov bl,ch
 		call DispNum
 		mov bl,cl
 		call DispNum

	ret
 	endp	
	
			
	subfunc proc
		clc
		MOV DX, OFFSET msg5
		MOV AH, 09H
		INT 21h
		call Accept
		mov ch,num
		call Accept
		mov cl,num
		mov onefirst,cx
		call Accept
		mov ch,num
		call Accept
		mov cl,num
		mov onesecond,cx

		MOV DX, OFFSET msg6
		MOV AH, 09H
		INT 21h
		call Accept
		mov ch,num
		call Accept
		mov cl,num
		mov twofirst,cx
		call Accept
		mov ch,num
		call Accept
		mov cl,num
		mov twosecond,cx

		
		sbb onefirst,twofirst
		mov cx,onefirst
		MOV DX, OFFSET msg8
		MOV AH, 09H 
		int 21h
		mov bl,ch
 		call DispNum
 		mov bl,cl
 		call DispNum

		sbb onesecond,twosecond 
		mov cx,onefirst
		MOV DX, OFFSET msg8
		MOV AH, 09H 
		int 21h
		mov bl,ch
 		call DispNum
 		mov bl,cl
 		call DispNum
	ret
 	endp	

CODE ends
end start

//OUTPUT
ENTER A CHOICE
1.Addition
2.Subtraction
3.Exit 1
Enter the first number 56489512
Enter the second number 214595AC
Result 778E2ABE
1.Addition
2.Subtraction
3.Exit 2
Enter the first number 56489215
Enter the second number 6254AEF5
Result
Borrow Occurs F3F3E320
ENTER A CHOICE
1.Addition
2.Subtraction
3.Exit 3

