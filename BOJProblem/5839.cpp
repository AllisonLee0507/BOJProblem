#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int b[1010][2];
int e[1010][2];
int main(){
    int n, m, i, j, sum =0, lb = 0, le = 0, s =0;
    scanf("%d%d", &n,&m);
    for(i = 1; i<=n; i++){
        scanf("%d%d", &b[i][0], &b[i][1]);
    }
    for(i = 1; i<=m; i++){
        scanf("%d%d", &e[i][0], &e[i][1]);
    }
    i = 1;
    j = 1;
    while (i<=n){
        int k = sum;
        lb += b[i][0];
        b[i][1]--;
        if(b[i][1]==0){
            i++;
        }
        le+= e[j][0];
        e[j][1]--;
        if(e[j][1]==0){
            j++;
        }
        if(lb>le){
            sum=1;
        }
        else if(lb<le){
            sum=2;
        }
        else{
            sum=0;
        }
        if(sum!=k&&sum!=0){
            s++;
        }
    }
    printf("%d",s>0 ? s-1 : 0 );
}
#endif
