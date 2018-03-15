#include "effectiveCplus.h"

static const int AspectRatio = 5;
static enum{num = 6};//这里通过enum将num作为6的一个标记

effectiveCplus::effectiveCplus() :Obj_effectiveCplus(NULL)
{

}

static effectiveCplus* obj_effectiveCplus = NULL;
effectiveCplus* effectiveCplus::GetInstance()
{
	if (obj_effectiveCplus == NULL)
	{
		obj_effectiveCplus = new effectiveCplus();
		return obj_effectiveCplus;
	}
	else
	/*  just test for new delete and new[] delete[]
	{
		delete obj_effectiveCplus;
		obj_effectiveCplus = new effectiveCplus();
	}
	*/
	return obj_effectiveCplus;
}

effectiveCplus* effectiveCplus::Get_Obj()
{
	return Obj_effectiveCplus;
}

effectiveCplus::effectiveCplus(const effectiveCplus& rhs)
{
	*this = rhs;//不要用拷贝函数中调用另外的拷贝的函数
}

effectiveCplus& effectiveCplus::operator= (const effectiveCplus& rhs)
{

	if (this == &rhs)
	{
		return *this;
	} //证同测试，主要是当对象内有指针时需要手动进行delete，而若是是同一个对象，那么delete之后指针就是个野指针了
	delete Obj_effectiveCplus;
	Obj_effectiveCplus = rhs.Obj_effectiveCplus;//swap 的一部分，需要将成员变量全部进行赋值 也就是要将成员中的指针全部置空再进行赋值。
	*this = rhs;
	return* this;//返回一个指向左侧运算对象的引用，即return一个*this。
}

//--------------effectiveCplusvirtual-------------
effectiveCplusvirtual::effectiveCplusvirtual()
{
	//func2(); 不能在析构构造函数里面调用virtual 函数。比如要构造一个继承该类的对象，在构造base class成分时，会
	//会调用base class中的func2函数。这样就会错乱了，
	//PS：C++对于多态的构造可以这样理解，class drived:public base 当调用drived的构造函数时
	//会先进行base成分的构造，等base成分构造结束后再进行drived成分的构造
}

//将pure virtual 的析构函数进行空的定义
effectiveCplusvirtual::~effectiveCplusvirtual()
{
}

int effectiveCplusvirtual::func2()
{
	this->func2();
	return 0;
}

effectiveCplus::~effectiveCplus()
{

}
static void effectivedeletor()
{

}
