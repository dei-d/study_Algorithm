#include <stdio.h>
#include "scheduler.h"
#define TASK_MAX 10
#define START_TIME 9.00
#define END_TIME 20.00


int main() {
    int num;
    double now_time = START_TIME; //9:00
    Task task[TASK_MAX];
    int ready = 0;
    int notArrival = 0;

    //scan
    scanf("%d", &num);
    printf("入力例:a 12.50(時) 2.00(時間) 3(数字が小さい方が優先度が高い)\n");
    for(int i=0; i<num; i++) {
        printf("%d個目:名前 到着時間 利用時間 優先順位 :", i+1);
        scanf("%s %lf %lf %d", task[i].name, &task[i].a_time, &task[i].p_time, &task[i].pri);
    }
    
    execute(num, &now_time, &ready, &notArrival, task);
    return 0;
}
