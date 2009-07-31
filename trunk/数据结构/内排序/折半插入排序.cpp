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
	int t=0,p=0,j=0;             //t记录比较停止的位置,p暂存新纳入元素的值，
	for(int i=1;i<n;i++)
	{
		t=0;p=0;                 //注意：标志为以及全局变量每次循环的时候都要进行初始化
		if(st[i]<st[i-1])        //如果新加入的元素比其前边的元素大的话，不进行比较，直接纳入新的元素，
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
	













		

	

