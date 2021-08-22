#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define MAX_SIZE 1005
int N, M; 
int map[MAX_SIZE][MAX_SIZE]; 
int queue[MAX_SIZE * MAX_SIZE][2]; 
int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 };
int zerocount, daycount; 
int front, back; 

void push(int x, int y); 
int bfs(int row, int column);

int main(void)
{
	scanf("%d %d", &M, &N);
	for (int i = 0; i <= N+1; i++)
	{
		for (int j = 0; j <= M+1; j++)
		{
			if (i == 0 || j == 0 || i == N + 1 || j == M + 1)
			{
				map[i][j] = -1; 
			}
			else
			{
				scanf("%d", &map[i][j]);
				if (map[i][j] == 0)
				{
					zerocount++; 
				}
				else if(map[i][j] == 1)
				{
					push(i, j); 
				}
			}
			
		}
	}
	if (zerocount == 0)
	{
		printf("0"); 
	}
	printf("%d\n", bfs(M, N)); 

	return 0;
}

void push(int x, int y)
{
	queue[back][0] = x; 
	queue[back][1] = y; 
	back++; 
}
void pop()
{
	front++; 
}

int bfs(int row, int column)
{
	int cur_x, cur_y; 

	while (front != back)
	{
		cur_x = queue[front][0]; 
		cur_y = queue[front][1]; 

		pop(); 
		for (int i = 0; i < 4; i++)
		{
			if (map[cur_x - dx[i]][cur_y - dy[i]] == 0)
			{
				map[cur_x - dx[i]][cur_y - dy[i]] = map[cur_x][cur_y] + 1;
				
				push(cur_x - dx[i], cur_y - dy[i]); 
				zerocount--; 
			}
		}
		printf("%d ", map[cur_x][cur_y]); 

	}
	if (zerocount > 0)
	{
		return -1;
	}
	return map[cur_x][cur_y] - 1; 

}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

int arr[1010][1010]; 
int point[1010 * 1010][2]; 
int point_next[1010 * 1010][2]; 
int point_count_next; 
int dx[4] = { 0, 0, -1, 1 }; 
int dy[4] = { -1, 1, 0, 0 }; 

void check_box(int row, int col)
{
	if (arr[row][col] == 0)
	{
		arr[row][col] = 1; 
		point_next[point_count_next][0] = row; 
		point_next[point_count_next][1] = col; 

		point_count_next++; 
	}
}
int main(void)
{
	int row, col;
	int onecount = 0;
	int zerocount = 0;
	int daycount = 0;
	int pointcount = 0;
	int pointrow;
	int pointcol;

	scanf("%d %d", &col, &row);

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			scanf("%d", &arr[i][j]);

			if (arr[i][j] == 1)
			{
				onecount++;
			}
			if (arr[i][j] == 0)
			{
				zerocount++;
			}
		}
	}

	if (zerocount == 0)
	{
		printf("0");
	}
	else if (onecount == 0)
	{
		printf("-1");
	}

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 1)
			{
				point[pointcount][0] = i;
				point[pointcount][1] = j;

				pointcount++;
			}
		}
	}

	while (1)
	{
		for (int i = 0; i < pointcount; i++)
		{
			pointrow = point[i][0];
			pointcol = point[i][1];

			if (pointrow != 0)
			{
				check_box(pointrow - 1, pointcol);
			}
			if (pointcol != 0)
			{
				check_box(pointrow, pointcol - 1);
			}
			if (pointrow != row - 1)
			{
				check_box(pointrow + 1, pointcol);
			}
			if (pointcol != col - 1)
			{
				check_box(pointrow, pointcol + 1);
			}
		}
		if (point_count_next == 0)
		{
			break; 
		}
		for (int i = 0; i < point_count_next; i++)
		{
			point[i][0] = point_next[i][0]; 
			point[i][1] = point_next[i][1]; 
		}

		pointcount = point_count_next; 
		point_count_next = 0; 

		daycount++; 
	}
	zerocount = 0; 
	
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (arr[i][j] == 0)
			{
				zerocount++; 
			}
		}
	}
	if (zerocount != 0)
	{
		printf("-1"); 
	}
	else
	{
		printf("%d", daycount); 
	}
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

struct QUEUE {
	int i, j;
}q[1000001];

int f = 0, l = 0;

