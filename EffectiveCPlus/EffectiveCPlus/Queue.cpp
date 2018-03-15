#include "Queue.h"

void Customer::set(long when)
{
	processtime = std::rand() % 3 + 1;
	arrive = when;
}

Queue_Self::Queue_Self(int qs) :qsize(qs)
{
	front = rear = nullptr;
	items = 0;
}

Queue_Self::~Queue_Self()
{
	while (!isempty())
	{
		Node* temp;
		temp = front;
		front = front->next;
		delete temp;
	}
}

bool Queue_Self::isempty() const
{
	//return(front == rear);
	return (items == 0);
}

bool Queue_Self::isfull() const
{
	return (items == qsize);
}

int Queue_Self::queuecount() const
{
	return items;
}

bool Queue_Self::enqueue(const Item& item)
{
	if (isfull())
	{
		std::cout << "this Queue_Self is full" <<std::endl;
		return false;
	}
	Node* Node_item = new Node;
	Node_item->item = item;
	Node_item->next = nullptr;
	items++;
	if (front == nullptr)
		front = Node_item;
	else
		rear->next = Node_item;
	//Node_item->next = nullptr;
	rear = Node_item;
	return true;
}

bool Queue_Self::dequeue(Item& item)
{
	if (isempty())
	{
		std::cout << "this Queue_Self is empty" << std::endl;
		return false;
	}
	item = front->item;
	Node* temp = front;
	front = front->next;
	delete temp;
	items--;
	if (items == 0)
	{
		rear = nullptr;//为什么front不赋值为空？因为前面front已经将rear的next赋值过来了，这种情况下
		//rear->next == nullptr
	}
	return true;
}

