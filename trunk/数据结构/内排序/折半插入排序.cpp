#include<iostream.h>
#define max 50


void zbsearch(int st [],int & t,int i)
{
	int low=0,high=i-1,mid=(low+high)/2;
	while(low<=high)
	{
		mid=(low+high)/2;
		if(st[i]<st[mid]) high=mid-1;
		if(st[i]>st[mid]) low=mid+1;
		if(st[i]==st[mid]) break;
		
	}
	t=mid;

		

}





void insertpx(int st[],int n )
{
	int t=0,p=0,j=0;             //t��¼�Ƚ�ֹͣ��λ��,p�ݴ�������Ԫ�ص�ֵ��
	for(int i=1;i<n;i++)
	{
		t=0;p=0;                 //ע�⣺��־Ϊ�Լ�ȫ�ֱ���ÿ��ѭ����ʱ��Ҫ���г�ʼ��
		if(st[i]<st[i-1])        //����¼����Ԫ�ر���ǰ�ߵ�Ԫ�ش�Ļ��������бȽϣ�ֱ�������µ�Ԫ�أ�
		{
		    zbsearch(st,t,i);
			p=st[i];
			for(j=i-1;j>=t;j--)
			{
			  st[j+1]=st[j];
			}
			st[t]=p;
	                 
			
		}
	}
}

void disp(int st[],int n)
{
	for(int i=0;i<n;i++)
		cout<<st[i]<<" ";
	cout<<endl;
}

void main()
{
	int st[max],n=0,t=1;
	cout<<"����Ԫ��,����0����:";
	cin>>t;
	for(n=0;n<max;n++)
	{
		if(t==0) break;
		st[n]=t;
		cout<<"����Ԫ��,����0����:";
	    cin>>t;
	}
	cout<<"����ǰ:";
	disp(st,n);

	insertpx(st,n);
	cout<<"�����:";
	disp(st,n);
}
	













		

	

