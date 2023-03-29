/*
*
* NTUT 111 Problem 5
*
*/

#include <stdio.h>
#include <iostream>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;
template <class T>

string print(T x){
	return x.getName();
}

class Pet{
protected:
	double _weight;
	string _name;
public:
	Pet(double weight,string name){
		_weight = weight;
		_name = name;
	}
	double getWeight(){
		return _weight;
	}
	virtual string getName() const = 0;
	virtual ~Pet(){ }
};

class Cat:public Pet{
private:
	vector<string> _toy;
	bool static sortedByAlph(string a,string b){
		return a[0] > b[0];
	}
public:
	Cat(double weight,string name) : Pet(weight,name) { }
	~Cat() override { }
	void addToy(string toy){
		_toy.push_back(toy);
		sort(_toy.begin(), _toy.begin() + _toy.size(), sortedByAlph);
	}
	string getToy(int index){
		return "cat's toy::" + _toy.at(index);
	}
	string getName() const override{
		return "cat::" + _name;
	}
};

class Bird:public Pet{
private:
	double _canFly;
public:
	Bird(double weight, string name,bool canFly):Pet(weight,name){
		_canFly = canFly;
	}
	~Bird() override { }
	string getName() const override{
		return "bird::" + _name;
	}
};

int main(){
	Cat diang(8.0, "diang");
	Cat *siang = new Cat(5.0, "siang");
	Bird spar(0.6,"loudly",true);
	diang.addToy("tshirt");
	diang.addToy("ball");
	diang.addToy("human");
	siang->addToy("cockroach");
	siang = &diang;
	cout << print<Cat>(diang) << endl;
	cout << siang->getToy(0) << endl;
	cout << print<Cat>(*siang) << endl;
	return 0;
}
