#ifndef PUREFLAT43_HEADER
#define PUREFLAT43_HEADER 


#include<iostream>
using namespace std;
#include"inch43.h"
#include"pureflat.h"

class PureFlat43:public inch43,protected PureFlat
{

public:
	virtual void adjustvolume()
	{
		std::cout<<"pureflat43 adjustvolume"<<std::endl;
	}
	
		
	

	virtual void switchchanel()
	{
	std::cout<<"pureflat43 swithchchanel"<<std::endl;
	}
	

	


};

#endif