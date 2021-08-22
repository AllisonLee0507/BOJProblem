#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
using namespace std;

int N;
int** map;
int** sunken;
void DFS(int row, int col, int num);
int main(){
    int min = 100;
    int max = 0;
    int unsunken_max;
    int search_cnt;
    cin >> N;
    map = new int*[N];
    sunken = new int*[N];
    for(int i = 0; i < N; i++){
        map[i] = new int[N];
        sunken[i] = new int[N];
        for(int j = 0; j < N; j++){
            cin >> map[i][j];
            if(map[i][j] < min){
                min = map[i][j];
            }
            if(map[i][j] > max){
                max = map[i][j];
            }
        }
    }
    unsunken_max = 1;
    for(int i = min; i < max; i++){
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(map[j][k] <= i){
                    sunken[j][k] = -1;
                }
                else{
                    sunken[j][k] = 0;
                }
            }
        }
        search_cnt = 0;
        for(int j = 0; j < N; j++){
            for(int k = 0; k < N; k++){
                if(sunken[k][k] == 0){
                    search_cnt++;
                    DFS(j, k, search_cnt);
                }
            }
        }
        if(search_cnt > unsunken_max){
            unsunken_max = search_cnt;
        }
    }
    cout << unsunken_max << endl;
    
    return 0;
}

void DFS(int row, int col, int num){
    sunken[row][col] = num;
    if(row > 0 && sunken[row-1][col] == 0){
        DFS(row -1, col, num);
    }
    if(row < N-1 && sunken[row+1][col] == 0){
        DFS(row +1, col, num);
    }
    if(row > 0 && sunken[row][col-1] == 0){
        DFS(row, col-1, num);
    }
    if(row < N-1 && sunken[row][col+1] == 0){
        DFS(row, col+1, num);
    }
}
#endif

#if 0
#include <iostream>
using namespace std;

int N;
int** map;
int** sunken;

void DFS(int row, int col, int num);

int main(){

   int min = 100;
   int max = 0;
   int unsunken_max;
   int search_cnt;
   cin >> N;
   map = new int*[N];
   sunken = new int*[N];
   for(int i=0; i<N; i++){
      map[i] = new int[N];
      sunken[i] = new int[N];
      for(int j=0; j<N; j++){
         cin >> map[i][j];
         if(map[i][j] < min) min = map[i][j];
         if(map[i][j] > max) max = map[i][j];
      }
   }

   unsunken_max = 1;
   for(int i=min; i<max; i++){
      for(int j=0; j<N; j++){
         for(int k=0; k<N; k++){
            //가라앉은 구역: -1
            if(map[j][k] <= i) sunken[j][k] = -1;
            //가라앉지 않았으며 아직 순회하지 않은 구역: 0
            else sunken[j][k] = 0;
            //순회한 구역: 1 이상
         }
      }
      /*
      cout << "수면: " << i << endl;
      for(int j=0; j<N; j++){
         for(int k=0; k<N; k++){
            if(sunken[j][k] == -1) cout << 1;
            else cout << 0;
         }
         cout << endl;
      }*/
      
      search_cnt = 0;
      for(int j=0; j<N; j++){
         for(int k=0; k<N; k++){
            if(sunken[j][k] == 0){
               search_cnt++;
               DFS(j, k, search_cnt);
            }
         }
      }

   //   cout << "개수: " << search_cnt << endl << endl;
      if(search_cnt > unsunken_max) unsunken_max = search_cnt;
   }

   cout << unsunken_max << endl;

   return 0;
}

void DFS(int row, int col, int num){
   sunken[row][col] = num;
   if(row > 0 && sunken[row-1][col] == 0) DFS(row-1, col, num);
   if(row < N-1 && sunken[row+1][col] == 0) DFS(row+1, col, num);
   if(col > 0 && sunken[row][col-1] == 0) DFS(row, col-1, num);
   if(col < N-1 && sunken[row][col+1] == 0) DFS(row, col+1, num);
}
#endif

#if 0
#include <stdio.h>
#include <string.h>

const int dx[] = {0, 0, 1, -1};
const int dy[] = {1, -1, 0, 0};

int n, w, cnt, ans, mx, a[102][102], b[102][102];

int max(int a, int b){return a>b ? a : b; }
void dfs(int x, int y){
    b[x][y] = 0;
    for(int i = 0; i < 4; i++){
        int nx = x + dx[i], ny = y+dy[i];
        if(b[nx][ny] > w){
            dfs(nx, ny);
        }
    }
}
int main(){
    scanf("%d", &n);
    for(int i = 1; i <= n; i++){
        for(int j = 1; j <= n; j++){
            scanf("%d", &a[i][j]);
        }
    }
    for(int k = 0; k <= 100; k++){
        memcpy(b, a, sizeof(a));
        for(int i = 1; i <= n; i++){
            for(int j = 1; j <= n; j++){
                if(b[i][j] > k){
                    w = k, cnt++;
                    dfs(i, j);
                }
            }
        }
        ans = max(cnt, ans);
        cnt = 0;
    }
    printf("%d", ans);
    return 0;
}
#endif

#if 0
#include <stdio.h>
#define DEBUG 0

int X[20000];
int Y[20000];
int start = 0;
int end = 0;
int N;
char map[102][102];
char tmpmap[102][102];

int push(int ix, int iy){
    X[end] = ix;
    Y[end] = iy;
    end++;
    return 1;
}

void printmap(){
    for(int i = 0; i < N +2; i++){
        for(int j = 0; j < N+2; j++){
            printf("%d ", tmpmap[i][j]);
        }
        printf("\n");
    }
}
int bfs(){
    int popx;
    int popy;
    while(1){
        if(start == end){
            start = 0;
            end = 0;
            break;
        }
        popx = X[start];
        popy = Y[start];
        start++;
        
        if(tmpmap[popx+1][popy] == 1){
            tmpmap[popx+1][popy] = 0;
            push(popx+1, popy);
        }
        if(tmpmap[popx-1][popy] == 1){
            tmpmap[popx-1][popy] = 0;
            push(popx-1, popy);
        }
        if(tmpmap[popx][popy+1] == 1){
            tmpmap[popx][popy+1] = 0;
            push(popx, popy+1);
        }
        if(tmpmap[popx][popy-1] == 1){
            tmpmap[popx][popy-1] = 0;
            push(popx, popy-1);
        }
        tmpmap[popx][popy] = 0;
    }
    return 1;
}
int main(){
    for(int i = 0; i < 102; i++){
        for(int j = 0; j < 102; j++){
            map[i][j] = 0;
            tmpmap[i][j] = 0;
        }
    }
    scanf("%d", &N);
    int landmax = 0;
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            int tmp;
            scanf("%d", &tmp);
            if(landmax < tmp){
                landmax = tmp;
            }
            map[i+1][j+1] = tmp;
        }
    }
    int maxblob = 0;
    for(int i = 0; i < landmax; i++){
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if(map[j][k] > i){
                    tmpmap[j][k] = 1;
                }
                else{
                    tmpmap[j][k] = 0;
                }
            }
        }
        if(DEBUG)printf("rain %d\n", i);
        int blobs = 0;
        for(int j = 1; j <= N; j++){
            for(int k = 1; k <= N; k++){
                if(tmpmap[j][k] == 1){
                    push(j, k);
                    blobs += bfs();
                }
            }
        }
        if(DEBUG)printf("blobs %d\n\n", blobs);
        if(maxblob < blobs){
            if(DEBUG)printf("maxblob %d changed to %d\n", maxblob, blobs);
            maxblob = blobs;
        }
    }
    printf("%d\n", maxblob);
    return 0;
}
#endif
