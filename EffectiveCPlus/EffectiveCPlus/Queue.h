#ifndef QUEUE_H_
#define QUEUE_H_
#include <stdio.h>
#include <stdlib.h>
#include <cstdlib>
#include <iostream>

class Customer
{
private:
	long arrive;
	int processtime;
public:
	Customer(){ arrive = processtime = 0;}
	void set(long when);
	long when() const { return arrive;}
	int ptime() const { return processtime; }
};

typedef Customer Item;

class Queue_Self
{
	enum{Q_SIZE = 10};
private:
	const int qsize;
	struct Node
	{
		Item item;
		struct Node* next;
	};
	Node* front;
	Node* rear;
	int items;
public:
	Queue_Self(int qs = Q_SIZE);
	~Queue_Self();
	bool isempty() const;
	bool isfull() const;
	int queuecount() const;
	bool enqueue(const Item& item);
	bool dequeue(Item& item);//此时可能由于出队列的元素需要delete所以不适合添加const关键字
	//由于是队列所以需要先把队列头的元素先push出去，再将push出去的元素值传出去
private:
	Queue_Self(const Queue_Self& q) :qsize(0){}//防止调用默认的复制函数
	Queue_Self& operator=(const Queue_Self& q){ return *this;}//防止调用默认的赋值操作符
};





#endif
