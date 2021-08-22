#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <vector>
#include <iostream>
using namespace std;
int N, A, B, i, j, v[500], p, q, price;
int main(void){
    int x, y;
    cin >> A >> B >> N;
    price  = 99999;
    for(i = 0; i < N; i++){
        cin >> x >> y;
        for(j = 0; j < y; j++){
            cin >> v[j];
        }
        for(j = 0; j < y; j++){
            if(v[j] == A){
                p = j;
            }
            if(v[j] == B){
                q = j;
            }
        }
        if(p < q && price < x){
            price = x;
        }
    }
    if(price == 99999){
        cout << -1;
    }
    else{
        cout << price;
    }
}
#endif
