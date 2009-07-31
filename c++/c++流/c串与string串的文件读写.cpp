#include<iostream> //string Á÷
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
using namespace std;
void main()
{
  /*	string s1;
	string s="10000 1111111";
	istringstream istr(s);
	istr>>s1;
	cout<<s1;
	istr>>s1;
	cout<<s1;*/

	string s;char * p=new char [100];
	int m=0,sum=0;
	ifstream inf("aaa.txt");
	//inf.getline(p,100,'\n');
	inf>>p;
	cout<<p<<" ";
	inf>>p;
	cout<<p<<"  ";
	
	inf>>s;
	cout<<s<<endl;

	inf>>s;
	cout<<s;
	inf.getline(p,100,'\n');
	cout<<p<<endl;
	getline(inf,s);
	cout<<s<<endl;
	
	
	
	
	/*for(;getline(inf,s);) 
	{
		for(istringstream istr(s);istr>>m;)
			sum+=m;
		cout<<sum<<endl;
	
	}*/

    



	
		





	
}
