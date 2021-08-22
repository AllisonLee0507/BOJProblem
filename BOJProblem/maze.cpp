#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int matrix[17][17];
int result;
void solve(int x, int y) {  // 1 = 위   2= 아래  3= 오른쪽   4= 왼쪽

    if (matrix[x][y] == 3)
        result = 1;

    if (matrix[x + 1][y] != 1) {
        matrix[x][y] = 1;
        solve(x + 1, y);
    }
    if (matrix[x - 1][y] != 1) {
        matrix[x][y] = 1;
        solve(x - 1, y);
    }
    if (matrix[x][y - 1] != 1) {
        matrix[x][y] = 1;
        solve(x, y - 1);
    }
    if (matrix[x][y + 1] != 1) {
        matrix[x][y] = 1;
        solve(x, y + 1);
    }
}

int main(){
    int X = 0, Y = 0;
    
    freopen("/Users/allison/Desktop/Coding/123/Bronze/maze input.txt", "r", stdin);
    int T_C;
    
    for(int test_case = 0; test_case<10; test_case++){
        result = 0;
        scanf("%d", &T_C);
        for(int i = 0; i < 16; i++){
            for(int j = 0; j <16; j++){
                scanf("%1d", &matrix[i][j]);
                if(matrix[i][j] == 2){
                    X = i;
                    Y = j;
                }
            }
        }
        solve(X, Y);
        printf("#%d %d\n", test_case+1, result);
    }
    
    return 0;
}

#endif

#if 0
#include <stdio.h>

int matrix[17][17];
int result;
void solve(int x, int y) {  // 1 = 위   2= 아래  3= 오른쪽   4= 왼쪽

    if (matrix[x][y] == 3)
        result = 1;

    if (matrix[x + 1][y] != 1) {
        matrix[x][y] = 1;
        solve(x + 1, y);
    }
    if (matrix[x - 1][y] != 1) {
        matrix[x][y] = 1;
        solve(x - 1, y);
    }
    if (matrix[x][y - 1] != 1) {
        matrix[x][y] = 1;
        solve(x, y - 1);
    }
    if (matrix[x][y + 1] != 1) {
        matrix[x][y] = 1;
        solve(x, y + 1);
    }

}

int main(void)
{
    int X, Y;

    freopen("/Users/allison/Desktop/Coding/123/Bronze/maze input.txt", "r", stdin);
    int T_C;
    setbuf(stdout, NULL);

    for (int test_case = 0; test_case < 10; test_case++) {
        result = 0;
        scanf("%d", &T_C);

        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                scanf("%1d", &matrix[i][j]);
                if (matrix[i][j] == 2) {
                    X = i;
                    Y = j;
                }
            }
        }
        solve(X, Y);

        printf("#%d %d\n", test_case + 1, result);
    }

    return 0;
}
#endif

#if 0
#include <stdio.h>
int row[4] = {1, -1, 0, 0};
int column[4] = {0, 0, -1, 1};
char maze[16][16], ret;
void find(int r, int c){
    maze[r][c] = '1';
    for(int i = 0; i < 4; i++){
        int dr = r + row[i];
        int dc = c + column[i];
        if((dr < 0) || (dc < 0) || (dr >= 16) || (dc >= 16) || maze[dr][dc] == '1'){
            continue;
        }
        if(maze[dr][dc] == '3'){
            ret = 1;
            break;
        }
        else if (maze[dr][dc] == '0'){
            find(dr, dc);
        }
    }
    maze[r][c] = '0';
    return;
    
}
int main(){
    int r, c;
    freopen("/Users/allison/Desktop/Coding/123/Bronze/maze input.txt", "r", stdin);
    for (int test_case = 1; test_case <= 10; test_case++){
        ret = 0;
        scanf("%d", &test_case);
        for(int i = 0; i < 16; i++){
            scanf("%s", maze[i]);
        }
        for (int i = 0; i < 16; i++) {
            for (int j = 0; j < 16; j++) {
                if(maze[i][j] == '2'){
                    r = i;
                    c = j;
                    break;
                }
            }
        }
        find(r, c);
        printf("#%d %d\n", test_case, ret);
    }
    
    
    
}
#endif

#if 0
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct pos{
    int x, y;
    pos(){}
    pos(int x, int y) : x(x), y(y) {}
};

int T = 10, t;
char a[16][16];
int d[16][16];
int dx[4] = {0, 0, 1, -1};
int dy[4] = {1, -1, 0, 0};
pos startp;
pos endp;
void init(){
    memset(d, -1, sizeof(d));
    cin >> t;
    for(int i = 0; i < 16; i++){
        for(int j = 0; j < 16; j++){
            cin >> a[i][j];
            if(a[i][j] == '2'){
                d[i][j] = 0;
                startp = pos(i, j);
            }
            else if(a[i][j] == '3'){
                endp = pos(i, j);
            }
        }
    }
}
int bfs(pos now){
    queue<pos> q;
    q.push(now);
    while(!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int k = 0; k<4; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx >= 0 && ny >= 0 && nx <16 && ny < 16){
                if(a[nx][ny] != '1' && d[nx][ny] == -1){
                    d[nx][ny] = d[x][y] + 1;
                    q.push(pos(nx, ny));
                }
            }
        }
    }
    return d[endp.x][endp.y] != -1 ? 1:0;
}
int main(){
    freopen("/Users/allison/Desktop/Coding/123/Bronze/maze input.txt", "r", stdin);
    while(T--){
        init();
        cout << '#' << t << ' ' << bfs(startp) << '\n';
    }
    return 0;
}
#endif
