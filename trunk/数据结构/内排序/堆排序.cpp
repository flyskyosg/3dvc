#include<iostream.h>
#define max 10
int st[max]={0,5,6,4,8,7,9,8,1,3}; //规定从1号元素开始存放节点的关键字

void disp();
void creatheap(int n)      //初始建堆的过程,n为最后一个元素的序号（也可以作为调整堆的过程）
{
	int j=n,s=1,t=0;       //状态标志位s,当循环一趟不再进行交换的时候根据s的值决定是否停止循环，减少循环比较的次数
	while(j>=1&&s==1)      //外层循环控制要比较的趟数
	{
		s=0;
		int i=n/2;    
		while(i>=1)        //这层循环控制比较元素的标号，每次都是从n/2的元素位置上开始比较
		{
			
			if(st[2*i]>st[i]&&2*i<=n) {t=st[i];st[i]=st[2*i];st[2*i]=t;s=1;}            //根据当前根节点元素的值与左右孩子进行比较，找到比较大的元素
			if(st[2*i+1]>st[i]&&2*i+1<=n) { t=st[i];st[i]=st[2*i+1];st[2*i+1]=t;s=1;}
		    i--;
		}
		j--;
	}
}

void adjust(int n)
{
	int i=1,j=0,t=0,s=1;
	while(i<=n/2&&s==1)
	{
		s=0;
		t=st[i];j=0;
		if(st[2*i]>t&&2*i<=n) {t=st[2*i];j=2*i;s=1;}    
		if(st[2*i+1]>t&&2*i+1<=n) {t=st[2*i+1];j=2*i+1;s=1;}
		if(s==1) {st[j]=st[i];st[i]=t;i=j;}            //这里要注意在找到j后要把i与j的值进行交换后在把i值为j;
	}
}
		




void heap()                   //比较的主函数
{
	int j=2,t=0,n=max-1;      //j=2,控制排除至于一个元素的情况
	if(n>=2) creatheap(n);    //当数组中只有一个元素的时候不在进行排序
   	while(j<max)
	{
	 
	  t=st[1];                //每次排序找到最大的元素后，把他放到数组的最后一个位置上，并且把最后一个位置上的元素放到第一个位置，从新调整堆
	  st[1]=st[n];
	  st[n]=t;
	  n--;                    //n--把刚找到的元素排除在外，不需要在进行排序
	  //creatheap(n);	      //调整新的数组，n--;(也可以用重新建堆的方法进行调整，速度慢)	 
	  adjust(n);              //调整函数（速度快）
      j++;
	}
   
}






void disp()
{
	for(int i=1;i<max;i++)
		cout<<st[i]<<" ";
	cout<<endl;
}

void main()
{
	cout<<"排序前:";
    disp();
	cout<<"创建堆:";
	creatheap(max-1);
	disp();
	cout<<"排序后:";
	heap();
	disp();

}

	  
	  

	  

	



















		






































































