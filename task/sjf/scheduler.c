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
int task_check(int x_head, int tail, Task* s, double now_time) {
    for(int i=x_head; i<=tail; i++) {
        if(s[i].a_time <= now_time) {
            if(i != x_head)
                swap_task(s, x_head, i);
            x_head++;
        } 
    }
    return x_head;
}
//タスク実行
void task_implement(int head, Task* s, double now_time) {
    printf("%s実行  %.2f～%.2f\n", s[head].name, now_time, now_time+s[head]. p_time);
}