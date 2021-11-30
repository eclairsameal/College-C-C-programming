TITLE MASM Template						(main.asm)

; Description:
; 
; Revision date:

INCLUDE Irvine32.inc
.data

a DB 1, 1, 5 DUP(?) ;1byte

.code
main PROC

  mov esi,OFFSET a ;設定esi等於a的位置
  mov ecx,5
  mov eax,0

  L1:
    mov al,[esi]
	inc esi
	add al,[esi]
	inc esi
	mov [esi],al
	dec esi
  loop L1

  mov esi,OFFSET a
  mov ecx,LENGTHOF a
  mov ebx,TYPE a
  call DumpMem
  call WAITMSG  
    
	exit
main ENDP

END main