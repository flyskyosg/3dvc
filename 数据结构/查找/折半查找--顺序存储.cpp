//****************二分查找**********************//
#include<iostream.h>
#include<stdio.h>
#define max 50
typedef char datatype;         //通用数据类型
int st[max],                   //全局数组，存放查找的数据
    k=-1;


void px()                      //排序函数（由小到大）
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
	printf("排序后的数据组是:");
	for(i=0;i<=k;i++)
		printf("%c ",st[i]);
	cout<<endl;
		

 


}

void creatst()                 //创建数据组 
{
 datatype n='\0';
 int i=1;
 cout<<"创建数据组,输入0结束操作."<<endl;
 do
 {
	 cout<<"输入第"<<i<<"个数据:";
	 cin>>n;
	 if(n=='0') break;
	 k++;st[k]=n;i++;
 }while(1);
 

}



int binsearch(datatype n)      //二分查找函数
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
	cout<<"请输入要查找的数据:";
	cin>>n;
	m=binsearch(n);
	switch(m)
	{
	case -1:cout<<"元素"<<n<<"不再数据组中."<<endl;break;
    default: cout<<"元素"<<n<<"在数据组的第"<<m+1<<"个位置."<<endl;break;
	}
}
	
			





