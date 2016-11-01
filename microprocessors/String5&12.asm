Data Segment
 	chc db 0dh,0ah,"Choose Operation: $"
 	chc1 db 0dh,0ah," 1. Accept String $"
 	chc2 db 0dh,0ah," 2. Display String $"
 	chc3 db 0dh,0ah," 3. Display Length $"
 	chc4 db 0dh,0ah," 4. Display Reverse $"
 	chc5 db 0dh,0ah," 5. Check Palindrome $"
 	chc6 db 0dh,0ah," 6. Exit $"
 	len db ?
 	msg db 0dh,0ah,"Please enter the String: $"
 	msg1 db 0dh,0ah,"The length of the entered String is: $"
 	msg2 db 0dh,0ah,"The entered String is: $"
 	msg3 db 0dh,0ah,"The reverse of the entered String is: $"
 	pal db 0dh,0ah,"The String is a Palindrome. $"
 	npal db 0dh,0ah,"The String is not a Palindrome. $"
	newl db 0dh,0ah," $"
Data ends
Code Segment
 	assume DS:Data,CS:Code
	Start:
 		mov ax,Data
 		mov DS,ax

		call AcceptString 
 		l: 	mov dx,offset chc//For menu
 			mov ah,09h
 			int 21h
 			mov dx,offset chc1
 			mov ah,09h
 			int 21h
 			mov dx,offset chc2
 			mov ah,09h
 			int 21h
 			mov dx,offset chc3
 			mov ah,09h
 			int 21h
 			mov dx,offset chc4
 			mov ah,09h
 			int 21h
 			mov dx,offset chc5
 			mov ah,09h
 			int 21h
 			mov dx,offset chc6
 			mov ah,09h
 			int 21h

 	mov dx,offset newl
 	mov ah,09h
 	int 21h

	mov ah,01h//take the choice
 	int 21h
 	sub al,30h

 	cmp al,06h
 	jz ex//jz means jump if zero and zero flag is set when destination=source

 	cmp al,05h
 	jne n1//jne means jump if not equal
 	call CheckPal

	n1: 	cmp al,04h 
 		jne n2//jne means jump if not equal
 		call DisplayRev

	n2: 	cmp al,03h 
 		jne n3//jne means jump if not equal
 		call DisplayLength

	n3: 	cmp al,02h 
 		jne n4//jne means jump if not equal
 		call DisplayString

	n4: 	cmp al,01h
 		jne l//jne means jump if not equal
 		call AcceptString 
 	jmp l//Always jump

		ex: 	mov ah,4ch
 			int 21h

		AcceptString proc
 			mov si,1000h
 			mov di,1000h
 			mov cx,0000h

 			mov dx,offset msg
 			mov ah,09h
 			int 21h

    			back: 
 				mov ah,01h
 				int 21h
 
 				cmp al,0dh//0dh means enter
 				je comp//je  means hump if equal
 				inc cx//Go on incrementing counter till enter is pressed
 				mov [si],al//Store the strings in si and di
 				mov [di],al
 				inc si
 				inc di
 				jmp back//Always jump for next character
				comp: mov len,cl
 		ret
		endp

		DisplayString proc
 			mov dx,offset msg2
			mov ah,09h
 			int 21h

 			mov cl,len
		 	mov ch,00h
 			mov si,1000h

    			disp: 
 				mov dl,[si]
 				mov ah,02h
 				int 21h
 
 				inc si
 				loop disp//loop till cl=0
 		ret
		endp

		DisplayLength proc
 			mov dx,offset msg1
 			mov ah,09h
 			int 21h

 			mov bl,len
 			call DispNum
 		ret
		endp

		DispNum proc//display of length of string
 			mov al,bl
 			and al,0f0h
 			ror al,4

 			mov dl,al
 			call HexDisp
 			mov ah,02h
 			int 21h

 			mov al,bl
 			and al,0fh
 
 			mov dl,al
 			call HexToAscii
 			mov ah,02h
 			int 21h
		endp

		HexToAscii proc
 			cmp dl,0ah
 			jc sk2//jc means jump if carry and carry flag is set if destination<source
			add dl,07h
			sk2: add dl,30h
 		ret
		endp


		DisplayRev proc
 			mov dx,offset msg3
 			mov ah,09h
 			int 21h

			mov cl,len
			mov ch,00h
			mov si,1000h//Take the first letter of string in si
 			add si,cx//Go to last letter by adding cx to si
 			dec si

     			dispr: 
 				mov dl,[si]
 				mov ah,02h
 				int 21h
 
 				dec si//Go on decrementing towards the start and displaying each character in reverse
 			loop dispr//Loop till cl=0
 		ret
		endp

		CheckPal proc
 			mov al,len
 			mov ah,00h
 			mov bl,02h
 			div bl//al/bl(finding the mid)
 			mov cl,len
 			dec cl
 			mov ch,00h
 			mov di,1000h
 			mov si,1000h
 			add di,cx
 			mov cl,al//Counter now has the mid
 			mov ch,00h
 
     			pchk: 
 				mov al,[si]
 				cmp al,[di]
 				jnz np//jnz means jump if not zero i.e. for not a palindrome
 				inc si
 				dec di
 				loop pchk//loop till cl=0

 			mov dx,offset pal
 			mov ah,09h
 			int 21h
	 	ret
 
      	np: 
 			mov dx,offset npal
 			mov ah,09h
 			int 21h
 		ret
		endp

Code ends
end Start

//OUTPUT
Please enter the String: Micro Processors
Choose Operation:
 1. Accept String
 2. Display String
 3. Display Length
 4. Display Reverse
 5. Check Palindrome
 6. Exit
2
The entered String is: Micro Processors
Choose Operation:
 1. Accept String
 2. Display String
 3. Display Length
 4. Display Reverse
 5. Check Palindrome
 6. Exit
3
The length of the entered String is: 10
Choose Operation:
 1. Accept String
 2. Display String
 3. Display Length
 4. Display Reverse
 5. Check Palindrome
 6. Exit
4
The reverse of the entered String is: srossecorP orciM
Choose Operation:
 1. Accept String
 2. Display String
 3. Display Length
 4. Display Reverse
 5. Check Palindrome
 6. Exit
5
The String is not a Palindrome. 
Choose Operation:
 1. Accept String
 2. Display String
 3. Display Length
 4. Display Reverse
 5. Check Palindrome
 6. Exit
6
