#include<iostream> //λ����
#include<string>
//#include<iomanip>
#include<sstream>
#include<fstream>
#include<vector>
#include<cmath>
using namespace std;

double cheng(double n)
{
	
	for(double sum=1.0, i=1.0;i<=n;sum*=i,i++);
	
	return sum;
}





void main()
{

   

    cout<<cheng(5.0)<<endl;
	cout<<cheng(18.0)/(cheng(13.0)*cheng(5.0))<<endl;

	double d1=123456789.9*9,d2=1111111109.1;
	if(abs(d1-d2)<1e-5) cout<<"same"<<endl;  //����Ƚϼ������ж������������Ƿ����
	cout<<(d1-d2)<<endl;
   
	 

	 double p=123456789.9;      //���ȶ�ʧ

	 int o;float l;
	 o=l=p;
	 cout<<o<<endl<<l<<endl<<p<<endl;     


	 int  g=1000000000,j=2000000000;
	 int c0=(double(g)+j)/2;         //�����ת��λdouble�м�������������û��������ɸ�ֵ��int�ͱ���
	 
	 cout<<c0<<endl; 
}



