#include "scheduler.h"
#include <stdio.h>
#define END_TIME 20.00

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
void task_check(int* notArrival, int tail, Task* s, double now_time) {
    int head = (*notArrival);
    for(int i=head; i<=tail; i++) {
        if(s[i].a_time <= now_time) {
            if(i > (*notArrival))
                swap_task(s, *notArrival, i);
            (*notArrival)++;
        } 
    }
}
//タスク実行
void task_implement(int ready, Task* s, double now_time) {
    printf("%s実行  %.2f～%.2f\n", s[ready].name, now_time, now_time+s[ready]. p_time);
}

void execute(int num, double* now_time, int* ready, int* notArrival, Task* task) {
    while(1) {   
        if(*now_time > END_TIME)
            break;
        task_check(notArrival, num-1, task, *now_time); 
        if(*ready != *notArrival) {
            insertion_sort(*ready, *notArrival-1, task);
            task_implement(*ready, task, *now_time);
            *now_time += task[*ready].p_time;
            (*ready)++;
        }else {
            printf("空き時間\n");
            (*now_time)++;
        }
    }
}