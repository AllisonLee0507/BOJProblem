#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <string.h>
using namespace std;
int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
int M, N, K;
int arr[50][50] = { 0 };
int visited[50][50] = { 0 };
void dfs(int y, int x) {

    for (int i = 0; i < 4; i++) {
        int ny = y + dy[i];
        int nx = x + dx[i];

        if (ny < 0 || ny >= N || nx < 0 || nx >= M)
            continue;

        if (arr[ny][nx] && !visited[ny][nx]) {
            visited[ny][nx]++;
            dfs(ny, nx);
        }
    }
}int main() {
    int T, x, y;
    cin >> T;

    for (int testCase = 0; testCase < T; testCase++) {
        scanf("%d %d %d", &M, &N, &K);

        memset(arr, 0, sizeof(arr));
        memset(visited, 0, sizeof(visited));

        int ans = 0; //¡ˆ∑∑¿Ã ∞≥ºˆ

        for (int i = 0; i < K; i++) {
            scanf("%d %d", &x, &y);
            arr[y][x] = 1;
        }

        for (int i = 0; i < N; i++)
            for (int j = 0; j < M; j++)
                if (arr[i][j] && !visited[i][j]) {

                    ans++;
                    visited[i][j]++;
                    dfs(i, j);

                }

        cout << ans << endl;
    }
    return 0;
}
#endif

#if 0
#include<cstdio>
int t, m, n, k, ans;
bool a[50][50];
int dx[] = { 0, 1, 0, -1 };
int dy[] = { 1, 0, -1, 0 };
void bfs(int x, int y) {
    a[x][y] = false;
    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx < 0 || ny < 0 || nx == m || ny == n)
            continue;
        if (a[nx][ny])
            bfs(nx, ny);
    }
}
int main() {
    scanf("%d", &t);
    while (t--) {
        scanf("%d %d %d", &m, &n, &k);
        for (int i = 0; i < m; i++)
            for (int j = 0; j < n; j++)
                a[i][j] = 0;
        ans = 0;

        for (int i = 0; i < k; i++) {
            int x, y;
            scanf("%d %d", &x, &y);
            a[x][y] = 1;
        }
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if (a[i][j]) {
                    ans++;
                    bfs(i, j);
                }
            }
        }
        printf("%d\n", ans);
    }
}
#endif

#if 0
#include<stdio.h>
int m, n, k;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
void dfs(int x, int y, int v[][50]) {
    v[x][y] = 0;
    for (int i = 0; i < 4; ++i) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (!(0 <= nx && nx < m)) continue;
        if (!(0 <= ny && ny < n)) continue;
        if (v[nx][ny]) dfs(nx, ny, v);
    }
}
int main() {
    int t; scanf("%d", &t);
    while (t--) {
        int a = 0, v[50][50] = { 0 };
        scanf("%d%d%d", &m, &n, &k);
        for (int x, y, i = 0; i < k; ++i) {
            scanf("%d%d", &x, &y);
            v[x][y] = 1;
        }
        for (int i = 0; i < m; ++i)
            for (int j = 0; j < n; ++j)
                if (v[i][j]) {
                    dfs(i, j, v);
                    a++;
                }
        printf("%d\n", a);
    }
}
#endif

#if 0
#include <stdio.h>
#include <stdbool.h>
bool field[50][50];
int M, N;
int dx[4] = { 0,1,0,-1 }, dy[4] = { 1,0,-1,0 };
bool safe(int X, int Y)
{
    return 0 <= X && X < M && 0 <= Y && Y < N;
}
void DFS(int X, int Y)
{
    if (!safe(X, Y) || !field[X][Y]) return;
    field[X][Y] = false;
    for (int i = 0; i < 4; i++)
        DFS(X + dx[i], Y + dy[i]);
}
int main(void)
{
    int T;
    scanf("%d", &T);
    while (T--)
    {
        int K;
        scanf("%d%d%d", &M, &N, &K);
        for (int i = 0; i < K; i++)
        {
            int X, Y;
            scanf("%d%d", &X, &Y);
            field[X][Y] = true;
        }
        int answer = 0;
        for (int i = 0; i < M; i++)
            for (int j = 0; j < N; j++)
                if (field[i][j])
                {
                    DFS(i, j);
                    answer++;
                }
        printf("%d\n", answer);
    }
    return 0;
}
#endif

#if 0
#include <stdio.h>
bool planted[52][52];
int M, N, K;
bool dfs(int X, int Y) {
    if (!planted[Y][X]) return false;
    planted[Y][X] = false;
    if (planted[Y - 1][X]) dfs(X, Y - 1);
    if (planted[Y + 1][X]) dfs(X, Y + 1);
    if (planted[Y][X + 1]) dfs(X + 1, Y);
    if (planted[Y][X - 1]) dfs(X - 1, Y);
    return true;
}

int main(){
    int t;
    scanf("%d", &t);
    while (t-- > 0) {
        scanf("%d %d %d", &M, &N, &K);
        int x, y;
        for (int i = 0; i <= N + 1; i++) {
            for (int j = 0; j <= M + 1; j++) planted[i][j] = false;
        }
        for (int i = 0; i < K; i++) {
            scanf("%d %d", &x, &y);
            planted[y + 1][x + 1] = true;
        }
        int cnt = 0;
        for (int Y = 1; Y <= N; Y++) {
            for (int X = 1; X <= M; X++) if (dfs(X, Y)) cnt++;
        }
        printf("%d\n", cnt);
    }
    return 0;
}
#endif


