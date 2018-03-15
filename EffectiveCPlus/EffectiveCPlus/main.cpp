#include "effectiveCplus.h"
#include "Tr1Function.h"
#include <vector>
#include <sstream>
#include "CCmString.h"
#include <ctime>
#include "Queue.h"
void callme1(CCmString &);
void callme2(CCmString);
bool newcustomer(double x);
using std::cout;
using std::cin;

const int MIN_PER_HR = 60;

int main()
{
	if (0)
	{
		const long const_test = 15;//const����Ҫ������ʱ��ʼ����������ֵ�ǲ�ȷ�������޷��޸�
		char array1[80] = {};
		int things[] = { 5, 9, 15, 20 };
		char string[] = { 's', 't', 'r', 'i', 'n', 'g', '\0' };//a string һ���ַ����϶�Ҫ��\0��������β
		cout << "data array" << array1[0] << endl;

		//ʹ�ö��������Դ��Ϊ�������Զ����ع�����Դ
		//����һ������ָ�����ʹ�����ü����ķ�ʽ��������������ָ��������Դ����ָ�룬������
		//ֻ�Ḵ��ָ֮���ֵ������������һ������������������ܻ�ָ��Ұָ�롣Ҳ����˵copy��ʱ��Ҳ���⿽����һ����������
		//��������Դ��ָ���Աָ����ڴ�����
		std::tr1::shared_ptr<effectiveCplus> shared_ptr1(new effectiveCplus()); //��סҪ�Զ�������佫new�����Ķ�����������ָ��
		//�и�����Ȥ�����������ͣ��������������Ż�ʱ������������������һ��ִ�У�����new���������������ָ�������
		//���ܻ������������䣬����Щ����������ʧ��ʱ���ͻ���Ŷ��������ڴ�й©����Ϊ��ʱnew������ָ�벢δ������
		//effectivedeletor ��һ��������ָ�룬��������һ��ɾ������ָ�뼴�ɡ������������ֵ����Ҫ��Ϊ��
		//һ�����������ɾ���������������Զ����mutexs ������Ҫ�����Ļ�ֻ��Ҫһ��ʼ�������ɣ�����������ʱ���Զ���������
		std::tr1::bind(&CalSum, 3, 4);//��calSum��������� 3��4���а�
		std::cout << "--------------divid line-----------\n";
		std::cout << CalSum;

		Bird bird;
		Func func = std::tr1::bind(&Bird::Move, &bird);
		//func();
		std::tr1::bind(&Bird::Move, &bird)();

		Fish fish;
		func = std::tr1::bind(&Fish::Move, &fish);
		func();

		std::cout << "-------------divid line-----------\n";
		func = std::tr1::bind(&Fish::Say, &fish, 3);
		func();

		//std::vector<int>::iterator ;

		Func2 func2 = std::tr1::bind(&Fish::Say, &fish, std::tr1::placeholders::_1);
		func2(3);
		//�������bind��ʵ���Ǻ�functionһ���Ķ�������ʵ����bind��װ�˷������ҽ�����ҲһͬŪ���˰���
		//����˵bind�ķ���ֵ��function��һ��ʵ����
		int cin_test;
		std::stringstream m_iostring;
		m_iostring << "898";
		m_iostring.str();
		m_iostring >> cin_test;
		cout << "cin_test : " << cin_test << endl;

		structTest param_test = { 1, 15 };
		cout << "param_0: " << param_test.param_val.param_0 << endl;
		param_test.param_val.param_0 = 165521;
		int test = static_cast<int>(bits::three);
		//int test = bits::three;
		//cout << "bits::three " << bits::one << endl;
		//cout << "bits::three " << test << endl;
		//cout <<  "three3: " << three3 << endl;


		cout << "param_0: " << param_test.param_val.param_0 << endl;
		cout << "param_1: " << param_test.param_val.parameter_val.param_1 << endl;
		cout << "param_2: " << param_test.param_val.parameter_val.param_2 << endl;
		//cin >> cin_test;
		cin.getline(array1, 20);//���治�ܽ���һ��cin>>��������ܻ�ʹcin.getline����getline�ᶪ������������Ϊ
		//cin�Ὣ�س�������������У�����getline�õ��ľ���һ���س���һ������
		using std::endl;
		{//�˴���Ϊһ������飬������Ҫusing std::endl; 
			//��������н���ʱ��������������Խ�����鿴�����ƺ�����ջ�����Ľṹ
			cout << "Starting an inner block.\n";
			CCmString headline1("celery Stalks at Midnight");
			CCmString headline2("Lettuce Prey");
			CCmString sports("Spinach Leves Bowl for Dollars");
			cout << "headline1: " << headline1 << endl;
			callme1(headline1);
			//callme2(headline2);//��ֵ���ݣ�����֮ǰ���룬�����Ĳ������ǻḴ��һ��ֵȻ�����������
			//�������ﴴ����һ����ʱ�Ķ��󣬺���������������

			cout << "Initialize one object to another:\n";
			CCmString sailor = sports;//CCmString sailor = CCmString(sports);���� �� =��
			cout << "sailor: " << sailor << endl;
			cout << "Assign one object to another:\n";
			CCmString knot;
			knot = headline1;
			cout << "knot: " << knot << endl;
			cout << "Exiting the block.\n";
			cout << "knot: " << knot[3] << endl;
			if (knot == headline1)
			{
				cout << "operator == is OK" << endl;
			}
			cout << "_num_strings: " << CCmString::HowMany() << endl;
		}
		//cout << "cin_test: " << cin_test << endl;
		cout << "array: " << array1 << endl;
		cout << "print this name" << endl;
		CCmString name;
		cin >> name;
		//ATM
		using std::ios_base;
		{
			std::srand(std::time(0));
			cout << "Case Study: Bank of Heather Automatic Teller\n";
			cout << "Enter maximum size of Queue_Self: ";
			int qs;
			cin >> qs;
			Queue_Self line(qs);

			cout << "Enter the number of simulation hours: ";
			int hours;
			cin >> hours;
			long cyclelimit = MIN_PER_HR*hours;

			cout << "Enter the Average number of customers per hour: ";
			double perhour;
			cin >> perhour;
			double min_per_cust;
			min_per_cust = MIN_PER_HR / perhour;

			//Item temp;
			long turnaways = 0;
			long customers = 0;
			long served = 0;
			long sum_line = 0;
			int wait_time = 0;
			long line_wait = 0;

			for (int cycle = 0; cycle < cyclelimit; cycle++)
			{
				if (newcustomer(min_per_cust))
				{
					if (line.isfull())
						turnaways++;
					else
					{
						customers++;
						Item temp;
						temp.set(cycle);
						line.enqueue(temp);
					}
				}
				if (wait_time <= 0 && !line.isempty())
				{
					Item temp;
					line.dequeue(temp);
					wait_time = temp.ptime();
					line_wait += cycle - temp.when();
					served++;
				}
				if (wait_time > 0)
					wait_time--;
				sum_line += line.queuecount();
			}
		}
	}
	CCmString s1("66");
	CCmString s2("77");
	//s1 = s1+s2;
	s1 = "hha" + s2;

	if (0)
	{
		cout << "s1+s2: " << s1 << endl;
		cout << "s1: " << s1 << endl;
		cout << "s1low " << s1.StringLow() << endl;

		char str[] = "Test operator +test Operator +++";
		cout << "str len: " << strlen(str);

		cout << "string num: " << s1.coutcharnum('e') << endl;
	}

	if (!cin)//��û�����������ʱ�򡣡�������Ϊͬ���ĳ���ִ�е��˴�ʱͨ��û�������������ˣ���Ȼ���߳�����
	{
		cin.clear();
		cin.get();
	}
	cin.get();
	cin.get();
	//system("pause");
	return 0;
}

void callme1(CCmString& rhs)
{
	cout << "String passed by reference:"<< "\""<<endl;
	cout << "   \"";
	cout << rhs<<"\"\n";
}

void callme2(CCmString rhs)
{
	cout << "String passed by value:" << "\"" << endl;
	cout << "   \"";
	cout << rhs << "\"\n";
}

bool newcustomer(double x)
{
	return (std::rand()*x / RAND_MAX < 1);
}