#include<iostream.h>
#define max 50
int st[max]={6,4,2,8,1,3,7,9,4,2},                  //存放数据
    top=10;
int inc[]={1,3,5};           //增量序列

void insertpx(int j,int inc)
{
	int k=0,t=0,p=0,z=0;
	for(k=j+inc;k<=top-1;k+=inc)   //控制纳入新元素
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
	int i=0,j=0,k=1,t=0,n=2;      //n来决定增量序列,i,j,k循环变量
	for(i=n;i>=1;i--)
	{
		if(st[i]<top+1)
		{
		  cout<<"第"<<k<<"轮比较:"<<endl;
		  k++;
		  int incr=inc[i];
		  for(int j=0;j<incr;j++)
			  insertpx(j,incr);
		  disp();
		}
	}
	insertpx0();
	cout<<"最后一轮排序:"<<endl;
	disp();
}

void insertpx0()
{
	int t=0,p=0,s=0,n=top;             //t记录比较停止的位置,p暂存新纳入元素的值，这只标志位s，减少调用的次数
	for(int i=1;i<n;i++)
	{
		t=0;p=0;s=0;             //注意：标志为以及全局变量每次循环的时候都要进行初始化
		for(int j=0;j<i;j++)
		{
			if(st[i]<st[j]){ t=j;s=1;break;}
		}
		if(s==1)                 //s==1说明比较的过程中有大于当前比较元素的，否则表示前边的元素都比当前的元素小，已经有序，
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










	



