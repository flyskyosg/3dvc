#include<iostream>

#define max 100

using namespace std;
void main()
{

	int x=1,y=1,z=1;
	for(x=1;x<=max/7;x++)            //�����㷨
		for(y=1;y<=max/5;y++)
			for(z=1;z<=300;z++)
			{
				if((x+y+z)==100&&(21*x+15*y+z)==300)
					cout<<"x="<<x<<" "<<"y="<<y<<" "<<"z="<<z<<endl;
			}
     
	for(x=1;x<=max/7;x++)            //�Ľ��㷨(������Ԫ��ϵ�Լ�z����������z��������ѭ���Ĳ���)
		for(y=1;y<=max/5;y++)
		   {
			   if(10*x+7*y==100&&(100-x-y)%3==0)
				   cout<<"x="<<x<<" "<<"y="<<y<<" "<<"z="<<100-x-y<<endl;
		   }


     






}