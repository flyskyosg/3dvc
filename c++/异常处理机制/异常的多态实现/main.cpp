
#include"myexception.h"
#include"throw_t.h"



void solut()                         //�Զ��崦���񲻵����쳣
{
	cout<<"�������unexception"<<endl;

}

int main()
{
	//set_unexpected(solut);          //ϵͳ���ڸ��ֳ����ܴ�����쳣�Զ�����ǿ����ֹ����
	set_terminate(solut);             // ���ϱߵĺ������ƣ�����������ָ�������쳣�ĺ���,��������
	try 
	{
		//t_int();
		t_char();
	}
	catch(me & a )                    //����ʵ�����쳣�Ķ�̬�������쳣��������е���ʽ���м̳У�����ʵ�ֶ�̬
	{
		
		a.disp();
	}
	

	return 0;

}


