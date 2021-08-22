#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <stdio.h>
#include <algorithm>
using namespace std;

int main(){
    int i, j, k;
    int n, count;
    count = 0;
    scanf("%d", &n);
    
    for(i = 1; i<=n; i++){
        for(j = i; j<=n; j++){
            for(k = j; k<=n;k++){
                if(i+j+k == n && i+j>k){
                    count++;
                }
            }
        }
    }
    printf("%d", count);
}
#endif

#if 0
#include <stdio.h>
#include <algorithm>
int main(void){
    int n, a, b, c, count = 0;
    scanf("%d", &n);
    for(a = 1; a<=n;a++){
        for(b = 1; b<=n; b++){
            c = n - (a+b);01
            if((a+b>c)&&(a<=b&&b<=c)){
                count++;
            }
        }
    }
    printf("%d\n", count);
    return 0;
}
#endif

#if 0
#include <stdio.h>
int cnt, chk[21][21][21];
int dx[3] = {1, 0, 0};
int dy[3] = {0, 1, 0};
int dz[3] = {0, 0, 1};

void solve(int n, int a, int b, int c){
    if(a+b+c==n){
        if(a<=b&&b<=c&&a+b>c&&chk[a][b][c]==0){
            cnt++;
            chk[a][b][c]=1;
        }
        return;
    }
    for(int i = 0; i < 3; i++){
        solve(n, a+dx[i], b+dy[i], c+dz[i]);
    }
//    solve(n, a+1, b, c);
//    solve(n, a, b+1, c);
//    solve(n, a, b, c+1);
}

int main(void){
    int n;
    scanf("%d", &n);
    solve(n, 1, 1, 1);
    printf("%d\n", cnt);
}
#endif
