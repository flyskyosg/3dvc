#include<iostream.h>
#define max 50
int st[max]={6,4,2,8,1,3,7,9,4,2},                  //�������
    top=10;
int inc[]={1,3,5};           //��������

void insertpx(int j,int inc)
{
	int k=0,t=0,p=0,z=0;
	for(k=j+inc;k<=top-1;k+=inc)   //����������Ԫ��
	{
	      t=0;p=0;
		  if(st[k]<st[k-inc])
		  {
			  for(z=j;z<k;z+=inc)   
			  {
				  if(st[k]<=st[z]) {t=z;break;}
			  }
			  p=st[k];
			  for(z=k-inc;z>=j;z-=inc)
			  {
				  st[z+inc]=st[z];
			  }
			  st[t]=p;
		  }
	}
}

void disp()
{
	for(int i=0;i<top;i++)
		cout<<st[i]<<" ";
	cout<<endl;
}

void insertpx0();

void shell()
{
	int i=0,j=0,k=1,t=0,n=2;      //n��������������,i,j,kѭ������
	for(i=n;i>=1;i--)
	{
		if(st[i]<top+1)
		{
		  cout<<"��"<<k<<"�ֱȽ�:"<<endl;
		  k++;
		  int incr=inc[i];
		  for(int j=0;j<incr;j++)
			  insertpx(j,incr);
		  disp();
		}
	}
	insertpx0();
	cout<<"���һ������:"<<endl;
	disp();
}

void insertpx0()
{
	int t=0,p=0,s=0,n=top;             //t��¼�Ƚ�ֹͣ��λ��,p�ݴ�������Ԫ�ص�ֵ����ֻ��־λs�����ٵ��õĴ���
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




void main()
{
   
	
	disp();
	shell();
}










	



