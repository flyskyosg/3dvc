//****************���ֲ���**********************//
#include<iostream.h>
#include<stdio.h>
#define max 50
typedef char datatype;         //ͨ����������
int st[max],                   //ȫ�����飬��Ų��ҵ�����
    k=-1;


void px()                      //����������С����
{
	int i=0,j=0;datatype t;
	for(i=0;i<k;i++)
	{
		for(j=0;j<k-i;j++)
		{
			if(st[j]>st[j+1])
			{
				t=st[j];
				st[j]=st[j+1];
				st[j+1]=t;
			}
		}
	}
	printf("��������������:");
	for(i=0;i<=k;i++)
		printf("%c ",st[i]);
	cout<<endl;
		

 


}

void creatst()                 //���������� 
{
 datatype n='\0';
 int i=1;
 cout<<"����������,����0��������."<<endl;
 do
 {
	 cout<<"�����"<<i<<"������:";
	 cin>>n;
	 if(n=='0') break;
	 k++;st[k]=n;i++;
 }while(1);
 

}



int binsearch(datatype n)      //���ֲ��Һ���
{
	int low=0,
		high=0,
		mid=0;
	low=0;high=k;mid=(low+high)/2;
	if(n<st[low]||n>st[high]) return -1;
	while(low<=high)
	{
		if(st[mid]==n) return mid;
		else
		{
			if(st[mid]<n) 
				low=mid+1;
			else 
				high=mid-1;
			mid=(low+high)/2;
		}
	}
	return -1;
}

void main()
{
	datatype n;int m=0;
	creatst();
	px();
	cout<<"������Ҫ���ҵ�����:";
	cin>>n;
	m=binsearch(n);
	switch(m)
	{
	case -1:cout<<"Ԫ��"<<n<<"������������."<<endl;break;
    default: cout<<"Ԫ��"<<n<<"��������ĵ�"<<m+1<<"��λ��."<<endl;break;
	}
}
	
			





