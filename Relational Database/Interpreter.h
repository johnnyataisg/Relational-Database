#pragma once
#ifndef INTERPRETER_H_
#define INTERPRETER_H_
#include "Database.h"

using namespace std;

class Interpreter
{
private:
	DatalogProgram datalog;
	Database database;
public:
	Interpreter() {};

	Interpreter(DatalogProgram datalogProgram)
	{
		this->datalog = datalogProgram;
		this->database = Database(datalogProgram);
	}

	~Interpreter() {};

	Database getDatabase()
	{
		return this->database;
	}

	Relation runQuery()
	{
		Predicate pred = datalog.getQueries().front();
		Relation relation = database[pred.getID()];
		map<string, int> rpMap;
		vector<string> rename;
		for (size_t i = 0; i < pred.getParamList().size(); i++)
		{
			string value = pred.getParamList().at(i)->toString();
			if (pred.getParamList().at(i)->isConstant())
			{
				relation.select(i, value);
			}
			else if (rpMap.find(value) == rpMap.end())
			{
				rpMap.insert(pair<string, int>(value, i));
				rename.push_back(value);
			}
			else
			{
				int index = rpMap[value];
				for (Tuple tpl : relation.getTuples())
				{
					string value2 = tpl.at(index);
					if (tpl.at(i) != value2)
					{
						relation.deleteTuple(tpl);
					}
				}
			}
		}
		relation.project(rpMap);
		relation.rename(rename);
		return relation;
	}
};

#endif