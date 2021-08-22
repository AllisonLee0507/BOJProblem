#define _CRT_SECURE_NO_WARNINGS
//#if 0
//#include <iostream>
//#include <list>
//#include <algorithm>
//
//using namespace std;
//int main(void){
//    list<int> lt;
//    lt.push_back(1);
//    lt.push_back(2);
//    lt.push_back(3);
//    (&lt)->push_back(4);
//    (&lt)->push_back(5);
//    (&lt)->push_back(6);
//
//    sort(lt.begin(), lt.end(), less<int>());
//
//    return 0;
//}
//#endif

#if 0
#include <iostream>
#include <list>
using namespace std;
int main(void){
    list<int> lt;
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);
    
    list<int>::iterator iter = lt.begin();
    list<int>::iterator iter2;
    
    ++iter;
    ++iter;
    
    iter2 = lt.erase(iter);
    
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter << ' ';
    }
    cout << endl;
    
    cout << "iter2: " << *iter2 << endl;
    iter = iter2;
    iter2 = lt.insert(iter,300);
    for(iter = lt.begin(); iter != lt.end(); iter++){
        cout << *iter << ' ';
    }
    cout << endl;
    return 0;
}
#endif


#if 0
#include <iostream>
#include <vector>
#include <list>

using namespace std;
int main(void){
    vector<int> v;
    list<int> lt;
    
    v.push_back(10);
    v.push_back(20);
    v.push_back(30);
    v.push_back(40);
    v.push_back(50);
    
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);
    
    vector<int>::iterator viter = v.begin();
    ++viter;
    
    list<int>::iterator liter = lt.begin();
    ++liter;
    
    viter = v.insert(viter, 600);
    liter = lt.insert(liter, 600);
    
    cout << "vector: " << *viter << endl;
    cout << "list: " << *liter << endl;
    
    cout << "vecotr : ";
    for(viter = v.begin(); viter != v.end(); ++viter){
        cout << *viter << ' ';
    }
    cout << endl;
    
    cout << "list : ";
    for(liter = lt.begin(); liter != lt.end(); ++liter){
        cout << *liter << ' ';
    }
    cout << endl;
    
    return 0;
}
#endif


#if 0
#include <iostream>
#include <list>
using namespace std;

int main(void){
    list<int> lt;
    
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);
    lt.push_back(10);
    lt.push_back(10);
    
    list<int>::iterator iter;
    for(iter = lt.begin(); iter != lt.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
    
    lt.remove(10);
    for(iter = lt.begin(); iter != lt.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
}
#endif


#if 0
#include <iostream>
#include <list>
using namespace std;
bool Predicate(int n){
    return 10<= n && n <= 30;
}
int main(void){
    list<int> lt;
    
    lt.push_back(10);
    lt.push_back(20);
    lt.push_back(30);
    lt.push_back(40);
    lt.push_back(50);
    lt.push_back(10);
    
    list<int>::iterator iter;
    for(iter = lt.begin(); iter != lt.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
    
    lt.remove_if(Predicate);
    for(iter = lt.begin(); iter != lt.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
}
#endif


#if 0
#include <iostream>
#include <list>
using namespace std;

int main(void){
    list<int> lt1;
    list<int> lt2;
    
    lt1.push_back(10);
    lt1.push_back(20);
    lt1.push_back(30);
    lt1.push_back(40);
    lt1.push_back(50);
    
    lt2.push_back(100);
    lt2.push_back(200);
    lt2.push_back(300);
    lt2.push_back(400);
    lt2.push_back(500);
    
    list<int>::iterator iter;
    list<int>::iterator iter2;
    cout << "lt1: ";
    for(iter = lt1.begin(); iter != lt1.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
    
    cout << "lt2: ";
    for(iter = lt2.begin(); iter != lt2.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl << "================" << endl;
    
    iter = lt1.begin();
    ++iter;
    ++iter;
    
    lt1.splice(iter, lt2);
    cout << "lt1: ";
    for(iter = lt1.begin(); iter != lt1.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
    
    cout << "lt2: ";
    for(iter = lt2.begin(); iter != lt2.end(); ++iter){
        cout << *iter << ' ';
    }
    cout << endl;
    
    return 0;
}
#endif
