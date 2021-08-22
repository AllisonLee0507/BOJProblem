#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <queue>
#include <iostream>
using namespace std;

const int roff[4] = { -1, 1, 0, 0 }; 
const int coff[4] = { 0, 0, -1, 1 }; 

int main(void)
{
	int N, M, sr, sc, r1 = -1, c1; 
	int i, j;
	scanf("%d %d", &N, &M); 
	char map[50][50]; 
	for (i = 0; i < N; i++)
	{
		getchar(); 
		for ( j = 0; j < M; j++)
		{
			map[i][j] = getchar();
			if (map[i][j] == 'S')
			{
				sr = i;
				sc = j;
			}
			else if (map[i][j] == 'C' && r1 == -1)
			{
				r1 = i; 
				c1 = j; 
			}
		}
	}
	bool visited[3][4][50][50] = { 0 }; 
	queue <int> Q: 
	for (int d = 0; d < 4; d++)
	{
		visited[0][d][sr][sc] = true;
		Q.push(d * 2500 + sr * 50 + sc); 
	}
	int result = 0; 
	bool success = false; 

	while (!Q.empty())
	{
		int qSize = Q.size(); 
		for (int i = 0; i < qSize; i++)
		{
			int deliver = Q.front() / 10000; 
			int pdir = Q.front() % 10000 / 2500; 
			int r = Q.front() % 2500 / 50;
			int c = Q.front() % 50; 
			Q.pop(); 
			if (map[r][c] == 'C')
			{
				if (r1 == r && c1 == c)
				{
					deliver = deliver | 1;
					deliver | 1;

				}
				else 
				{
					deliver |= 2; 
				}

			}
		}
	}
	return 0;
}
#endif