DATA segment
	msg1 db 0dh, 0ah, "ENTER A CHOICE $";
	msg2 db 0dh, 0ah, "1.Addition $";
	msg3 db 0dh, 0ah, "2.Subtraction $"; 
	msg4 db 0dh, 0ah, "3.Exit $";
	msg5 db 0dh, 0ah, "Enter the first number $";
	msg6 db 0dh, 0ah, "Enter the second number $";
	msg7 db 0dh, 0ah, "Result $";
	msg8 db 0dh, 0ah, "Enter a valid input $";
	msg9 db 0dh, 0ah, "$";
	buffer Db ?;
	ten dw 0010;
	hun dw 0100;
	tho dw 1000;
	rem dw ?;
DATA ends

CODE segment
assume CS:CODE,DS:DATA
start:

	him proc
		MOV AX,DATA; 
		MOV DS,AX; 
	   
		MOV DX, OFFSET msg1;
		MOV AH, 09H;
		INT 21h;
		MOV DX, OFFSET msg2;
		MOV AH, 09H;
		INT 21h;
		MOV DX, OFFSET msg3;
		MOV AH, 09H;
		INT 21h;
		MOV DX, OFFSET msg4;
		MOV AH, 09H;
		INT 21h;
		MOV DX, OFFSET msg9;
		MOV AH, 09H;
		INT 21h;
		
		mov ah, 01h;
		int 21h;
		
		cmp al, 33h;
		je ex;
		cmp al, 31h;
		je addfunc;
		cmp al, 32h;
		je subfunc;
		cmp al, 33h;
		jg errfunc
		cmp al, 31h;
		jl errfunc
		
		read proc
			mov ah,01
			int 21h
			sub al,48
			mul ten
			mov buffer,al      
			mov ah,01           
			int 21h
			sub al,48
			add buffer,al
			ret                 ;number in buffer 
		endp
		
		errfunc proc
			mov dx, offset msg8
			mov ah, 09h
			int 21h
			call him
		endp
		
		ex proc
			MOV AH,4CH 
			INT 21H 
		endp
	
		addfunc proc
			MOV DX, OFFSET msg5;
			MOV AH, 09H;
			INT 21h;
			call read
			mov cl,buffer
			MOV DX, OFFSET msg6;
			MOV AH, 09H;
			INT 21h;
			call read
			mov bl,buffer
			MOV DX, OFFSET msg7;
			MOV AH, 09H;
			INT 21h;
			add cl,bl;
			mov al,cl
			mov ah,00
			call write
			call him
		endp
			
		subfunc proc
			MOV DX, OFFSET msg5;
			MOV AH, 09H;
			INT 21h;
			call read
			mov cl,buffer
			MOV DX, OFFSET msg6;
			MOV AH, 09H;
			INT 21h;
			call read
			mov bl,buffer
			MOV DX, OFFSET msg7;
			MOV AH, 09H;
			INT 21h;
			sub cl,bl;
			mov al,cl
			mov ah,00
			call write
			call him
		endp
		
		write proc;assuming value is stored in ax
			mov dx,0000
			div tho
			mov rem,dx
			add al,48
			mov dl,al
			mov ah,02h
			int 21h
			
			mov ax,rem
			mov dx,0000
			div hun
			mov rem,dx
			add al,48
			mov dl,al
			mov ah,02h
			int 21h
			
			mov ax,rem
			mov dx,0000
			div ten
			mov rem,dx
			add al,48
			mov dl,al
			mov ah,02h
			int 21h
			
			mov ax,rem
			mov dx,0000
			add al,48
			mov dl,al
			mov ah,02h
			int 21h
			
			ret         
		endp
	endp

CODE ends
end start