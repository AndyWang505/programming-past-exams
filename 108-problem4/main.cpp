#include <iostream>
using namespace std;

class N{
    public:
        N():np(new int[5]){}
        ~N(){
            delete np;
        }
    private:
        int *np;
};

class NChild:public N{
    public:
        NChild():N(),ncp(new int[1000]){
        }
        ~NChild(){
            delete ncp;
        }
    private:
        int *ncp;
};

class Fibonacci:public N{
    public:
        Fibonacci(int n){
            p = new int[n];
            setFibonacci(n);
        }
        ~Fibonacci(){ delete [] p; }
        int sumFibonacci(int n){
            int sum = 0;
            for(int i=0; i<n; i++){
                sum += p[i];
            }
            return sum;
        }
        void incrementFibonacci(int n){
            for(int i=0; i<n; i++){
                p[i] += n;
            }
        }
    private:
        int *dp;
        int *p;

        void setFibonacci(int n){
            if(n > 2){
                p[0] = 1;
                p[1] = 1;
                for(int i=2; i<n; i++){
                    p[i] = p[i-1]+p[i-2];
                }
            }
        }
};

int main(){
    for(int i=0; i<100; i++){
        N *p = new NChild;
        delete p;
    }
    Fibonacci f(5);
    cout << f.sumFibonacci(5) << endl;

    f.incrementFibonacci(2);
    cout << f.sumFibonacci(5) << endl;
    return 0;
}