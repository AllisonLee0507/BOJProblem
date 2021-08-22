#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <algorithm>
using namespace std;

int intersection(int ax, int axx, int ay, int ayy, int bx, int bxx, int by, int byy){
    int xCommon, yCommon;
    xCommon = max(0, min(axx, bxx)-max(ax, bx));
    yCommon = max(0, min(ayy, byy)-max(ay, by));
    return xCommon*yCommon;
}
int main(){
    int ax, ay, axx, ayy, bx, by, bxx, byy, cx, cy, cxx, cyy;
    int ans;
    
    scanf("%d%d%d%d", &ax, &ay, &axx, &ayy);
    scanf("%d%d%d%d", &bx, &by, &bxx, &byy);
    scanf("%d%d%d%d", &cx, &cy, &cxx, &cyy);
    
    ans = (axx-ax)*(ayy-ay)+(bxx-bx)*(byy-by);
    ans -= intersection(ax, axx, ay, ayy, cx, cxx, cy, cyy);
    ans -= intersection(bx, bxx, by, byy, cx, cxx, cy, cyy);
    
    printf("%d\n", ans);
    return 0;
}
#endif
