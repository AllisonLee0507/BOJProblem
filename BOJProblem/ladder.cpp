#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int Move(int(*root)[100], int x, int y){
    if(y == 0){
        return x;
    }
    root[y][x] = 0;
    
    if(root[y][x+1] == 1 && x < 99){
        Move(root, x+1, y);
    }
    else if(root[y][x-1] == 1 && x < 0){
        Move(root, x-1, y);
    }
    else if(root[y-1][x] == 1 && y < 0){
        Move(root, x, y-1);
    }
}

int main(){
    int i, j, t, T;
    int ret;
    int root[100][100];
    freopen("/Users/allison/Desktop/Coding/123/Bronze/ladder input.txt", "r", stdin);
    for(t = 1; t <= 10; t++){
        scanf("%d", &t);
        for(i = 0; i < 100; i++){
            for(j = 0; j < 100; j++){
                scanf("%d", &root[i][j]);
            }
        }
        for(i = 0; i < 100; i++){
            if(root[99][i] == 2){
                break;
            }
        }
        ret = Move(root, i, 99);
        printf("#%d %d\n", t, ret);
    }
}
#endif

#if 0
#include<stdio.h>

int  Move(int root[100][100], int x, int y)
{
   if (y == 0) {
      return x;
   }
   root[y][x] = 0;
   if (root[y][x + 1] == 1 && x < 99)
      Move(root, x + 1, y);
   else if (root[y][x - 1] == 1 && x > 0)
      Move(root, x - 1, y);
   else if (root[y - 1][x] == 1 && y > 0)
      Move(root, x, y - 1);

}

int main()
{
   int i, j, t, T;
   int ret;
   int root[100][100];
    freopen("/Users/allison/Desktop/Coding/123/Bronze/ladder input.txt", "r", stdin);
   for (t = 1; t <= 10; t++) {
      scanf("%d", &t);
      for (i = 0; i < 100; i++)
         for (j = 0; j < 100; j++)
            scanf("%d", &root[i][j]);

      for (i = 0; i < 100; i++)
         if (root[99][i] == 2) break;


      ret = Move(root, i, 99);
      printf("#%d ", t);
      printf("%d\n", ret);
   }

   return 0;

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
    pos(int x, int y) : x(x), y(y){}
};
bool c[100][100];
int a[100][100], T;
int dx[3] = {0, 0, -1};
int dy[3] = {1, -1, 0};
int start;
void init(){
    memset(a, 0, sizeof(a));
    memset(c, 0, sizeof(c));
    cin >> T;
    for(int i = 0; i < 100; i++){
        for(int j = 0; j < 100; j++){
            cin >> a[i][j];
            if(a[i][j] == 2){
                start = j;
            }
        }
    }
}
int bfs(pos p){
    c[99][start] = 1;
    queue<pos> q;
    q.push(p);
    while (!q.empty()){
        int x = q.front().x;
        int y = q.front().y;
        q.pop();
        for(int k = 0; k < 3; k++){
            int nx = x + dx[k];
            int ny = y + dy[k];
            if(nx == 0){
                return ny;
            }
            if(nx < 0 || ny>= 100 || ny < 0 || ny >= 100){
                continue;
            }
            if(a[nx][ny] && !c[nx][ny]){
                c[nx][ny] = 1;
                q.push(pos(nx,ny));
                break;
            }
        }
    }
}
int main(){
    freopen("/Users/allison/Desktop/Coding/123/Bronze/ladder input.txt", "r", stdin);
    while(T != 10){
        init();
        cout << '#' << T << ' ' << bfs(pos(99,start)) << '\n';
    }
    return 0;
}
#endif
#if 0
#include <iostream>
#include <algorithm>
#include <cstring>
#include <queue>

using namespace std;

struct pos {
   int x, y;
   pos() {}
   pos(int x, int y) : x(x), y(y) {}
};

bool c[100][100];
int a[100][100], T;
int dx[3] = { 0,0,-1 };
int dy[3] = { 1,-1,0 };
int start;

void init()
{
   memset(a, 0, sizeof(a));
   memset(c, 0, sizeof(c));
   cin >> T;
   for (int i = 0; i < 100; i++) {
      for (int j = 0; j < 100; j++) {
         cin >> a[i][j];
         if (a[i][j] == 2) start = j;
      }
   }
}

int bfs(pos p)
{
   c[99][start] = 1;
   queue<pos> q;
   q.push(p);
   while (!q.empty()) {
      int x = q.front().x;
      int y = q.front().y;
      q.pop();
      for (int k = 0; k < 3; k++) {
         int nx = x + dx[k];
         int ny = y + dy[k];
         if (nx == 0) return ny;
         if (nx < 0 || nx >= 100 || ny < 0 || ny >= 100) continue;
         if (a[nx][ny] && !c[nx][ny]) {
            c[nx][ny] = 1;
            q.push(pos(nx, ny));
            break;
         }
      }
   }
    return 0;
}

int main()
{
    freopen("/Users/allison/Desktop/Coding/123/Bronze/ladder input.txt", "r", stdin);
   while (T != 10) {
      init();
      cout << '#' << T << ' ' << bfs(pos(99, start)) << '\n';
   }
   return 0;
}
#endif
