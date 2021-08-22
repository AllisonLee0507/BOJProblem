#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int N, M, count = 0; 
int arr[1001][1001], visit[10001]; 
void DFS(int x)
{
	visit[x] = 1; 
	for (int i = 1; i <= N; i++)
	{
		if (arr[x][i] && !visit[i])
		{
			DFS(i); 
		}
	}
}
int main(void)
{
	int a, b; 
	scanf("%d %d", &N, &M); 
	for (int i = 1; i <= M; i++)
	{
		scanf("%d %d", &a, &b); 
		arr[a][b] = arr[b][a] = 1; 
	}
	for (int i = 1; i <= N; i++)
	{
		if (!visit[i])
		{
			count++;
			DFS(i);
		}
	}

	printf("%d\n", count); 
	return 0;
}
#endif



