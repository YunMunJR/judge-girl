> 期末無關，請迴避
# 題目描述
俄羅斯套娃有許多不同的大小，小的可以放置在大的之中，定義結構如下： <br>
![doll.h](https://github.com/WjrHyl/judge-girl/blob/main/Advanced/10078.%20Matryoshka%20Doll/doll.h) <br>
其中 Doll.top 和 Doll.bottom 蓋子和底座的樣式，用一個字元表示。 <br>

- Doll *newDoll(char top, char bottom); <br>
初始化一個俄羅斯娃娃，其中蓋子樣式 top、底座樣式 bottom。
- void package(Doll *outer, Doll *inter); <br>
將一個小的俄羅斯娃娃放進大的裡面。 
- const char* doll_c_str(Doll *doll); <br>
將一個俄羅斯娃娃內部訊息用括弧表示法輸出，回傳字串的起始位置。 
# Sample Output
<(@>)~