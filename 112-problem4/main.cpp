/*
*
* NTUT 112 Problem 4
*
*/

#include <iostream>
#include <string>
using namespace std;

class Animal {
    public:
        void makeSound() { cout << "animal sound" << endl; };
        virtual void food() { cout << "water" << endl; }; //virtual function
        virtual string getColor() = 0; //pure virtual function
};

class Cat : public Animal {
    private:
        string color;
    public:
        Cat(string co = "white"): color(co) {};
        Cat(const Cat& a) {
            color = a.color;
        };
        void makeSound() { cout << "cat sound" << endl; };
        virtual void food() { cout << "mouse" << endl; };
        virtual string getColor() { return color; };
        Cat operator + (Cat &other) {
            return Cat(getColor() + other.getColor());
        }
};

int main() {
    Animal *p1 = new Cat("black");
    Cat *p2 = new Cat();
    Cat cat = Cat("silver") + *p2;
    cout << cat.getColor() << endl;
    p1->makeSound();
    p1->food();
    p2->makeSound();
    p2->food();
}