#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
#include <deque>

using namespace std;

int main(void){
    deque<int> dq;
    
    for(deque<int>::size_type i = 0; i < 10; ++i){
        dq.push_back((i+1)*10);
    }
    
    for(deque<int>::size_type i = 0; i < dq.size(); ++i){
        cout << dq[i] << ' ';
    }
    cout << endl;
}
#endif

#if 0
#include <iostream>
#include <vector>
#include <deque>

using namespace std;

int main(void){
    vector<int> v(4,100);
    deque<int> dq(4,100);
    
    v.push_back(200);
    dq.push_back(200);
    
    for(vector<int>::size_type i = 0; i < v.size(); ++i){
        cout << v[i] << " ";
    }
    cout << endl;
    
    for(deque<int>::size_type i = 0; i < dq.size(); ++i){
        cout << dq[i] << " ";
    }
    cout << endl;
    return 0;
}
#endif

#if 0
#include <iostream>
#include <deque>
using namespace std;

int main(void){
    deque<int> dq;
    
    dq.push_back(10);
    dq.push_back(20);
    dq.push_back(30);
    dq.push_back(40);
    dq.push_back(50);
    
    for(deque<int>::size_type i = 0; i < dq.size(); ++i){
        cout << dq[i] << " ";
    }
    cout << endl;
    
    dq.push_front(100);
    dq.push_front(200);
    
    for(deque<int>::size_type i = 0; i < dq.size(); ++i){
        cout << dq[i] << " ";
    }
    cout << endl;
    
    deque<int>::iterator iter;
    deque<int>::iterator iter2;
    
    for(iter = dq.begin(); iter != dq.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
    
    iter = dq.begin() + 2;
    iter2 = dq.insert(iter, 500);
    cout << *iter2 << endl;
    
    for(iter = dq.begin(); iter != dq.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
    return 0;
}

#endif
