#include<iostream.h>     //循环双链表
typedef struct node         //定义节点的数据结构
{
	int data;
	struct node *prior;
	struct node *next;
}Node;
typedef struct list  //定义表的数据结构
{
	Node *head;
	int length;
}List;
void initlist(List & l)      //初始化双链表
{
	l.head=NULL;
	l.length=0;
}
void creatlist(List & l)
{
	Node *p,*q;int i=1;

	cout<<"请输入数据,输入0结束操作:"<<endl;
	while(i!=0)
	{
	p=new Node;
	cin>>i;
	if(i==0) break;
	p->data=i;
    if(l.head==NULL)     //这里要判断表是否为空表,如果是空表,
	{
		
		p->next=p;
		p->prior=p;
		l.head=p;
		q=l.head;
	
	}
	else
	{
		q->next=p;  //当表不是空表的时候雨表示空表的时候不同//
		p->prior=q;
		p->next=l.head;
		(l.head)->prior=p;
		q=p;
	}
	l.length++;
	
	}
	cout<<"建表结束."<<endl;
}
void putin(List & l)           //在某一位置上插入元素//
{
	int i=1,j=1;Node *q=l.head,*p,*r;
	p=new Node;
	cout<<"请输入插入元素的值:";
	cin>>p->data;
	cout<<"请输入插入位置:";cin>>i;cout<<endl;
	if(i<1||i>l.length+1) cout<<"position error.";
	else
	{
        while(j!=i)          //寻找插入元素的位置//
		{
			q=(*q).next;
			j++;
		}
	
			r=(*q).prior;       //实现插入算法//
		    p->next=q;p->prior=r;
		    q->prior=p;r->next=p;
			if(i==1) l.head=p;
	}
	l.length++;      //插入后不能忘记把表长增加
}
	
void deletelist(List & l) //删除某一位置上的元素
{
	int i=1,j=1;Node *q=l.head,*r,*p;
	cout<<"输入删除元素的位置:";cin>>i;
	if(i<1||i>l.length) cout<<"position error.";
	else 
	{
		while(j!=i)      //寻找删除元素的位置,
		{
			q=q->next;
			j++;
		}
		r=q->prior;        
		p=q->next;
		r->next=p;
		p->prior=r;
		if(q==l.head)     //需要判断一下是否把第一个元素删除,如果删除第一个元素,需要把头指针指向下一个元素.
		{
			l.head=p;
		}
	}
	l.length--;
}
void lookfor(List &l) //按照序号查找元素
{
	int i=1,j=1;Node *q=l.head;
    cout<<"请输入元素位置:";cin>>i;cout<<endl;
	if(i<1||i>l.length) cout<<"position error.";
	else
	{
        while(j!=i)
		{
			q=q->next;
			j++;
		}
	
		cout<<"该元素是:"<<q->data<<endl;
	}
}
void disp(List &l)  //输出表中所有元素
{
	Node *p=l.head;
	cout<<"该表的元素列表是:"<<endl;
	for(int i=1;i<=l.length;i++)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}

void main()          
{
	List l;
	initlist(l);
	creatlist(l);
	disp(l);
	putin(l);
    disp(l);
	deletelist(l);
	disp(l);
	lookfor(l);
}
	



	
		




	

	



		
	




