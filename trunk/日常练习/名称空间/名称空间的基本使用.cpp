#include<iostream.h>
namespace ns1
{
	int x=100;
	void funx()
	{
		cout<<"���ڵ���ns1."<<endl;
	}
}
namespace ns2
{
	int y=200;
	void funy()
	{
		cout<<"����ns2."<<endl;
	}

}
namespace _a=ns2;  //�����ռ�������������Խϳ�������ʱ��
namespace ns3
{
	int z=300;
	void funz()
	{
		cout<<"����ns3."<<endl;
	}
}
int x=600;	
void main()
{
	using namespace ns1;             //�������ƿռ����֣����Ե������ƿռ��е��κεĳ�Ա//
	funx();
	int x=400;                       //������ʽ���Զ���ֲ�ͬ��������Ҳ����ʹ��ȫ�ֱ���//
	cout<<"�ֲ�x="<<x<<endl;
	cout<<"���ƿռ�x="<<ns1::x<<endl;//����ʹ������������ʱ��Ҫ��������ʽ���ñ����ƿռ�ĳ�Ա//
	cout<<"ȫ��x="<<::x<<endl;       //����ͬ��ȫ�ֱ���//
    using ns2::y;
    using _a::funy;                 //�����������������������ƿռ�ĳ�Ա����ʱֻ��Ҫ��������������'''''''''//
                          
	funy();                          //��y��funy()Ƕ�뵽�˳����У������ڳ����оò������ڶ�������ͬ���ı���//
	cout<<"y="<<y<<endl;
	ns3::funz();                     //ʹ���������ʱ��Ҫдȫ�����������ڲ����б�//
	int z=500;                  
	cout<<"z="<<z<<endl;  
	cout<<"z="<<ns3::z<<endl;        //ʹ�������������ʽ�������ƿռ�ĳ�Ա�������κε����ƣ�ֱ�ӷ��ʳ�Ա//
}

