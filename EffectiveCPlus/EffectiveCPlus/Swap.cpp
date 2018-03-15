#include"Swap.h"
/*
namespace std //当加上这句之后swap<WidgetImpl*>(pImpl, other.pImpl)的调用就没有问题了，如果没有加则不行，估计是命名作用的域不同
{
	template<typename T>
	void swap(T& a, T& b)
	{
		T temp = a;
		a = b;
		b = temp;
	}
}
*/

Widget& Widget::operator=(const Widget& rhs)
{
	*pImpl = *(rhs.pImpl);//一定要拷贝指针指向的内存，否则若两个指针指向同一块区域而用户没意识到很容易发生安全事故
	return *this;
}

void Widget::swap(Widget& other)
{
	using std::swap; //这里的调用语法需要注意，调用std的swap需要使用 using std::swap 而调用non-menmber的swap则直接调用即可
	//前面已经为此做了namespace std的声明
	swap<WidgetImpl*>(pImpl, other.pImpl);
}

void Widget::swap(WidgetImpl* lhs, WidgetImpl* rhs)
{
	WidgetImpl* temp;
	temp = lhs;
	lhs = rhs;
	rhs = temp;

}
namespace std //namespace 还是需要会用啊，特别是这些名字都一样的情况下
{
	template<>
	void swap<Widget>(Widget& a, Widget& b)
	{
		a.swap(b);
	}
}