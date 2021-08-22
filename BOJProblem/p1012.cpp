#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <string.h>
#include <iostream>

using namespace std;

int dy[4] = { 1, -1, 0, 0 }; 
int dx[4] = { 0, 0, 1, -1 }; 
int M, N, K; 
int arr[50][50] = { 0 }; 
int visited[50][50] = { 0 };
void dfs(int y, int x)
{
	for (int i = 0; i < 4; i++)
	{
		visited[y][x]++;
		int ny = y + dy[i]; 
		int nx = x + dx[i]; 

		if (ny < 0 || nx < 0 || ny >= N || nx >= M)
		{
			continue; 
		}

		if (arr[ny][nx] && !visited[ny][nx])
		{
			visited[ny][nx]++; 
			dfs(ny, nx); 
		}
	}

}
int main(void)
{
	int T, x, y; 
	cin >> T; 
	int ans = 0; 
	for (int Test_Case = 0; Test_Case < T; Test_Case++)
	{
		scanf("%d %d %d", &M, &N, &K);
		memset(arr, 0, sizeof(arr)); 
		memset(visited, 0, sizeof(visited)); 
		ans = 0; 
		for (int i = 0; i < K; i++)
		{
			scanf("%d %d", &x, &y);
			arr[y][x] = 1; 
		}
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < M; j++)
			{
				if (arr[i][j] && !visited[i][j])
				{
					ans++; 
					dfs(i, j); 
				}
			}
		}

		cout << ans << endl; 
	}
	return 0;
}
#endif