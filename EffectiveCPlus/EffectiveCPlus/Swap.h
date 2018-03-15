#ifndef SWAP_H
#define SWAP_H

#include<stdio.h>
#include<memory>
#include<iostream>
using namespace std;

class WidgetImpl
{
public:
	virtual ~WidgetImpl();
private:
	int a, b, c;
};

class Widget
{
public:
	Widget(const Widget& rhs);
	Widget& operator=(const Widget& rhs);
	void swap(Widget& other);
	void swap(WidgetImpl* lhs, WidgetImpl* rhs);
private:
	WidgetImpl* pImpl;
};
/*
template<typename T>
void swap(T& a, T& b)
{
	T temp = a;
	a = b;
	b = temp;
}
*/


#endif