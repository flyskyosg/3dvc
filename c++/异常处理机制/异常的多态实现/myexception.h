#ifndef MYEXCEPTION_H
#define MYEXCEPTION_H

#include<iostream>
#include<iostream>
#include<typeinfo>
#include<exception> 
using namespace std;
class me
{
public:
	virtual void disp()=0; 
};

class e_char:public me
{
public:
	void disp() ;
};


class e_int:public me
{
public:
	void disp() ;
};

#endif