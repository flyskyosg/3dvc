#include<iostream>          //名称空间其他的一些用法



namespace                   //无名名称空间
{
	using namespace std;    //嵌套其他名称空间--组合
	int a=10;               //无名名称空间中的对象相当于全局的,
	
}

//int a;                    //不可以在全局的作用域内在定义与无名名称空间同名的对象
namespace uu
{

	void  f()
	{
		cout<<a<<endl;      //虽然uu内没有定义a但是f函数会从全局的作用域内去寻找a
	}
	void f1()
	{
		cout<<a<<endl;
	}

}


namespace u=uu;             //为名称空间定义别名，只能用来做限定词，不可以用来实现分离定义
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
	void f();                //申明全局的f();
	using namespace u;
    int a=20;
	std::cout<<a<<endl;
	uu::f();                 //别名
	u::f1();
	f();                     //如果没有第一行的全局的f的声明，那么这里会产生二意性；编译器不知道是u中de还是全局的f，
	return 0;
}


