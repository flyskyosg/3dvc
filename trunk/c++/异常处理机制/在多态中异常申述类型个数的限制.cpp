#include<iostream>

using namespace std;

//�쳣�Ķ�̬

class base_bad
{
public:
	virtual ~base_bad()
	{cout<<"base_bad"<<endl; }
};

class bad1:public base_bad
{
public:
	~bad1()
	{cout<<"base_bad1"<<endl; }
};


class bad2:public bad1
{
public:
	~bad2()
	{cout<<"base_bad2"<<endl; }
};


//�쳣�����İ�������


class base
{
public:
	virtual void disp() throw(base_bad,int)=0;
};

typedef void (* p)() ;//;throw(base_bad,int);       //�ڶ��庬���쳣�������ĺ�����ָ���ʱ�򣬲���Ҫ�����쳣�� ������������ 



class base1:public base
{
public:
    void disp() throw(base_bad,int)           //������麯������������쳣�� �����Ļ�����ô�������е��麯��Ҫ�������и���ʵ�ֶ�̬ʱ�� 
	{  cout<<"base1"<<endl;   }               //�������еĺ������쳣�ĵ����Ͳ��ܶ��ڻ��۵������ĸ��� 
};

class base2:public base1                    ////������麯������������쳣�� �����Ļ�����ô�������е��麯��Ҫ�������и���ʵ�ֶ�̬ʱ��                                    //�������еĺ������쳣�ĵ����Ͳ��ܶ��ڻ��۵������ĸ��� 
{             
public:
    void disp() throw(base_bad)             //�������еĺ������쳣�ĵ����Ͳ��ܶ��ڻ��۵������ĸ���
	{  cout<<"base2"<<endl;   }
};



//������ 

int main()
{


	
	return 0;
	
}
