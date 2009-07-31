#include<iostream.h>
class da
{

public:
	int x;
	da(int i)
	{
		x=i;
	}
};

template <class t,class r,int m>  //在模板的类型参数表中，不但可以抽象的类型，而且还可以是基本数据类型，但必须定义一个变量，在说名的地方赋值而在实例中不用赋值，可以直接使用该变量//
class xiao
{
	public:	t x;r y;

	xiao(t i,r j):y(j) //无论是嵌套类，还是友元类， 还是别的类，当一个类中有其他的类的对像作为自己的子对像时，都必须用：x(y)这中方式赋值；//
	{
		x=i;
	}
	void disp()
	{
		cout<<x+y.x+m<<endl;
	}
};
template <class t,class r>    //在函数模板的类型参数表中，不需要定义基本的数据类型//
 void jia(t a,r b,int m)
{
	cout<<a+b.x+m<<endl;
}
void main()
{
	da u(100);int o=100;
	xiao <int,da,100>a(100,u);//类的模板在实现的时候必须先把用到的数据类型列出，而且必须和模板中的类型参数表对应,如果在模板的类型参数表中有基本类型，在这里只需给他赋值就行,//
	a.disp();
	jia(o,u,100);

}

