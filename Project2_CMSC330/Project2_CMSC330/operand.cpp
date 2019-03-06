/*File: operand.cpp
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: Creates an operand as a literal or as a variable.
 */
#include <cctype>
#include <iostream>
#include <sstream>
#include <list>
#include <string>
using namespace std;
#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "variable.h"
#include "literal.h"
#include "parse.h"

Expression* Operand::parse(stringstream& linestr)
{
	char paren;
	int value;

	linestr >> ws;
	if (isdigit(linestr.peek()))
	{
		linestr >> value;
		Expression* literal = new Literal(value);
		return literal;
	}
	if (linestr.peek() == '(')
	{
		linestr >> paren;
		return SubExpression::parse(linestr);
	}
	else
		return new Variable(parseName(linestr));
	return 0;
}