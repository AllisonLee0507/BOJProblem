#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#include <cstring>
#define MAX 8
using namespace std;

int n, m, space, result;
int map[MAX][MAX];
int cmap[MAX][MAX];
bool flag[MAX * MAX];
bool visit[MAX][MAX];
vector <pair<int,int>> virus, zero;

int dx[4] = {0,0,1,-1};
int dy[4] = {1, -1,0, 0};

void input(){
    cin >> n >> m;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cin >> map[i][j];
            if(map[i][j] == 0){
                zero.push_back(make_pair(i, j));
            }
            if(map[i][j] == 2){
                virus.push_back(make_pair(i, j));
            }
        }
    }
    space = zero.size();
}
void bfs(int x, int y){
    queue<pair<int, int>> q;
    q.push(make_pair(x,y));
    visit[x][y] = true;
    while(!q.empty()){
        x = q.front().first;
        y = q.front().second;
        q.pop();
        for(int i = 0; i < 4; i++){
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx < 0 || ny < 0 || nx >= n || ny >= m){
                continue;
            }
            if(!visit[nx][ny] && cmap[nx][ny] == 0){
                cmap[nx][ny] = 2;
                visit[nx][ny] = true;
                q.push(make_pair(nx, ny));
                
            }
        }
    }
}
void spread_virus(){
    int cnt = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            cmap[i][j] = map[i][j];
        }
    }
    memset(visit, false, sizeof(visit));
    
    for(int i = 0; i <space; i++){
        if(cnt == 3){
            break;
        }
        if(flag[i] == true){
            int x = zero[i].first;
            int y = zero[i].second;
            cmap[x][y] = 1;
            cnt++;
        }
    }
    for(int i = 0; i<virus.size(); i++){
        int x = virus[i].first;
        int y = virus[i].second;
        bfs(x, y);
    }
    int safe = 0;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < m; j++){
            if(cmap[i][j] == 0){
                safe++;
            }
        }
    }
    result = (result > safe ? result : safe);
}

void make_wall(int idx, int cnt){
    if(cnt == 3){
        spread_virus();
        return;
    }
    for(int i = idx; i < space; i++){
        if(flag[i] == true){
            continue;
        }
        flag[i] = true;
        make_wall(i, cnt+1);
        flag[i] = false;
    }
}
int main(){
    input();
    make_wall(0,0);
    cout << result << "\n";
    return 0;
}

#endif
