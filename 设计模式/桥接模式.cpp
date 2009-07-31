#include<iostream>
#include<string>
using namespace std;

class pen
{
public:
	virtual void draw() = 0;
};

class smallpen : public pen
{
public:
	void draw()
	{
		cout << "smallpen" << endl; 
	}
};

class midpen : public pen
{
public:
	void draw()
	{
		cout << "midpen" << endl; 
	}
};

class bigpen : public pen
{
public:
	void draw()
	{
		cout << "bigpen" << endl; 
	}
};


class color
{
public:
	virtual void setcolor() = 0;
};

class red : public color
{
public:
	void setcolor()
	{
		cout << "red" << endl;
	}
};

class blue : public color
{
public:
	void setcolor()
	{
		cout << "blue" << endl;
	}
};


class yellow : public color
{
public:
	void setcolor()
	{
		cout << "yellow" << endl;
	}
};

class client
{
	color * mcolor;
	pen   * mpen;
public:
	client(){}
	client(color * clo, pen * pe):mcolor(clo),mpen(pe)
	{
		cout << "初始化成功" << endl;
		
	}

	void disp()
	{
		mcolor->setcolor();
		mpen->draw();
	}
};


int main()
{
	client * mclient = new client(new red,new smallpen);
	mclient->disp();
	getchar();
}







