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
	typedef std::tr1::function<int (const GameCharacter&)> HealthCalcFunc;//��ʵ�����ض��ĺ���ָ�룬���Ե��ɺ���ָ��������ʹ��
	explicit GameCharacter(HealthCalcFunc hcf = defaultHealthCalc) :healthFunc(hcf){}
	int healthValue() const
	{
		return healthFunc(*this);
	}
private:
	HealthCalcFunc healthFunc;
};
//����������Ҫʹ�ø��򵥵���֤������function������ʹ����
typedef std::tr1::function<void()> Func;//����һ����������Ϊ�� �޲����ĺ���ָ��
typedef std::tr1::function<void (int)> Func2;//����һ����������Ϊ�� ֻ��һ��int�����ĺ���ָ��

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
	//const��Ա�������෽�������޸ĵ��ö��� ������ Obj_Animal.Move()�����޸ĵ��ö��� Obj_Animal.Move
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
	union param //��union�еĸ������Ͷ��ǹ���һ���ڴ�ռ䣬ֻ�����ֲ�ͬ����Сȡ���ġ�
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