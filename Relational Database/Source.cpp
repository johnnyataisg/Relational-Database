#include <iostream>
#include <fstream>
#include "LexicalAnalyzer.h"
#include "Parser.h"
#include "Relation.h"
#ifdef _MSC_VER
#define _CRTDBG_MAP_ALLOC  
#include <crtdbg.h>
#define VS_MEM_CHECK _CrtSetDbgFlag(_CRTDBG_ALLOC_MEM_DF | _CRTDBG_LEAK_CHECK_DF);
#else
#define VS_MEM_CHECK
#endif

using namespace std;

int main(int argc, char* argv[])
{
		VS_MEM_CHECK;

		ifstream inputFile(argv[1]);
		string line;
		string con;
		//Read all lines from the input file
		while (getline(inputFile, line))
		{
			con = con + line + "\n";
		}

		LexicalAnalyzer lex(con);
		//Generate the list of tokens from the input file
		lex.generateList();
		//Copy the list of tokens into a vector of the parser object
		Parser parser(lex.getList());
		parser.parse();

		vector<Relation> relations;
		vector<Predicate> schemes = parser.getDatalog().getSchemes();
		Header header;
		Tuple tuple;
		tuple.addString("Johnny");
		tuple.addString("Jina");
		for (Predicate pred : schemes)
		{
			for (Parameter* param : pred.getParamList())
			{
				header.addString(param);
			}
			Relation relation(pred.getID(), header);
			relation.addTuple(tuple);
			relations.push_back(relation);
		}

		for (Relation rel : relations)
		{
			cout << rel.toString() << endl;
		}

		system("pause");
		return 0;
}