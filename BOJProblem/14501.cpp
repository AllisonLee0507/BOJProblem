#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <algorithm>
using namespace std;
int dp[20], t[20], p[20];
int main(void){
    int i, j, N;
    int a, b;
    int day, time, price, end;
    cin >> N;
    for(i = 1; i <= N; i++){
        cin >> a >> b;
        t[i] = a;
        p[i] = b;
    }
    for(day = 1; day <= N +1; day++){
        time = t[day];
        price = p[day];
        end = time + day;
        if(day + time > N +1){
            continue;
        }
        for(j = end; j <= N +1; j++){
            dp[j] = max(dp[day] + p[day], dp[j]);
        }
    }
    cout << dp[N+1] << endl;
    return 0;
}
#endif
