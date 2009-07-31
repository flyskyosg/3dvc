#include<iostream.h>
#include<iostream> 
typedef int datatype;
typedef struct node  //定义栈节点
{
	datatype data;
	struct node *next;
}node;
typedef struct//定义栈
{
	node *top;
}Lstack;

void initstack(Lstack & l) //初始化栈
{
	l.top=NULL;
}

bool empty(Lstack & l)//判断栈是否为空
{
	if(l.top==NULL) return 1;
	else return 0;
}

void push(Lstack & l,datatype x) //入栈,要注意判断是否是空战,空与不空不一样.
{
	node *p=(node *)malloc(sizeof(node));
	p->data=x;
	if(l.top==NULL)
	{
		p->next=NULL;
		
	}
	else
	{
		p->next=l.top;
	}

    l.top=p;
}

datatype pop(Lstack & l) //出栈.注意判断站空
{
	datatype t=l.top->data;
	node *p=l.top;
	if(empty(l))
	{
		cout<<"栈空."<<endl;return NULL;
	}
	else
	{
		l.top=p->next;
		free(p);
		return t;
	}
}

datatype read (Lstack & l) //读取栈顶元素
{
	return l.top->data;
}

void main()
{
	Lstack l;
	initstack(l);
	if(empty(l)) cout<<"栈空."<<endl;
	push(l,10);
	push(l,20);
	cout<<"当前栈顶元素:"<<read(l)<<endl;
	if(empty(l)) cout<<"栈空."<<endl;
	cout<<"第二个:"<<pop(l)<<endl;
	cout<<"第一个:"<<pop(l)<<endl;
	if(empty(l)) cout<<"栈空."<<endl;
}
































