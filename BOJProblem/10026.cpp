#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <cstring>
#include <queue>

#define endl "\n"
#define MAX 100
using namespace std;

int N;
char MAP[MAX][MAX];
bool Visit[MAX][MAX];
int dx[] = {0, 0, 1, -1};
int dy[] = {1, -1, 0, 0};

void Input(){
    cin >> N;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0 ; j < N; j++)
        {
            cin >> MAP[i][j];
        }
    }
}
void BFS(int a, int b)
{
    queue<pair<int, int>> Q;
    Q.push(make_pair(a,b));
    Visit[a][b] = true;
    
    while(Q.empty() == 0){
        int x = Q.front().first;
        int y = Q.front().second;
        Q.pop();
        
        for(int i = 0; i < 4; i++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            
            if(nx >= 0 && ny >= 0 && nx < N && ny < N)
            {
                if(Visit[nx][ny] == false)
                {
                    if(MAP[nx][ny] == MAP[x][y])
                    {
                        Visit[nx][ny] = true;
                        Q.push(make_pair(nx,ny));
                    }
                }
            }
        }
    }
}

void Solution(){
    int Answer, Answer2;
    Answer = Answer2 = 0;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(Visit[i][j] == false)
            {
                BFS(i, j);
                Answer++;
            }
        }
    }
    memset(Visit, false, sizeof(Visit));
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(MAP[i][j] == 'G')
            {
                MAP[i][j] = 'R';
            }
        }
    }
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < N; j++)
        {
            if(Visit[i][j] == false)
            {
                BFS(i, j);
                Answer2++;
            }
        }
    }
    cout << Answer << " " << Answer2 << endl;
}
void Solve()
{
    Input();
    Solution();
}
int main(void)
{
    cin.tie(NULL);
    cout.tie(NULL);
    Solve();
    return 0;
}
#endif

#if 0
#include <stdio.h>
typedef struct node { int x, y; }node;
node queue[10001];
int front, rear, countA, countB;
char gridA[103][103], gridB[103][103];
node newnode(int x, int y)
{
    node tmp;
    tmp.x = x;
    tmp.y = y;
    return tmp;
}

void BFS(int x, int y, int choice)
{
    int i, xx[] = {1, 0, -1, 0}, yy[] = {0, -1, 0, 1};
    char tmp;
    if(choice == 0){
        tmp = gridA[x][y];
        gridA[x][y] = '0';
        countA++;
    }
    else
    {
        tmp = gridB[x][y];
        gridB[x][y] = '0';
        countB++;
    }
    front = rear = 0;
    queue[rear++] = newnode(x, y);
    
    while((rear-front) != 0)
    {
        for(i = 0; i < 4; i++)
        {
            if(choice == 0)
            {
                if(gridA[queue[front].x + xx[i]][queue[front].y + yy[i]] == tmp)
                {
                    gridA[queue[front].x + xx[i]][queue[front].y + yy[i]] = '0';
                    queue[rear++] = newnode(queue[front].x + xx[i], queue[front].y + yy[i]);
                }
            }
            else
            {
                if(tmp == 'R' || tmp == 'G')
                {
                    if(gridB[queue[front].x + xx[i]][queue[front].y + yy[i]] == 'R' || gridB[queue[front].x + xx[i]][queue[front].y + yy[i]] == 'G')
                    {
                        gridB[queue[front].x + xx[i]][queue[front].y + yy[i]] = '0';
                        queue[rear++] = newnode(queue[front].x + xx[i], queue[front].y+yy[i]);
                    }
                }
                else
                {
                    if(gridB[queue[front].x + xx[i]][queue[front].y + yy[i]] == tmp)
                    {
                        gridB[queue[front].x + xx[i]][queue[front].y + yy[i]] = '0';
                        queue[rear++] = newnode(queue[front].x + xx[i], queue[front].y+yy[i]);
                    }
                }
            }
        }
        front++;
    }
}
int main()
{
    int N, i, j;
    char tmp;
    scanf("%d", &N);
    for(i = 0; i <= N+1; i++){
        for(j = 0; j <= N+1; j++){
            gridA[i][j] = '0';
            gridB[i][j] = '0';
        }
    }
    countA = countB = 0;
    
    for(i = 1; i <= N; i++)
    {
        for(j = 1; j <= N; j++)
        {
            scanf("%c", &tmp);
            while(tmp == '\n' || tmp == '\0')
            {
                scanf("%c", &tmp);
            }
            gridA[i][j] = tmp;
            gridB[i][j] = tmp;
        }
    }
    for(i = 1; i <= N; i++)
    {
        for(j = 1; j <= N; j++)
        {
            if(gridA[i][j] != '0')
            {
                BFS(i, j, 0);
            }
            if(gridB[i][j] != '0')
            {
                BFS(i, j, 1);
            }
        }
    }
    printf("%d %d\n", countA, countB);
    return 0;
}
#endif

#if 0
#include <stdio.h>
#include <string.h>
int N, sol1, sol2;
int color;
int change;
char a[100+10][100+10];
int visited[100+10][100+10];

int dy[4] = {0, 0, 1, -1};
int dx[4] = {1, -1, 0, 0};
void Flood(int y, int x)
{
    int i;
    if(a[y][x] != color)
    {
        return;
    }
    a[y][x] = change;
    for(i = 0; i < 4; i++)
    {
        if(y + dy[i] < 00 || y + dy[i] >= N || x + dx[i] < 0 || x + dx[i] >= N)
        {
            continue;
        }
        Flood(y + dy[i], x + dx[i]);
    }
}
int main(void)
{
    int i, j;
    scanf("%d", &N);
    for(i = 0; i < N; i++)
    {
        scanf("%s", a[i]);
    }
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(a[i][j] == 'R' || a[i][j] == 'G' || a[i][j] == 'B')
            {
                color = a[i][j];
                if(color == 'R' || color == 'G')
                {
                    change = 1;
                }
                else if(color == 'B')
                {
                    change = 2;
                }
                Flood(i, j);
                sol1++;
            }
        }
    }
    for(i = 0; i < N; i++)
    {
        for(j = 0; j < N; j++)
        {
            if(a[i][j] > 0)
            {
                change = 0;
                color = a[i][j];
                Flood(i, j);
                sol2++;
            }
        }
    }
    printf("%d %d", sol1, sol2);
    
    return 0; 
}
#endif
