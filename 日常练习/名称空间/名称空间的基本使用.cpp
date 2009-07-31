#include<iostream.h>
namespace ns1
{
	int x=100;
	void funx()
	{
		cout<<"现在调用ns1."<<endl;
	}
}
namespace ns2
{
	int y=200;
	void funy()
	{
		cout<<"调用ns2."<<endl;
	}

}
namespace _a=ns2;  //命名空间可以起别名，针对较长的名字时。
namespace ns3
{
	int z=300;
	void funz()
	{
		cout<<"调用ns3."<<endl;
	}
}
int x=600;	
void main()
{
	using namespace ns1;             //声明名称空间名字，可以调用名称空间中的任何的成员//
	funx();
	int x=400;                       //这中形式可以定义局部同名变量，也可以使用全局变量//
	cout<<"局部x="<<x<<endl;
	cout<<"名称空间x="<<ns1::x<<endl;//但是使用其他的类型时需要用这种形式调用本名称空间的成员//
	cout<<"全局x="<<::x<<endl;       //调用同名全局变量//
    using ns2::y;
    using _a::funy;                 //‘’‘’‘’‘’声明名称空间的成员函数时只需要声明函数的名字'''''''''//
                          
	funy();                          //把y和funy()嵌入到了程序中，多以在程序中久不可以在定义于其同名的变量//
	cout<<"y="<<y<<endl;
	ns3::funz();                     //使用与运算符时需要写全函数的名称于参数列表//
	int z=500;                  
	cout<<"z="<<z<<endl;  
	cout<<"z="<<ns3::z<<endl;        //使用域运算符的形式调用名称空间的成员，不受任何的限制，直接访问成员//
}

