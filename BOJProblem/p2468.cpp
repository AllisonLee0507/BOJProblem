#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

int N, waterH, M, ans;
int a[101][101];  
int b[101][101]; 
int dx[4] = { -1, 1, 0, 0 }; 
int dy[4] = { 0, 0, -1, 1 }; 
void count(int x, int y)
{
	b[x][y] = 0; 
	for (int i = 0; i < 4; i++)
	{
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 

		if (b[nx][ny] > waterH)
		{
			count(nx, ny); 
		}
	}
}
int main(void)
{
	scanf("%d", &N); 

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &a[i][j]); 
			if (a[i][j] > waterH)
			{
				waterH = a[i][j];
			}
		}
	}

	while (waterH--)
	{ 
		memcpy(b, a, sizeof(a)); 
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (b[i][j] > waterH)
				{
					M++;
					count(i, j);
				}
			}
		}
		if (M > ans)
		{
			ans = M; 
		}
		M = 0; 
	}
	
	 
	printf("%d", ans); 

	return 0;
}
#endif

#if 01
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int map[101][101]; 
int N; 
int dr[4] = { 0, 0, -1, 1 }; 
int dc[4] = { -1 ,1, 0, 0 }; 
int temp_map[102][102]; 
int max_height = 1; 
int max_ans = -1; 
int min_height = 100; 

typedef struct _info
{
	int r; 
	int c;
}info;
info queue[20000]; 
void Init(void)
{
	scanf("%d", &N); 
	for (int i = 1; i < N + 1; i++)
	{
		for (int j = 1; j < N + 1; j++)
		{
			scanf("%d", &map[i][j]); 
			if (max_height < map[i][j])
			{
				max_height = map[i][j];
			}
			if (min_height > map[i][j])
			{
				min_height = map[i][j];
			}
		}
	}
}
void reset_map(void)
{
	for (int i = 0; i < N + 2; i++)
	{
		for (int j = 0; j < N + 2; j++)
		{
			temp_map[i][j] = map[i][j]; 
		}
	}
}
void BFS(int sr, int sc, int k)
{
	info data; 
	int nr, nc; 
	int wp = 0;
	int rp = 0; 

	queue[wp].r = sr; 
	queue[wp].c = sc; 
	temp_map[sr][sc] = k; 
	wp++; 

	while (rp < wp) {
		data = queue[rp]; 
		for (int i = 0; i < 4; i++)
		{
			nr = data.r + dr[i]; 
			nc = data.c + dc[i]; 

			if (temp_map[nr][nc] > k)
			{
				queue[wp].r = nr; 
				queue[wp].c = nc; 
				wp++; 
				temp_map[nr][nc] = k; 
			}
		}
		rp++; 
	}
}
int main(void)
{
	int temp_ans; 
	Init(); 
	for (int k = min_height - 1; k < max_height; k++)
	{
		reset_map(); 
		temp_ans = 0; 
		for (int i = 1; i < N + 1; i++)
		{
			for (int j = 1; j < N + 1; j++)
			{
				if (temp_map[i][j] > k)
				{
					temp_ans++; 
					BFS(i, j, k); 
				}
			}
		}
		if (max_ans < temp_ans)
		{
			max_ans = temp_ans; 
		}
	}
	printf("%d\n", max_ans); 
	return 0;
}
#endif