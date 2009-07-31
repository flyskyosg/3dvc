#ifndef PLASMA43_HEADER
#define PLASMA43_HEADER 


#include<iostream>
using namespace std;
#include"inch43.h"
#include"plasma.h"
class Plasma43:public inch43,protected Plasma
{

public:
	virtual void adjustvolume()
	{
		cout<<"plasma43 adjustvolume"<<endl;
	}
	
		
	

	virtual void switchchanel()
	{
		cout<<"plama43 swithchchanel"<<endl;
	}
	

	


};

#endif