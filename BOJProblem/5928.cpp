#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int main(){
    int a, b, c;
    scanf("%d %d %d", &a, &b, &c);
    int time;
    time = (a-11)*1440 + (b-11)*60 + (c-11);
    printf("%d", time>=0?time:-1);
}
#endif
