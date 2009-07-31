#include<iostream>

#include<exception> 

using namespace std;

void disp() throw(int);                //在函数声明的时候将函数有可能抛掷的异常声明在函数的后边

void disp1() throw (char); 

void disp2() throw( double )         
{
	throw 10.0;
}

void disp3() throw();                 //声明函数不抛掷任何的异常，但是在该函数内部也可以抛掷异常，这仅仅是生命

void solut()                         //不声明表示函数由可能抛掷各种异常
{
	cout<<"处理各种unexception"<<endl;

}

int main()
{
	//set_unexpected(solut);  //系统对于各种程序不能处理的异常自动捕获，强制终止程序
	set_terminate(solut);     // 与上边的函数类似，不过他可以指定处理异常的函数,进行软处理
	try 
	{
		//disp ();
	  	 //disp1();
		disp2();
	}
	catch(char)
	{
		cout<<"char"<<endl;
		exit(1);
	}
	catch(int)
	{
    cout<<"int"<<endl;
	}
	
	return 0;

}

void disp() throw(int)
{
	
	throw 10;
}

void disp1() throw(char)
{
	
	throw 'a';
}


