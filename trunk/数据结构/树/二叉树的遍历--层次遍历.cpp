#include<iostream.h>   //链式存储结构
#include<iostream>  
#include<string.h>
#define max 100
typedef char datatype;

typedef struct node    //二叉链表的节点
{
	datatype data;
	struct node * lch;
	struct node * rch;
}node;
typedef struct         //二叉链表定义
{
	 struct node * root;
}ltree;


void initltree(ltree & l)   //初始化二叉树
{
	l.root=NULL;
}

void  creattree(ltree & l,datatype  str[]) //括号法创建二叉树
{
	node * p=NULL;  //p用来指向树的节点
	int k=0,j=0,top=-1;  //k作为一个状态标志位,根据前一个元素的值来确定一个元素是左还是右孩子.或者退栈
	node * a[max];    //作为存储双亲节点的顺序栈使用。
	datatype t=str[j];   //t作为暂存数组元素值的中间变量。

	while(t!='\0')
	{
		switch(t)
		{
		case '(':top++;a[top]=p;k=1;break;
		case ')':top--;break;
		case ',':k=2;break;
		default:
			{
				p=(node *)malloc(sizeof(node));
				p->data=t;p->lch=NULL;p->rch=NULL;
				if(l.root==NULL){ l.root=p;break;}
				else
				{
					switch(k)
					{
					case 1:a[top]->lch=p;break;
					case 2:a[top]->rch=p;break;
				
					}
				}

			}
			
		}
		j++;
		t=str[j];
	}
}

typedef struct lnode  //定义链队的节点
{
	node * data;
	struct lnode * next;
}lnode;
typedef struct        //定义链队列
{
	lnode * front;
	lnode * rear;
}lqueue;

void initlqueue(lqueue & l) //初始化链队.
{
	l.rear=l.front=NULL;
}


node * pop(lqueue & l)    //出队
{
	if(l.front==NULL) //这立要注意判断栈链栈为空的条件是队头指针是否为空.
	{
		cout<<"队空."<<endl;return NULL;
	}
	else
	{
	lnode * p=l.front;node * q;
	l.front=p->next;
    q=p->data;
	free(p);
	return q;
	}
}

void push(lqueue & l,node * x)//入队
{
	lnode * p=(lnode *)malloc(sizeof(lnode));
	p->data=x;
	p->next=NULL;
	if(l.front==NULL)  //这立要注意判断栈链栈为空的条件是队头指针是否为空.
	{
		
		l.front=l.rear=p;
	}
	else
	{
		l.rear->next=p;
		l.rear=p;
	}	

}



bool levelorder(ltree & l)    //层次遍历--链式存储.
{
	lqueue a;initlqueue(a);    
	node * p=l.root;
	if(p!=NULL) 
	{
		push(a,p);    //先将根节点事先入栈
		while(a.front!=NULL)//栈空为循环终止的条件
		{
		p=pop(a);       
		cout<<p->data<<" "; //出栈顶元素
		if(p->lch!=NULL) push(a,p->lch);//将该元素的左孩子及有孩子入栈,(如果存在);
		if(p->rch!=NULL) push(a,p->rch);
		}
		return 1;
	}
	else 
	{
		cout<<"树空";return 0;
	}
	
}



void main()
{
	ltree m;initltree(m);
    cout<<"输入数据(树的括号表示法,限100个字符以内)."<<endl;
    datatype p[max];
    cin>>p;
	cout<<p<<endl;
	creattree(m,p);
	cout<<"层次遍历."<<endl;
	levelorder(m);
}