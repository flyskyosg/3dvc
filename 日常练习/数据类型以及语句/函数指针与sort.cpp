#include<iostream>   //����ָ�룬�Լ�sortʹ��
#include<fstream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;

typedef void (*mm)(int);  //����mmΪָ��int (int) ���ͺ�����ָ��ı�����������ͨ������ʹ��

void fun(int a)
{
	cout<<a<<endl;
}

int bitsum(int a)
{
	int sum=0;
	for(int x=a; x;x/=10) sum+=x%10;
	return sum;
}

bool ppp(int a,int b)
{
	return bitsum(a)<bitsum(b);
}





void main()
{
	mm p=fun;              //����ָ��
	p(100);
	
	void (*q)(int);q=fun;  //����ָ��
	q(200);


	int b[]={60,05,13,92,49,10,5,6};
	vector<int> aa(b,b+7);
	
	sort(aa.begin(),aa.end());
	
	for(int i=0;i<aa.size();i++)
		cout<<aa[i]<<" ";
	cout<<endl;



	
	sort(aa.begin(),aa.end(),ppp);
	
	for(i=0;i<aa.size();i++)
		
		cout<<aa[i]<<" ";
	cout<<endl;

    mm & o=p;           //����ָ�������
	o(300);

	mm u[2];            //���庯��ָ�������
	u[0]=fun;
	u[0](400);          //����ָ���ʹ��

   



	
}

	
