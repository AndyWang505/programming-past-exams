/*
*
* NTUT 108 Problem 3
*
*/

#include <iostream>
using namespace std;
class Number{
 private:
  int a;
 public:
  Number():a(7){}
  int getA(){return a;}
  int get(){return a;}
  int * getAaddress(){return &a;}
  int setA(int v){a = v;}
};
class Complex : public Number{
 private:
  int *b;
 public:
  Complex(){
   setA(4);
   b = new int(5); 
  }
  Complex(int x,int y){
   setA(x);
   b = new int(y);
  }
  int *getB(){return b;}
  int get(){return b[0];}
  void setB(){b = getAaddress();}
  void setB(int v){b[0] = v;}
  
  int getSum(){
   return getA() + *b;
  }
  Complex *foo(){
   return new Complex(6,7);
  }
  void foo(Complex &c){
   c = Complex(8,9);
  }
  Complex foo(Complex *c1, Complex &c2){
   return Complex(c1->getA()+
   c2.getA(),*c1->getB()+*c2.getB());
  }
};
int main(){
 Number *r = new Complex(8,9);
 cout<<r->get()<<endl;
}

