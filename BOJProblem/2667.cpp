#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;
bool check[30][30];
int n, arr[30][30], num[1010], cnt;
int dx[4] = {0,0,-1,1};
int dy[4] = {0,0,-1,1};

void dfs(int x, int y){
    check[x][y] = true;
    num[cnt]++;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(0 <= nx && nx < n && 0 <= ny && ny < n){
            if(!check[nx][ny] && arr[nx][ny]){
                dfs(nx, ny);
            }
        }
    }
}
int main(){
    scanf(" %d", &n);
    for(int i = 0; i < n; i++){
        for(int j = 0; j < n; j++){
            scanf(" %ld", &arr[i][j]);
        }
    }
    for(int i = 0; i<n; i++){
        for(int j = 0; j < n; j++){
            if(!check[i][j] && arr[i][j]){
                dfs(i, j);
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    sort(num, num+cnt);
    for(int i = 0; i<cnt; i++){
        printf("%d\n", num[i]);
    }
}
#endif

#if 0
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b){
    int x = *(int *)a, y = *(int *)b;
    if(x < y){
        return -1;
    }
    if(x > y){
        return 1;
    }
    return 0;
}
int d[25][25], dx[4]={-1, 1, 0, 0}, dy[4] = {0,0,1,-1}, n, sum;
void bfs(int x, int y, int k){
    if(d[x][y] != 1){
        return;
    }
    int nx, ny, i;
    sum += 1;
    d[x][y] = k;
    for(i = 0; i  < 4; i++){
        nx = x + dx[i];
        ny = y + dy[i];
        if( 0 <= nx && nx < n && 0 <= ny && ny < n){
            bfs(nx, ny, k);
        }
    }
}
int main(){
    int i, j, len = 2, ans[1000];
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        for(j = 0; j <n; j++){
            scanf("%ld", &d[i][j]);
        }
    }
    for(i = 0; i < n; i++){
        for(j = 0; j<n; j++){
            if(d[i][j] == 1){
                sum = 0;
                bfs(i, j, len);
                ans[len-2] = sum;
                len++;
            }
        }
    }
    printf("%d\n", len - 2);
    len -= 2;
    qsort(ans, len, sizeof(int), compare);
    for(i = 0; i < len; i++){
        printf("%d\n", ans[i]);
    }
}
#endif


#if 0
#include <stdio.h>

int x[4] = {0, 0, 1, -1};
int y[4] = {1, -1, 0, 0};
char map[30][30];
int island[500], n, t= 1;

void check(char map[][30], int i, int j){
    int k;
    map[i][j] = 2;
    island[t]++;
    for(k = 0; k< 4; k++){
        if(i + x[k] >= 0 && i + x[k] < n && j + y[k] >= 0 && j + y[k] < n && map[i+x[k]][j+y[k]] == '1'){
            check(map, i + x[k], j+y[k]);
        }
    }
}

void qsort(int left, int right){
    int i, j, s, t;
    if(left<right){
        s = island[(left + right) / 2];
        i = left - 1;
        j = right + 1;
        while(1){
            while(island[++i] < s);
            while(island[--j] > s);
            if(i >= j){
                break;
            }
            t = island[i];
            island[i] = island[j];
            island[j] = t;
        }
        qsort(left, i -1);
        qsort(j + 1, right);
    }
}
int main(){
    int i, j;
    scanf("%d", &n);
    for(i = 0; i < n; i++){
        scanf("%s", map[i]);
    }
    for(i = 0; i < n; i++){
        for(j = 0; j < n; j++){
            if(map[i][j] == '1'){
                check(map, i, j);
                t++;
            }
        }
    }
    qsort(0, t-1);
    printf("%d\n", t-1);
    for(i = 1; i < t; i++){
        printf("%d\n", island[i]);
    }
    return 0;
}
#endif
