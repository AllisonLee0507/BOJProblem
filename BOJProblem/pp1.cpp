#define _CRT_SECURE_NO_WARNINGS

#if 0
#include <stdio.h>
#include <algorithm>
#include <iostream>

using namespace std;

int main()
{
    int s[7] = {};
    int p, a, b, c;
    int i = 0;
    for(i = 0; i < 7; i++)
    {
        scanf("%d", &s[i]);
    }
    sort(s, s+7);
    p = s[6];
    a = s[0];
    b = s[1];
    c = p - a - b;
    
    printf("%d %d %d", a, b, c);
    
    return 0;
}
#endif
