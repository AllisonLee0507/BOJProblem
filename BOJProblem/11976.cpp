#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>

int main(){
    int a, b, c, d, e, f, g, h;
    scanf("%d%d%d%d%d%d%d%d", &a, &b, &c, &d, &e, &f, &g, &h);
    int plat, gold, silver;
    plat = h - g;
    gold = plat + f - e;
    silver = gold + d - c;
    
    printf("%d\n%d\n%d\n", silver, gold, plat);
}
#endif
