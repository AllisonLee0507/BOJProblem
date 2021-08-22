#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <cstdio>
#include <iostream>
#include <cstring>

using namespace std;
int T = 10, ans, N;
int h[1001];
void init(){
    ans = 0;
    cin >> N;
    for(int i = 0; i < N; i++){
        cin >> h[i];
    }
    return;
}
int main(){

    freopen("/Users/allison/Desktop/Coding/123/Bronze/SWEA1206_input.txt", "r", stdin);
    for(int tc = 1; tc <= T; tc++){
        init();
        for(int i = 0; i <N; i++){
            for(int nh = h[i]; nh > h[i-1] && nh > h[i-2] && nh > h[i+1] && nh > h[i+2]; nh--){
                ans++;
            }
        }
        cout << '#' << tc << ' ' << ans << '\n';
    }
}
#endif
