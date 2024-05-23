#include <iostream>
#include <string>
#include <unordered_map>
#include <stdlib.h>
using namespace std;

// 抽象原型类
class Prototype
{
public:
	virtual Prototype *clone() = 0;
	virtual void draw() = 0;
};

// 具体的矩阵类
class RectanglePrototype : public Prototype
{
	// 成员属性
private:
	string m_strTypeName;

	// 成员函数
public:
	RectanglePrototype(string name) : m_strTypeName(name){};

	// 重载克隆函数接口
	Prototype *clone() override
	{
		return new RectanglePrototype(*this);
	}
	void draw() override
	{
		cout << "Inside Rectangle::draw() method." << endl;
	}
	void setName(const string &name)
	{
		m_strTypeName = name;
	}
	string getName() const
	{
		return m_strTypeName;
	}
};

// 具体的正方形类
class SquarePrototype : public Prototype
{
	// 成员属性
private:
	string m_strTypeName;

	// 成员函数
public:
	SquarePrototype(string name) : m_strTypeName(name){};

	// 重载克隆函数接口
	Prototype *clone() override
	{
		return new SquarePrototype(*this);
	}
	void draw() override
	{
		cout << "Inside Square::draw() method." << endl;
	}
	void setName(const string &name)
	{
		m_strTypeName = name;
	}
	string getName() const
	{
		return m_strTypeName;
	}
};

// 具体的圆形类
class CirclePrototype : public Prototype
{
	// 成员属性
private:
	string m_strTypeName;

	// 成员函数
public:
	CirclePrototype(string name) : m_strTypeName(name){};

	// 重载克隆函数接口
	Prototype *clone() override
	{
		return new CirclePrototype(*this);
	}
	void draw() override
	{
		cout << "Inside Circle::draw() method." << endl;
	}
	void setName(const string &name)
	{
		m_strTypeName = name;
	}
	string getName() const
	{
		return m_strTypeName;
	}
};

class PrototypeRegistry
{
private:
	unordered_map<string, Prototype *> items;

public:
	void addItem(string id, Prototype *p)
	{
		items[id] = p;
	}
	Prototype *getById(string id)
	{
		return items[id]->clone();
	}
};

int main()
{
	RectanglePrototype *rect = new RectanglePrototype("Rectangle");
	SquarePrototype *square = new SquarePrototype("Square");
	CirclePrototype *circle = new CirclePrototype("Circle");
	PrototypeRegistry *prototypeRegistry = new PrototypeRegistry();

	prototypeRegistry->addItem("1", rect);
	prototypeRegistry->addItem("2", square);
	prototypeRegistry->addItem("3", circle);

	RectanglePrototype *clonedRect = (RectanglePrototype *)prototypeRegistry->getById("1");
	clonedRect->setName("my rectangle");
	cout << clonedRect->getName() << endl;
	clonedRect->draw();

	delete prototypeRegistry;
	delete rect;
	delete square;
	delete circle;
	delete clonedRect;

	system("pause");
	return 0;
}
