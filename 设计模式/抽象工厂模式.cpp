// ���󹤳�ģʽ.cpp : �������̨Ӧ�ó������ڵ㡣
//
   
//���ģʽ-���󹤳�ģʽ


#include<iostream>
#include<string>

using namespace std;

class light
{
public:
  virtual bool turnon() = 0;
  virtual bool turnoff() = 0;
};

class redlight : public light
{
public:
	bool turnon()
	{
		cout << "redlight is on" << endl;
		return true;
	}
	bool turnoff()
	{
		cout << "redlight is off" << endl;
		return true;
	}
};

class bluelight : public light
{
public:
	bool turnon()
	{
		cout << "bluelight is on" << endl;
		return true;
	}
	bool turnoff()
	{
		cout << "bluelight is off" << endl;
		return true;
	}
};

class abstractfactory
{
public:
	virtual light * createlight() = 0;
	
};

class redlightfac : public abstractfactory
{
public:
	 light * createlight() 
	 {
		 return new redlight;
	 }
	
};

class bluelightfac : public abstractfactory
{
public:
	light * createlight()
	{
		return new bluelight;
	}
	
};



int main()
{
  abstractfactory  * absfac = new bluelightfac;
  light * plight = absfac->createlight();
  plight->turnon();
  plight->turnoff();
  getchar();
}









