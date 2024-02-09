#include "employee.h"
#include <stdio.h>
#include <string.h>
typedef struct returnvalue {
    int re;
    Employee* boss;
}returnvalue;
returnvalue findsub(Employee* employee1, Employee* employee2) {
    Employee* em = employee1; returnvalue re;
    while (strcmp(em->first_name, employee2->first_name) != 0 || strcmp(em->last_name, employee2->last_name) != 0) {
        if (!strcmp(em->first_name, em->boss->first_name) && !strcmp(em->last_name, em->boss->last_name)){ 
            re.boss = em->boss; 
            re.re = 0; 
            return re; 
            }
        else{
            em = em->boss;
        }
    }
    re.boss = em->boss; 
    re.re = 1;
    return re;
}
returnvalue findsup(Employee* employee1, Employee* employee2) {
    Employee* em = employee2; returnvalue re;
    while (strcmp(em->first_name, employee1->first_name) != 0 || strcmp(em->last_name, employee1->last_name) != 0){
        if (!strcmp(em->first_name, em->boss->first_name) && !strcmp(em->last_name, em->boss->last_name)){ 
            re.boss = em->boss; 
            re.re = 0; 
            return re; 
        }
        else{
            em = em->boss;
        }
    }
    re.boss = em->boss; 
    re.re = 1;
    return re;
}
int relation(Employee *employee1, Employee *employee2) {
    returnvalue val1, val2;
    val1 = findsub(employee1, employee2);
    val2 = findsup(employee1, employee2);
    if (val1.re){
        return 1;
    }else{
        if (val2.re){
            return 2;
        }else {
            if (!strcmp(val1.boss->first_name, val2.boss->first_name) && !strcmp(val1.boss->last_name, val2.boss->last_name)){
                return 3;
            }else{
                return 4;
            }
        }
    }
}