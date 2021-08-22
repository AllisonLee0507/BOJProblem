#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <algorithm>
#include <iostream>
#include <vector>

using namespace std;

bool check[30][30]; 
int n, arr[30][30], num[1010], cnt; 

int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 }; 

void dfs(int x, int y)
{
	check[x][y] = true; 
	num[cnt]++;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n) {
			if (!check[nx][ny] && arr[nx][ny]) dfs(nx, ny);
		}
	}
}
int main(void)
{
	scanf(" %d, &n"); 
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			scanf("%ld", &arr[i][j]); 
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (!check[i][j] && arr[i][j])
			{
				dfs(i, j); 
				cnt++; 
			}
		}
	}
	printf("%d\n", cnt);
	sort(num, num + cnt);
	for (int i = 0; i < cnt; i++)
	{
		printf("%d\n", num[i]);
	}
	return 0;
}
#endif


#if 01
#include <stdio.h>
#include <stdlib.h>
int compare(const void *a, const void *b) {
	int x = *(int *)a; 
	int y = *(int *)b;
	if (x < y) return -1;
	if (x > y) return 1;
	return 0;
}
int d[25][25], dx[4] = { -1,1,0,0 }, dy[4] = { 0,0,1,-1 }, n, sum;
void bfs(int x, int y, int k) {
	if (d[x][y] != 1) return;
	int nx, ny, i;
	sum += 1;
	d[x][y] = k;
	for (i = 0; i < 4; i++)
	{
		nx = x + dx[i];
		ny = y + dy[i];
		if (0 <= nx && nx < n && 0 <= ny && ny < n)
		{
			bfs(nx, ny, k);
		}
	}
}
int main() {
	int i, j, len = 2, ans[1000];
	scanf("%d", &n);
	for (i = 0; i < n; i++) 
	{
		for (j = 0; j < n; j++) scanf("%1d", &d[i][j]);
	}
	for (i = 0; i < n; i++)
	{
		for (j = 0; j < n; j++) 
		{
			if (d[i][j] == 1) 
			{
				sum = 0;
				bfs(i, j, len);
				ans[len - 2] = sum;
				len++;
			}
		}
	}
	printf("%d\n", len - 2);
	len -= 2;
	qsort(ans, len, sizeof(int), compare);
	for (i = 0; i < len; i++)
	{
		printf("%d\n", ans[i]);
	}
}

#endif