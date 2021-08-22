#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <algorithm>
using namespace std;

int T = 10, tc, N;
int h[100];


int dump(){
    int minv, maxv, mini, maxi;
    minv = maxv = h[0];
    mini = maxi = 0;

    for(int i = 0; i < 100; i++){
        if(minv>h[i]){
            minv = h[i];
            mini = i;
        }
        if(maxv<h[i]){
            maxv = h[i];
            maxi = i;
        }
    }
    --h[maxi];
    ++h[mini];
    return(*max_element(h, h+100) - *min_element(h, h+100));
}
int main(){
    freopen("/Users/allison/Desktop/Coding/123/Bronze/SWEA1208_input.txt", "r", stdin);
    for(int tc = 1; tc <= T; tc++){
        cin >> N;
        for(int i = 0; i < 100; i++){
            cin >> h[i];
        }
        while(N--){
            dump();
        }
        cout << '#' << tc << ' ' << dump() << '\n';
    }
    return 0;
}

#endif
