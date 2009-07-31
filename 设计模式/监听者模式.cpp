
//观察者模式
#include<iostream>
#include<string>
#include<vector>

using namespace std;
//////////////////////////////////////////////////////////
class listener
{
public:
  	virtual void send() =0;      //用于主题像本监听者发送消息
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
class application      //主题类，发出消息
{
	
public:
			  //存储监听者列表
	virtual void addlistener(listener *) = 0; //增加监听者
    virtual void update() = 0;                //像监听者发送消息
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




			

	
