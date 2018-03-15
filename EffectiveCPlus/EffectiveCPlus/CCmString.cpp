#include"CCmString.h"
using std::cout;

int CCmString::_num_strings = 0; //��������Ͳ���Ҫ�ټ����static��
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
	if (this == &obj)//���ж��Ƿ����������������Ĵ���Ὣ������ڴ��ɾ������������û��������
	{
		return *this;
	}
	delete[] _ptr_string;//��ԭ�����ڴ��ɾ������Ϊ���ڶ����Ƕ�̬����ģ������µ��ַ�����ռ�õ��ڴ��С��ͬ
	//������ɾ����������ܻ�����ڴ�й©
	_len = obj._len;
	_ptr_string = new char[_len+1];//������Ϊ���len������ǰ��û�и�ֵ�����ֵû�б���ʼ����
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
	os << string._ptr_string;//�����ط��ұ�ֻ�����ַ�����ָ�룬��Ȼ���б������������������ֱ�ӷ����ַ�����ָ��
	return os;
}

std::istream& operator>>(std::istream& is, CCmString& string)//�ⲿ�ֵĴ��뻹δ����
{
	char temp[100];
	is.get(temp, 100);//��ȡһ�����ַ�
	if (is)
	{
		string = temp;//��ֵ
	} 
	cout << "temp:" << temp << "\n";
	while (is&&is.get() != '\n')
	{
		cout << "what is this" << "\n";
		continue;//���ѭ��Ҫ����������������ѭ����?Ŀǰû�н�ȥ����ʱ�����������п�ѭ�������ѭ����λ�þ��ǷŴ�����
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
	//strcpy(ptr_new, _ptr_string);//һ��ʼnew��ʱ�����û�и�һ���Ѻõ��ڴ棬��������ڴ�û���������䣬
	//��Ҫһ���ڴ濽������������ȡ���ڴ棬�����´��ڴ�Ҫ���п�������memsetһ�¡�
	memset(ptr_new,0,len + 1);//��0��ʼ���ڴ棬����ʹ��'\0'�����г�ʼ��
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


