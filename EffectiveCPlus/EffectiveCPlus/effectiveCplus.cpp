#include "effectiveCplus.h"

static const int AspectRatio = 5;
static enum{num = 6};//����ͨ��enum��num��Ϊ6��һ�����

effectiveCplus::effectiveCplus() :Obj_effectiveCplus(NULL)
{

}

static effectiveCplus* obj_effectiveCplus = NULL;
effectiveCplus* effectiveCplus::GetInstance()
{
	if (obj_effectiveCplus == NULL)
	{
		obj_effectiveCplus = new effectiveCplus();
		return obj_effectiveCplus;
	}
	else
	/*  just test for new delete and new[] delete[]
	{
		delete obj_effectiveCplus;
		obj_effectiveCplus = new effectiveCplus();
	}
	*/
	return obj_effectiveCplus;
}

effectiveCplus* effectiveCplus::Get_Obj()
{
	return Obj_effectiveCplus;
}

effectiveCplus::effectiveCplus(const effectiveCplus& rhs)
{
	*this = rhs;//��Ҫ�ÿ��������е�������Ŀ����ĺ���
}

effectiveCplus& effectiveCplus::operator= (const effectiveCplus& rhs)
{

	if (this == &rhs)
	{
		return *this;
	} //֤ͬ���ԣ���Ҫ�ǵ���������ָ��ʱ��Ҫ�ֶ�����delete����������ͬһ��������ôdelete֮��ָ����Ǹ�Ұָ����
	delete Obj_effectiveCplus;
	Obj_effectiveCplus = rhs.Obj_effectiveCplus;//swap ��һ���֣���Ҫ����Ա����ȫ�����и�ֵ Ҳ����Ҫ����Ա�е�ָ��ȫ���ÿ��ٽ��и�ֵ��
	*this = rhs;
	return* this;//����һ��ָ����������������ã���returnһ��*this��
}

//--------------effectiveCplusvirtual-------------
effectiveCplusvirtual::effectiveCplusvirtual()
{
	//func2(); �������������캯���������virtual ����������Ҫ����һ���̳и���Ķ����ڹ���base class�ɷ�ʱ����
	//�����base class�е�func2�����������ͻ�����ˣ�
	//PS��C++���ڶ�̬�Ĺ������������⣬class drived:public base ������drived�Ĺ��캯��ʱ
	//���Ƚ���base�ɷֵĹ��죬��base�ɷֹ���������ٽ���drived�ɷֵĹ���
}

//��pure virtual �������������пյĶ���
effectiveCplusvirtual::~effectiveCplusvirtual()
{
}

int effectiveCplusvirtual::func2()
{
	this->func2();
	return 0;
}

effectiveCplus::~effectiveCplus()
{

}
static void effectivedeletor()
{

}
