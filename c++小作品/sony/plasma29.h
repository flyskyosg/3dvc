#ifndef PLASMA29_HEADER
#define PLASMA29_HEADER 


#include<iostream>
using namespace std;
#include"inch29.h"
#include"plasma.h"
class Plasma29:public inch29,protected Plasma
{

public:
	virtual void adjustvolume()
	{
		cout<<"plasma29 adjustvolume"<<endl;
	}
	
		
	

	virtual void switchchanel()
	{
		cout<<"plama29 swithchchanel"<<endl;
	}
	

	


};

#endif