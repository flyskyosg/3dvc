#include<iostream>
#include"plasmacreate.h"
#include"plasma29.h"
#include"plasma43.h"

Sony *  PlasmaCreate::createinch29()
{
	return new  Plasma29();
}

Sony *  PlasmaCreate::createinch43()
{
	return new  Plasma43();
}

CreateSony * createplasma()
{
	return new PlasmaCreate();
}