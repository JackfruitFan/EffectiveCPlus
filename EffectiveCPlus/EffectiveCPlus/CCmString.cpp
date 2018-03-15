#include"CCmString.h"
using std::cout;

int CCmString::_num_strings = 0; //定义这里就不需要再加这个static了
static CCmString* CCmString_ = NULL;

CCmString* CCmString::GetInstance()
{
	if (CCmString_ == NULL)
	{
		CCmString_ = new CCmString();
		return CCmString_;
	}
	return CCmString_;
}

int CCmString::HowMany()
{
	return _num_strings;
}


CCmString::CCmString(const char* string) :_q_size(5), _len(1)
{
	_len = strlen(string);
	_ptr_string = new char[_len+1];
	strcpy(_ptr_string, string);
	_num_strings++;
	cout << "num_string" << ":\"" << _ptr_string
		<< "\" object created \n";

}

CCmString::CCmString(const CCmString& string) :_q_size(5), _len(2)
{
	_len = string._len;
	_ptr_string = new char[_len + 1];
	strcpy(_ptr_string, string._ptr_string);
	_num_strings++;
	cout << "num_string" << ":\"" << _ptr_string
		<< "\" object created \n";

}

CCmString::CCmString() :_len(4), _ptr_string(nullptr), _q_size(5)
{
	_ptr_string = new char[_len + 1];//new[]
	strcpy(_ptr_string, "C++");
	_num_strings++;
	cout << "num_string" << ":\"" << _ptr_string
		<< "\" default object created \n";
}

CCmString& CCmString::operator= (const CCmString& obj)
{
	if (this == &obj)//先判断是否等于自身，否则下面的代码会将本身的内存给删除掉，这样就没有数据了
	{
		return *this;
	}
	delete[] _ptr_string;//将原来的内存块删除，因为现在都不是动态分配的，并且新的字符可能占用的内存大小不同
	//而不做删除处理则可能会造成内存泄漏
	_len = obj._len;
	_ptr_string = new char[_len+1];//就是因为这个len啊，在前面没有赋值，这个值没有被初始化啊
	strcpy(_ptr_string, obj._ptr_string);
	_num_strings++;
	return *this;
}

CCmString::~CCmString()
{
	cout << _num_strings << " : left \n";
	_num_strings--;
	if (_num_strings >= 0)
	{
		cout << "\"" << _ptr_string << "\"" << "object deleted \n";
 		delete[] _ptr_string;//delete[]
		_ptr_string = nullptr;
	}
}

std::ostream& operator<<(std::ostream& os, const CCmString& string)
{
	os << string._ptr_string;//此重载符右边只能是字符串的指针，当然会有别的类根据这个操作符会直接返回字符串的指针
	return os;
}

std::istream& operator>>(std::istream& is, CCmString& string)//这部分的代码还未理解好
{
	char temp[100];
	is.get(temp, 100);//获取一定的字符
	if (is)
	{
		string = temp;//赋值
	} 
	cout << "temp:" << temp << "\n";
	while (is&&is.get() != '\n')
	{
		cout << "what is this" << "\n";
		continue;//这个循环要干嘛是整个函数的循环吗?目前没有进去，到时候有问题会进行空循环那这个循环的位置就是放错了嘛
	}
	return is;
}

bool CCmString::operator< (const CCmString& rhs)
{
	return (strcmp(this->_ptr_string, rhs._ptr_string) < 0);
}

bool CCmString::operator> (const CCmString& rhs)
{
	return (rhs._ptr_string < this->_ptr_string);
}

bool CCmString::operator==(const CCmString& rhs)
{
	return (strcmp(this->_ptr_string, rhs._ptr_string) == 0);
}

char& CCmString::operator[](const int index)
{
	return this->_ptr_string[index];
}

const char& CCmString::operator[](const int index) const
{
	return this->_ptr_string[index];
}

CCmString& CCmString::operator=(const char* st)
{
	if (st == NULL)
	{
		cout << "inputst is NULL" << std::endl;
		return *this;
	}
	delete[] _ptr_string;
	_len = strlen(st);
	_ptr_string = new char[_len+1];
	strcpy(_ptr_string, st);
	return *this;
}

CCmString operator+(const CCmString& lhs, const CCmString& rhs)
{
	if (lhs._ptr_string == nullptr ||
		rhs._ptr_string == nullptr)
	{
		//return;
	}
	char* temp = nullptr;
	temp = lhs._ptr_string;
	int len = strlen(lhs._ptr_string) + strlen(rhs._ptr_string);
	CCmString mhs;
	mhs._ptr_string = new char[len + 1];
	mhs._len = len;
	strcpy(mhs._ptr_string, temp);
	/*
	delete[] temp;
	temp = nullptr;
	*/
	strcat(mhs._ptr_string, rhs._ptr_string);
	return mhs;
}

#if 1
CCmString& CCmString::StringLow()
{
	if (_ptr_string == nullptr)
	{
		//return;
	}
	int len = strlen(_ptr_string);
	char* temp = _ptr_string;
	char* ptr_new = new char[len+1];
	//strcpy(ptr_new, _ptr_string);//一开始new的时候可能没有给一块友好的内存，或者这块内存没有真正分配，
	//需要一次内存拷贝才能真正获取到内存，所以下次内存要进行拷贝或者memset一下。
	memset(ptr_new,0,len + 1);//用0初始化内存，不能使用'\0'来进行初始化
	char* ptr_temp = ptr_new;
	while(*temp != '\0')
	{
		static int num = 0;
		*ptr_temp = tolower(*temp);
		temp++;
		ptr_temp++;
		num++;
		cout << "StringLow num: " << num << "\n";
	}
	temp = _ptr_string;
	_ptr_string = ptr_new;
	delete[] temp;
	return *this;
}
#else
CCmString& CCmString::StringLow()
{
	if (_ptr_string == nullptr)
	{
		//return;
	}
	char* temp = _ptr_string;
	while (*temp != '\0')
	{
		*temp = tolower(*temp);
		temp++;
	}
	return *this;
}
#endif

int CCmString::coutcharnum(const char c)
{
	char* temp = _ptr_string;
	int num = 0;
	while (*temp != '\0')
	{
		if (c==*temp)
		{
			num++;
			temp++;
		}
		temp++;

	}
	return num;
}


