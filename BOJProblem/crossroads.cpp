#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
int H, W, ans;
void solve(int h, int w){
    if(h>H || w>W){
        return;
    }
    if(h==H && w==W){
        ans++;
        return;
    }
    solve(h+1, w);
    if((double)H/W<=(double)h/(w+1)){
        solve(h,w+1);
    }
}
int main(){
    scanf("%d%d", &H, &W);
    solve(0,0);
    printf("%d\n", ans);
    return 0;
}
#endif
