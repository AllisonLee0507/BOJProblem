#define _CRT_SECURE_NO_WARNINGS
#if 0
#include <iostream>
using namespace std;

class userData{
    
private:
    int x;
protected:
public:

private:
protected:
public:
    userData() {cout << "기본 생성자 생성자\n"; this->x = 0;}
    ~userData() {cout << "기본 소멸자 소멸자\n"; }
    void SetX(int _x){ this->x = _x; }
    int GetX(void) {return this -> x; }
    void printDataX(void) {cout << this->x << endl; }
};

int main(void){
    userData a, b, c;
    a.SetX(10);
    b.SetX(11);

    cout << a.GetX() << endl;
    cout << b.GetX() << endl;
    cout << c.GetX() << endl;
    
    a.printDataX();
    b.printDataX();
    c.printDataX();
    
    return 0;
}
#endif



#if 0
#include <iostream>
using namespace std;

class userData{
    
private:
    int x;
protected:
public:

private:
protected:
public:
    userData()
    {
        cout << "기본 생성자\n";
        this->x = 0;
    }
    userData(int _x)
    {
        cout << "함수 중복 생성자\n";
        this->x = _x;
    }
    ~userData()
    {
        cout << "기본 소멸자\n";
    }
    void SetX(int _x)
    {
        this->x = _x;
    }
    int GetX(void)
    {
        return this -> x;
    }
    void printDataX(void)
    {
        cout << this->x << endl;
    }
};

