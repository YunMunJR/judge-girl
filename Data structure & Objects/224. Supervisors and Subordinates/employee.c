#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "employee.h"

void init_storage(Employee** storage, int n){
    (*storage) = (Employee*)malloc(sizeof(Employee) * n);
}
 
void free_storage(Employee** storage){
    free(*storage);
    *storage = 0;
}
 
Employee* find_employee_by_id(Employee* set, int n, int id) {
    Employee* re = (Employee*)malloc(sizeof(Employee));
    for (int i = 0; i < n; i++) {
        if (set[i].id == id) {
            re = &set[i]; break;
        }
    }
    return re;
}
 
Employee* find_employee_by_name(Employee* set, int n, const char* first_name, const char* last_name) {
    Employee* re = (Employee*)malloc(sizeof(Employee));
    for (int i = 0; i < n; i++) {
        if (!strcmp(set[i].first_name, first_name) && !strcmp(set[i].last_name, last_name)) {
            re = &set[i]; break;
        }
    }
    return re;
}
 
Employee* find_root_boss(Employee* set, int n, Employee* employee) {
    Employee** find = (Employee*)malloc(sizeof(Employee) * 2);
    find[0] = employee; find[1] = NULL; int idx;
    if ((*find[0]).boss_id != (*find[0]).id) {
        for (int i = 0; i < n; i++) {
            if (set[i].id == (*find[0]).boss_id) {
                find[1] = &set[i]; idx = i; break;
            }
        }
        free(find);
        return find_root_boss(set, n, &set[idx]);
    }else {
        return find[0];
    }
}
 
int check_relationship(Employee* set, int n, Employee* A, Employee* B) {
    int sub = 0, sup = 0; Employee find = *A; 
        while (find.id != (*B).id && find.id != find.boss_id) {
            for (int i = 0; i < n; i++) {
                if (set[i].id == find.boss_id) {
                    find = set[i]; break;
                }
            }
            if (find.id == (*B).id){
                sub = 1;
            }
        }
        if (!sub) {
            find = *B;
            while (find.id != (*A).id && find.id != find.boss_id) {
                for (int i = 0; i < n; i++) {
                    if (set[i].id == find.boss_id) {
                        find = set[i]; break;
                    }
                }
                if (find.id == (*A).id){
                    sup = 1;
                }
            }
        }
    if (sub || sup) {
        return (sub) ? 1 : 2;
    }else {
        Employee a = *find_root_boss(set, n, A), b = *find_root_boss(set, n, B);
        return (a.id == b.id) ? 3 : 0;
    }    
}