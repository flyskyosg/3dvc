#include<iostream.h>   //链式存储结构
#include<iostream>  
#include<string.h>
typedef char datatype;
#define max 100

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

void  creattree(ltree & l,datatype  str[])
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





void aoru(node * p,int n)
{
	if(p)
	{
	   for(int i=1;i<=n;i++)
		   cout<<"-";
	   cout<<p->data<<endl;
	  
	   if(p->lch) aoru(p->lch,n+1);
	   if(p->rch) aoru(p->rch,n+1);
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
	cout<<"凹入法显示:"<<endl;
	aoru(m.root,1);

	
}



