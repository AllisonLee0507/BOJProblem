#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <algorithm>
using namespace std;
const int roff[4] = {-1, 1, 0, 0};
const int coff[4] = {0, 0, -1, 1};

int R, C, result;
char map[20][20];
bool visited[20][20], used[26];

void backtrack(int r, int c, int dist){
    result = max(result, dist);
    visited[r][c] = true;
    used[map[r][c]-'A'] = true;
    for(int d = 0; d<4; d++){
        int nr = r+roff[d];
        int nc = c+coff[d];
        if(nr < 0 || nr >= R || nc < 0 || nc >= C || visited[nr][nc]){
            continue;
        }
        if(!used[map[nr][nc] - 'A']){
            backtrack(nr, nc, dist+1);
        }
    }
    visited[r][c] = false;
    used[map[r][c]-'A'] = false;
}
int main(){
    scanf("%d %d", &R, &C);
    for(int i = 0; i < R; i++){
        getchar();
        for(int j = 0; j < C; j++){
            map[i][j] = getchar();
        }
    }
    backtrack(0, 0, 1);
    printf("%d\n", result);
}
#endif
