/*File: Main.cpp
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: Contains main entry for program to get user
 *input and read a file into a binary tree.
 */
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <sstream>

using namespace std;

#include "expression.h"
#include "subexpression.h"
#include "symboltable.h"
#include "parse.h"

SymbolTable symbolTable;
void parseAssignments(stringstream& linestr);

int main()
{
	Expression* expression;
	char paren, comma, line[100];
	//gets user input for file
	string  text;
	cout << "Enter text file name: ";
	cin >> text;
	//opens text file
	ifstream file(text);
	//checks if file was open
	if (!file.is_open()) {
		exit(EXIT_FAILURE);
	}
	//loop runs while file has a line
	while (file.good()) 
	{
		//resets table
		symbolTable.resetElement();
		//gets line to be used in linestr
		file.getline(line, 100);
		stringstream linestr(line, ios_base::in);
		linestr >> paren;
		cout << line << " ";
		try 
		{
			expression = SubExpression::parse(linestr);
			linestr >> comma;
			parseAssignments(linestr);
			cout << "Value = " << expression->evaluate() << endl;
		}
		catch (exception) 
		{
			return EXIT_FAILURE;
		}
	}
	system("pause");
	return 0;
}//end of main
void parseAssignments(stringstream& linestr)
{
	char assignop, delimiter;
	string variable;
	int value;
	do
	{
		variable = parseName(linestr);
		linestr >> ws >> assignop >> value >> delimiter;
		symbolTable.insert(variable, value);
	} while (delimiter == ',');
}