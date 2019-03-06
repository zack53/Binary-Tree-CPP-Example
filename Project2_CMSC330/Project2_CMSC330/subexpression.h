/*File: subexpression.h
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: Subexpression uses switch statement to evaulate the data.
 */
#pragma once
class SubExpression : public Expression
{
public:
	SubExpression(Expression* left, Expression* right);
	static Expression* parse(stringstream& linestr);
protected:
	Expression * left;
	Expression* right;
};