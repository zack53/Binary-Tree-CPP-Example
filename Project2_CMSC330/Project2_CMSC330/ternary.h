/*File: ternary.h
 *Author: Zackary Scott
 *Date: 7-12-2018
 *Purpose: returns left->evaluate() if the value
 *is true and returns right->evaluate() if false.
 */
#pragma once
class Ternary : public SubExpression
{
public:
	Ternary(Expression* left, Expression* right, Expression* cond) :
		SubExpression(left, right)
	{
		this->cond = cond;
	}
	int evaluate()
	{
		return cond->evaluate() ? left->evaluate() : right->evaluate();
	}
private:
	Expression * cond;
};