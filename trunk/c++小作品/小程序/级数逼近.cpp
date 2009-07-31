#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
#define max 10000000

void main()
{
	double sum=0.0,i=1.0;
	for(int n=1;abs(i)>1e-6;n++)
	{
		i*=(-1.0)*(2*n-3)/(2*n-1);
        sum+=i;
	  
	  
	}

	cout<<setprecision(7)<<sum*4.0<<endl;
	
}


	