# Assembly language

## 作業一 宣告有號資料結構進行學號運算

1. 使用 SBYTE 的資料結構, 和 add 語法來算出你的學號數字相減的結果

例如學號為 09301234 , 則計算式為 0 + (-9) + (-3) + 0 + (-1) + (-2) + (-3) + (-4) = -22 ( 第一個數字為正, 其餘數字為負相加)

將結果放在 EAX , 呼叫程序 WriteInt 和 DumpRegs 列印出現在螢幕上

(AL 或 AH 即為 EAX 內一部分) +22

2. 使用 SDWORD 的資料結構, 和 add 語法來算出你的學號數字相減的結果

例如學號為 09301234 , 則計算式為

0 + (-9) + (-3) + 0 + (-1) + (-2) + (-3) + (-4) = -22 ( 第一個數字為正, 其餘數字為負相加)

將結果放在 EAX, 呼叫程序 WriteInt 和 DumpRegs 列印出現在螢幕上

PS. 如果使用陣列等進階技巧加分\*

請將你的程式命名為 學號.asm
將 學號.asm 和 學號.exe 作成壓縮檔 上傳
主旨為 "學號 作業一"

# 3/22 上課 demo

參考範例:

```x86asm


TITLE Add and Subtract              (AddSub.asm)

; This program adds and subtracts 32-bit integers.
; Last update: 06/01/2006


INCLUDE Irvine32.inc
.data

value1 SBYTE +0
value2 SBYTE -9

hvalue1 SDWORD +0
hvalue2 SDWORD -9


.code
main PROC
    mov al, value1
 add al, value2

 call writeint
 call crlf
    call dumpregs

    mov eax, hvalue1
 add eax, hvalue2

 call writeint
 call crlf
 call DumpRegs
 call waitmsg



 exit
main ENDP
END main

```

## 寫下列一個使用 LOOP 的程式計算出費式陣列

至少要能計算出下列 7 個數字 { 1,1,2,3,5,8,13 }

1.請先以 宣告此一資料陣列在資料區段

此一資料陣列只有前兩個為 1, 後面的資料必須都為未初始之資料

2.以 LOOP 計算第三個以後的數值, 將資料存入上面宣告的資料陣列

的第三個元素以後

3.請參考第五章 5.3.2 的 DumpMem 範例程式, 將該資料陣列列出出來

結果應類似如下

```
01 01 02 03 05 08 0D

或是

00000001 00000001 00000002 00000003 00000005 00000008
0000000D
```

## 作業三 隨機產生十個數字進行有號乘除法計算

請撰寫一個組合語言程式，隨機產生十個 32 bit 的有號整數, 範圍在+100~-100 之間, 然後請將下面之數字列印在螢幕上

(1) 第 i 跟 i+1 個數字, (2) 第 i 跟 i+1 的數字相乘的結果 和 (3) 第 i 跟 i+1 的數字相除的商與餘數

(i=1~9, 第十個數字不用算, 計算 N*i\*N*(i+1) 和 N*i/N*(i+1)之結果 )

(提示: call randomrange, call writeint, 有號乘除為 IMUL, IDIV, 記得有號除法之前要使用有號延伸指令 CDQ)

結果應該類似如下:

```
數字i  數字i+1   乘積     商     餘數
i, i+1, Product, Quotient, Remainder
+62,-56,-3472,-1,+6
-56,+4,-224,-14,+0
+4,-69,-276,+0,+4
-69,-62,+4278,+1,-7
-62,-30,+1860,+2,-2
-30,-72,+2160,+0,-30
-72,+89,-6408,+0,-72
+89,-79,-7031,-1,+10
-79,+12,-948,-6,-7
```

## 作業四 輸入兩個字串組合後反轉印出

請撰寫一個組合語言程式，可以讓使用者任意輸入兩組字串，然後請利用 Runtime stack 將兩組字串分別反轉後，組合輸出在螢幕上。(程式碼內必須要用到 push 和 pop)

例如: 輸入兩個字串 handsome 和 boy 後，結果應該輸出 emosdnahyob。

```
First String: handsome
Second String: boy
Result: emosdnahyob

```

例如: 輸入兩個字串 pretty 和 girl 後，結果應該輸出 ytterplrig。

```
First String: pretty
Second String: girl
Result: ytterplrig
```

提示: call readstring, 課本範例 reversing a string

## 作業五 字串內之部分字元移除

請利用第九章 SCASB, STOSB, LODSB 等指令撰寫一個組合語言程式，可以讓使用者任意輸入一個字串，然後將字串內的阿拉伯數字去除掉，然後輸出在螢幕上。

例如: 輸入 A1B2C3D4E5 應該輸出 ABCDE。

## 作業六 輸入兩個端點座標畫出長方形四個邊

請宣告一個四邊形的資料結構，可以讓使用者任意輸入一個四角形的左上和右下的(X,Y)座標。然後利用第五章的 Clrscr 先清除畫
面然後利用 GetMaxXY 和 GotoXY 將所輸入的兩個座標所構成的四個邊用 \* 的符號畫出輸出在螢幕上

例如:

```
**********
*        *
*        *
*        *
*        *
*        *
*        *
*        *
**********
```
