#ifndef CREATESONY_HEADER
#define CREATESONY_HEADER

#include"sony.h"
//#include"pureflatcreate.h"
//#include"liquidcreate.h"
//#include"plasmacreate.h"




class CreateSony
{
public:
	virtual Sony * createinch29()=0;
	virtual Sony * createinch43()=0;
     ~CreateSony(){};
};


Sony * createsonyinch29(CreateSony * ); 
Sony * createsonyinch43(CreateSony * ); 
CreateSony * createcreatesony(int);



CreateSony * createpureflat();
CreateSony * createplasma();
CreateSony * createliquidcrystal();

#endif






