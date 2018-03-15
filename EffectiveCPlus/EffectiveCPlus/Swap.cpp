#include"Swap.h"
/*
namespace std //���������֮��swap<WidgetImpl*>(pImpl, other.pImpl)�ĵ��þ�û�������ˣ����û�м����У��������������õ���ͬ
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
	*pImpl = *(rhs.pImpl);//һ��Ҫ����ָ��ָ����ڴ棬����������ָ��ָ��ͬһ��������û�û��ʶ�������׷�����ȫ�¹�
	return *this;
}

void Widget::swap(Widget& other)
{
	using std::swap; //����ĵ����﷨��Ҫע�⣬����std��swap��Ҫʹ�� using std::swap ������non-menmber��swap��ֱ�ӵ��ü���
	//ǰ���Ѿ�Ϊ������namespace std������
	swap<WidgetImpl*>(pImpl, other.pImpl);
}

void Widget::swap(WidgetImpl* lhs, WidgetImpl* rhs)
{
	WidgetImpl* temp;
	temp = lhs;
	lhs = rhs;
	rhs = temp;

}
namespace std //namespace ������Ҫ���ð����ر�����Щ���ֶ�һ���������
{
	template<>
	void swap<Widget>(Widget& a, Widget& b)
	{
		a.swap(b);
	}
}