#include<iostream.h>
class xiao    //��Ϊ����ʹ��//               //˽��>����>����//
{
private:      
	int x;
protected:
	int y;
public:
	int z;
    xiao(int i,int j,int k)
	{
		x=i;y=j;z=k;
	}
	void disp()
	{
		cout<<x<<endl;
	}
	void disp1()
	{
		cout<<x<<y<<z<<endl;
	}
};
class da :private xiao    //˽�м̳�//
{
	int w;xiao m;           //�����൱�� ����Ļ�����Ӷ���//
public:
	da(int i,int j,int k,int l):xiao(i,j,k), m(i,j,k) //���̳еĹ��캯����//
	{
		w=l;
	}
	void output()
	{	
		disp();//���۵�˽�г�Աֻ��ͨ�����û���ĳ�Ա���������û������������������������//
		            
		cout<<y<<endl<<z<<endl<<w<<endl;  // ԭ���Ǳ����͹������Եĳ�Ա��˽�м̳к��Ϊ�������˽�г�Ա�������˽�г�Աʼ��֮�ܱ������Լ��ĳ�ԭ��������//  
		m.disp1();
	}
};


class da1 :public xiao      //���м̳�// //���м̳еĻ���ĳ�Աʱ�����̳еĳ�Ա�������ڻ��൱�е����Բ��䣬ԭ�����൱�е�˽�г�ԭ��Ȼֻ�ܱ����ԭ��������//
{
    int w;xiao m;           //�����൱�ж���Ļ�����Ӷ���//
public:
	da1(int i,int j,int k,int l):xiao(i,j,k), m(i,j,k) //���̳еĹ��캯��//
	{
		w=l;                
	}
	void output()
	{	
		disp();                   //���û���ĳ�Ա����//
		cout<<y<<endl<<z<<endl<<w<<endl;     
		m.disp1();               //������Ӷ�����ó�Ա����//
	}
};

class da2 :protected xiao    //�����̳У���˽�м̳����ʻ���һ�£�ֻ�Ǳ����̳����ĳ�Ա��������������Ϊ������Ա�ģ�ԭ���ǹ��еĳ�Ա��Ϊ������ı����ĳ�Ա//
{
	int w;xiao m;           //�����൱�� ����Ļ�����Ӷ���//
public:
	da2(int i,int j,int k,int l):xiao(i,j,k), m(i,j,k) //���̳еĹ��캯����//
	{
		w=l;
	}
	void output()
	{	
		disp();         //���۵�˽�г�Աֻ��ͨ�����û���ĳ�Ա���������û������������������������//
		            
		cout<<y<<endl<<z<<endl<<w<<endl;     
		m.disp1();
	}
};

void main()
{
   da x(10,20,30,40);da1 x1(10,20,30,40);da2 x2(10,20,30,40);
   x.output();x1.output();x2.output();
}
	





	