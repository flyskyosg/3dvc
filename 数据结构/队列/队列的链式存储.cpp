#include<iostream.h>
#include<iostream>
typedef int datatype;
typedef struct node
{
	datatype data;
	struct node *next;
}dlnode;
typedef struct queue
{

	node *front,*rear;
}dl;
void initdl(dl & l)
{
	l.front=l.rear=NULL;
}
bool empty(dl & l)
{
	if(l.front==NULL) return 1;
	else return 0;
}
datatype read(dl & l)
{
	return l.front->data;
}

void push(dl & l,datatype x)
{
	
	node *p=(node *)malloc(sizeof(node));
	p->data=x;p->next=NULL;
	
	if(empty(l))
	{
	l.front=p;l.rear=p;
	}
	else
	{
		l.rear->next=p;
		l.rear=p;

	}
}

datatype pop(dl & l)
{
	datatype t=read(l);
	node *p=l.front;
	l.front=l.front->next;
	free(p);
	return t;
}

void main()
{
	dl l;
	initdl(l);
	if(empty(l)) cout<<"队空."<<endl;
	push(l,10);
	push(l,20);
	if(empty(l)) cout<<"队空."<<endl;
	else cout<<"队不空."<<endl;
	cout<<"元素一:"<<pop(l)<<"元素二:"<<pop(l)<<endl;
	if(empty(l)) cout<<"队空."<<endl;
	else cout<<"队不空."<<endl;

}






































