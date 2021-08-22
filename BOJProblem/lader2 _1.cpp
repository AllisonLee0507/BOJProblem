#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct pos{
    int x, y;
    pos() {}
    pos(int x, int y) : x(x), y(y) {}
};

int c[100][100];
int a[100][100], T;
int dx[3] = {0, 0, 1};
int dy[3] = {-1, 1, 0};
vector<int> s;

void init(){
    s.clear();
    memset(a, 0, sizeof(a));
    cin >> T;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j <100; j++){
            cin >> a[i][j];
            if(i == 0 && a[i][j] == 1){
                s.push_back(j);
            }
        }
    }
}

int bfs(pos p){
    memset(c, -1, sizeof(c));
    c[0][p.y] = 0;
    queue<pos> q;
    q.push(p);
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        if(x == 99){
            return c[x][y];
        }
        for(int k = 0; k < 3; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx < 0 || nx >= 100 || ny <0 || ny >= 100){
                continue;
            }
            if(a[nx][ny] && c[nx][ny] == -1){
                c[nx][ny] = c[x][y]+1;
                q.push(pos(nx, ny));
                break;
            }
        }
    }
    return 0;
}

int main(){
    freopen("/Users/allison/Desktop/Coding/123/Bronze/SWEA1211_input.txt", "r", stdin);
    while(T!=10){
        init();
        int path = 0x3f3f3f3f, ans;
        for(int i = 0; i < s.size(); i++){
            int dist = bfs(pos(0, s[i]));
            if(path > dist){
                path = dist;
                ans = s[i];
            }
        }
        cout << '#' << T << ' ' << ans << '\n';
    }
    return 0;
}
#endif
