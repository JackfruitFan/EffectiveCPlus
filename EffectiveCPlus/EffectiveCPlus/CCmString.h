#ifndef CCMSTRING_H_
#define CCMSTRING_H_
#include <iostream>
#include <cstring> 

class CCmString
{
public:
	CCmString(const char* string);
	CCmString(const CCmString& string);
	CCmString();//可以通过static来声明为单例，因为static的方法只能通过类名来访问，它不会出现在各个对象的数据域中
	static CCmString* CCmString::GetInstance();
	static int CCmString::HowMany();
	CCmString& CCmString::operator=(const CCmString& obj);
	CCmString& CCmString::operator=(const char* st);//防止 (CCmstring)lhs = (char*)rhs 执行过多的多余操作
	//先调用CCmString(const char* string);创建临时变量，调用CCmString& CCmString::operator=(const CCmString& obj);
	//赋值，再调用~CCmString()将临时对象析构。
	bool CCmString::operator<(const CCmString& rhs);
	bool CCmString::operator>(const CCmString& rhs);
	bool CCmString::operator==(const CCmString& rhs);
	char& CCmString::operator[](const int index);
	const char& CCmString::operator[](const int index) const;//第二个const表示该方法不会改变调用者
	//比如该例子中表示原来的obj[5]不会被改变。第一个const表示类型不会被改变
	//前面的const修饰返回类型，后一个const修饰调用者
	friend CCmString CCmString::operator+(const CCmString& lhs, const CCmString& rhs);//需要将这个左边是字符串的也能进行调用
	//为了兼容"xxxx"类型的常量字符串需要将变量声明为const并在方法里面新建一个对象赋值并返回
	//这样该操作符可以满足 a = "xx"+a;a=a+"xx";
	CCmString& CCmString::StringLow();

	int CCmString::coutcharnum(const char c);
	//这样的重载无法应对CCmString obj_lhs = obj_rhs;这样的情况 即CCmString obj_lhs = CCmString(obj_rhs)
	~CCmString();
	friend std::ostream& operator<<(std::ostream& os, const CCmString& string);//顺序不能乱此顺序能匹配的算术表达式
	friend std::istream& operator>>(std::istream& is,CCmString& string);
	//为  <<string;
private:
	int _len;
	char* _ptr_string;
	static int _num_strings;//不能赋初值，声明并不会真正分配内存
	const int _q_size;//可以在初始化列表中进行初始化该对象
	//CCmString& _CCmString;必须要放在初始化列表中进行初始化，也就是说只有创建时才能初始化的值
	//只能放在初始化列表中进行初始化
};



#endif
