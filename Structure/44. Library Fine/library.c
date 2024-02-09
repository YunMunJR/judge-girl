#include "book.h"
#include "date.h"
#include <stdio.h>
int Is_Lunar_Or_Not(int year1) {
    if (year1 % 400 == 0 || (year1 % 4 == 0 && year1 % 100 != 0)){
        return 1;
    }else{
        return 0;
    }
}
int the_days_of_month(int month,int year) {
    switch (month){
        case 1: case 3: case 5: case 7: case 8: case 10: case 12: 
            return 31; 
        case 4: case 6: case 9: case 11: 
            return 30;
        case 2:
            if (Is_Lunar_Or_Not(year)){
                return 29;
            }else{
                return 28; 
            }
    }
}
int the_days_of_a_year(int year) {
    if (Is_Lunar_Or_Not(year)){
        return 366;
    }else{
        return 365;
    }
}
int solve(struct Date date_borrowed, struct Date date_returned) {
    int k = (date_returned.year - date_borrowed.year > 1), sum = 0, n = 0;
    if (k){
        for (int i = date_borrowed.year + 1; i <= date_returned.year - 1; i++){
            sum += the_days_of_a_year(i);
        }   
        for (int i = date_borrowed.month + 1; i <= 12; i++){
            sum += the_days_of_month(i, date_borrowed.year);
        }
        sum += (the_days_of_month(date_borrowed.month, date_borrowed.year) - date_borrowed.day);
        for (int i = 1; i < date_returned.month; i++){
            sum += the_days_of_month(i, date_returned.year);
        }
        sum += date_returned.day;
        return sum + 1;
    }else if (date_returned.year - date_borrowed.year == 1){
        for (int i = 12; i > date_borrowed.month; i--){
            sum += the_days_of_month(i, date_borrowed.year);
        }
        sum += (the_days_of_month(date_borrowed.month, date_borrowed.year) - date_borrowed.day);
        for (int i = 1; i < date_returned.month; i++){
            sum += the_days_of_month(i, date_returned.year);
        }
        sum += date_returned.day;
        return sum + 1;
    }else{
        if (date_returned.month - date_borrowed.month > 1){
            for (int i = date_borrowed.month + 1; i < date_returned.month; i++){
                sum += the_days_of_month(i, date_returned.year);
            }
            sum += date_returned.day;
            sum += (the_days_of_month(date_borrowed.month, date_borrowed.year) - date_borrowed.day);
            return sum + 1;
        }else if (date_returned.month - date_borrowed.month == 1){
            sum += (the_days_of_month(date_borrowed.month, date_borrowed.year) - date_borrowed.day);
            sum += date_returned.day;
            return sum + 1;
        }else{
            sum += (date_returned.day - date_borrowed.day);
            return sum + 1;
        }
    }
}
unsigned int library_fine(struct Book book, struct Date date_borrowed, struct Date date_returned) {
    unsigned int importance = book.importance;
    int fisrt1 = -1, second1 = -1, fine;
    for (int i = 0; importance > 0; i++) {
        if (importance % 2) {
            if (second1 < 0){ 
                second1 = i;  
            }else{ 
                fisrt1 = i; 
                break; 
            }
        }
        importance >>= 1;
    }
    importance = fisrt1 - second1 - 1;
    switch (book.type) {
        case NOVEL:
            fine = (solve(date_borrowed, date_returned) - 90) * importance; 
            break;
        case COMICS:
            fine = (solve(date_borrowed, date_returned) - 10) * importance; 
            break;
        case MANUAL:
            fine = (solve(date_borrowed, date_returned) - 100) * importance; 
            break;
        case TEXTBOOK:
            fine = (solve(date_borrowed, date_returned) - 5) * importance; 
            break;
        default:
            fine = 0;
    }
    return (fine >= 0) ? fine : 0;
}