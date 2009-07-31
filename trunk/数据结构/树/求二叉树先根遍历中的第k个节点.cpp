#include<iostream.h>   //链式存储结构
#include<iostream>
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


void  creattree(ltree & l,datatype  str[])  //括号法建立二叉树
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

int t=0,k;

int  preorder(node *p)  //先根遍历--递归算法 ,p指向的是树的根节点
{
	
	if(p!=NULL)
	{
    t++;
	if(t==k){	cout<<p->data<<"为第"<<k<<"个位置上的节点."<<endl; return 1;  }

	preorder(p->lch);
	preorder(p->rch);
	}
	else
	{
		return 0;
	}
}

void main()
{
	ltree a;a.root=NULL;
    cout<<"输入数据(树的括号表示法,限100个字符以内)."<<endl;
    datatype p[max];
    cin>>p;
	cout<<p<<endl;
	creattree(a,p);
	cout<<"输入位置:";
	cin>>k;
	cout<<endl;
    preorder(a.root);
}


