
#include<iostream>  //�쳣��Ƕ���Լ�ѭ��
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
			catch(n)//(char *)��(struct x) //ֻҪ���Ա����Ƶ��������Ͷ�������Ϊ���׳����쳣
			{                              //ע�⣬�������������ʱ��Ӧ�ý��������ͷ���ǰ�ߣ�ͨ�����ͷ��ں�㣬������������Ӧ�÷���ǰ�ߣ������;͸÷��ں�ߣ���Ϊ���ڡ������͡���
				cerr<<"�����쳣��"<<endl;	
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
                   
