/*File: subexpression.cpp
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: Subexpression uses switch statement to evaulate the data.
 */
#include <iostream>
#include <sstream>
using namespace std;
#include "expression.h"
#include "subexpression.h"
#include "operand.h"
#include "plus.h"
#include "minus.h"
#include "times.h"
#include "divide.h"
#include "and.h"
#include "greater.h"
#include "less.h"
#include "equal.h"
#include "or.h"
#include "negation.h"
#include "ternary.h"

SubExpression::SubExpression(Expression* left, Expression* right)
{
	this->left = left;
	this->right = right;
}
Expression* SubExpression::parse(stringstream& linestr)
{
	Expression* left;
	Expression* right;
	Expression* cond;

	char operation, paren;

	left = Operand::parse(linestr);
	linestr >> operation;
	if (operation == '!') {
		linestr >> paren;
		return new Negation(left, NULL);
	}else if (operation == ':') {
		right = Operand::parse(linestr);
		linestr >> paren;
		cond = Operand::parse(linestr);
		linestr >> paren;
		return new Ternary(left, right, cond);
	}
	else {
		right = Operand::parse(linestr);
		linestr >> paren;
		switch (operation)
		{
		case '+':
			return new Plus(left, right);
		case '-':
			return new Minus(left, right);
		case '*':
			return new Times(left, right);
		case '/':
			return new Divide(left, right);
		case '&':
			return new And(left, right);
		case '>':
			return new Greater(left, right);
		case '<':
			return new Less(left, right);
		case '=':
			return new Equal(left, right);
		case '|':
			return new Or(left, right);
		}
	}
	return 0;
}