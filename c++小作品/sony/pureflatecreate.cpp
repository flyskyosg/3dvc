#include<iostream>
#include"pureflatcreate.h"
#include"pureflat29.h"
#include"pureflat43.h"

Sony * PureFlatCreate::createinch29()
{
	return new PureFlat29();
}

Sony * PureFlatCreate::createinch43()
{
	return new PureFlat43();
}

CreateSony * createpureflat()
{
	return new PureFlatCreate();
}



