# Linux 使用筆記

[TOC]
---
## 打開終端機:
使用鍵盤輸入:   

    Ctrl + Alt + T
    
## 一些簡單指令:
 
### 知道當下的路徑:
```bash=
$ pwd 
```

### 列出當下所在路徑的所有檔案及資料夾:
```bash=
$ ls

# 以樹狀表示:
$ tree
```

### 印出文字/創建檔案:
```bash=
# 印出文字
$ cat 檔名

# 創建檔案
$ touch 檔名
```

### 建立新目錄:
```bash=
$ mkdir 資料夾名稱

# 同時建立許多目錄在同一層:
$ mkdir 目錄1 目錄2 目錄3

# 建立多層目錄:
$ mkdir -p /目錄1/目錄2/目錄3 #-p:parent
#若目錄1本來就存在，但沒有目錄2及目錄3，則會在目錄1下先建立目錄2，再建立目錄3
```
### 切換工作目錄:
```bash=
#相對路徑(切換至當下目錄中已存在的目錄)
$ cd 目錄名稱

#絕對路徑(需要完整的輸入路徑，可以一次多層移動)
$ cd /home/username/Documents/dir1/dir2

#返回上一層目錄
$ cd ..

#返回兩層目錄(以"/"分割..)
$ cd ../..

#切換到上一層目錄中其他的子目錄
$ cd ../子目錄名稱

#改回上一個更改前的目錄
$ cd -

#回到家目錄(即/home/username):
$ cd ~
```

### 刪除檔案或目錄:
```bash=
# 刪除單一檔案:
$ rm 檔案名稱
$ rm -i 檔案名稱 #刪除前會先詢問是否刪除此檔案
$ rm -f 檔案名稱 #強制刪除 -f:force

# 刪除空目錄:
$ rm -d 目錄名稱 #內部不能有東西才能刪除

# 刪除該目錄及以下所有的檔案及子目錄:
$ rm -r 目錄名稱 #-r:recursive
```