int x[1000][1000]; 
int I, J, remain = 0; 
void inqueue(int i, int j)
{
	q[l].i = i; 
	q[l].j = j; 
	l++; 
}
int main(void)
{
	int i, j, t = 0, s = 0; 
	scanf("%d %d", &I, &J); 
	for (j = 0; j < J; j++)
	{
		for (i = 0; i < I; i++)
		{
			scanf("%d", &x[i][j]); 

			if (x[i][j] == 1)
			{
				inqueue(i, j); 
			}
			else if (x[i][j] == 0)
			{
				remain++; 
			}
		}
	}
	while (t < l)
	{
		for (t = l; f < t; f++)
		{
			i = q[f].i; 
			j = q[f].j; 

			if (j > 0 && x[j - 1][i] == 0)
			{
				inqueue(i, j - 1); 
				x[j - 1][i] = 1; 
				remain--; 
			}
			if (j < J - 1 && x[j + 1][i] == 0)
			{
				inqueue(i, j + 1); 
				x[j + 1][i] = 1; 
				remain--; 
			}
			if (i > 0 && x[j][i - 1] == 0)
			{
				inqueue(i - 1, j); 
				x[j][i - 1] = 1; 
				remain--; 
			}
			if (i < I - 1 && x[j][i + 1] == 0)
			{
				inqueue(i + 1, j); 
				x[j][i + 1] = 1; 
				remain--; 
			}
		}
		s++; 
	}
	if (remain > 0)
	{
		printf("-1\n"); 
	}
	else
	{
		printf("%d\n", s - 1); 
	}
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
int qx[1000005]; 
int qy[1000005]; 
int head, tail; 
int map[1001][1001]; 
int main(void)
{
	int x, y, i, j;
	int flag1, flag2, cnt, day;
	flag1 = flag2 = cnt = 0; 

	scanf("%d %d", &y, &x); 

	for (i = 0; i < x; i++)
	{
		for (j = 0; j < y; j++)
		{
			scanf("%d", &map[i][j]); 
			if (map[i][j] == -1)
			{
				flag2++; 
			}
			else if (map[i][j] == 0)
			{
				cnt++; 
			}
			else
			{
				flag1 = 1; 
				tail++; 
				qx[tail] = i; 
				qy[tail] = j; 
			}
		}
	}
	if (flag1 == 0 || flag2 == x * y)
	{
		printf("-1\n"); 
	}
	else
	{
		while (1)
		{
			if (cnt == 0)
			{
				day = map[qx[tail]][qy[tail]] - 1; 
				break;
			}
			if (head > x * y)
			{
				day = -1; 
				break; 
			}
			head++; 
			if (qx[head] > 0 && map[qx[head] - 1][qy[head]] == 0)
			{
				cnt--; 
				tail++;
				qx[tail] = qx[head] - 1; 
				qy[tail] = qy[head]; 
				map[qx[head] - 1][qy[head]] = map[qx[head]][qy[head]] + 1; 
			}
			if (qx[head] < x - 1 && map[qx[head] + 1][qy[head]] == 0)
			{
				cnt--;
				tail++;
				qx[tail] = qx[head] + 1;
				qy[tail] = qy[head];
				map[qx[head]+1][qy[head]] = map[qx[head]][qy[head]] + 1;
			}
			if (qy[head] > 0 && map[qx[head]][qy[head] - 1] == 0)
			{
				cnt--; 
				tail++; 
				qx[tail] = qx[head]; 
				qy[tail] = qy[head] - 1; 
				map[qx[head]][qy[head] - 1] = map[qx[head]][qy[head]] + 1; 
			}
			if (qy[head] < y - 1 && map[qx[head]][qy[head] + 1] == 0)
			{
				cnt--; 
				tail++; 
				qx[tail] = qx[head]; 
				qy[tail] = qy[head] + 1; 
				map[qx[head]][qy[head] + 1] = map[qx[head]][qy[head]] + 1; 
			}
		}
		printf("%d\n", day);
	}
	return 0;
}
#endif

#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

int i, j, max, n, m, map[1005][1005], queue[1000005][2], cnt, real, front; 

int main(void)
{
	scanf("%d %d", &m, &n);
	for (i = 0; i <= n + 1; i++)
	{
		for (j = 0; j <= m + 1; j++)
		{
			map[i][j] = -1; 
		}
	}
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			scanf("%d", &map[i][j]); 
			if (map[i][j] == 1)
			{
				queue[real][0] = i; 
				queue[real++][1] = j; 
			}
			if (map[i][j] == 0)
			{
				cnt++; 
			}
		}
	}
	if (cnt == 0)
	{
		printf("0"); 
		return 0; 
	}
	while (1)
	{
		i = queue[front][0]; 
		j = queue[front++][1]; 

		if (map[i][j - 1] == 0)
		{
			map[i][j - 1] = map[i][j] + 1; 
			queue[real][0] = i; 
			queue[real++][1] = j - 1; 
		}
		if (map[i][j + 1] == 0)
		{
			map[i][j + 1] = map[i][j] + 1; 
			queue[real][0] = i;
			queue[real++][1] = j + 1; 
		}
		if (map[i - 1][j] == 0)
		{
			map[i - 1][j] = map[i][j] + 1; 
			queue[real][0] = i - 1; 
			queue[real++][1] = j; 
		}
		if (map[i + 1][j] == 0)
		{
			map[i + 1][j] = map[i][j] + 1; 
			queue[real][0] = i + 1; 
			queue[real++][1] = j; 
		}
		if (real == front)
		{
			break; 
		}
	}
	cnt = 0; 
	for (i = 1; i <= n; i++)
	{
		for (j = 1; j <= m; j++)
		{
			if (map[i][j] == 0)
			{
				cnt++; 
			}
			if (max < map[i][j])
			{
				max = map[i][j]; 
			}
		}
	}
	if (cnt != 0)
	{
		printf("-1");
	}
	else
	{
		printf("%d", max - 1);
	}
	return 0;
}
#endif

