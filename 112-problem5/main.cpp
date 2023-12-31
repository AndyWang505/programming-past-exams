/*
*
* NTUT 112 Problem 5
*
*/

#include <vector>
#include <iostream>
#include <algorithm>
#include <string>
using namespace std;

class RedTea {
    protected:
        string _name = "Unknown";
        int _price = 0;
        double _content = 0;
    public:
        RedTea() = default;
        RedTea(string name, int price, double content) : _name(name), _price(price), _content(content) {}
        virtual ~RedTea() {};
        virtual void dilute() = 0;
        int get_price() const {
            return _price;
        }
        string get_name() const {
            return _name;
        }
        double get_alcohol_content() const {
            return _content;
        }
};

class LongIsland : public RedTea {
    public:
        LongIsland() = default;
        LongIsland(string name, int price, double alcohol_content) : RedTea(name, price, alcohol_content) {}
        ~LongIsland() = default;
        void dilute() override {
            this->_content *= 0.7;
        }
};

class NewBloodyMary;
static NewBloodyMary CreateNewBloodyMary(string name, int price, double content);

class NewBloodyMary : public RedTea {
    friend NewBloodyMary CreateNewBloodyMary(string name, int price, double content);
    private:
        NewBloodyMary(string name, int price, double content) : RedTea(name, price, content) {}
    public:
        NewBloodyMary() = default;
        ~NewBloodyMary() = default;
        void dilute() override {
            this->_content *= 0.95;
        }
        static NewBloodyMary* CreateNewBloodyMaryPry(string name, int price, double content) {
            return new NewBloodyMary(name, price, content);
        }
        NewBloodyMary& operator = (const NewBloodyMary& other) {
            this->_name = other._name;
            this->_price = other._price;
            this->_content = other._content;
            return *this;
        }
        NewBloodyMary operator+(const NewBloodyMary& other) {
            return NewBloodyMary(this->_name, this->_price + other._price, (this->_content + other._content)/2);
        }
};

static NewBloodyMary CreateNewBloodyMary(string n, int p, double c) {
    return NewBloodyMary(n, p, c);
}

class Order {
    private:
        std::vector<RedTea*> vec;
    public:
        Order() = default;
        ~Order() {
            for (int i=0; i<vec.size(); i++) {
                delete vec[i];
            }
        }
        void append_alcohol(RedTea* alcohol) {
            vec.push_back(alcohol);
        }
        int get_total_price() {
            int total = 0;
            for (int i=0; i<vec.size(); i++) {
                total += vec[i]->get_price();
            }
            return total;
        }
};

int main() {
    Order order;
    order.append_alcohol(NewBloodyMary::CreateNewBloodyMaryPry("A", 870, 0.7));
    order.append_alcohol(new LongIsland("B", 230, 0.7));
    vector<RedTea*> alcohol_vec = {new LongIsland("C", 77, 0.7),
    NewBloodyMary:: CreateNewBloodyMaryPry("D", 88, 0.8),
    NewBloodyMary:: CreateNewBloodyMaryPry("E", 12, 0.8)};
    std::sort(alcohol_vec.begin(), alcohol_vec.end(), [](RedTea* a, RedTea* b) { return a->get_price() < b->get_price(); });
    NewBloodyMary H = CreateNewBloodyMary("F", 90, 0.8) + CreateNewBloodyMary("G", 10, 0.8);
    cout << alcohol_vec.at(0) -> get_price() << endl;
    cout << alcohol_vec.at(1) -> get_price() << endl;
    cout << order.get_total_price() << endl;
    cout << H.get_name() << endl;
    cout << H.get_price() << endl;
    cout << H.get_alcohol_content() << endl;
    return 0;
}