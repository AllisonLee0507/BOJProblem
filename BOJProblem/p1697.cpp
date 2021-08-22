#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define qmax 50000
typedef struct st {
	int p, cnt; 
}NODE;

NODE que[qmax]; 
int w, r; 
int s, d; 
char check[10000 + 1000]; 
int main(void)
{
	scanf("%d %d", &s, &d); 
	que[w].p = s; 
	que[w++].cnt = 0; 
	check[s] = 1; 

	w %= qmax; 

	while (w != r)
	{
		NODE cur = que[r++]; 
		if (cur.p == d)
		{
			printf("%d", cur.cnt);
			break;
		}; 

		int ns[3] = { cur.p + 1, cur.p - 1, cur.p * 2 };
		r %= qmax; 

		for (int i = 0; i < 3; i++)
		{
			if (ns[i] < 0 || ns[i] > 100000)
			{
				continue; 
			}

			check[ns[i]] = 1; 
			que[w].p = ns[i];
			que[w++].cnt = cur.cnt + 1; 

			w %= qmax; 
		}
	}

	return 0;
}
#endif