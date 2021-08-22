#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
void dfs(int startPoint, int n, int(*arr)[1001], int visit[], int *cnt){
    if(visit[startPoint]){
        return;
    }
    visit[startPoint] = 1;
    (*cnt)++;
    for(int i = 1; i <= n; i++){
        if(arr[startPoint][i]){
            dfs(i, n, arr, visit, cnt);
        }
    }
}
int main(){
    int m, n, arr[1001][1001] = {0}, visit[1001] = {0}, a, b, cnt = 0, mcnt = 1;
    
    scanf("%d %d", &n, &m);
    for(int i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        arr[a][b] = 1;
        arr[b][a] = 1;
    }
    for(int i = 1; i <= n; i++){
        if(visit[i]){
            continue;
        }
        dfs(i, n, arr, visit, &cnt);
        if(cnt != n){
            mcnt++;
        }
    }
    printf("%d\n", mcnt);
    
    return 0;
}
#endif

#if 0
#include <stdio.h>

int n, m;
int g[1001][1001];
int visited[1001];

void dfs(int s){
    int i;
    visited[s] = 1;
    for(i = 1; i <= n; i++){
        if(g[s][i] && !visited[i]){
            dfs(i);
        }
    }
}
int main(){
    int i, ans = 0;
    scanf("%d%d", &n, &m);
    while(m--){
        int a, b;
        scanf("%d%d", &a, &b);
        g[a][b] = g[b][a] = 1;
    }
    for(i = 1; i<= n; i++){
        if(!visited[i]){
            ans++;
            dfs(i);
        }
    }
    printf("%d\n", ans);
}
#endif

#if 0
#include <stdio.h>
#include <string.h>

int n, m, count;
int E[1001][1001];
int visited[1001];
void dfs(int v){
    int i;
    visited[v] = 1;
    for(i = 1; i <= n; i++){
        if(E[v][i] && !visited[i]){
            dfs(i);
        }
    }
}
int main(){
    int i, v1, v2;
    scanf("%d %d", &n, &m);
    for(i = 0; i < m; i++){
        scanf("%d %d", &v1, &v2);
        E[v1][v2] = E[v2][v1] = 1;
    }
    for(i = 1; i <= n; i++){
        if(!visited[i]){
            dfs(i);
            count++;
        }
    }
    printf("%d", count);
    return 0;
}
#endif
