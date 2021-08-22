#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int main(){
    long long x, y, n;
    int i, j, k, l, ans;
    ans = 0;
    cin >> x >> y;
    for(l = 3; l < 18; l++){
        for(i = 0; i<10; i++){
            n = (pow(10, l)-1)/9*i;
            for(j = 0; j<10; j++){
                if(i==j){
                    continue;
                }
                for(k = 0; k<l; k++){
                    if(!i&&k!=l-1){
                        continue;
                    }
                    if(!j&&k==l-1){
                        continue;
                    }
                    n+=pow(10,k)*(j-i);
                    if(x<=n&&n<=y){
                        ans++;
                    }
                    n-=pow(10,k)*(j-i);
                }
            }
        }
    }
    printf("%d", ans);
    return 0;
}
#endif
