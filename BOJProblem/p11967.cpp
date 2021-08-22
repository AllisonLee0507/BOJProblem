#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
int n, m;
int on[102][102];
int vis[102][102];
int phase[102][102];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
vector<pair<int, int>> cor[105][105];
bool isCan(int y, int x)
{
	return y >= 1 && y <= n && x >= 1 && x <= n;
}
void dfs(int y, int x)
{
	vis[y][x] = 1;
	for (int i = 0; i < cor[y][x].size(); i++)
	{
		int cy = cor[y][x][i].first;
		int cx = cor[y][x][i].second;

		on[cy][cx] = 1;

		if (phase[cy][cx] && !vis[cy][cx])
		{
			dfs(cy, cx);
			phase[cy][cx] = 0;
			on[cy][cx] = 1;
		}
	}
	for (int k = 0; k < 4; k++)
	{
		int ny = y + dy[k];
		int nx = x + dx[k];
		if (isCan(ny, nx) && !vis[ny][nx])
		{
			if (!on[ny][nx])
			{
				phase[ny][nx] = 1;
			}
			else
			{
				on[ny][nx] = 1;
				dfs(ny, nx);
			}
		}

	}
}
int main(void)
{
	cin >> n >> m;
	for (int i = 1; i <= m; i++)
	{
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		cor[b][a].push_back({ d, c });
	}
	int cy = 1;
	int cx = 1;

	on[cy][cx] = 1;

	dfs(1, 1);

	int ans = 0;

	for (int i = 1; i <= n; i++)
	{
		for (int j = 1; j <= n; j++)
		{
			ans += on[i][j];
		}
	}
	cout << ans;
	return 0;
}
#endif