#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int a1[101][101], a2[101][101];
int n, m;
void copy(){
    int i, j;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            a1[i][j] = a2[i][j];
        }
    }
}
void fill1(int x, int y){
    if(x<1||y<1||x>n||y>m){
        return;
    }
    if(a1[x][y]==0){
        a1[x][y] = 2;
        fill1(x+1, y);
        fill1(x-1, y);
        fill1(x, y+1);
        fill1(x, y-1);
    }
}
int check(int x, int y){
    int t = 0;
    if(a1[x+1][y]==2){
        t++;
    }
    if(a1[x-1][y]==2){
        t++;
    }
    if(a1[x][y+1]==2){
        t++;
    }
    if(a1[x][y-1]==2){
        t++;
    }
    return t;
}
int main(){
    int i, j, hour = 0, count;
    scanf("%d %d", &n, &m);
    for(i = 1; i<= n; i++){
        for(j = 1; j<= m ; j++){
            scanf("%d", &a1[i][j]);
            a2[i][j] = a1[i][j];
        }
    }
    while(1){
        fill1(1, 1);
        count = 0;
        for(i = 1; i <= n ; i++){
            for(j = 1; j <= m ; j++){
                if(a1[i][j]==1 && check(i, j)>=2){
                    a2[i][j] = 0;
                    count++;
                }
            }
        }
        if(count == 0){
            printf("%d", hour);
            break;
        }
        hour++;
        copy();
    }
    return 0;
}

#endif

#if 0
#include <stdio.h>
int dx[4] = {1, -1, 0, 0 };
int dy[4] = {0, 0, 1, -1};

int a1[101][101], a2[101][101];
int n, m;
void copy(){
    int i, j;
    for(i = 1; i <= n; i++){
        for(j = 1; j <= m; j++){
            a1[i][j] = a2[i][j];
        }
    }
}
void fill1(int x, int y){
    if(x<1||y<1||x>n||y>m){
        return;
    }
    if(a1[x][y]==0){
        a1[x][y] = 2;
        for(int i = 0; i < 4; i++){
            fill1(x+dx[i], y+dy[i]);
        }
//        fill1(x+1, y);
//        fill1(x-1, y);
//        fill1(x, y+1);
//        fill1(x, y-1);
    }
}
int check(int x, int y){
    int t = 0;
    if(a1[x+1][y]==2){
        t++;
    }
    if(a1[x-1][y]==2){
        t++;
    }
    if(a1[x][y+1]==2){
        t++;
    }
    if(a1[x][y-1]==2){
        t++;
    }
    return t;
}
int main(){
    int i, j, hour = 0, count;
    scanf("%d %d", &n, &m);
    for(i = 1; i<= n; i++){
        for(j = 1; j<= m ; j++){
            scanf("%d", &a1[i][j]);
            a2[i][j] = a1[i][j];
        }
    }
    while(1){
        fill1(1, 1);
        count = 0;
        for(i = 1; i <= n ; i++){
            for(j = 1; j <= m ; j++){
                if(a1[i][j]==1 && check(i, j)>=2){
                    a2[i][j] = 0;
                    count++;
                }
            }
        }
        if(count == 0){
            printf("%d", hour);
            break;
        }
        hour++;
        copy();
    }
    return 0;
}

#endif
