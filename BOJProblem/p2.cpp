#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
//#include <math.h>
int abs(int);

int main(){
    int count;
    int o, i;
    string result;
    cin >> count;
    o = count/2;
    for(i = -o; i<=o; i++){
        int k = 0;
        for(int j = 0; j<count - abs(i); j++){
            result = k <abs(i) ? ' ' : '*';
            cout << result;
            k++;
        }
        cout << endl;
    }
    return 0;
}
int abs(int i){
    if(i>0){
        return i;
    }
    else{
        return -i;
    }
}
#endif
