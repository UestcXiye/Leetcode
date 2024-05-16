#include <iostream>
#include <string>
#include <stdlib.h>
using namespace std;

class Expression
{
public:
	virtual double evaluate() = 0;
};

class Number : public Expression
{
private:
	double val;

public:
	Number(double v) : val(v){};

	virtual double evaluate()
	{
		return val;
	}
};

class Operator : public Expression
{
protected:
	Expression *left;
	Expression *right;

public:
	Operator(Expression *l, Expression *r) : left(l), right(r){};
};

class AddOperator : public Operator
{
public:
	AddOperator(Expression *l, Expression *r) : Operator(l, r){};

	virtual double evaluate()
	{
		return left->evaluate() + right->evaluate();
	}
};

class SubOperator : public Operator
{
public:
	SubOperator(Expression *l, Expression *r) : Operator(l, r){};

	virtual double evaluate()
	{
		return left->evaluate() - right->evaluate();
	}
};

class MultOperator : public Operator
{
public:
	MultOperator(Expression *l, Expression *r) : Operator(l, r){};

	virtual double evaluate()
	{
		return left->evaluate() * right->evaluate();
	}
};

class DivideOperator : public Operator
{
public:
	DivideOperator(Expression *l, Expression *r) : Operator(l, r){};

	virtual double evaluate()
	{
		if (right->evaluate())
			return left->evaluate() / right->evaluate();
		else
			return -1;
	}
};

int main()
{
	// 构建一个算数表达式: (2 + 3) * 4 - 20 / 5
	Expression *expression = new SubOperator(
		new MultOperator(
			new AddOperator(new Number(2), new Number(3)), new Number(4)),
		new DivideOperator(new Number(20), new Number(5)));

	// 计算表达式的结果
	double result = expression->evaluate();
	cout << "(2 + 3) * 4 - 20 / 5 = " << result << endl;

	system("pause");
	return 0;
}
