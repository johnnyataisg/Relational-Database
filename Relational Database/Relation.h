#pragma once
#ifndef RELATION_H_
#define RELATION_H_
#include "Tuple.h"
#include "Header.h"
#include <map>

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

	Relation(Predicate pred, vector<Predicate> facts)
	{
		Header hdr(pred.getParamList());
		this->name = pred.getID();
		this->header = hdr;
		for (Predicate pred : facts)
		{
			if (pred.getID() == this->name)
			{
				Tuple tuple(pred.getParamList());
				this->addTuple(tuple);
			}
		}
	}

	~Relation() {};
	
	void addTuple(Tuple tpl)
	{
		tuples.insert(tpl);
	}

	void deleteTuple(Tuple tpl)
	{
		tuples.erase(tpl);
	}

	string getName()
	{
		return this->name;
	}

	void select(int col, string val)
	{
		for (Tuple tpl : getTuples())
		{
			if (tpl.at(col) != val)
			{
				this->deleteTuple(tpl);
			}
		}
	}

	void rename(vector<string> vec)
	{
		for (size_t i = 0; i < vec.size(); i++)
		{
			this->header.at(i) = vec.at(i);
		}
	}

	void project(vector<int> indexes)
	{
		Header newHeader;
		set<Tuple> newTuples;
		for (int index : indexes)
		{
			newHeader.push_back(header.at(index));
		}
		for (Tuple tpl : tuples)
		{
			Tuple tuple;
			for (int index : indexes)
			{
				tuple.push_back(tpl.at(index));
			}
			newTuples.insert(tuple);
		}
		this->header = newHeader;
		this->tuples = newTuples;
	}

	Header getHeader()
	{
		return this->header;
	}

	set<Tuple> getTuples()
	{
		return this->tuples;
	}

	string toString()
	{
		string output;
		for (Tuple tup : tuples)
		{
			for (size_t i = 0; i < header.size(); i++)
			{
				if (i == 0)
				{
					output += "  ";
				}
				output += header.at(i) + "=" + tup.at(i);
				if (i != header.size() - 1)
				{
					output += ", ";
				}
				else
				{
					output += "\n";
				}
			}
		}
		return output;
	}
};

#endif