#include<iostream.h>
typedef int datatype;
typedef struct stack
{
	datatype *p;//定义数组
	int top;
	int k;
}Stack;
void statu(Stack * l)
{
	cout<<"栈指针"<<(*l).top;
}
void initstack(Stack & l) //初始化栈,把栈顶指针指向-1;//
{
    int *i=new int;
	cout<<"栈的空间:";
	cin>>*i;
	l.k=*i;
	l.p=new datatype[*i];
    l.top=-1;
}


void push(Stack &l) //入栈//
{
	datatype u;
	cout<<"输入数据,输入0结束:"<<endl;
	for(int i=0;i<l.k;i++ )
	{
    
	cin>>u;
	if(u==0) break;
	l.top++;
	l.p[l.top]=u;
	}
	if(l.top==l.k-1) cout<<"栈满."<<endl;
	cout<<"压入数据成功."<<endl;
} 
void pop(Stack & l)   //出栈//
{
	
	cout<<"输出元素:"<<l.p[l.top]<<endl;
	l.top--;
}
void disp(Stack & l) //输出栈内的所有元素//
{
	int i=l.top;
  while(i!=-1)
	{
		cout<<l.p[i]<<" ";
		i--;
		
	}cout<<endl;
}
void first (Stack &l) //取栈顶元素//
{
	cout<<"栈顶元素:"<<l.p[l.top]<<endl;
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







