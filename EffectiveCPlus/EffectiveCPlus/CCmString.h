#ifndef CCMSTRING_H_
#define CCMSTRING_H_
#include <iostream>
#include <cstring> 

class CCmString
{
public:
	CCmString(const char* string);
	CCmString(const CCmString& string);
	CCmString();//����ͨ��static������Ϊ��������Ϊstatic�ķ���ֻ��ͨ�����������ʣ�����������ڸ����������������
	static CCmString* CCmString::GetInstance();
	static int CCmString::HowMany();
	CCmString& CCmString::operator=(const CCmString& obj);
	CCmString& CCmString::operator=(const char* st);//��ֹ (CCmstring)lhs = (char*)rhs ִ�й���Ķ������
	//�ȵ���CCmString(const char* string);������ʱ����������CCmString& CCmString::operator=(const CCmString& obj);
	//��ֵ���ٵ���~CCmString()����ʱ����������
	bool CCmString::operator<(const CCmString& rhs);
	bool CCmString::operator>(const CCmString& rhs);
	bool CCmString::operator==(const CCmString& rhs);
	char& CCmString::operator[](const int index);
	const char& CCmString::operator[](const int index) const;//�ڶ���const��ʾ�÷�������ı������
	//����������б�ʾԭ����obj[5]���ᱻ�ı䡣��һ��const��ʾ���Ͳ��ᱻ�ı�
	//ǰ���const���η������ͣ���һ��const���ε�����
	friend CCmString CCmString::operator+(const CCmString& lhs, const CCmString& rhs);//��Ҫ�����������ַ�����Ҳ�ܽ��е���
	//Ϊ�˼���"xxxx"���͵ĳ����ַ�����Ҫ����������Ϊconst���ڷ��������½�һ������ֵ������
	//�����ò������������� a = "xx"+a;a=a+"xx";
	CCmString& CCmString::StringLow();

	int CCmString::coutcharnum(const char c);
	//�����������޷�Ӧ��CCmString obj_lhs = obj_rhs;��������� ��CCmString obj_lhs = CCmString(obj_rhs)
	~CCmString();
	friend std::ostream& operator<<(std::ostream& os, const CCmString& string);//˳�����Ҵ�˳����ƥ����������ʽ
	friend std::istream& operator>>(std::istream& is,CCmString& string);
	//Ϊ  <<string;
private:
	int _len;
	char* _ptr_string;
	static int _num_strings;//���ܸ���ֵ���������������������ڴ�
	const int _q_size;//�����ڳ�ʼ���б��н��г�ʼ���ö���
	//CCmString& _CCmString;����Ҫ���ڳ�ʼ���б��н��г�ʼ����Ҳ����˵ֻ�д���ʱ���ܳ�ʼ����ֵ
	//ֻ�ܷ��ڳ�ʼ���б��н��г�ʼ��
};



#endif
