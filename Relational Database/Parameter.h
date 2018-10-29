#pragma once
#ifndef PARAMETER_H_
#define PARAMETER_H_

using namespace std;

class Parameter
{
private:
	string value;
	string type;
public:
	Parameter() {};
	virtual ~Parameter() {};
	virtual string toString() = 0;
};

#endif