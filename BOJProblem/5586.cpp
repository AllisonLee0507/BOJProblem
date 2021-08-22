#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <cstring>
using namespace std;

int main(){
    string N;
    int countJ, countI, i;
    int length;
    cin >> N;
    length = (int)N.length();
    countJ = countI = 0;
    for(i=0; i<length; i++){
        if(N[i] == 'J'&& N[i+1] == 'O'&& N[i+2] == 'I'){
                    countJ++;
        }
        else if(N[i] == 'I'&& N[i+1] == 'O'&& N[i+2] == 'I'){
                    countI++;
        }
    }
    cout << countJ << endl;
    cout << countI;
    
    
}
#endif
