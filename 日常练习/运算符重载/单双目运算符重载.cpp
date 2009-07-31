#include<iostream>

using namespace std;
class xiao
{
	
public:
	int x,y;
	explicit xiao(int i,int j)
	{
		x=i;y=j;
		cout<<"调用。";
	}
	xiao()
	{}
	void disp()
	{
		cout<<x<<y<<endl;
	}
	friend  xiao operator /(xiao a,xiao b);//运算符重载为有缘函数时所需要的参数于实际的参数是一致的，重载为成员函数时所需要的参数比实际的参数少一个。//
	xiao  operator *(xiao b)
	{     int p,q;
		p=x*b.x;
		q=y*b.y;
		return xiao(p,q);
	}
	xiao & operator --()       //单目的自增运算符做重载函数时没有参数时是先用后运算//注意，因为前++操作符的运算结果是变量本身可以作为左值，所以在重载自定义类型的时候进行前++或--重载的时候 要返回该类 型的引用 
	{
		--x;--y;
		return *this;
	}
    xiao operator --(int ) //有参数时候是先运算在使用，//
	{   
		int a,b;
		a=x;b=y;
		x--;y--;
		return xiao(a,b);
	
	}

    
};
xiao operator / (xiao a,xiao b)
{
    int p;int q;
	p=(a.x)/(b.x);
	q=(a.y)/(b.y);
	return  xiao(p,q);  //此时是显式的调用了构造函数。可以从输出结果中看出
}


int main()
{
	xiao a(10,10),b(5,5);
	xiao c,d;
	c=a/b;
    c.disp();
	c=a.operator *( b);
	c.disp();
	d=--a;
	d.disp();
	d=b--;
	d.disp();
	
   



	
}
