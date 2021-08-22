#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>

using namespace std;
int adj[101][101]; 
int visited[101][101]; 
queue<pair<int, int>> q; 
int N; 

void bfs(int a, int b)
{
	visited[a][b] = 1; 
	q.push(make_pair(a, b)); 
	while (!q.empty())
	{
		for (int i = 0; i < N; i++)
		{
			if (adj[q.front().second][i] && !visited[a][i])
			{
				visited[a][i] = 1; 
				q.push(make_pair(q.front().second, i)); 
			}
		}
		q.pop();
	}
}
int main(void)
{
	cin >> N; 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0;  j < N;  j++)
		{
			cin >> adj[i][j]; 
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (adj[i][j])
			{
				bfs(i, j); 
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visited[i][j] << ' '; 
		}
		cout << '\n'; 
	}

	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue>
using namespace std;

int adj[101][101]; 
int visited[101][101]; 
queue<pair<int, int>> q; 
int N; 


void bfs(int a, int b)
{
	visited[a][b] = 1; 
	q.push(make_pair(a, b)); 
	while (!q.empty())
	{
		for (int i = 0; i < N; i++)
		{
			if (adj[q.front().second][i] && !visited[a][i])
			{
				visited[a][i] = 1; 
				q.push(make_pair(q.front().second, i)); 
			}
		}
		q.pop(); 
	}
}
int main(void)
{
	cin >> N; 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> adj[i][j]; 
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (adj[i][j])
			{
				bfs(i, j); 
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visited[i][j] << ' ';
		}
		cout << '\n'; 
	}
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <queue> 

using namespace std;

int adj[101][101]; 
int visited[101][101]; 
queue<pair<int, int>> q; 
int N;

void dfs(int a, int b)
{
	visited[a][b] = 1; 
	for (int i = 0; i < N; i++)
	{
		if (adj[b][i] && !visited[a][i]) {
			dfs(a, i); 
		}
	}
}

int main(void)
{
	cin >> N; 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> adj[i][j]; 
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (adj[i][j])
			{
				dfs(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visited[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <algorithm> 

using namespace std;

#define INF 1000

int N;

int main(void)
{
	register int arr[100][100] = { 0, }; 
	
	cin >> N; 

	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			scanf("%d", &arr[i][j]); 
			if(arr[i][j] == 0)
			{
				arr[i][j] = INF; 
			}
		}
	}

	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (arr[i][j] > arr[i][k] + arr[k][j])
				{
					arr[i][j] = arr[i][k] + arr[k][i]; 
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			putchar((arr[i][j] != INF) ? '1' : '0'); 
			putchar(' '); 
		}
		putchar('\n');
	}
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> 
#define MAX_SIZE 100 

int map[MAX_SIZE][MAX_SIZE]; 
int map2[MAX_SIZE][MAX_SIZE]; 

int main(void)
{
	int N = 0; 
	int i, j, k; 
	int u, v; 

	scanf("%d", &N); 

	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			scanf("%d", &map[i][j]);
			map2[i][j] = map[i][j];
		}
	}
	for (k = 0; k < N; k++)
	{
		for (u = 0; u < N; u++)
		{
			for (v = 0; v < N; v++)
			{
				if (map2[u][k] == 1 && map2[k][v] == 1)
				{
					map2[u][v] = 1; 
				}
			}
		}
	}
	for (i = 0; i < N; i++)
	{
		for (j = 0; j < N; j++)
		{
			printf("%d ", map2[i][j]);
		}
		printf("\n"); 
	}

	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;
int adj[101][101]; 
int visited[101][101]; 
int N; 
void DFS(int a, int b)
{
	visited[a][b] = 1; 
	for (int i = 0; i < N; i++)
	{
		if (adj[b][i] == 1 && !visited[a][i])
		{
			DFS(a, i); 
		}
	}
}
int main(void)
{
	cin >> N; 
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> adj[i][j]; 
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			if (adj[i][j])
			{
				DFS(i, j);
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << visited[i][j] << ' ';
		}
		cout << endl; 
	}
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
using namespace std;

int map[101][101]; 
int main(void)
{
	int N;
	cin >> N;
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cin >> map[i][j];
		}
	}
	for (int k = 0; k < N; k++)
	{
		for (int i = 0; i < N; i++)
		{
			for (int j = 0; j < N; j++)
			{
				if (map[i][k] && map[k][j])
				{
					map[i][j] = 1;
				}
			}
		}
	}
	for (int i = 0; i < N; i++)
	{
		for (int j = 0; j < N; j++)
		{
			cout << map[i][j] << ' '; 
		}
		cout << endl; 
	}
	return 0;
}
#endif