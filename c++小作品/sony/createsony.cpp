#include"createsony.h"

Sony * createsonyinch29(CreateSony * sp)
{
	return sp->createinch29();
}


Sony * createsonyinch43(CreateSony * sp)
{
	return sp->createinch43();
}


CreateSony * createcreatesony(int a)   //ѡ�񴴽����ֲ���
{
	switch(a)
	{
	case 0:return createpureflat();    //
	case 1:return createplasma();
	case 2:return createliquidcrystal();
	default:return 0;
	}
}








