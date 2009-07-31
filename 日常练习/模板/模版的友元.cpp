//模版友元
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

	//多对多的关系
	 template<typename T1> 
	 friend class test1;        //test1模版的任何类型的实力都可以访问test的任何类型的实例的私有成员

	 template<typename T4>
	 friend void test4<T4>(T4 data); //允许test4模版函数的任何类型型访问任何类型的test的实例的私有成员
	 
	 
	 //一对多的关系
	 friend class test2<int>;   //只允许test2模版的int型实例访问test模版的任何类型的实例的私有成员
     
	 friend class test3;        //允许普通类test3的访问模版的任何类型的实例的私有成员

	 //friend void test4<int>(int data); //只允许test4模版函数的int型访问任何类型的test的实例的私有成员
	 
	 

	 
	 //一对一的关系

	 		
	 friend class test5<T>;        //允许和test相同类型的test5模版访问对应类型的test的实例的私有成员

	 
	 //friend void test4<T>(T data); // 允许和test相同类型的test4模版访问对应类型的test的实例的私有成员
	 

	 

	 //以上三种关系在实际编码的时候只允许出现一种，否则会出现二义性,

	
	 
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

	//多对多关系
   
   test1<int> mint("ssss");
   mint.disp();

   //一对多关系
   test2<int> nint("dddd");
   nint.disp();

   //一对一关系
   test<int> p;
   test5<int> q;
   q.disp(p);

   ///  
   getchar();

}