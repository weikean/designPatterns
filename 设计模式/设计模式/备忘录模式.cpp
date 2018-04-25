#include <cstdio>
#include <iostream>
#include <vector>
using namespace std;
/* 备忘录模式是在不破坏封装的前提下，新建一个外部类去存储当前类的状态，
 * 并在必要的时候恢复它 
 */

class Mememto
{
public:
	Mememto(string state)
	{
		this->state = state;
	}

	string getState()
	{
		return state;
	}
private:
	string state;
};

class CareTaker
{
private:	
	vector<Mememto> *vec = new vector<Mememto>();

public:
	void add(Mememto state)
	{
		vec->push_back(state);
	}

	Mememto get(int index)
	{
		return vec->at(index);
	}
};

class Originator
{
public:
	void setState(string state)
	{
		this->state = state;
	}

	string getState()
	{
		return state;
	}

	Mememto saveStateToMem()
	{
		Mememto mem(state);
		return mem;
	}

	void getStateFromMem(Mememto mememto)
	{
		state = mememto.getState();
	}

private:
	string state;
};

int main()
{
	Originator *originator = new Originator();
	CareTaker *careTaker = new CareTaker();
	originator->setState("State #1");
	originator->setState("State #2");
	careTaker->add(originator->saveStateToMem());
	originator->setState("State #3");
	careTaker->add(originator->saveStateToMem());
	originator->setState("State #4");

	return 0;
}