#include<iostream>          //���ƿռ�������һЩ�÷�



namespace                   //�������ƿռ�
{
	using namespace std;    //Ƕ���������ƿռ�--���
	int a=10;               //�������ƿռ��еĶ����൱��ȫ�ֵ�,
	
}

//int a;                    //��������ȫ�ֵ����������ڶ������������ƿռ�ͬ���Ķ���
namespace uu
{

	void  f()
	{
		cout<<a<<endl;      //��Ȼuu��û�ж���a����f�������ȫ�ֵ���������ȥѰ��a
	}
	void f1()
	{
		cout<<a<<endl;
	}

}


namespace u=uu;             //Ϊ���ƿռ䶨�������ֻ���������޶��ʣ�����������ʵ�ַ��붨��
namespace u
{
int a=30;;


}



void f()
{
	cout<<a<<endl;          
}
 

int main()                  
{
	void f();                //����ȫ�ֵ�f();
	using namespace u;
    int a=20;
	std::cout<<a<<endl;
	uu::f();                 //����
	u::f1();
	f();                     //���û�е�һ�е�ȫ�ֵ�f����������ô�������������ԣ���������֪����u��de����ȫ�ֵ�f��
	return 0;
}


