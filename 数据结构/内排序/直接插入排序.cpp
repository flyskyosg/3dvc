#include<iostream.h>
#define max 50

void insertpx(int st[],int n )
{
	int t=0,p=0,s=0;             //t��¼�Ƚ�ֹͣ��λ��,p�ݴ�������Ԫ�ص�ֵ����ֻ��־λs�����ٵ��õĴ���
	for(int i=1;i<n;i++)
	{
		t=0;p=0;s=0;             //ע�⣺��־Ϊ�Լ�ȫ�ֱ���ÿ��ѭ����ʱ��Ҫ���г�ʼ��
		for(int j=0;j<i;j++)
		{
			if(st[i]<st[j]){ t=j;s=1;break;}
		}
		if(s==1)                 //s==1˵���ȽϵĹ������д��ڵ�ǰ�Ƚ�Ԫ�صģ������ʾǰ�ߵ�Ԫ�ض��ȵ�ǰ��Ԫ��С���Ѿ�����
		{
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
	













		

	

