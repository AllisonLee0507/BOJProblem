#define _CRT_SECURE_NO_WARNINGS
#if 0
#define _CRT_SECURE_NO_WARNINGS
#include <iostream>
#include <string>
#include <stack>
using namespace std;

int main(){
    string a, b;
    char command, inputChar;
    int Num;
    cin >> a >> Num;
    while (Num--){
        cin >> command;
        switch (command){
            case'L':
                if(a.size()!=0){
                    b.push_back(a.back());
                    a.pop_back();
                }
            case'D':
                if(b.size() !=0){
                    a.push_back(b.back());
                    b.pop_back();
                }
                break;
            case 'B':
                if(a.size() != 0){
                    a.pop_back();
                }
                break;
            case 'P':
                cin >> inputChar;
                a.push_back(intputChar);
                break;
            default:
                break;
        }
    }
    cout << a;
    while(b.size() != 0){
        cout << b.back();
        b.pop_back();
    }
    return 0;
}
#endif
