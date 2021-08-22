#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

int q[1000], qf, qb, qs, n, m, v; 
char p[1001][1001], visited[1001]; 
void dfs(int v)
{
	printf("%d ", v); 
	visited[v] = 1; 
	for (int i = 1; i <= n; i++)
	{
		if (p[v][i] == 1 && visited[i] == 0)
		{
			dfs(i); 
		}
	}
}
void bfs(int v)
{
	int i, j; 
	memset(visited, 0, 1001); 
	q[qb++] = v; 
	qs++;
	visited[v] = 1; 
	
	while (qs)
	{
		i = q[qf++]; 
		qs--; 
		printf("%d ", i);
		for (j = 1; j <= n; j++)
		{
			if (!visited[j] && p[i][j])
			{
				q[qb++] = j; 
				qs++; 
				visited[j] = 1; 
			}
		}

	}
}
int main(void)
{
	int a, b; 
	scanf("%d %d %d", &n, &m, &v); 
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d", &a, &b); 
		p[a][b] = p[b][a] = 1; 
	}

	dfs(v); 
	printf("\n"); 
	bfs(v); 
	printf("\n");
	
	return 0;
}
#endif
