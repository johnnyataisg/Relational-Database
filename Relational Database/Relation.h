#pragma once
#ifndef RELATION_H_
#define RELATION_H_
#include "Tuple.h"
#include "Header.h"

using namespace std;

class Relation
{
private:
	string name;
	Header header;
	set<Tuple> tuples;
public:
	Relation() {};

	Relation(string str, Header hdr)
	{
		name = str;
		header = hdr;
	}

	~Relation() {};
	
	void addTuple(Tuple tpl)
	{
		tuples.insert(tpl);
	}

	string getName()
	{
		return this->name;
	}

	string toString()
	{
		string output;
		for (Tuple tup : tuples)
		{
			for (size_t i = 0; i < tup.size(); i++)
			{
				output += header.at(i) + "=" + tup.at(i);
				if (i != tup.size() - 1)
				{
					output += ", ";
				}
			}
			output += "\n";
		}
		return output;
	}
	//S='12345', N='Charlie', A='12 Apple St.', P='555-1234'
};

#endif