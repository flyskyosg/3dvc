
//�۲���ģʽ
#include<iostream>
#include<string>
#include<vector>

using namespace std;
//////////////////////////////////////////////////////////
class listener
{
public:
  	virtual void send() =0;      //���������񱾼����߷�����Ϣ
};

class tel1listener : public listener
{
	int flag;
public:
	tel1listener()
	{
		flag = 0;
	}
	void send()
	{
		flag = 1;
		cout <<"tel1listener recevie message" << flag<< endl;
	}
};

class tel2listener : public listener
{
	int flag;
public:
	tel2listener()
	{
		flag = 0;
	}
	void send()
	{
		flag = 1;
		cout <<"tel2listener recevie message" << flag<< endl;
	}
};

//////////////////////////////////////////////////////
class application      //�����࣬������Ϣ
{
	
public:
			  //�洢�������б�
	virtual void addlistener(listener *) = 0; //���Ӽ�����
    virtual void update() = 0;                //������߷�����Ϣ
};

class telapp:public application
{
	vector<listener *> mlistener;	
public:
	void addlistener(listener * lis)
	{
		mlistener.push_back(lis);
	}
	void update()
	{
		vector<listener *>::iterator itr; 
		for(itr = mlistener.begin(); itr != mlistener.end();itr++)
			(*itr)->send();
		
		
	}
};

//////////////////////////////////////////////////////////////////
int main()
{
	telapp * mtelapp = new telapp;
	mtelapp->addlistener(new tel1listener);
	mtelapp->addlistener(new tel2listener);
	mtelapp->update();
}




			

	
