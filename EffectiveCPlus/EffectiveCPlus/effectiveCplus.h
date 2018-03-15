#ifndef EFFECTIVE_C_PLUS
#define EFFECTIVE_C_PLUS

#include<stdio.h>
#include<stdlib.h>
#include<iostream>
#include<memory>
using namespace std;

//static const int AspectRatio = 5; static��ò�Ҫ����ͷ�ļ���
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
	virtual ~effectiveCplus();//��������Ϊprivate ����Ϊ��Ҫ���ⲿ���ã�������ָ������ʱ����������������
private:
	effectiveCplus(const effectiveCplus& rhs);
	//E7 ����classû��virtual ��������������Ҳ��Ӧ������Ϊvirtual
	//��Ϊ�̳�һ��non-virtual �����������ǲ�ǡ���ġ�
	effectiveCplus& operator= (const effectiveCplus& rhs);//һ������������ض�������=�� ������ʽΪ
	//��������  operetor������ �������ɽ�����͡�һ������������ض��᷵��һ����֪��������ʵ�ֲ������Ľ�Ϲ���
private:
	effectiveCplus* Obj_effectiveCplus;

};

class effectiveCplusvirtual
{
public:
	//���ס�������صĶ�����ò�Ҫ�Ǻ����ڴ����Ķ����ָ��������ã���Ϊ������ִ�н�������Щʵ���ᱻ������ָ�������Ұָ��
	virtual int func1()=0;
private:
	effectiveCplusvirtual();
	effectiveCplusvirtual(const effectiveCplusvirtual& rhs);
	virtual ~effectiveCplusvirtual() = 0;

	virtual int func2() = 0;
	//�ڼ̳����棬������̳еĸ����������������virtual����ô���޷�ʹ�ø����ָ����������������Ķ���
	//������ò�Ҫ�̳�һ��non-virtual ��������������Ϊ����ζ�ŵ��ø����ָ���������ʱ��Զ���ǵ��ø������������

	effectiveCplusvirtual& operator= (const effectiveCplusvirtual& rhs);
	
};

static void effectivedeletor();


#endif