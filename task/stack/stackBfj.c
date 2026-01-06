#include <stdio.h>
#define Max 20

typedef struct stack {
    int x, y;
} Stack;

int is_road(int h, int w, char c, int x, int y) {
    if(x < 0 || x >= h)
        return 0;
    if(y < 0 || y >= w)
        return 0;
    if(c == '#')
        return 0;
    return 1;
}


void push(int h, int w, int* tail, char maze[Max][Max], Stack stack[Max * Max], int glid[Max][Max], int dist[Max][Max], int x, int y, int px, int py) {
    if(!is_road(h, w, maze[x][y], x, y) || glid[x][y])
        return;
    stack[(*tail)++] = (Stack){x, y};
    glid[x][y] = 1;
    dist[x][y] = dist[px][py] + 1;
}


int main() {
    int top = 0, tail=0;
    int h, w;
    int sx, sy;
    int gx, gy;
    char maze[Max][Max];
    int glid[Max][Max];
    int dist[Max][Max];
    Stack stack[Max * Max];


    scanf("%d %d", &h, &w);
    scanf("%d %d", &sx, &sy);
    scanf("%d %d", &gx, &gy);
    for(int i=0; i<h; i++)
        scanf("%s", maze[i]);


    //初期条件
    if(!is_road(h, w, maze[sx][sy], sx, sy) || !is_road(h, w, maze[gx][gy], gx, gy)) {
        printf("初期値エラー\n");
        return 0;
    }
    for(int i=0; i<h; i++) 
        for(int j=0; j<w; j++) 
            glid[i][j]=0;
    for(int i=0; i<h; i++) 
        for(int j=0; j<w; j++) 
            dist[i][j]=-1;


    dist[sx][sy] = 0;
    stack[tail++] = (Stack){sx, sy};
    glid[sx][sy] = 1;
    while(top < tail) {
        int x = stack[top].x;
        int y = stack[top].y;

        if(x == gx && y == gy) {
            printf("%d", dist[gx][gy]);
            return 0;
        }
        
        top++;
        push(h, w, &tail, maze, stack, glid, dist, x+1, y, x, y);
        push(h, w, &tail, maze, stack, glid, dist, x-1, y, x, y);
        push(h, w, &tail, maze, stack, glid, dist, x, y+1, x, y);
        push(h, w, &tail, maze, stack, glid, dist, x, y-1, x, y);
    }
    printf("%d\n", dist[gx][gy]);

    
    return 0;
}

/*stack
maze[i][j]に進む　→　pop stck[top]
    glid[i][j]にフラグを立てる
    maze[i][j]から進めるマスをstackに入れる
        i+-1, j+-1,の評価
        ゴールについたら即終了
stack[top]に進む

stackが空になったら終了
*/