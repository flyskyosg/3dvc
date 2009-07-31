#ifndef LIQUID43_HEADER
#define LIQUID43_HEADER 


#include<iostream>
//using namespace std;
#include"inch43.h"
#include"liquidcrystal.h"

class Liquid43:public inch43,protected LiquidCrystal
{

public:
	virtual void adjustvolume()
	{
		std::cout<<"liquid43 adjustvolume"<<std::endl;
	}
	
		
	

	virtual void switchchanel()
	{
		std::cout<<"liquid43 swithchchanel"<<std::endl;
	}
	

	


};

#endif