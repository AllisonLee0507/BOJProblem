#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main()
{
    int N, i, hansu;
    hansu = 0; 
    scanf("%d", &N);
    for(i = 1; i<= N; i++){
        if(i<100){
            hansu++;
        }
        else if((i/100)-(i/10)%10 == (i/10)%10 - i%10){
            hansu++;
        }
    }
    printf("%d\n", hansu);
    
}
#endif
