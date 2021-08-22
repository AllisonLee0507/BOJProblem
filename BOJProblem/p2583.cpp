#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int N, M, K; 
char a[110][110]; 
int label = 1; 
int cnt[1000]; 
int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 }; 
int f(int y, int x)
{
	a[y][x] = label + '0'; 
	cnt[label]++; 
	for (int i = 0; i < 4; i++)
	{
		int ny = y + dy[i]; 
		int nx = x + dx[i]; 

		if (ny >= 0 && nx >= 0 && ny < M && nx < N && a[ny][nx] == 0)
		{
			f(ny, nx); 
		}
	}
	return 0; 
}
int main(void)
{
	scanf("%d %d %d", &M, &N, &K); 
	for (int i = 0; i < K; i++)
	{
		int x1, y1, x2, y2; 
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 
		for (int i = y1; i < y2; i++)
		{
			for (int j = x1; j < x2; j++)
			{
				a[i][j] = 1; 
			}
		}
	}
	for (int i = 0; i < M; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (a[i][j] == 0)
			{
				label++; 
				f(i, j); 
			}
		}
	}

	printf("%d\n", label - 1); 

	for (int i = 2; i <= label; i++)
	{
		for (int j = i + 1; j <= label; j++)
		{
			if (cnt[i] > cnt[j])
			{
				int tmp = cnt[j]; 
				cnt[j] = cnt[i]; 
				cnt[i] = tmp; 
			}
		}
	}

	for (int i = 2; i <= label; i++)
	{
		printf("%d ", cnt[i]); 
	}
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <math.h>
#include <stdio.h>

#define MAX 102

int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 }; 

char map[MAX][MAX]; 
int N; 
int M; 
int K; 

int Count; 
int dt[MAX]; 
int Num; 
void fill(int x1, int y1, int x2, int y2); 
void qsort(int s, int e); 

void dfs(int y, int x, int val)
{
	int a;
	for (a = 0; a < 4; a++)
	{
		if (map[y + dy[a]][x + dx[a]] == 0)
		{
			Num++; 
			map[y + dy[a]][x + dx[a]] = Count; 
			dfs(y + dy[a], x + dx[a], Count); 
		}
	}
}
int main(void)
{
	int lp; 
	int x1, y1, x2, y2; 
	int a, b; 

	scanf("%d", &M); 
	scanf("%d", &N); 
	scanf("%d", &K); 
	for (lp = 0; lp <= M + 1; lp++)
	{
		map[lp][0] = -1; 
		map[lp][N + 1] = -1;
	}
	for (lp = 0; lp <= N + 1; lp++)
	{
		map[0][lp] = -1; 
		map[M + 1][lp] = -1; 
	}
	for (lp = 1; lp <= K; lp++)
	{
		scanf("%d %d %d %d", &x1, &y1, &x2, &y2); 
		fill(x1 + 1, y1 + 1, x2, y2);
	}

	for (a = 1; a <= M; a++)
	{
		for (b = 1; b <= N; b++)
		{
			if (map[a][b] == 0)
			{
				Count++;
				map[a][b] = Count; 
				Num = 1; 
				dfs(a, b, Count); 
				dt[Count] = Num; 
			}
		}
	}
	qsort(1, Count); 
	printf("%d\n", Count); 
	for (lp = 1; lp <= Count; lp++)
	{
		printf("%d ", dt[lp]); 
	}
	printf("\n"); 

	return 0;
}

void fill(int x1, int y1, int x2, int y2)
{
	int a, b; 
	for (a = y1; a <= y2; a++)
	{
		for (b = x1; b <= x2; b++)
		{
			map[a][b] = -1; 
		}
	}
}
void qswap(int a, int b)
{
	int tmp; 
	tmp = dt[a]; 
	dt[a] = dt[b]; 
	dt[b] = tmp; 
}
void qsort(int s, int e)
{
	int p = s; 
	int l = s + 1; 
	int r = e; 

	if (s < e)
	{
		while (l <= r)
		{
			while (l <= e && dt[l] <= dt[p])
			{
				l++; 
			}
			while (s + 1 <= r && dt[p] <= dt[r])
			{
				r--; 
			}
			if (l < r)
			{
				qswap(l, r); 
			}
		}
		qswap(p, r); 
		qsort(s, r - 1); 
		qsort(r + 1, e); 
	}
}
#endif

