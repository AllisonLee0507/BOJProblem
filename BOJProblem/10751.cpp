#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int main(){
    int N;
    long long C, O, W;
    C = 0;
    O = 0;
    W = 0;
    scanf("%d", &N);
    char cow[N];
    scanf("%s", cow);
    for(int i = 0; i < N; i++){
        if (cow[i] == 'C'){
            C++;
        }
        else if (cow[i] == 'O'){
            O += C;
        }
        else if (cow[i] == 'W'){
            W += O;
        }
    }

    printf("%lld", W);
    
}
#endif
