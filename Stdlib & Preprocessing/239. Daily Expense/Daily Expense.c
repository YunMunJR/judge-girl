 #include <stdio.h>
#include <stdlib.h>
#include <string.h>
typedef struct data {
    int year;
    int month;
    int day;
    char name[33];
    int expense;
}data;
int cmp(const void* a, const void* b) {
    data* ptr1 = a;
    data* ptr2 = b;
    if (ptr1->year > ptr2->year){
        return 1;
    }else if (ptr1->year < ptr2->year){
        return -1;
    }else if (ptr1->month > ptr2->month){
        return 1;
    }else if (ptr1->month < ptr2->month){
        return -1;
    }else if (ptr1->day > ptr2->day){
        return 1;
    }else if (ptr1->day < ptr2->day){
        return -1;
    }else{
        return (strcmp(ptr1->name, ptr2->name));
    }
}        
int main(int argc, char* argv[]) {
    int n = 0, find;
    static data data_[10000];
    while (scanf("%d%d%d%s%d", &data_[n].year, &data_[n].month, &data_[n].day, data_[n].name, &data_[n].expense) != EOF) {
        find = 0;
        for (int i = 0; i < n; i++) {
            if (data_[n].year == data_[i].year && data_[n].month == data_[i].month && data_[n].day == data_[i].day && !strcmp(data_[i].name, data_[n].name)){
                data_[i].expense += data_[n].expense; 
                find = 1; 
                break;
            }
        }
        if (!find){
            n++;
        }
    }
    qsort(data_, n, sizeof(data), cmp);
    for (int i = 0; i < n; i++) {
        printf("%d %d %d %s %d", data_[i].year, data_[i].month, data_[i].day, data_[i].name, data_[i].expense);
        (i != n - 1) && printf("\n");
    }
    return 0;
}