/*File: negation.h
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: allows for the use of
 *the ! operator.
 */
#pragma once
class Negation : public SubExpression
{
public:
	Negation(Expression* left, Expression* right) :
		SubExpression(left, right)
	{
	}
	int evaluate()
	{
		return !(left->evaluate());
	}
};