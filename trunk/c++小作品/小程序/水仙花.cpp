#include<iostream>
#include<iomanip>
#include<string>

#define max 10

using namespace std;

void main()
{
	for(int i=1;i<max;i++)
		cout<<setfill(' ')<<setw(10-i)<<' '<<setfill('#')<<setw(i)<<'#'<<"     "<<setfill('$')<<setw(i)<<'$'<<endl;
	
	for(i=1;i<max;i++)
		cout<<string(10-i,' ')+string(i,'#')+string(5,' ')+string(i,'$')<<endl;
}