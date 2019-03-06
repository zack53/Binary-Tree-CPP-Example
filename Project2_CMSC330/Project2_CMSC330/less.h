/*File: less.h
 *Author: Zackary Scott
 *Date: 7-12-2018 
 *Purpose: compares left and right expression with
 *the < operator.
 */
#pragma once
class Less : public SubExpression
{
public:
	Less(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return left->evaluate() < right->evaluate();
	}
};