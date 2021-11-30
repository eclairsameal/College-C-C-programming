TITLE MASM Template      (main.asm)

; Description:
; 
; Revision date:

INCLUDE Irvine32.inc

Square STRUCT
  x1 BYTE ?
  x2 BYTE ?
  y1 BYTE ?
  y2 BYTE ?
Square ENDS

.data
  string BYTE "Enter :",0
  s Square <>
  row BYTE ?
  col BYTE ?
  ix BYTE ?
  iy BYTE ?
.code
main PROC  
  mov edx, offset string
  call writestring

  mov eax, 0

  call readdec
  mov s.x1, al
  call readdec
  mov s.y1, al 
  call readdec
  mov s.x2, al 
  call readdec
  mov s.y2, al
  call Clrscr

  movzx ecx, s.x2
  movzx eax, s.x1
  mov ix, al
  sub ecx, eax
  inc ecx
  L1:
    mov dh, s.y1
	mov dl, ix
	call gotoxy
	mov al, '*'
	call writechar
	mov dh, s.y2
	call gotoxy
	mov al, '*'
	call writechar
	inc ix
  loop L1

  movzx ecx, s.y2
  movzx eax, s.y1
  mov iy, al
  inc iy
  sub ecx,eax
  dec ecx
  L2:
    mov dh, iy
	mov dl, s.x1
	call gotoxy
	mov al, '*'
	call writechar
	mov dl, s.x2
	call gotoxy
	mov al, '*'
	call writechar
	inc iy
  loop L2
	call crlf
	call crlf
  call waitmsg

 exit
main ENDP

END main
 