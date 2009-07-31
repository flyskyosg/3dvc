#include<iostream.h>
#define max 50

void insertpx(int st[],int n )
{
	int t=0,p=0,s=0;             //t记录比较停止的位置,p暂存新纳入元素的值，这只标志位s，减少调用的次数
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

void disp(int st[],int n)
{
	for(int i=0;i<n;i++)
		cout<<st[i]<<" ";
	cout<<endl;
}

void main()
{
	int st[max],n=0,t=1;
	cout<<"输入元素,输入0结束:";
	cin>>t;
	for(n=0;n<max;n++)
	{
		if(t==0) break;
		st[n]=t;
		cout<<"输入元素,输入0结束:";
	    cin>>t;
	}
	cout<<"排序前:";
	disp(st,n);

	insertpx(st,n);
	cout<<"排序后:";
	disp(st,n);
}
	













		

	

