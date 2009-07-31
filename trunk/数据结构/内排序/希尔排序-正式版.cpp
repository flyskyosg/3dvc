#include<iostream.h>
#define max 50
int st[max],                        //存放数据
    top=0;
int inc[]={1,3,5,7,11};             //增量序列

void insertpx(int j,int inc)        //根据插入排序改写，要注意元素之间的间隔为每次循环比较的增量，但该函数只能处理增量不等于1的排序，最后一次排序用其他的函数处理        
{
	int k=0,t=0,p=0,z=0;
	for(k=j+inc;k<=top-1;k+=inc)    //控制纳入新元素
	{
	      t=0;p=0;
		  if(st[k]<st[k-inc])        //如果新纳入的元素比其前边的元素大，则不用排序，
		  {
			  for(z=j;z<k;z+=inc)    //找到第一个比该元素大的元素 
			  {
				  if(st[k]<=st[z]) {t=z;break;}
			  }
			  p=st[k];
			  for(z=k-inc;z>=j;z-=inc)//将该元素在村后，一次移动元素，完成一次排序
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

void insertpx0();                 //处理最后一次排序

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

void insertpx0()                 //最后一次排序必须用另外的函数排序，当增量等于1的时候，必须用单独的函数逐个排序                   
{
	int t=0,p=0,s=0,n=top;       //t记录比较停止的位置,p暂存新纳入元素的值，这只标志位s，减少调用的次数
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
	int n=0,i=1;
	cout<<"输入第"<<i<<"个数据,endof(0):";
	cin>>n;
	while(n!=0)
	{
		st[top]=n;
		top++;
		i++;
		cout<<"输入第"<<i<<"个数据,endof(0):";
	    cin>>n; 
	}  
	
	disp();
	shell();
}










	



