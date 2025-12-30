#include <stdio.h>
#define Height 30
#define Width 30
typedef struct{
    int x, y;
} position;

void push(int H, int W, char maze[Height][Width], position q[1000], int dist[Height][Width], int x, int y, int px, int py, int* tail) {
    if(x<0 || x>=H)
        return;
    if(y<0 || y>=W)
        return;
    if(maze[x][y]=='#')
        return;
    if(dist[x][y] != -1)
        return;

    dist[x][y]=dist[px][py]+1;
    (*tail)++;
    q[*tail]=(position){x, y};

}

void bfs(int H, int W, char maze[Height][Width], position q[1000], int dist[Height][Width], int sx, int sy, int gx, int gy, int* head, int* tail) {
    if(maze[sx][sy]=='#' || maze[gx][gy]=='#')
        return;
    dist[sx][sy]=0;
    q[*head]=(position){sx, sy};
    while(*head <= *tail) {
        if(q[*head].x==gx && q[*head].y==gy) {

            printf("最短距離：%d", dist[q[*head].x][q[*head].y]);
            return;
        }
        push(H, W, maze, q, dist, q[*head].x+1, q[*head].y, q[*head].x, q[*head].y, tail);
        push(H, W, maze, q, dist, q[*head].x-1, q[*head].y, q[*head].x, q[*head].y, tail);
        push(H, W, maze, q, dist, q[*head].x, q[*head].y+1, q[*head].x, q[*head].y, tail);
        push(H, W, maze, q, dist, q[*head].x, q[*head].y-1, q[*head].x, q[*head].y, tail);
        (*head)++;
    }
    printf("到達不可能\n");
}
int main() {
    int h, w;
    int sx, sy;
    int gx, gy;
    char maze[Height][Width];
    int dist[Height][Width];
    position q[1000]; 
    int head =0;
    int tail =0;
    

    scanf("%d %d", &h, &w);
    scanf("%d %d", &sx, &sy);
    scanf("%d %d", &gx, &gy);
    for(int i=0; i<h; i++) {
        scanf("%s", &maze[i]);
    }

    for(int i=0;i<h;i++) 
        for(int j=0;j<w;j++) 
            dist[i][j] = -1;

    bfs(h, w, maze, q, dist, sx, sy, gx, gy, &head, &tail);

    return 0;
}