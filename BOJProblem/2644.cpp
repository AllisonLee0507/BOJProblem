#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <queue>

using namespace std;

int n, start, finish, m, a[101][101], d[101];

int main(){
    cin >> n >> start >> finish >> m;
    for (int i = 0; i <  m; i++){
        int x = 0, y = 0;
        cin >> x >> y;
        a[x][y] = a[y][x] = 1;
    }
    queue<int> q;
    q.push(start);
    while(!q.empty()){
        int now = q.front();
        q.pop();
        
        for(int i = 1; i <= n; i++){
            if(a[now][i] == 0 || d[i] != 0){
                continue;
            }
            d[i] = d[now] + 1;
            q.push(i);
        }
    }
    cout << (d[finish] == 0 ? -1 : d[finish]) << endl;
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
#include <queue>
int n, m;
int num1, num2;
int x, y;

int depth[101];
int family[101][101];
bool visit[101];
queue <int> q;

void bfs(int i){
    visit[i] = true;
    q.push(i);
    int temp;
    while(!q.empty()){
        temp = q.front();
        q.pop();
        for(int j = 1; j <= n; j++){
            if(family[temp][j] == 1 && !visit[j]){
                visit[j] = true;
                depth[j] = depth[temp] + 1;
                q.push(j);
            }
        }
    }
}
int main(){
    cin >> n;
    cin >> num1 >> num2;
    cin >> m;
    int a, b;
    for(int i = 1; i <= m; i++){
        cin >> a >> b;
        family[a][b] = 1;
        family[b][a] = 1;
    }
    bfs(num1);
    if(depth[num2] != 0){
        cout << depth[num2] << endl;
    }
    else{
        cout << "-1" << endl;
    }
    return 0;
}
#endif

#if 0
#include <stdio.h>

int n,a,b,m,f,e,sol = -1;
int map[100+10][100+10];
int sel[100+10];
void dfs(int idx, int cnt){
    int i;
    if(idx == b){
        sol = cnt;
        return;
    }
    for(i =1; i <= n; i++){
        if(sel[i]){
            continue;
        }
        if(map[idx][i]){
            sel[i] = 1;
            dfs(i, cnt+1);
        }
    }
}
int main(void){
    int i;
    scanf("%d %d %d %d", &n, &a, &b, &m);
    for(i = 0; i < m; i++){
        scanf(" %d %d", &f, &e);
        map[f][e] = map[e][f] = 1;
    }
    dfs(a, 0);
    printf("%d\n", sol);
    
    return 0;
}
#endif
