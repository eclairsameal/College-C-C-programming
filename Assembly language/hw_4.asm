TITLE MASM Template						(main.asm)

; Description:
; 
; Revision date:

INCLUDE Irvine32.inc
.data
  aName  byte 50 DUP(0)
  bName  byte 50 DUP(0)
  anameSize  dword ?
  bnameSize  dword ?

  string1 BYTE "First String: ",0
  string2 BYTE "Second String: ",0
  string3 BYTE "Result: ",0

.code
main PROC
   ; ��� string1
  mov  edx,OFFSET string1
  call Writestring
   ; ��J�r��
  mov edx, offset aName
  mov ecx, (sizeof aName)-1
  call readstring
  mov anameSize, eax

    ;�]�ʰj��
  mov ecx,anameSize
  mov esi,0
  L1: 
    movzx eax,aName[esi]
    push eax    ; push on stack
    inc esi
  loop L1

   ; ��� string2
  mov  edx,OFFSET string2
  call Writestring
   ; ��J�r��
  mov edx, offset bName
  mov ecx, (sizeof bName)-1
  call readstring
  mov bnameSize, eax

    ;�]�ʰj��
  mov ecx,bnameSize
  mov esi,0
  L2: 
    movzx eax,bName[esi]
    push eax    ; push on stack
    inc esi
  loop L2

   ; ��� string3
  mov  edx,OFFSET string3
  call Writestring

   ;�]�j��
  mov ecx,anameSize
  add ecx,bnameSize
  mov eax,0
  L3:  
    pop eax 
	call writechar
  loop L3
  call Crlf

  call waitmsg
	exit
main ENDP

END main