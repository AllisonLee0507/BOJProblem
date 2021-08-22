#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <stdlib.h>

int n, scale[8] = {1, 3, 9, 27, 81, 243, 729}, chk[8], end;
void solve(int n, int sum){
    if(end){
        return;
    }
    if(sum == n){
        printf("1111111111\n");
        for(int c=2; c>0; c--){
            for(int i = 0; i < 7; i++){
                if(chk[i] == c){
                    printf("%d ", scale[i]);
                }
            }
            if(c==2){
                printf("0 ");
            }
        }
        end = 1;
        for(int i = 0; i < 7; i++){
            if(chk[i]==0){
                chk[i] = 1;
                solve(n, sum+scale[i]);
                chk[i]=2;
                solve(n+scale[i], sum);
                chk[i]=0;
            }
        }
    }
}
int main(){
    scanf("%d", &n);
    printf("%d ", n);
    solve(n,0);
    return 0;
}
#endif
