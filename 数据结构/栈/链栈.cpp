#include<iostream.h>
#include<iostream> 
typedef int datatype;
typedef struct node  //����ջ�ڵ�
{
	datatype data;
	struct node *next;
}node;
typedef struct//����ջ
{
	node *top;
}Lstack;

void initstack(Lstack & l) //��ʼ��ջ
{
	l.top=NULL;
}

bool empty(Lstack & l)//�ж�ջ�Ƿ�Ϊ��
{
	if(l.top==NULL) return 1;
	else return 0;
}

void push(Lstack & l,datatype x) //��ջ,Ҫע���ж��Ƿ��ǿ�ս,���벻�ղ�һ��.
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

datatype pop(Lstack & l) //��ջ.ע���ж�վ��
{
	datatype t=l.top->data;
	node *p=l.top;
	if(empty(l))
	{
		cout<<"ջ��."<<endl;return NULL;
	}
	else
	{
		l.top=p->next;
		free(p);
		return t;
	}
}

datatype read (Lstack & l) //��ȡջ��Ԫ��
{
	return l.top->data;
}

void main()
{
	Lstack l;
	initstack(l);
	if(empty(l)) cout<<"ջ��."<<endl;
	push(l,10);
	push(l,20);
	cout<<"��ǰջ��Ԫ��:"<<read(l)<<endl;
	if(empty(l)) cout<<"ջ��."<<endl;
	cout<<"�ڶ���:"<<pop(l)<<endl;
	cout<<"��һ��:"<<pop(l)<<endl;
	if(empty(l)) cout<<"ջ��."<<endl;
}
































