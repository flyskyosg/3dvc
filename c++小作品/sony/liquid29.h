#ifndef LIQUID29_HEADER
#define LIQUID29_HEADER 


#include<iostream>

#include"inch29.h"
#include"liquidcrystal.h"

class Liquid29:public inch29,protected LiquidCrystal
{

public:
	virtual void adjustvolume()
	{
		std::cout<<"liquid29 adjustvolume"<<'\n';
	}
	
		
	

	virtual void switchchanel()
	{
		std::cout<<"liquid29 swithchchanel"<<'\n';
	}
	

	


};

#endif