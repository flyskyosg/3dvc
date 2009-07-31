#ifndef PLASMA_HEADER
#define PLASMA_HEADER 


#include<iostream>



class Plasma
{
public:

	virtual void drawgraph()
	{
		std::cout<<"plasma.drawgraph"<<'\n';
	}

	virtual void specialforplasma()
	{
		std::cout<<"plasma"<<'\n';
	}


};

#endif