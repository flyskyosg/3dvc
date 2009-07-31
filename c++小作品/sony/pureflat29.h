#ifndef PUREFLAT29_HEADER
#define PUREFLAT29_HEADER 


#include<iostream>
using namespace std;
#include"inch29.h"
#include"pureflat.h"
class PureFlat29:public inch29,protected PureFlat
{

public:
	virtual void adjustvolume()
	{
		std::cout<<"pureflat29 adjustvolume"<<std::endl;
	}
	
		
	

	virtual void switchchanel()
	{
		std::cout<<"pureflat 29 swithchchanel"<<std::endl;
	}
	

	


};

#endif