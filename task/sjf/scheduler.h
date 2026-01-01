#ifndef SCHEDULER_H
#define SCHEDULER_H
#define NAME_LEN 20

typedef struct process {
    char name[NAME_LEN];
    double a_time; //arrival_time
    double p_time; //processing_time
    int pri; //priority
} Task;


void swap_task(Task* a, int i, int j);
void sort_condition(int i, int j, Task* s);
void insertion_sort(int head, int tail, Task* s);
void task_check(int* notArrival, int tail, Task* s, double now_time);
void task_implement(int ready, Task* s, double now_time);
void execute(int num, double* now_time, int* ready, int* notArrival, Task* task);

#endif