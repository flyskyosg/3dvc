#include<iostream.h>
#define max 10
int st[]={9,4,6,8,5,1,3,5,4,8};

void disp()
{
	for(int i=0;i<max;i++)
		cout<<st[i]<<" ";
	cout<<endl;
}

void fastpx(int i,int j)
{
	if(j>i)
	{
	  int t=st[i],           //t�洢��Ԫ��,Ĭ������ĵ�һ��Ԫ��Ϊ��Ԫ��
		  zi=i,zj=j;         //��¼i��j�ĳ�ʾλ�ã�������ĵݹ鴫�ݲ���
	                 
      
		while(i!=j)
		{

       
		while(j!=i&&st[j]>=t) j--;
		if(j>i)st[i]=st[j];            //��ѭ���ȽϽ�����j>i˵���ҵ��˱�tС��Ԫ�أ������滻
			

	
		while(i!=j&&st[i]<=t) i++;
		
		if(i<j) st[j]=st[i];           //��ѭ���ȽϽ�����i<j˵���ҵ��˱�tС��Ԫ�أ������滻
		}
	    st[j]=t;
	    fastpx(zi,j-1);
  	    fastpx(j+1,zj);
                   

	}

	
	
}

void main()
{
	cout<<"����ǰ:";
	disp();
    fastpx(0,max-1);
	cout<<"�����:";
	disp();
}

	
	







