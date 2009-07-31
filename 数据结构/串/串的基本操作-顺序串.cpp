#include<iostream.h>
#include<string.h>
#include<iomanip.h>
typedef int datatype;
#define size 10                           //主要编写串的一些复杂操作,以串的顺序存储结构为例.
typedef struct 
{
	datatype data[size];
	int len;
}sqstring;


void initstring(sqstring & l) //初始化串
{
	for(int i=0;i<size;i++)
	{
		l.data[i]=0;
	}
	l.len=0;
}

void creatstring( sqstring & l) //创建串
{
	int i=0,j=0;
	for(;i<size;i++)
	{
		cout<<"输入第"<<i<<"个元素,输入0结束.";
		cin>>j;
		if(j==0) break;
		l.data[i]=j;
		l.len++;
	}
}


bool recog(sqstring  a,sqstring  b) //判断两个串是否相等,
{
	int i=a.len,statue=0;
	if(i==b.len)
	{
		for(i--;i>=0;i--)
		{
			if(a.data[i]!=b.data[i]) statue=0;
		}
		if(statue==1) return 1;
	}
	else return  0;
}


void concat(sqstring a,sqstring b,sqstring & d)     //连接两个串
{
	int i=0,j=0;
	if((a.len+b.len)>size) cout<<"数据长度超出范围,无法连接."<<endl;
	else
	{
		for(;j<a.len;i++,j++)
			d.data[i]=a.data[j];
		for(j=0;j<b.len;i++,j++)
			d.data[i]=b.data[j];
	}
	d.len=a.len+b.len;
	
}

	
	
	
	
void substr(sqstring & l,int i,int j,sqstring & c)  //提取从第i个位置开始的依次包含j个元素的子串,//
{         

	
	initstring(c);
    int k=0,m=0;
    if((i+j+1)>size)
	{
		cout<<"超出范围."<<endl;
	}
	else
	{    
		m=--i;
		for(k;k<j-1;k++,m++)
		{
			c.data[k]=l.data[m];
			c.len++;
		}
		
	}
}



int index(sqstring a,sqstring b)            //查找子串b在主串a中的位置. //是实现子串的删除,插入,替换,操作的基础.
{
	int i=0,j=0,statue=0;
	for(;i<a.len;i++)
	{
		if(a.data[i]==b.data[0])
		{
			for(j=0;j<b.len;j++,i++)
			{
				if(a.data[i]==b.data[j]) statue=1;
				else statue=0;
			}
			if(statue==1) return i-b.len+1;//i是子串在主串的起始位置.
		}

	}
	if(statue==0) return 0;
}


void deletestr(sqstring & l,int i,int j)   //删除主串中从第i个位置起的j个元素.
{
	int n=i+j-1;
	if(j>l.len) cout<<"超出范围."<<endl;
	else
	{
		for(;n<=l.len-1;n++)
		{
		l.data[n-j]=l.data[n];
		
		}
		l.len-=j;
	
	}
}



void insert (sqstring & a ,int k,sqstring b)  //将子串插入到主串的第k个位置.
{
	int i=a.len-1,j=0;k--;
	if((a.len+b.len)>size) cout<<"超出范围."<<endl; 
	else
	{
		for(i;i>=k;i--) //从最后一个元素起分别向后移动j个位置,给b腾出空间.
		{
			a.data[i+b.len]=a.data[i];
		}
		i++;
		for(;j<b.len;j++,i++)
		{
			a.data[i]=b.data[j];
			a.len++;
		}
	}

}

void replace1(sqstring & a,sqstring b,sqstring c) //将子串b的所有元素替换为c,要求b与c一样长.
{
	int p=index(a,b);
	if(b.len!=c.len) cout<<"串长不一致."<<endl;
	else
	{

	for(int i=0;i<c.len;i++,p++)
		a.data[p]=c.data[i];
	}
}

void replace2(sqstring & a,sqstring b,sqstring c)
{
	if((a.len-b.len+c.len)>size) cout<<"超出范围."<<endl;
	else
	{
		int p=1;
	while(p!=0)
	{
		p=index(a,b);
		if(p==0) break;
	    deletestr( a,p,b.len);
	    insert( a,p,c);
	}

	
	}
}


void disp(sqstring l)
{
	int i=0;
	for(;i<l.len;i++)
		cout<<setw(3)<<l.data[i];
	cout<<endl;
}

void main()
{
	sqstring a,b,c,d;
	initstring(a);initstring(b);initstring(c);initstring(d);//初始化串
	cout<<"初始化后a串是:";
	disp(a);
	
	cout<<"创建a串."<<endl; //创建串a于b.
    creatstring(a);
	cout<<"创建b串."<<endl;
	creatstring(b);
	
	cout<<"a串是:";
	disp(a);
	cout<<"b串是:";
	disp(b);

	
	if(recog(a,b)==1) cout<<"a与b相等."<<endl; //判断a于b是否相等.
	else
	{
		cout<<"a与b不相等."<<endl;
	}
	
	cout<<"子串b在主串a的第"<<index(a,b)<<"位"<<endl;//查找串b在串a中的位置.

	cout<<"从a中删除从第1个位置起的3个元素后a为:";
	deletestr(a,1,3);                                         //主串的删除操作从a中删除从第i个位置起的k个元素.
	disp(a);

	cout<<"将b插入到a的第1个位置."<<endl;
	insert(a,1,b);
	disp(a);
	
	cout<<"创建c串."<<endl; //创建c串.
	creatstring(c);
	cout<<"c串是:";
	disp(c);

	cout<<"连接b于c串."<<endl; 
    concat(b,c,d);      //将b于c连接起来.
	cout<<"连接后是:";
	cout<<endl;
	disp(d);

    cout<<"将a中的b串全部替换为c."<<endl;
	replace2(a,b,c);
	cout<<"替换后a为:";
	disp(a);

    



	

}





















		   
			






	











