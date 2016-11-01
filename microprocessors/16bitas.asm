DATA segment
	msg1 db 0dh, 0ah, "ENTER A CHOICE $"
	msg2 db 0dh, 0ah, "1.Addition $"
	msg3 db 0dh, 0ah, "2.Subtraction $"
	msg4 db 0dh, 0ah, "3.Exit $"
	msg5 db 0dh, 0ah, "Enter the first number $"
	msg6 db 0dh, 0ah, "Enter the second number $"
	msg7 db 0dh, 0ah, "Result $"
	msg8 db 0dh, 0ah, "Carry Occurs $"
	msg9 db 0dh, 0ah, "Borrow Occurs $"
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
		MOV DX, OFFSET msg5
		MOV AH, 09H
		INT 21h
		call Accept
		mov ch,num
		call Accept
		mov cl,num

		MOV DX, OFFSET msg6
		MOV AH, 09H
		INT 21h
		call Accept
		mov bh,num
		call Accept
		mov bl,num
		MOV DX, OFFSET msg7
		MOV AH, 09H
		INT 21h
		add cx,bx
		jnc resultwocarry
		MOV DX, OFFSET msg8
		MOV AH, 09H 
		int 21h
		resultwocarry:
			mov bl,ch
 			call DispNum
 			mov bl,cl
 			call DispNum
	ret
 	endp	
	
			
	subfunc proc
		MOV DX, OFFSET msg5
		MOV AH, 09H
		INT 21h
		call Accept
		mov ch,num
		call Accept
		mov cl,num

		MOV DX, OFFSET msg6
		MOV AH, 09H
		INT 21h
		call Accept
		mov bh,num
		call Accept
		mov bl,num
		MOV DX, OFFSET msg7
		MOV AH, 09H
		INT 21h
		sub cx,bx
		jnc resultwoborrow
		MOV DX, OFFSET msg9
		MOV AH, 09H 
		int 21h
		resultwoborrow:
			mov bl,ch
 			call DispNum
 			mov bl,cl
 			call DispNum
	ret
 	endp	

CODE ends
end start
