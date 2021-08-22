#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <vector>
#include <utility>
#include <algorithm>

using namespace std;
int N, K, r;
int bucket[400001] = {0};
int main(void){
    cin >> N >> K;
    int a, b;
    for(int i = 0; i < N; i++){
        cin >> b >> a;
        bucket[a] = b;
    }
    long long sum = 0, ans;
    for(int i = 0; i <= 2 * K; i++){
        sum += bucket[i];
    }
    ans = sum;
    int l = 0, r = 2 * K + 1;
    while (r <= 100000){
        sum = sum + bucket[r++] - bucket[l++];
        ans = max(ans, sum);
    }
    cout << ans << endl;
    return 0;
}
#endif
