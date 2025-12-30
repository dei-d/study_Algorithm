#include <stdio.h>
#define Height_max 30
#define Weight_max 30

void dfs(int h, int w, char maze[Height_max][Weight_max], int glid[Height_max][Weight_max], int sx, int sy, int gx, int gy, int* found) {
    if(*found)
        return;
    //範囲内だったら処理をするではなく、範囲外だったら処理をしないで考える
    if(sx<0 || sx>=h )
        return;
    if(sy<0 || sy>=w)
        return;
    if(maze[sx][sy] == '#')
        return;
    if(glid[sx][sy]==1)
        return;
    glid[sx][sy]=1;
    if(sx==gx && sy==gy) {
        *found=1;
        return;
    }
    dfs(h, w, maze, glid, sx+1, sy, gx, gy, found);
    dfs(h, w, maze, glid, sx-1, sy, gx, gy, found);
    dfs(h, w, maze, glid, sx, sy+1, gx, gy, found);
    dfs(h, w, maze, glid, sx, sy-1, gx, gy, found);
}

int main() {
    int h, w;
    int sx, sy;
    int gx, gy;
    int found=0;
    char maze[Height_max][Weight_max];
    int glid[Height_max][Weight_max];

    scanf("%d %d", &h, &w);
    scanf("%d %d", &sx, &sy);
    scanf("%d %d", &gx, &gy);
    for(int i=0; i<h; i++) {
        scanf("%s", maze[i]);
    }

    dfs(h, w, maze, glid, sx, sy, gx, gy, &found);
    if(found) {
        printf("到達可能\n");
    }else {
        printf("到達不可能\n");
    }
    return 0;
}