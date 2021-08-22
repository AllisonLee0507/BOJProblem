#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int map[20][20];
int i, j, n, k, l, cnt = 0;

int main(){
    scanf("%d", &n);
    for(i = 1; i <=n; i++){
        for(j = 1; j <=n; j++){
            scanf("%1d", &map[i][j]);
        }
    }
    for(i = n; i >= 1; i--){
        for(j = n; j>= 1; j--){
            if(map[i][j] == 1){
                for(k = 1; k<=i; k++){
                    for(l = 1; l<=j; l++){
                        map[k][l] = 1 - map[k][l];
                    }
                }
                cnt++;
            }
        }
    }
    printf("%d\n", cnt);
    return 0;
}
#endif 
