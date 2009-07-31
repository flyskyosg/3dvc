#include<iostream.h>
#include<iostream>
#define max 50

typedef struct lnode
{
	int key;
	char data;
	struct lnode * next;
}lnode;


lnode * st[max];
//***哈希函数******************//
int hax(int key)
{
	return key%45;
}
//**********创建表******************//
void creat()
{
	int i=0;
	for(i;i<max;i++)
		st[i]=NULL;


	int key,n;char data='\0';lnode * p=NULL,*q=NULL;
	cout<<"输入关键字与数据(key_data),输入0_0结束操作:";
	cin>>key>>data;

    while(data!='0')
	{
	if(key>max||key<0) cout<<"关键字超出范围."<<endl;
	else
	{
		p=(lnode *)malloc(sizeof(lnode));
		p->data=data;
		p->key=key;
		p->next=NULL;
		n=hax(key);
		if(st[n]!=NULL) p->next=q;
			
	    st[n]=p;q=p;
		
	
	}
	cout<<"输入关键字与数据(key_data):";
	cin>>key>>data;
	}


	
}
//*************输出函数******************//
void disp()
{
	lnode * p=NULL;int i=0;
	cout<<"输出如下:";
	for( i=0;i<max;i++)
	{
		p=st[i];
		while(p!=NULL)
		{
			cout<<p->key<<"_"<<p->data<<" ";
			p=p->next;
		}
		cout<<"   ";
	
		
	}
}




//*************查找表元素*****************//

void search()
{   
	int key;
	cout<<"输入查找的关键字:";
	cin>>key;
	int n=0;lnode * p=NULL;
	n=hax(key);
	p=st[n];
	while(p->key!=key)	p=p->next;
    cout<<"要查找的元素是:";
    cout<<p->key<<"_"<<p->data<<endl;
}
//*************插入元素****************//

void insert()
{
	int key,n;char data='\0';lnode * p=NULL,*q=NULL;
	cout<<"输入要插入的关键字与数据(key_data):";
	cin>>key>>data;
	if(key>max||key<0) cout<<"关键字超出范围."<<endl;
	else
	{
	    n=hax(key);
		p=(lnode *)malloc(sizeof(lnode));
		p->data=data;
		p->key=key;
		p->next=NULL;
		if(st[n]!=NULL) p->next=q;
			
	    st[n]=p;q=p;
	}
}
		
//************删除元素***********************//
void delelem()
{
    int key=0,n=0;
	cout<<"输入删除的关键字:";
	cin>>key;

    n=hax(key);
	lnode * p=NULL,*q=NULL;
	p=st[n];

	while(p->key!=key)
	{
		q=p;
		p=p->next;
	}
	if(q==NULL) st[n]=p->next;
	else q=p->next;
	delete p;
}


//**********主函数*****//
void main()
{
	creat();
	disp();
	insert();
	disp();
	search();
	delelem();
	disp();

}







