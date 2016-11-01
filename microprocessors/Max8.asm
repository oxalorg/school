Data Segment
 	msg db 0dh,0ah,"Please enter the length of the array: $"
 	msg1 db 0dh,0ah,"Enter a number: $"
 	res db 0dh,0ah,"The maximum is: $"
 	len db ?
 	max db ?
Data ends
Code Segment
assume CS:Code,DS:Data
Start:
 	mov ax,Data
 	mov DS,ax

 	mov dx,offset msg
 	mov ah,09h
 	int 21h
 
 	call Accept

 	mov len,bl
 	mov cl,bl
 	mov ch,00h

 	mov di,1000h
 
	back: mov dx,offset msg1
 		mov ah,09h
 		int 21h
 		call Accept
 		mov [di],bl
 		inc di
 		loop back

 	mov di,1000h
 	mov cl,len
	mov ch,00h

 	mov al,[di] 
 	mov max,al

	chk: 	mov bl,max
 		mov al,[di]
 		cmp bl,al
 		jc a
 		mov max,bl
 		jmp b
		a: mov max,al
		b: inc di
 		loop chk

 	mov dx,offset res
 	mov ah,09h
 	int 21h

 	mov bl,max
 	call DispNum

	mov ah,4ch
	int 21h
	Accept proc
 		mov ah,01h
 		int 21h
 		call AsciiToHex
 		rol al,4
		mov bl,al
 		mov ah,01h
		int 21h
 		call AsciiToHex
 		add bl,al
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
Code ends
end Start
