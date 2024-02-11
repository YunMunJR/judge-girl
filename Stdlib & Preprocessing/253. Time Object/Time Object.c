#ifndef MWTIME
#define MWTIME
#include <stdio.h>
#include <string.h>
typedef struct Time {
    int hour;
    int minute;
    int second;
} Time;
void initTime(Time*time){
    time->hour=0;
    time->minute=0;
    time->second=0;
}
void setTime(Time *time, int hour, int minute, int second){
    time->hour=hour;
    time->minute=minute;
    time->second=second;
}
void addTime(Time *time, int hour, int minute, int second){
    time->second+=second;
    if(time->second>=60){
        time->second-=60;
        time->minute++;
    }
    time->minute+=minute;
    if(time->minute>=60){
        time->minute-=60;
        time->hour++;
    }
    time->hour+=hour;
    time->hour%=24;
}
void printTime(Time *time){   
#ifdef H24
    if(time->hour>9){
        printf("%d",time->hour);
    }else{
        printf("0%d",time->hour);
    }
#else
    if(time->hour>21){
        printf("%dpm",time->hour-12);
    }else if(time->hour>11){
        if(time->hour==12){
            fputs("12pm",stdout);
        }else{
            printf("0%dpm",time->hour-12);
        }
    }else if(time->hour>9){
            printf("%dam",time->hour);
    }else{
        if(time->hour==0){
            fputs("12am",stdout);
        }else{
            printf("0%dam",time->hour);
        }
    } 
#endif
    if(time->minute>9){
        printf(":%d",time->minute);
    }else{
        printf(":0%d",time->minute);
    }
    if(time->second>9){
        printf(":%d\n",time->second);
    }else{
        printf(":0%d\n",time->second);
    }
}
void initTime(Time *time);
void setTime(Time *time, int hour, int minute, int second);
void addTime(Time *time, int hour, int minute, int second);
void printTime(Time *time);
#endif