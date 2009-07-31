#ifndef LIQUID_HEADER
#define LIQUID_HEADER 


#include<iostream>



class LiquidCrystal
{
public:
	virtual void drawgraph()
	{
	std::	cout<<"liqiudcrystal.drawgraph"<<std::endl;
	}

	virtual void specialforliquidcrystal()
	{
		std::cout<<"liquidcrystal"<<std::endl;
	}


};

#endif