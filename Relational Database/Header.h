#pragma once
#ifndef HEADER_H_
#define HEADER_H_

using namespace std;

class Header
{
private:
	vector<string> header;
public:
	Header() {};

	~Header() {};

	void addString(Parameter* param)
	{
		this->header.push_back(param->toString());
	}

	string at(size_t index)
	{
		return header.at(index);
	}

	size_t size()
	{
		return this->header.size();
	}

	vector<string> getHeader()
	{
		return this->header;
	}
};

#endif