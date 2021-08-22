#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <iostream>
#include <algorithm>

using namespace std;

int cnt[1000005];
int n,k, a[50005];

int main(){
    scanf("%d %d",&n,&k);
    for (int i=0; i<n; i++) {
        scanf("%d",&a[i]);
    }
    for (int i=0; i<k; i++) {
        cnt[a[i]]++;
    }
    int ret = 0;
    for (int i=0; i<n; i++) {
        if(i + k < n){
            cnt[a[i+k]]++;
        }
        cnt[a[i]]--;
        if(cnt[a[i]]) {
            ret = max(ret,a[i]);
        }
    }
    printf("%d",ret);
}
#endif
