#include<iostream.h>
#include<stdio.h>
class xiao
{
	int x,y,z;
public:
	xiao(int i,int j,int k )
	{
		x=i;y=j;z=k;
	}
	xiao(){}
	xiao operator +(int m);
	xiao operator -(int m);
	void disp()
	{
		cout<<x<<"年"<<y<<"月"<<z<<"日"<<endl;
	}
};
xiao  xiao:: operator +(int m)
{
int a=0,b=0,c=0;
switch(y)
{
   case 1:m+=z;break;
   case 2:m+=31+z;break;
   case 3:m+=59+z;break;
   case 4:m+=90+z;break;
   case 5:m+=120+z;break;
   case 6:m+=151+z;break;
   case 7:m+=181+z;break;
   case 8:m+=212+z;break;
   case 9:m+=243+z;break;
   case 10:m+=273+z;break;
   case 11:m+=304+z;break;
   case 12:m+=334+z;break;
   default:break;
}
if(m>=365) {a+=m/365;m%=365;};
if(m>0&&m<=31) { c=m; b+=1;}
else
if(m>31&&m<=59) {c=m-31; b+=2;}
else
if(m>59&&m<=90) {c=m-59;b+=3;}
else
if(m>90&&m<=120){c=m-90; b+=4;}
else
if(m>120&&m<=151){c=m-120; b+=5;}
else
if(m>151&&m<=181) {c=m-151;b+=6;}
else
if(m>181&&m<=212) {c=m-181;b+=7;}
else
if(m>212&&m<=243) {c=m-212;b+=8;}
else
if(m>243&&m<=273) {c=m-243;b+=9;}
else
if(m>273&&m<=304) {c=m-273;b+=10;}
else
if(m>304&&m<=334) {c=m-304;b+=11;}
else
if(m>334&&m<=365) {c=m-334;b+=12;}
a+=x;
return xiao(a,b,c);
}
void main()
{
	cout<<"请输入日期"<<endl;
	int i,j,k,d;
    cout<<"年:";cin>>i;cout<<endl;
	cout<<"月:";cin>>j;cout<<endl;
    cout<<"日:";cin>>k;cout<<endl;
    cout<<"请输入要加上的天数"<<endl;
	cin>>d;cout<<endl;
	xiao a(i,j,k),b;
	b=a+d;
	cout<<"您的结果是:";
	b.disp();
	cout<<"按任意键退出";
	getchar();
}
	










     







	



