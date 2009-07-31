#include"createsony.h"
#include"sony.h"

enum technology{pure,plasma,liquid};

void fn(Sony *  s)
{
	s->adjustvolume();
	s->switchchanel();
}

void createsonyobj(CreateSony * sp)
{
	Sony * s29=createsonyinch29(sp );
	Sony * s43=createsonyinch43(sp );

	fn(s29);
	fn(s43);

	delete s29 ;
	delete s43 ;

}



int main()
{
	if(CreateSony * sp =createcreatesony(plasma))
	{
		createsonyobj(sp);
		delete sp;
	}
	return 0;
}
	
