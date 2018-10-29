#pragma once
#ifndef TUPLE_H_
#define TUPLE_H_


using namespace std;

class Tuple
{
private:
	string first;
	vector<string> tuple;
public:
	Tuple() {};
	~Tuple() {};

	friend bool operator <(Tuple x, Tuple y) 
	{
		return x.getFirst() < y.getFirst();
	}

	string getFirst()
	{
		return this->first;
	}

	string at(size_t index)
	{
		return tuple.at(index);
	}

	size_t size()
	{
		return this->tuple.size();
	}

	void addString(string str)
	{
		tuple.push_back(str);
	}
};

#endif