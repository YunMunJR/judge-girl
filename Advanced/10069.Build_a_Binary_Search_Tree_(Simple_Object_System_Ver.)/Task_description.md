# 題目描述
二元搜尋樹（Binary Search Tree），也稱二叉搜索樹、有序二元樹（ordered binary tree），排序二元樹（sorted binary <br> tree），是指一棵空樹或者具有下列性質的二元樹：
<br>
- 若任意節點的左子樹不空，則左子樹上所有結點的值均小於它的根結點的值；
- 任意節點的右子樹不空，則右子樹上所有結點的值均大於它的根結點的值；
- 任意節點的左、右子樹也分別為二元搜尋樹。
- 沒有鍵值相等的節點（no duplicate nodes）。
通常一開始學到二元搜尋樹，會先教插入算法，現在的這個問題很簡單，只是稍微要求效率。

# 輸入格式
輸入有多組測資，每一組，第一行有一個數字 $N (0 < N <131072)$，接下來會建入 $N$ 個數字 $M$ (signed 32-bit) ，沒<br>有數字會重複。
# 輸出格式
對於每一組測資，輸出一行的前序走訪。
# 範例輸入
```
5
0 1 2 4 3
5
0 2 4 1 3
5
3 1 4 2 0
5
1 4 2 0 3
5
0 4 3 2 1
```
# 範例輸出
```
0 1 2 4 3
0 2 1 4 3
3 1 0 2 4
1 0 4 2 3
0 4 3 2 1
```
# 編譯參數
```
gcc main.c basic_node.c bst_node.c object.c -std=c99
```
## main.c
![main.c](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10069.Build_a_Binary_Search_Tree_(Simple_Object_System_Ver.)/main.c)
## node.c
![node.c](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10069.Build_a_Binary_Search_Tree_(Simple_Object_System_Ver.)/node.c)
## basic_node.c
![basic_node.c](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10069.Build_a_Binary_Search_Tree_(Simple_Object_System_Ver.)/basic_node.c)
## bst_node.c
![bst_node.c](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10069.Build_a_Binary_Search_Tree_(Simple_Object_System_Ver.)/bst_node.c)
## object.h
![object.h](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10069.Build_a_Binary_Search_Tree_(Simple_Object_System_Ver.)/object.h)
## object.c
![object.c](https://github.com/YunMunJR/judge-girl/blob/main/Advanced/10069.Build_a_Binary_Search_Tree_(Simple_Object_System_Ver.)/object.c)
# 後記
- 參考![Learn C The Hard Way](https://learncodethehardway.org/c/)

上述寫法用在 Singleton 比較好，用來寫 node 過於肥大。 `free()`  的時候請特別小心，這會與當初  `malloc`一整塊<br>空間一起回收，別總是利用限有的空間配置！