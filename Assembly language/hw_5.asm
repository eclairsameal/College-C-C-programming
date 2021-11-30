TITLE MASM Template      (main.asm)

; Description:
; 
; Revision date:


INCLUDE Irvine32.inc
.data
  a byte 50 DUP(0)
  b byte 50 DUP(0)
  num byte "0123456789", 0
  bytecount dword ?
  countecx dword ?
  countesi dword ?

.code
main PROC
  mov edx, offset a
  mov ecx, (sizeof a) - 1
  call readstring
  mov bytecount, eax

  mov ebx, OFFSET b
  mov ecx, bytecount
  mov esi, OFFSET a 

  L1:
   mov al, [esi]
   mov countecx, ecx
   mov countesi, esi
   
   mov ecx, 9
   mov edi, offset num
   L2:
     scasb
	 jz L3 
   loop L2
   lodsd
   mov [ebx], al
   add ebx, type b
   L3: 
     mov ecx, countecx 
     mov esi, countesi
	inc esi
 loop L1    


 mov edx, OFFSET b
 call writestring
 call crlf
 call waitmsg

 exit
main ENDP

END main

 