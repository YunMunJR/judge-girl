# 題目描述
學會 function 和 pointer 之後，總要來點 function pointer 才行。你的目標要完成 myint.c 中三個函數。在 <br>
 madd() 、 msub() 、 getmyheart()  三個函數中，其中  madd()  和  msub()  只需要完成兩個整數的加 <br>
法和減法即可。而在  getmyheart()  中，你必須將  myint.c  函數封裝到  int (*FUNC[])(int, int) <br> 
函數指標陣列。<br> <br>

特別注意  getmyheart()  的前兩行  secret(); 、 test_heart();  不需要更動，用來輸出 Morris 的秘密 <br>
以及測試你寫的  madd()  和  msub  的函數是否正確。Morris 藏在  singletest.c  的秘密不需理會。<br>
>AC 的通關密語當然要讓 Morris 說出秘密！