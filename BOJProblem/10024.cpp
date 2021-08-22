#define _CRT_SECURE_NO_WARNINGS
#if 0
#include<stdio.h>
int A[110];
int B[110];
int S_A[110];
int S_B[110];
int check[110];
int main(){
    int N, i, res=0, L=-1, r, len;
    scanf("%d", &N);
    for(i=1; i<=N; i++){
        scanf("%d", &A[i]);
        S_A[A[i]]=i;
    }
    for(i=1; i<=N; i++){
        scanf("%d", &B[i]);
        S_B[B[i]]=i;
    }
    for(i=1; i<=N; i++){
        if(A[i]==B[i] || check[i]==1) continue;
        res++;
        r=B[i];
        len=1;
        while(r!=A[i]){
            check[S_B[r]]=1;
            r=B[S_A[r]];
            len++;
        }
        check[S_B[r]]=1;
        if(L<len) L=len;
    }
    printf("%d %d", res, L);
}

#endif
