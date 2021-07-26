# Linux 使用筆記
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

## python:

## git使用:

## Atom(文字編輯器)使用: