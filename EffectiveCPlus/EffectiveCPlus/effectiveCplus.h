#ifndef EFFECTIVE_C_PLUS
#define EFFECTIVE_C_PLUS

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<memory>
using namespace std;

//static const int AspectRatio = 5; static最好不要放在头文件中
template<typename T>
inline void callWithMax(const T& a,const T& b)
{
	if (a > b)
	{
		b = a;
	}
}
//static effectiveCplus effectiveCplustest;
class effectiveCplus
{
public:
	static effectiveCplus* GetInstance();
	effectiveCplus();
	effectiveCplus* Get_Obj();
	virtual ~effectiveCplus();//不能声明为private ，因为需要被外部调用，当智能指针析构时会调用这个析构函数
private:
	effectiveCplus(const effectiveCplus& rhs);
	//E7 若该class没有virtual 函数则析构函数也不应该声明为virtual
	//因为继承一个non-virtual 的析构函数是不恰当的。
	effectiveCplus& operator= (const effectiveCplus& rhs);//一般操作符的重载都是重载=， 基本格式为
	//返回类型  operetor操作符 操作符可结合类型。一般操作符的重载都会返回一个已知的类型来实现操作符的结合规律
private:
	effectiveCplus* Obj_effectiveCplus;

};

class effectiveCplusvirtual
{
public:
	//请记住函数返回的对象最好不要是函数内创建的对象的指针或者引用，因为当函数执行结束，这些实例会被析构而指针则会变成野指针
	virtual int func1()=0;
private:
	effectiveCplusvirtual();
	effectiveCplusvirtual(const effectiveCplusvirtual& rhs);
	virtual ~effectiveCplusvirtual() = 0;

	virtual int func2() = 0;
	//在继承上面，如果被继承的父类的析构函数不是virtual的那么就无法使用父类的指针来进行析构子类的对象。
	//另外最好不要继承一个non-virtual 的析构函数，因为这意味着当用父类的指针调用析构时永远都是调用父类的析构函数

	effectiveCplusvirtual& operator= (const effectiveCplusvirtual& rhs);
	
};

static void effectivedeletor();


#endif