#include<iostream.h>
typedef int datatype;
typedef struct stack
{
	datatype *p;//��������
	int top;
	int k;
}Stack;
void statu(Stack * l)
{
	cout<<"ջָ��"<<(*l).top;
}
void initstack(Stack & l) //��ʼ��ջ,��ջ��ָ��ָ��-1;//
{
    int *i=new int;
	cout<<"ջ�Ŀռ�:";
	cin>>*i;
	l.k=*i;
	l.p=new datatype[*i];
    l.top=-1;
}


void push(Stack &l) //��ջ//
{
	datatype u;
	cout<<"��������,����0����:"<<endl;
	for(int i=0;i<l.k;i++ )
	{
    
	cin>>u;
	if(u==0) break;
	l.top++;
	l.p[l.top]=u;
	}
	if(l.top==l.k-1) cout<<"ջ��."<<endl;
	cout<<"ѹ�����ݳɹ�."<<endl;
} 
void pop(Stack & l)   //��ջ//
{
	
	cout<<"���Ԫ��:"<<l.p[l.top]<<endl;
	l.top--;
}
void disp(Stack & l) //���ջ�ڵ�����Ԫ��//
{
	int i=l.top;
  while(i!=-1)
	{
		cout<<l.p[i]<<" ";
		i--;
		
	}cout<<endl;
}
void first (Stack &l) //ȡջ��Ԫ��//
{
	cout<<"ջ��Ԫ��:"<<l.p[l.top]<<endl;
}
void main()
{
	Stack a;
	initstack(a);
    
	push(a);
	
	disp(a);

	pop(a);
	disp(a);
	first(a);
}







