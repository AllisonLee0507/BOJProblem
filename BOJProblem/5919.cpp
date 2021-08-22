#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
using namespace std;
int main(){
    int n, i, o, count, d;
    cin >> n;
    int a[n-1], sum;
    sum = 0;
    for (i = 0; i<n; i++){
        cin >> a[i];
        sum = sum + a[i];
    }
    o = sum / n;
    count = 0;
    for(i = 0; i<n; i++){
        if(a[i] > o){
            d = a[i] - o;
            count = count + d;
        }
    }
    cout << count;
    
}
#endif
