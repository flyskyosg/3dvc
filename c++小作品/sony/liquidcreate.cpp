#include<iostream>
#include"liquidcreate.h"
#include"liquid29.h"
#include"liquid43.h"

Sony * LiquidCreate::createinch29()
{
	return new Liquid29();
}

Sony * LiquidCreate::createinch43()
{
	return new Liquid43();
}

CreateSony * createliquidcrystal()
{
	return new LiquidCreate();
}
