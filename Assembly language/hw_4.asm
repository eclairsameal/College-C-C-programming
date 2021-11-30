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
   ; 顯示 string1
  mov  edx,OFFSET string1
  call Writestring
   ; 輸入字串
  mov edx, offset aName
  mov ecx, (sizeof aName)-1
  call readstring
  mov anameSize, eax

    ;設動迴圈
  mov ecx,anameSize
  mov esi,0
  L1: 
    movzx eax,aName[esi]
    push eax    ; push on stack
    inc esi
  loop L1

   ; 顯示 string2
  mov  edx,OFFSET string2
  call Writestring
   ; 輸入字串
  mov edx, offset bName
  mov ecx, (sizeof bName)-1
  call readstring
  mov bnameSize, eax

    ;設動迴圈
  mov ecx,bnameSize
  mov esi,0
  L2: 
    movzx eax,bName[esi]
    push eax    ; push on stack
    inc esi
  loop L2

   ; 顯示 string3
  mov  edx,OFFSET string3
  call Writestring

   ;設迴圈
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