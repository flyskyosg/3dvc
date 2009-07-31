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
	  int t=st[i],           //t存储轴元素,默认区间的第一个元素为轴元素
		  zi=i,zj=j;         //记录i与j的出示位置，方便后便的递归传递参数
	                 
      
		while(i!=j)
		{

       
		while(j!=i&&st[j]>=t) j--;
		if(j>i)st[i]=st[j];            //当循环比较结束后j>i说明找到了比t小的元素，进行替换
			

	
		while(i!=j&&st[i]<=t) i++;
		
		if(i<j) st[j]=st[i];           //当循环比较结束后i<j说明找到了比t小的元素，进行替换
		}
	    st[j]=t;
	    fastpx(zi,j-1);
  	    fastpx(j+1,zj);
                   

	}

	
	
}

void main()
{
	cout<<"排序前:";
	disp();
    fastpx(0,max-1);
	cout<<"排序后:";
	disp();
}

	
	







