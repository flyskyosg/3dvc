
#include"myexception.h"
#include"throw_t.h"



void solut()                         //自定义处理捕获不到的异常
{
	cout<<"处理各种unexception"<<endl;

}

int main()
{
	//set_unexpected(solut);          //系统对于各种程序不能处理的异常自动捕获，强制终止程序
	set_terminate(solut);             // 与上边的函数类似，不过他可以指定处理异常的函数,进行软处理
	try 
	{
		//t_int();
		t_char();
	}
	catch(me & a )                    //这里实现了异常的多态处理，把异常以类的类行的形式进行继承，可以实现多态
	{
		
		a.disp();
	}
	

	return 0;

}


