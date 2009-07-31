#include <iostream>
#include <iomanip>
using namespace std;
class time
{
	int hour,minute,second;
public:
	void set(int h,int m,int s)
	{
		hour=h;
		minute=m;
		second=s;
	}
	friend time& operator++(time & a);
	friend time  operator++(time &a,int );
	friend ostream & operator <<(ostream& o,const time& t);
   
};

time & operator ++(time &a)
{
	
		if(!(a.second=(a.second+1)%60)&&!(a.minute=(a.minute+1)%60))
			a.hour=(a.hour+1)%24;
		return a;
}
time  operator++(time &a,int)
{
	time t(a);
	if(!(a.second=(a.second+1)%60)&&!(a.minute=(a.minute+1)%60))
		a.hour=(a.hour+1)%24;
	return t;
}
ostream & operator<<(ostream & o,const time& t)
{
    	o<<setfill('0')<<setw(2)<<t.hour<<":"<<setw(2)<<t.minute<<":";
		return o<<setw(2)<<t.second<<endl<<setfill(' ');
}
int main()
{
	time t;
	t.set(11,59,55);
	cout<<t++;
	cout<<++t;
	cout<<t++;
	cout<<++t;
	cout<<++t;
} 