#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int n;
int map[5][5];
int cnt;

void input(){
    int i, j;
    scanf("%d", &n);
    for (i = 0; i<n; i++){
        for(j=0; j<n; j++){
            scanf("%d", &map[i][j]);
        }
    }
}
int back(int i, int j){
    if((map[i][j] != 0) || (j>=n) || (i<0) || (j<0))
    {
        return 0;
    }
    map[i][j] = 2;
    if(i == n-1 && j == n-1){
        cnt++;
        map[i][j] = 0;
        return 0;
    }
    back(i, j+1);
    back(i+1, j);
    back(i-1, j);
    back(i, j-1);
    map[i][j] = 0;
    return 1;
}
int main(){
    input();
    back(0,0);
    if(cnt!=0){
        printf("%d", cnt);
    }
    return 0;
}

#endif

#if 0
#include <stdio.h>
int n;
int map[5][5];
int cnt;
int dx[4] = {0, 1, -1, 0};
int dy[4] = {1, 0, 0, -1};
void input()
{
   int i, j;
   scanf("%d", &n);
   for (i = 0; i<n; i++)
   {
      for (j = 0; j<n; j++)
      {
         scanf("%d", &map[i][j]);
      }
   }
}
int back(int i, int j)
{
   if (map[i][j] != 0 || i >= n || j >= n || i<0 || j<0) return 0;
   map[i][j] = 2;
   if (i == n - 1 && j == n - 1)
   {
      cnt++;
      map[i][j] = 0;
      return 0;
   }
    for (int a = 0; a<4; a++){
            back(i + dx[a], j + dy[a]);
    }
   map[i][j] = 0;
    return 0;
}

int main()
{
   input();
   back(0, 0);
   if (cnt != 0) printf("%d\n", cnt);
   
   return 0;
}
#endif
