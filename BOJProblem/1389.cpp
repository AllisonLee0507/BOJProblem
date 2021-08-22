#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(){
    int n, m;
    char map[101][101];
    int i, j, k, a, b, sum, min, mini;
    scanf("%d %d", &n, &m);
    for(i = 1; i <= n; i++){
        for(j = 1; j <= n; j++){
            map[i][j] = 100;
        }
    }
    for(i = 1; i <= n; i++){
        map[i][i] = 0;
    }
    for(i = 0; i < m; i++){
        scanf("%d %d", &a, &b);
        map[a][b] = 1;
        map[b][a] = 1;
    }
    for(k = 1; k <= n; k++){
        for(i = 1; i <= n; i++){
            for(j = 1; j <= n; j++){
                if(map[i][j] > map[i][k] + map[k][j]){
                    map[i][j] = map[i][k] + map[k][j];
                }
            }
        }
    }
    mini = 0;
    min = 100000;
    for(i = 1; i <= n; i++){
        sum = 0;
        for(j = 1; j <= n; j++){
            sum += map[i][j];
        }
        if(sum < min){
            min = sum;
            mini = i;
        }
    }
    printf("%d\n", mini);
    return 0;
}
#endif
