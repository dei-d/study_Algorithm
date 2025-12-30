#include "scheduler.h"
#include <stdio.h>


void swap_task(Task* a, int i, int j) {
    Task tmp = a[i];
    a[i] = a[j];
    a[j] = tmp;
}
//挿入ソート
void sort_condition(int i, int j, Task* s) {
    if(s[i].p_time > s[j].p_time) {
        swap_task(s, i, j);
    }else if(s[i].p_time == s[j].p_time && s[i].pri > s[j].pri) {
        swap_task(s, i, j);
    }
}
void insertion_sort(int head, int tail, Task* s) {
    for(int i=head+1; i<=tail; i++) {
        for(int k=i; k>head; k--) {
            sort_condition(k-1, k, s);
        }
    }
}
//タスク判定
int task_check(int notArrival, int tail, Task* s, double now_time) {
    for(int i=notArrival; i<=tail; i++) {
        if(s[i].a_time <= now_time) {
            if(i != notArrival)
                swap_task(s, notArrival, i);
            notArrival++;
        } 
    }
    return notArrival;
}
//タスク実行
void task_implement(int ready, Task* s, double now_time) {
    printf("%s実行  %.2f～%.2f\n", s[ready].name, now_time, now_time+s[ready]. p_time);
}