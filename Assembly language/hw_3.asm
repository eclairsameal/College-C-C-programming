TITLE MASM Template						(main.asm)

; Description:
; 
; Revision date:

INCLUDE Irvine32.inc
.data
  a SDWORD 10 DUP(?)
  s byte "计i 计i+1 縩 坝 緇计",0
  s1 byte "i, i+1, Product, Quotient, Remainder",0
.code
main PROC

  mov edx, offset s
  call writestring
  call crlf

  mov edx, offset s1
  call writestring
  call crlf

  call Randomize
  mov ecx, 10
  mov esi,OFFSET a   ;砞﹚esi单array竚
  mov eax,0

  L1:
    mov eax,201
	call RandomRange
	sub eax,100
	mov [esi],eax
	add esi,4
  loop L1  
    ;玻ネ睹计

  mov ecx, 9
  mov esi,OFFSET a   ;砞﹚esi单array竚
  mov eax,0
  mov ebx,0
  mov edx,0
  L2:
    mov eax,[esi]
	mov ebx,eax
	call writeint
	mov al, ','

    call writechar
	add esi,4        ;i+1
	mov eax,[esi]    
	call writeint
	mov al, ','
    call writechar

	mov eax,[esi]
	  ; 材 i 蛤 i+1 计 eax = i+1
	mov edx,0
	imul ebx
	call writeint 
	  ; eax = (i+1) * i, ebx = i 
	mov al, ','
    call writechar
	mov eax,[esi-4]
	mov ebx,[esi]
	CDQ
	IDIV ebx
	call writeint
	mov al, ','
    call writechar
	mov eax,edx
	call writeint
    call crlf

  loop L2  



  call waitmsg

	exit
main ENDP

END main