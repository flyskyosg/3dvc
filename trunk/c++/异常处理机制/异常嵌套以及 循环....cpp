
#include<iostream>  //异常的嵌套以及循环
using namespace std;
struct x
{};

class m
{
	int a;
public:
};
class n:public m
{
	int b;
public:
};




struct x y;

m a1;n a2;
void disp() ;
void main()
{
	try
	{
		while(1)
		{
			try
			{ 
				 disp();
			}
			catch(n)//(char *)，(struct x) //只要可以被复制的数据类型都可以作为被抛出的异常
			{                              //注意，当有特殊的类型时，应该将特殊类型放在前边，通用类型放在后便，比如派生类型应该放在前边，基类型就该放在后边，因为存在“子类型”；
				cerr<<"捕获异常。"<<endl;	
			}
			catch(...)
			{
				clog<<"catch unknown unexception  !"<<endl;
				cout<<"    "<<endl;
				clog<<"catch unknown unexception  !"<<endl;
				throw;
		
			}
			cout<<"Do you want to try again"<<"(y/n):";
			char c;
			cin>>c;
			if(c=='n') break;

		}
	}
	catch(...)
	{cout<<"catch unknown exception !";}
	
	

 
}
    

void disp()
{
	cout<<"china joy"<<endl;
	//throw "exception";
	//throw y;
	throw(a1);
}
                   
