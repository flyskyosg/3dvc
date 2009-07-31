#include<iostream> //vectorÇ¶Ì×µÄÊ¹ÓÃ
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
using namespace std;

void print(vector<vector<int> >  m)
{
}





void main()
{
	vector<vector<int> > a;
	
	ifstream inf("aaa.txt");
    
    for(string s;getline(inf,s);)
	{
		vector<int> b;
	    int tem=0;
		for(istringstream istr(s);istr>>tem;)
		{
			cout<<tem<<endl;
			b.push_back(tem);
		}
		a.push_back(b);
	}

	
	
}
