/*
*
* NTUT 109 Problem 3
*
*/

#include <iostream>
using namespace std;

class B{
private:
  int a;
public:
  void f();
  virtual void g();
  ~B();
  int get(){
    return a;
  }
  void set(int v){
    a = v;
  }
};

B::~B(){
  cout << "66" << endl;
}

void B::f(){
  cout << "11" << endl;
}

void B::g(){
  cout << "22" << endl;
}

class D:public B{
private:
  int b;
public:
  void f();
  void g(); 
  ~D();
  D(){
    set(1); b = 2;
  }
  int getA(){
    return get();
  }
  int getB(){
    return b;
  }
};

D::~D(){
  cout << "99" << endl;
}

void D::f(){
  cout << "33" << endl;
}

void D::g(){
  cout << "44" << endl;
}

void f(B& p){
  p.f();
}

void g(B& p){
  p.g();
}

int main() {
  B b;
  D d;
  b.f();
  d.f();
  f(d);
  g(d);  

  B *b1, *b2;
  b1 = new B;
  b2 = new D;
  b1->f();
  b2->f();
  b1->g();
  b2->g();
  
  std::cout << "Hello World!\n";
  delete b1;
  std::cout << "Hello World!\n";
  delete b2;
}