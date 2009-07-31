#include<iostream>
#include<sstream>
#include<fstream>

using namespace std;

void main()

{
	char * p="123";
	string s;

	ostringstream ostr(s);
	ostr<<p<<' '<<123;

    cout<<ostr.str()<<endl;
	ofstream ouf("123.tat");
	s=ostr.str();
	ouf<<s;

	istringstream istr(ostr.str());
	istr>>s;
	cout<<s<<endl;
	istr>>s;
	cout<<s<<endl;



	
}

