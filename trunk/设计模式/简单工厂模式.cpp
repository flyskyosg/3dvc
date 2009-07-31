//设计模式-简单工厂模式


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

class simplefactory
{
public:
	light * createlight(string color)
	{
		if(color == "red") return new redlight;
		if(color == "blue") return new bluelight;
		return NULL;
	}
};
int main()
{
  simplefactory simfac;
  light * plight = simfac.createlight("red");
  plight->turnon();
  plight->turnoff();
  getchar();
}

