#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(){
    char N[10];
    int result, i;
    result = 0;
    scanf("%s", &N);
    for(i = 0; i<9; i++){
        result = (N[i] - '0' )+ result;
    }
    printf("%d", result); 
}
#endif
