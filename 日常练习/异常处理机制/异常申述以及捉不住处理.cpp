#include<iostream>

#include<exception> 

using namespace std;

void disp() throw(int);                //�ں���������ʱ�򽫺����п����������쳣�����ں����ĺ��

void disp1() throw (char); 

void disp2() throw( double )         
{
	throw 10.0;
}

void disp3() throw();                 //���������������κε��쳣�������ڸú����ڲ�Ҳ���������쳣�������������

void solut()                         //��������ʾ�����ɿ������������쳣
{
	cout<<"�������unexception"<<endl;

}

int main()
{
	//set_unexpected(solut);  //ϵͳ���ڸ��ֳ����ܴ�����쳣�Զ�����ǿ����ֹ����
	set_terminate(solut);     // ���ϱߵĺ������ƣ�����������ָ�������쳣�ĺ���,��������
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


