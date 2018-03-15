#ifndef TR1FUNCTION_H
#define TR1FUNCTION_H
#include <memory>
#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <functional>

using namespace std;

class GameCharacter;
int defaultHealthCalc(const GameCharacter& gc);
class GameCharacter
{
public:
	typedef std::tr1::function<int (const GameCharacter&)> HealthCalcFunc;//其实就是特定的函数指针，可以当成函数指针来进行使用
	explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc) :healthFunc(hcf){}
	int healthValue() const
	{
		return healthFunc(*this);
	}
private:
	HealthCalcFunc healthFunc;
};
//但是这里我要使用更简单的验证来进行function的特性使用了
typedef std::tr1::function<void()> Func;//声明一个返回类型为空 无参数的函数指针
typedef std::tr1::function<void (int)> Func2;//声明一个返回类型为空 只有一个int参数的函数指针

int CalSum(int a, int b){
	printf("%d + %d = %d\n", a, b, a + b);

	return a + b;
}
class Animal{
public:
	Animal(){}
	~Animal(){}

	void Move(){}
};
class Bird : public Animal{
public:
	Bird(){}
	~Bird(){}

	void Move(){
		std::cout << "I am flying...\n";
	}
};
class Fish : public Animal{
public:
	Fish(){}
	~Fish(){}
	//const成员方法，类方法不会修改调用对象 ，比如 Obj_Animal.Move()不会修改调用对象 Obj_Animal.Move
	void Move() const{
		std::cout << "I am swimming...\n";
	}

	void Say(int hour){
		std::cout << "I have swimmed " << hour << " hours.\n";
	}
};

struct structTest
{
	int param1;
	//int param2;
	union param //在union中的各个类型都是共用一个内存空间，只是名字不同，大小取最大的。
	{
		unsigned int param_0;
		struct parameter
		{
			unsigned int param_1 : 16;
			unsigned int param_2 : 16;
		}parameter_val;
	}param_val;
};

enum class bits{one = 1,two = 2,three = 100};
//enum { one1 = 1, two2 = 2, three3 = 99 };
#endif