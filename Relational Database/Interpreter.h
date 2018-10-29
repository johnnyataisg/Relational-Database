#pragma once
#ifndef INTERPRETER_H_
#define INTERPRETER_H_

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
};

#endif