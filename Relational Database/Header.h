#pragma once
#ifndef HEADER_H_
#define HEADER_H_

using namespace std;

class Header : public vector<string>
{
private:
public:
	Header() {};

	Header(vector<Parameter*> vec)
	{
		for (Parameter* param : vec)
		{
			this->push_back(param->toString());
		}
	}

	~Header() {};
};

#endif