//ģ����Ԫ
#include<iostream>
#include<string>
using namespace std;

template<typename T1> class test1;
template<typename T2> class test2;
class test3;

template<typename T5> class test5;

template<typename T4>
void test4(T4 data)
{
}


template<typename T>
class test
{
	T data;
public:
	test(T d):data(d)
	{}
	test():data(0){}

	//��Զ�Ĺ�ϵ
	 template<typename T1> 
	 friend class test1;        //test1ģ����κ����͵�ʵ�������Է���test���κ����͵�ʵ����˽�г�Ա

	 template<typename T4>
	 friend void test4<T4>(T4 data); //����test4ģ�溯�����κ������ͷ����κ����͵�test��ʵ����˽�г�Ա
	 
	 
	 //һ�Զ�Ĺ�ϵ
	 friend class test2<int>;   //ֻ����test2ģ���int��ʵ������testģ����κ����͵�ʵ����˽�г�Ա
     
	 friend class test3;        //������ͨ��test3�ķ���ģ����κ����͵�ʵ����˽�г�Ա

	 //friend void test4<int>(int data); //ֻ����test4ģ�溯����int�ͷ����κ����͵�test��ʵ����˽�г�Ա
	 
	 

	 
	 //һ��һ�Ĺ�ϵ

	 		
	 friend class test5<T>;        //�����test��ͬ���͵�test5ģ����ʶ�Ӧ���͵�test��ʵ����˽�г�Ա

	 
	 //friend void test4<T>(T data); // �����test��ͬ���͵�test4ģ����ʶ�Ӧ���͵�test��ʵ����˽�г�Ա
	 

	 

	 //�������ֹ�ϵ��ʵ�ʱ����ʱ��ֻ�������һ�֣��������ֶ�����,

	
	 
};

template<typename T1>
class test1
{
	test<string> mdat;
public:
	test1(){}
	test1(string m):mdat(m){}
	void disp( )
	{
		cout << mdat.data<< endl;
     	
	}
};

template<typename T2>
class test2
{
	test<string> mdat;

public:
	test2(string m):mdat(m){}

	void disp()
	{
		cout << mdat.data << endl;
	}


};

class test3
{
};

template<typename T5>
class test5
{

public:
	void disp(test<T5> m)
	{
		cout << m.data << endl;
	}
};









int main()
{

	//��Զ��ϵ
   
   test1<int> mint("ssss");
   mint.disp();

   //һ�Զ��ϵ
   test2<int> nint("dddd");
   nint.disp();

   //һ��һ��ϵ
   test<int> p;
   test5<int> q;
   q.disp(p);

   ///  
   getchar();

}