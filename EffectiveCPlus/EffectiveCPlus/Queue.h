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
	bool dequeue(Item& item);//��ʱ�������ڳ����е�Ԫ����Ҫdelete���Բ��ʺ����const�ؼ���
	//�����Ƕ���������Ҫ�ȰѶ���ͷ��Ԫ����push��ȥ���ٽ�push��ȥ��Ԫ��ֵ����ȥ
private:
	Queue_Self(const Queue_Self& q) :qsize(0){}//��ֹ����Ĭ�ϵĸ��ƺ���
	Queue_Self& operator=(const Queue_Self& q){ return *this;}//��ֹ����Ĭ�ϵĸ�ֵ������
};





#endif
