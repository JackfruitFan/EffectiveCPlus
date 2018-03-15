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
		const long const_test = 15;//const变量要在声明时初始化，否则其值是不确定的且无法修改
		char array1[80] = {};
		int things[] = { 5, 9, 15, 20 };
		char string[] = { 's', 't', 'r', 'i', 'n', 'g', '\0' };//a string 一个字符串肯定要以\0结束符结尾
		cout << "data array" << array1[0] << endl;

		//使用对象管理资源，为了视线自动化地管理资源
		//复制一个智能指针最好使用引用计数的方式管理，否则，若智能指针管理的资源存在指针，而复制
		//只会复制之指针的值，这样当其中一个被析构后，另外的智能会指向野指针。也就是说copy的时候也另外拷贝出一个副本包括
		//被管理资源中指针成员指向的内存区域
		std::tr1::shared_ptr<effectiveCplus> shared_ptr1(new effectiveCplus()); //记住要以独立的语句将new出来的对象置于智能指针
		//有个很有趣的例子来解释，即当编译器做优化时，（若和其他语句放在一起执行），在new出对象和置入智能指针过程中
		//可能会夹入其他的语句，当这些其他语句调用失败时，就会子哦啊后才能内存泄漏，因为此时new出来的指针并未被保存
		//effectivedeletor 即一个函数的指针，传入这样一个删除器的指针即可。但是这个传入值可能要是为空
		//一般而言这样的删除器都是用来作自动解除mutexs 这样需要上锁的话只需要一开始声明即可，当函数结束时会自动进行析构
		std::tr1::bind(&CalSum, 3, 4);//将calSum函数与参数 3，4进行绑定
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
		//所以这个bind其实就是和function一样的东西吗？其实就是bind封装了方法并且将参数也一同弄上了啊？
		//可以说bind的返回值是function的一个实例？
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
		cin.getline(array1, 20);//上面不能紧跟一个cin>>语句否则可能会使cin.getline并且getline会丢弃结束符，因为
		//cin会将回车符放在输出队列，这样getline得到的就是一个回车即一个空行
		using std::endl;
		{//此处作为一个程序块，并不需要using std::endl; 
			//程序块运行结束时会进行析构，可以将代码块看成类似函数堆栈这样的结构
			cout << "Starting an inner block.\n";
			CCmString headline1("celery Stalks at Midnight");
			CCmString headline2("Lettuce Prey");
			CCmString sports("Spinach Leves Bowl for Dollars");
			cout << "headline1: " << headline1 << endl;
			callme1(headline1);
			//callme2(headline2);//按值传递，正如之前设想，函数的参数总是会复制一份值然后放入代码块中
			//所以这里创建了一个临时的对象，函数结束后被析构。

			cout << "Initialize one object to another:\n";
			CCmString sailor = sports;//CCmString sailor = CCmString(sports);拷贝 和 =号
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

	if (!cin)//当没有其他输入的时候。。但是作为同步的程序，执行到此处时通常没有其他的输入了，当然多线程例外
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