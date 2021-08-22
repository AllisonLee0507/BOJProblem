#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;

int main(void){
    int x[4] = {};
    int y[4] = {};
    for(int i = 0; i < 4; i++)
    {
        scanf("%d %d", &x[i], &y[i]);
    }
    sort(x, x+4);
    sort(y, y+4);
    printf("%d", max(x[3]-x[0], y[3]-y[0])*max(x[3]-x[0], y[3]-y[0]));
}
#endif
