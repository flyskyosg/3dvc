#ifndef PUREFLAT_HEADER
#define PUREFLAT_HEADER 


#include<iostream>




class PureFlat
{
public:
	virtual void drawgraph()
	{
		std::cout<<"pureflat.drawgraph"<<std::endl;
	}

	virtual void specialforpureflat()
	{
		std::cout<<"pureflat"<<std::endl;
	}


};

#endif