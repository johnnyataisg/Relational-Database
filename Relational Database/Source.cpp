#include <iostream>
#include <fstream>
#include "LexicalAnalyzer.h"
#include "Parser.h"
#include "Interpreter.h"
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

		for (int i = 1; i < 11; i++)
		{
			stringstream ss;
			ss << i;
			string file = "test" + ss.str() + ".txt";
			string file2 = "output" + ss.str() + ".txt";
			ifstream inputFile(file);
			ifstream inputFile2(file2);
			cout << "Test " << ss.str() << ":\n";
			string line;
			string con;
			string con2;
			//Read all lines from the input file
			while (getline(inputFile, line))
			{
				con = con + line + "\n";
			}
			while (getline(inputFile2, line))
			{
				con2 = con2 + line + "\n";
			}

			LexicalAnalyzer lex(con);
			//Generate the list of tokens from the input file
			lex.generateList();
			//Copy the list of tokens into a vector of the parser object
			Parser parser(lex.getList());
			bool run = parser.parse();

			if (run)
			{
				Interpreter interpreter(parser.getDatalog());
				//cout << interpreter.getDatabase()["SK"].getName() << endl;
				//cout << (interpreter.getDatabase())["SK"].toString() << endl;

				Relation rel = interpreter.runQuery();
				string output2 = rel.toString();
				cout << output2 << endl;
				
				if (con2 == output2)
				{
					cout << "Success!" << endl;
				}
				else
				{
					cout << "Failure!" << endl;
				}

			}
		}
		system("pause");
		return 0;
}