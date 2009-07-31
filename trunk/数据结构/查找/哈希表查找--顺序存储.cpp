#include<iostream.h>  //哈希表的开放性解决冲突
#define max 50

typedef struct node
{
	int key;
	char data;
}node;

node st[max];      //存储表


int sol(int key)   //+1在散列(冲突函数)
{
	return (key+1)%max;
}


int hax(int key)   //哈希函数
{
	int n=-1;
	n=key%45;
	while(st[n].data!='\0')   //处理冲突
	{
		n++;
		n=sol(n);
	}
	return n;
}


void main()
{  
	int i=0;
	for(i;i<max;i++)
		st[i].data='\0';


	int key,n;char data='\0';
	cout<<"输入关键字与数据(key_data),输入0_0结束操作:";
	cin>>key>>data;

    while(data!='0')
	{
	if(key>max||key<0) cout<<"关键字超出范围."<<endl;
	else
	{
		n=hax(key);
		st[n].data=data;
		st[n].key=key;
	}
	cout<<"输入关键字与数据(key_data):";
	cin>>key>>data;
	}
	cout<<"输出如下:";
	for(i=0;i<max;i++)
	{
		if(st[i].data!='\0') cout<<st[i].key<<"_"<<st[i].data<<" ";
	}
}
		