int main(void){
    userData a, b(10);
    
    a.SetX(20);


    cout << a.GetX() << endl;
    cout << b.GetX() << endl;

    
    a.printDataX();
    b.printDataX();

    
    return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;

class userData{
    
private:
    static int cnt;
    int x;
protected:
public:

private:
protected:
public:
    userData();
    userData(int);
    ~userData();
    void SetX(int);
    int GetX(void);
    static int GetCnt(void);
    void printDataX(void);
};

userData::userData()
{
    cout << "기본 생성자\n";
    cnt++;
    this->x = 1;
}
userData::userData(int _x)
{
    cout << "함수 중복 생성자\n";
    this->x = _x;
}
userData::~userData()
{
    cout << "기본 소멸자\n";
}
void userData::SetX(int _x)
{
    this->x = _x;
}
int userData::GetX(void)
{
    return this -> x;
}
int userData::GetCnt(void)
{
    return cnt;
}
void userData::printDataX(void)
{
    cout << this->x << endl;
}

int userData::cnt = 0;

int main(void){
    userData a, b;

    cout << a.GetX() << endl;
    cout << userData::GetCnt() << endl;
    cout << a.GetCnt() << endl;
    cout << b.GetCnt() << endl;

    
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

class userData{
    
private:
    static int cnt;
    int x;
protected:
public:

private:
protected:
public:
    userData()
    {
        cout << "기본 생성자\n";
        cnt++;
        this->x = 1;
    }
    userData(int _x)
    {
        cout << "함수 중복 생성자\n";
        this->x = _x;
    }
    ~userData()
    {
        cout << "기본 소멸자\n";
    }
    void SetX(int _x)
    {
        this->x = _x;
    }
    int GetX(void)
    {
        return this -> x;
    }
    static int GetCnt(void)
    {
        return cnt;
    }
    void printDataX(void)
    {
        cout << this->x << endl;
    }
};
int userData::cnt = 0;

int main(void){
    userData a, b;

    cout << a.GetX() << endl;
    cout << userData::GetCnt() << endl;
    cout << a.GetCnt() << endl;
    cout << b.GetCnt() << endl;

    
    return 0;
}
#endif



#if 0
#include <iostream>
using namespace std;

class userData{
    
private:
    int x;
protected:
public:

private:
protected:
public:
    userData()
    {
        cout << "기본 생성자\n";
    }
    userData(int _x)
    {
        cout << "정수형 변환 생성자\n";
        this->x = _x;
    }
    userData(double _x)
    {
        cout << "함수 중복 생성자\n";
        this->x = (int)_x;
    }
    ~userData()
    {
        cout << "기본 소멸자\n";
    }
    void SetX(int _x)
    {
        this->x = _x;
    }
    void Display(void)
    {
        cout << "x = " << this->x << endl;
    }
};

int main(void){
    userData a;

    //a.x = 1;  //public
    //a.SetX(1);  //private
    a = 3;
    
    a.Display();
    
    return 0;
}
#endif


#if 0
#include <iostream>
using namespace std;

class userData{
    
private:
    int x;
protected:
public:

private:
protected:
public:
    userData();
    userData(int);
    userData(double);
    ~userData();
    void SetX(int);
    void Display(void);
};
userData::userData()
{
    cout << "기본 생성자\n";
}
userData::userData(int _x)
{
    cout << "정수형 변환 생성자\n";
    this->x = _x;
}
userData::userData(double _x)
{
    cout << "함수 중복 생성자\n";
    this->x = (int)_x;
}
userData::~userData()
{
    cout << "기본 소멸자\n";
}
void userData::SetX(int _x)
{
    this->x = _x;
}
void userData::Display(void)
{
    cout << "x = " << this->x << endl;
}
int main(void){
    userData a;

    //a.x = 1;  //public
    //a.SetX(1);  //private
    a = 3;
    
    a.Display();
    
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

class userData{
    
private:
    double x;
protected:
public:

private:
protected:
public:
    userData(double _x = 0.0)
    {
        cout << "기본 생성자\n";
        this -> x = _x;
    }
    operator double(void)
    {
        cout << "변환 함수 호출" << endl;
        return this->x;
    }
    ~userData(void)
    {
        cout << "기본 소멸자 호출" << endl;
    }
};

int main(void){
    userData a(1.0);
    double b = a;
    
    cout << (double)a << "\n";
    cout << "b = " << b << "\n";
    
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

class userData
{
private:
    double x;
protected:
public:
private:
protected:
public:
    userData(double _x = 0.0);
    operator double(void);
    ~userData(void);
};
userData::userData(double _x)
{
    cout << "기본 생성자" << endl;
    this->x = _x;
}
userData::operator double(void)
{
    cout << "변환 함수 호출1" << endl;
    return this->x;
}
userData::~userData(void)
{
    cout << "기본 소멸자 호출" << endl;
}

int main(void){
    userData a(1.0);
    double b = a;
    cout << (double)a << "\n";
    cout << "b = " << b << "\n";
    return 0;
}

#endif

#if 0
#include <iostream>
#include <string>
using namespace std;

class userData
{
public:
    char *pStr;
public:
    userData(char *str = NULL);
    userData(const userData& s);
    ~userData();
    void Display();
};

userData::userData(char *str)
{
    cout << "생성자\n";
    if(str)
    {
        int len = strlen(str);
        pStr = new char[len + 1];
        strcpy(pStr, str);
    }
    else{
        pStr = NULL;
    }
}
userData::userData(const userData& s)
{
    cout << "복사 생성자\n";
    int len = strlen(s.pStr);
    pStr = new char[len+1];
    strcpy(pStr, s.pStr);
}
userData::~userData(){
    cout << "소멸자\n";
    delete pStr;
}
void userData::Display()
{
    if(pStr)
    {
        cout << pStr << "\n";
    }
}
int main(void){
    userData s1("abcd");
    userData s2 = s1;
    s1.Display();
    s2.Display();
    return 0;
}
#endif


#if 0
#include <iostream>
#include <string>
using namespace std;

class userData
{
public:
    char *pStr;
public:
    userData(char *str = NULL);
    userData(const userData& s);
    ~userData();
    userData operator+(const userData& s);
    userData& operator=(const userData& s);
    void Display(void);
};

userData::userData(char *str)
{
    cout << "생성자\n";
    if(str)
    {
        int len = strlen(str);
        pStr = new char[len + 1];
        strcpy(pStr, str);
    }
    else{
        this ->pStr = NULL;
    }
}
userData::userData(const userData& s)
{
    cout << "복사 생성자\n";
    int len = strlen(s.pStr);
    pStr = new char[len+1];
    strcpy(pStr, s.pStr);
}
userData::~userData(){
    cout << "소멸자\n";
    delete pStr;
}
void userData::Display(void)
{
    if(pStr)
    {
        cout << pStr << "\n";
    }
}
userData userData::operator+(const userData& s)
{
    cout << "+연산자 함수" << endl;
    userData tmpObj;
    int len = strlen(pStr) + strlen(s.pStr);
    tmpObj.pStr = new char[len + 1];
    strcpy(tmpObj.pStr, pStr);
    strcat(tmpObj.pStr, s.pStr);
    return tmpObj;
}
userData& userData::operator=(const userData& s)
{
    cout << "연산자 함수 =" << endl;
    delete pStr;
    int len = strlen(s.pStr);
    pStr = new char[len + 1];
    strcpy(pStr, s.pStr);
    return *this;
}

int main(void){
    userData s1("abcd");
    userData s2("efg");
    userData s3, s4, s5;
    
    s3 = s1 + s2;
    s5 = s4 = s1;
    
    s1.Display();
    s2.Display();
    s3.Display();
    s4.Display();
    s5.Display();
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
class Point{
    int x;
    int y;
public:
//    Point()
//    {
//        x = 0;
//        y = 0;
//    }
//    Point(int _x, int _y)
//    {
//        x = _x;
//        y = _y;
//    }
    Point(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }
    void Print(void)
    {
        cout << x << ',' << y << endl;
    }
    Point operator+(Point &arg)
    {
        Point pt;
        pt.x = this->x + arg.x;
        pt.y = this->y + arg.y;
        return pt;
    }
};

int main(){
    Point p1(2,3), p2(5,5);
    Point p3;
    
    p3 = p1 + p2;
    p3.Print();
    p3 = p1.operator+(p2);
    p3.Print(); 
    
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
class Point{
    int x;
    int y;
public:
//    Point()
//    {
//        x = 0;
//        y = 0;
//    }
//    Point(int _x, int _y)
//    {
//        x = _x;
//        y = _y;
//    }
    Point(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }
    void Print(void)
    {
        cout << "(" << x << ',' << y << ")" << endl;
    }
//    Point operator+(Point &arg)
//    {
////        Point pt;
////        pt.x = this->x + arg.x;
////        pt.y = this->y + arg.y;
////        return pt;
//    }
    void operator++(){
        
    }
    void operator++(int){
        
    }
};

int main(){
    Point p1(2,3), p2(5,5);
    ++p1;
    p2++;
    
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
class Point{
    int x;
    int y;
public:
//    Point()
//    {
//        x = 0;
//        y = 0;
//    }
//    Point(int _x, int _y)
//    {
//        x = _x;
//        y = _y;
//    }
    Point(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }
    void Print(void)
    {
        cout << "(" << x << ',' << y << ")" << endl;
    }
    const Point& operator++()
    {
        (this->x)++;
        (this->y)++;
        return *this;
    }
    const Point operator++ (int)
    {
        Point pt(x,y);
        ++(this->x);
        ++(this->y);
        return pt;
    }
    const Point& operator--()
    {
        (this->x)--;
        (this->y)--;
        return *this;
    }
    const Point operator--(int)
    {
        Point pt(x,y);
        --(this->x);
        --(this->y);
        return pt;
    }
    
};

int main(){
    Point p1(2,3), p2(5,5);
    Point result;
    result == --p1;
    cout << "전위: ";
    p1.Print();
    result.Print();
    
    result == --p2;
    cout << "후위: ";
    p2.Print();
    result.Print();
    
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;
class Point{
    int x;
    int y;
public:
//    Point()
//    {
//        x = 0;
//        y = 0;
//    }
//    Point(int _x, int _y)
//    {
//        x = _x;
//        y = _y;
//    }
    Point(int _x = 0, int _y = 0)
    {
        x = _x;
        y = _y;
    }
    void Print() const
    {
        cout << "(" << x << ',' << y << ")" << endl;
    }
    bool operator== (const Point& arg) const{
        if(this->x == arg.x && this-> y == arg.y)
        {
            return true;
        }
        else{
            return false;
        }
    }
    bool operator != (const Point& arg) const
    {
        return !(*this == arg);
    }
    
};

int main(){
    Point p1(2,3), p2(5,5), p3(2,3);
    
    if(p1 == p2){
        cout << "p1 == p2" << endl;
    }
    if(p1 == p3){
        cout << "p1 == p3" << endl;
    }
    if(p1 != p2){
        cout << "p1 != p2" << endl;
    }
    if(p1 != p3){
        cout << "p1 != p3" << endl;
    }
    
    return 0;
}
#endif

#if 0
#include <iostream>
using namespace std;

struct FuncObject
{
private:
protected:
public:
private:
protected:
public:
    void operator()(int arg)const{
        cout << "정수: " << arg << endl;
    }
};
void Print1(int arg){
    cout << "정수 : " << arg << endl;
}
int main(){
    Print1(10);
    void(*Print2)(int) = Print1;
    Print2(20);
    FuncObject Print3;
    Print3(20);
}
#endif

#if 0
#include <iostream>
using namespace std;

class Point
{
private:
    int x, y;
protected:
public:
private:
protected:
public:
    Point(int _x, int _y){
        x = _x;
        y = _y;
    }
    void Print() const
    {
        cout << this -> x << ", " << this -> y << endl;
    }
    int operator[](int idx) const
    {
        if(idx == 0){
            return x;
        }
        else if(idx == 1){
            return y;
        }
        else{
            throw "예외상황";
        }
    }
};

int main(void){
    Point pt(1,2);
    pt.Print();
    cout << pt[0] << ", " << pt[1] << endl;
    
    cout << pt.operator[](0) << endl;
    cout << pt.operator[](1) << endl;
    
    return 0; 
}
#endif

#if 0
#include <iostream>
using namespace std;
class Point
{
private:
    int x, y;
protected:
public:
    
private:
protected:
public:
    Point(int _x, int _y)
    {
        this->x = _x;
        this->y = _y;
    }
    ~Point(void)
    {
        cout << "메모리 해제" << endl;
    }
    void print(void)const
    {
        cout << "(" << this->x << ", " << this->y << ")" << endl;
    }
};
int main(void){
    Point *p1, *p2;
    p1 = new Point(2,3);
    p2 = new Point(5,5);
    
    p1->print();
    p2->print();
    
    delete p1;
    delete p2;
    
    return 0;
}
#endif

