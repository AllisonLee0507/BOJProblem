#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;

int a[1000], T, tc;
int c[101], cnt, mf, idx;

int main(){
    freopen("/Users/allison/Desktop/Coding/123/Bronze/SWEA1204_input.txt", "r", stdin);
    cin >> tc;
    while(T!=tc){
        cin >> T;
        mf = cnt = idx = 0;
        memset(a, 0, sizeof(a));
        memset(c, 0, sizeof(c));
        for(int i = 0; i<1000; i++){
            cin >> a[i];
            c[a[i]]++;
        }
        for(int i = 0; i <101; i++){
            if(c[idx] < c[i]){
                idx = i;
                mf = c[i];
            }
        }
        for(int i = 0; i <101; i++){
            if(c[i] == mf){
                idx = i;
            }
        }
        cout << '#' << T << ' ' << idx << '\n';
    }
    return 0;
}
#endif
