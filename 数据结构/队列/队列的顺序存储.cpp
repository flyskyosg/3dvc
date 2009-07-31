#include<iostream.h>
typedef int datatype;
#define size 4
typedef struct queue
{
	datatype data[size];
	int front,rear;
}dl;

void initdl(dl & l)
{
	l.front=l.rear=0;
	for(int i=1;i<size;i++)
		l.data[i]=0;

}

bool empty(dl & l)
{
	if(l.front==l.rear) return 1;
	else return 0;
}

bool full(dl & l)
{
	if((l.rear+1)%size==l.front) return 1;
	else return 0;
}

datatype pop(dl & l)
{
	if(empty(l)==0)
	{
		datatype t=l.data[(l.front+1)%size];
		l.data[(l.front+1)%size]=0;
	    l.front=(l.front+1)%size;
		return t;
	}
	else
	{
		cout<<"队空."<<endl;
		return 0;
	}
}

void push(dl & l,datatype x)
{
	if(full(l)==0)
	{
		l.rear=(l.rear+1)%size;
		l.data[l.rear]=x;
	}
	else
	{
		cout<<"队满."<<endl;
	}
}

datatype read(dl & l)
{
	return l.data[(l.front+1)%size];
}

void main()
{
	dl l;
	initdl(l);
	if(empty(l)) cout<<"队空."<<endl;if(full(l))cout<<"队满."<<endl;
	push(l,1);
	push(l,2);
	push(l,3);
    push(l,4);
	push(l,5);
	cout<<"出队一次:"<<pop(l)<<endl;cout<<"出队二次:"<<pop(l)<<endl;
	push(l,6);push(l,7);
	if(empty(l)) cout<<"队空."<<endl;if(full(l))cout<<"队满."<<endl;
	for(int i=1;i<=5;i++)
	{
		cout<<pop(l)<<endl;
	}
	if(empty(l)) cout<<"队空."<<endl;if(full(l))cout<<"队满."<<endl;
}








		


