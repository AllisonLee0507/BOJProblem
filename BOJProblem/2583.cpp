#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAX = 100;
typedef struct{
    int y, x;
}Dir;

Dir moveDir[4] = {{1,0}, {-1,0}, {0,1}, {0,-1}};
int graph[MAX][MAX];
bool visited[MAX][MAX];
int M, N, K;
int cnt;
void DFS(int y, int x){
    visited[y][x] = true;
    cnt++;
    for(int i = 0; i < 4; i++){
        int nextY = y + moveDir[i].y;
        int nextX = x + moveDir[i].x;
        if(0 <= nextY && nextY < M && 0 <= nextX && nextX < N){
            if(graph[nextY][nextX] == 0 && !visited[nextY][nextX]){
                DFS(nextY, nextX);
            }
        }
    }
}

int main(void){
    cin >> M >> N >> K;
    for(int i = 0 ; i < K; i++){
        int x1, y1, x2, y2;
        cin >> x1 >> y1 >> x2 >> y2;
        
        for(int y = y1; y < y2; y++){
            for(int x = x1; x < x2; x++){
                graph[y][x] = 1;
            }
        }
    }
    vector<int> result;
    for(int y = 0; y < M; y++){
        for(int x = 0; x < N; x++){
            if(graph[y][x] == 0 && !visited[y][x]){
                cnt = 0;
                DFS(y,x);
                result.push_back(cnt);
            }
        }
    }
    cout << result.size() << endl;
    sort(result.begin(), result.end());
    for(int i = 0; i < result.size(); i++){
        cout << result[i] << " ";
    }
    cout << endl;
    return 0;
}
#endif

#if 0
#include <stdio.h>

int N, M, K;
char a[110][100];
int label = 1;
int cnt[1000];

int d[4][2] = {{-1,0},{1,0},{0,-1},{0,1}};
int f(int y, int x){
    a[y][x] = label + '0';
    cnt[label]++;
    for(int i = 0; i < 4; i++){
        int ny = y + d[i][0];
        int nx = x + d[i][1];
        
        if(ny >=0 && nx >= 0 && ny < M && nx < N && a[ny][nx]==0){
            f(nx, ny);
        }
    }
    return 0;
}

int main(){
    scanf("%d %d %d", &M, &N, &K);
    for(int i = 0; i < K; i++){
        int x1, y1, x2, y2;
        scanf("%d 5d %d %d", &x1, &y1, &x2, &y2);
        for(int i = y1; i < y2; i++){
            for(int j = x1; j < x2; j++){
                a[i][j] = 1;
            }
        }
    }
    for(int i = M - 1; i >= 0; i--){
        for(int j = 0; j < N; j++){
            printf("%d", a[i][j]);
        }
        printf("\n");
    }
    for(int i = 0; i < M; i++){
        for(int j = 0; j < N; j++){
            if(a[i][j] == 0){
                label++;
                f(i, j);
            }
        }
    }
    printf("%d\n", label-1);
    
    for(int i = 2; i <= label; i++){
        for(int j = i + 1; j <= label; j++){
            if(cnt[i] > cnt[j]){
                int tmp = cnt[j];
                cnt[j] = cnt[i];
                cnt[i] = tmp;
            }
        }
    }
    for(int i = 2; i <= label; i++){
        printf("%d ", cnt[i]);
    }
}
#endif