### 複製檔案:
```bash=
$ cp 路徑/檔案名稱 /目的地的路徑/(檔案名稱[若要改名])
```
#### 舉例說明:
例子1. 在share下建立dir1與dir2，在dir1下建立test，將其複製到dir2，並改名為temp
```bash=
$ mkdir dir1 dir2
$ cd dir1
$ touch test
$ cp test ../dir2/temp
```
![](https://i.imgur.com/qK87OKb.png)


例子2. 在share下建立dir1與dir2，在dir1及dir2下都建立test，將dir1的test複製到dir2
```bash=
$ mkdir dir1 dir2
$ cd dir1
$ touch test
$ cd ../dir2/
$ touch test
$ cd ../dir1/
$ cp -i test ../dir2/ #用參數"-i"時，當複製檔名一樣時會提出警告
```
![](https://i.imgur.com/khFjtGx.png)

例子3. 複製所有dir1目錄下的所有檔案至dir2
```bash=
$ mkdir dir1 dir2
$ cd dir1
$ touch test1 test2 test3
$ cp -r * ../dir2/
```
![](https://i.imgur.com/6HArF53.png)


### 移動檔案或重新命名:
```bash=
$ mkdir dir1 dir2
$ cd dir1
$ touch test
$ mv test temp      #改名
$ mv temp ../dir2/  #移動
```
![](https://i.imgur.com/3HMgHSq.png)


## Vim:
共有三種模式，分別為一般指令模式(command mode)、編輯模式(insert mode)、指令列命令模式(command-line mode)
### 一般指令模式(command mode)

### 編輯模式(insert mode)

### 指令列命令模式(command-line mode)

## C語言:
在linux系統上使用GCC編譯器，將C的程式碼編譯為執行檔

### 編譯C code:
寫好一支C code 如下並命名為helloworld.c:
```c=
#include <stdio.h>
int main(){
    printf("hello world\n");
    return 0;
}
```
執行gcc的命令將其轉為執行檔:
```bash=
#編譯C code
$ gcc helloworld.c
```
gcc會直接產生一個**a.out**的檔案，現在來執行程式:
```bash=
#執行gcc編譯完成的程式
$ ./a.out
```
輸出:  

    hello world
### gcc 其他參數使用
---
若要指定輸出執行檔的名稱，加上"-o"這個參數即可:
```bash=
#編譯helloworld.c這個檔案，並將執行檔改名為hello
$ gcc -o hello helloworld.c
$ ./hello
```
---
若要編譯時加上除錯的功能，加上"-g"這個參數即可，為gdb除錯的意思
```bash=
$ gcc -g helloworld.c
```
舉例說明，寫好一支C code如下，使用gcc -g的除錯功能:
```c=
#include <stdio.h>
int main(){
    printf("hello world\n");
    return 0                 #(故意忽略此處的分號)
}
```
```bash=
$ gcc -g helloworld.c
```
![](https://i.imgur.com/XJObvn8.png)

---
若要加上編譯時出現的警訊(warning)，則需要加上"-Wall"這個參數，一定要大寫!  
舉例說明，寫好一支C code(testwall.c)如下，使用gcc -Wall的警訊功能:
```c=
#include <stdio.h>

void main(){
    int a=0.01;
    return 3;
}
```
```bash=
$ gcc -Wall -o testwall testwall.c
```
![](https://i.imgur.com/BRPIZ97.png)

(通常在編譯的時候最好都加上-Wall -g 去檢視自己的code)

---
若只想要編譯且不需要進行連結，那可以使用 -c 這個參數，將會產生.o的檔案供日後使用。假如現在有hello.c的檔案，若要將其轉換成目標檔:
```bash=
gcc -c hello.c
```

## Makefile:
在寫程式的時候，可能會有許多副程式，或是標頭檔，那在編譯時，要如何將他們串接起來呢?倘若編譯完成後，需要修改內部某一個檔案，並不需要重新編譯所有的檔案，只要該程式有連結到的檔案編譯即可。make便是幫我們解決這個問題的好幫手，因此我們可以透過makefile粗略了解該程式的架構為何。

一般來說makefile的架構如下:
```bash=
target: dependencies
    command
```
target為目標文件要將其編譯為什麼東西，而dependencies則是要告訴電腦這個target會依賴於那些文件，而後在下一行加上一個tab鍵後，輸入要對其做的命令即可。

### 簡單的Makefile實作1:
假設現在有一個hello.c如下:
```c=
#include <stdio.h>
int main(){
    printf("Hello world\n");
    return 0;
}
```
那我們想要使用makefile去編譯他，所以要建立一個名為makefile的檔案，而內部要寫入要對這個hello.c所做的事。makefile如下:
```makefile=
hello:hello.c
	gcc hello.c -o hello
clean:
	rm -f hello
```
因為只有編譯一個hello.c檔，因此在linux終端輸入make時，便會執行gcc hello.c -o hello將其編譯為一個hello的執行檔案，而後輸入make clean時，便會將hello刪除。

### 多程式的Makefile實作2:
接著我們要在main.c這個檔案中使用其他的.c檔的function，那要如何撰寫makefile呢?先來看看這幾個.c檔:  

main.c
```c=
#include <stdio.h>
#include "tool.h"

int main(){
    int array[5]={1,8,3,4,5};
    int max=findMax(array, 5);
    printf("max=%d\n", max);
    return 0;
}
```
可以看到使用了外部程式"findMax"的function。及include了tool.h。  

tool.c
```c=
#include "tool.h"

int findMax(int array[], int size){
    int max=array[0];
    for(int i=0;i<size;i++){
        if(array[i]>max) max=array[i];
    }
    return max;
}
```
在這邊定義了"findMax"的function，將其寫入tool.h，使得在main.c這個檔案中可以被呼叫。  

tool.h
```c=
int findMax(int [], int);
```
一般在linux的terminal若要編譯上面的這兩個程式(main.c tool.c)為一個執行檔(main)，需要輸入:  
```bash=
gcc -g -Wall main.c tool.c -o main
```
倘若程式的規模變大，這樣又臭又長的編譯指令真的令人心煩，此外，若修改內部的一個分支的程式，所有程式都需要重新編譯一次，因此這時候我們便需要makefile來建立依賴關係，並且精簡編譯指令。因此這個例子的makefile可以這樣寫:  
```makefile=
main: main.c tool.o
	gcc -g -Wall main.c tool.o -o main

tool.o: tool.c
	gcc -c tool.c

clean:
	rm *.o main
```
在第一行，我們告訴編譯器要產生一個名為main的執行檔，而與該執行檔有關的檔案是main.c及tool.o，而後在第二行輸入要如何對其編譯。當編譯器在執行這邊的時候會發現尚未找到tool.o這個物件檔，因此會往後尋找tool.o這個檔案要如何產生，因此便會看到第4行，可以看到tool.o的依賴關係為tool.c，是透過tool.c編譯而成的物件檔。因此我們在linux終端輸入make時，執行順序應為:
```bash=
gcc -c tool.c
gcc -g -Wall main.c tool.o -o main
```
先將tool.c編譯但不連結成為tool.o的物件檔，在將其與main.c一同編譯為main的執行檔。

### 多程式的Makefile實作3:
剛剛的實作2是呼叫一個外部寫好的function而已，這次來試看看呼叫兩個:  

main.c
```c=
#include <stdio.h>
#include "max.h"
#include "min.h"

int main(){
    int array[5]={1,8,3,4,5};
    int max=findMax(array, 5);
    int min=findMin(array, 5);
    printf("max=%d\n", max);
    printf("min=%d\n", min);
    return 0;
}
```
max.c
```c=
#include "max.h"

int findMax(int array[], int size){
    int max=array[0];
    for(int i=0;i<size;i++){
        if(array[i]>max) max=array[i];
    }
    return max;
}
```
min.c
```c=
#include "min.h"

int findMin(int array[], int size){
    int min=array[0];
    for(int i=0;i<size;i++){
        if(array[i]<min) min=array[i];
    }
    return min;
}
```
那makefile要如何寫呢?先觀察彼此間的依賴關係main.c需要呼叫max.c及min.c的function，因此makefile寫法如下:  
```makefile=
main: main.c min.o max.o
	gcc -g -Wall main.c min.o max.o -o main

min.o: min.c
	gcc -c min.c

max.o: max.c
	gcc -c max.c

clean:
	rm *o main
```
### 多程式的Makefile實作4:
透過上面的三個實作應該對makefile比較了解了，但是上面的那種寫法僅能產生一個執行檔而已，倘若我需要產生兩個執行檔那要如何寫makefile呢?  

我們將上面寫的兩個findMax及findMin兩個function分別在main_max.c及main_min.c中呼叫，並分別產生兩個main_max及main_min的執行檔。

main_max.c
```c=
#include <stdio.h>
#include "max.h"

int main(){
    int array[5]={1,8,3,4,5};
    int max=findMax(array, 5);
    printf("max=%d\n", max);
    return 0;
}
```
main_min.c
```c=
#include <stdio.h>
#include "min.h"

int main(){
    int array[5]={1,8,3,4,5};
    int min=findMin(array, 5);
    printf("min=%d\n", min);
    return 0;
}
```
那根據上述規則我們應該可以寫出的makefile如下:  
```makefile=
main_max: main_max.c max.o
	gcc -g -Wall main_max.c max.o -o main_max

main_min: main_min.c min.o
	gcc -g -Wall main_min.c min.o -o main_min

max.o: max.c
	gcc -c max.c

min.o: min.c
	gcc -c min.c

clean:
	rm *.o main_max main_min
```
實際執行會發現仍然只有產生一個名為main_max的執行檔，而終端只有執行了兩行:
```bash=
gcc -c max.c
gcc -g -Wall main_max.c max.o -o main_max
```
原因是在第一行尋找main_max的依賴關係時，與main_min根本沒有相關，因此在編譯完main_max之後便結束了，要解決這個問題只需要在最上面加上所有要編譯的執行檔名稱即可，因此makefile改為:
```makefile=
all: main_max main_min

main_max: main_max.c max.o
	gcc -g -Wall main_max.c max.o -o main_max

main_min: main_min.c min.o
	gcc -g -Wall main_min.c min.o -o main_min

max.o: max.c
	gcc -c max.c

min.o: min.c
	gcc -c min.c

clean:
	rm *.o main_max main_min
```
那麼輸入make後可以看到執行了:
```bash=
gcc -c max.c
gcc -g -Wall main_max.c max.o -o main_max
gcc -c min.c
gcc -g -Wall main_min.c min.o -o main_min
```
也就成功的產生兩個main_max及main_min的執行檔了。

### Makefile實作5-使用變量:
在上面的makefile實作中，可以發現我們一直使用到gcc 或是在編譯時使用的參數-g -Wall等等，我們可以將其視為一個變量，要使用時以$(變量名稱)使用即可。  

以實作4的makefile為例子:
```makefile=
all: main_max main_min

main_max: main_max.c max.o
	gcc -g -Wall main_max.c max.o -o main_max

main_min: main_min.c min.o
	gcc -g -Wall main_min.c min.o -o main_min

max.o: max.c
	gcc -c max.c

min.o: min.c
	gcc -c min.c

clean:
	rm *.o main_max main_min
```
我們可以將其改為:
```makefile=
CC = gcc
CFLAGS = -g -Wall

all: main_max main_min

main_max: main_max.c max.o
	$(CC) $(CFLAGS) main_max.c max.o -o main_max

main_min: main_min.c min.o
	$(CC) $(CFLAGS) main_min.c min.o -o main_min

max.o: max.c
	$(CC) -c max.c

min.o: min.c
	$(CC) -c min.c

clean:
	rm *.o main_max main_min
```
改成以變量使用可以去掉重複修正的問題，並且較容易閱讀，也能達到同樣的功能。此外，也能夠透過閱讀makefile快速搞懂整個程式的架構及編譯流程。

## python:

### 創立虛擬環境
為了讓專案之間不要彼此汙染並且能夠有一個乾淨的環境，python提供一個創立virtual enviromnent的方法。
1. 在.bashrc加入這一行  (我還不知道什麼意思><) <- SO CUTE 
```
export PATH="$HOME/.local/bin:$PATH"
```
2. 下載virtualenv
```
$ pip install virtualenv
```
3. 進到要創立虛擬環境的目錄底下
4. 創立它  (輸入以下兩個指令都可以，但我還不知道差別><)
```
$ python3 -m venv venv
```
```
$ virtualenv -p python3 venv
```
5. 啟動環境
```
$ source ./venv/bin/activate
```  

6. 關掉環境
```
$ deactivate
```
7. 就可以在這個環境裡為所欲為了
## git使用:


## Atom(文字編輯器)使用:
       
## 聊天區:
我打玩了! 還有什麼更詳細的會再補充Xd 
借我當成做筆記的地方哈哈 晚安!