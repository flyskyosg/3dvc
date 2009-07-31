#include<iostream.h>   //链式存储结构
#include<iostream>  
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


void  creattree(ltree & l,datatype  str[]) ///创建二叉树
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

void initltree(ltree & l)   //初始化二叉树
{
	l.root=NULL;
}

typedef struct snode  //定义栈的数据节点
{
	node * data;
	struct snode * next;
}snode;
typedef struct  //定义链栈
{
	snode * top;
}lstack;

void initstack(lstack & l)//初始化栈空间
{
	l.top=NULL;
}

node * pop(lstack & l)  //出栈,返回指向树的节点的指针.
{
	snode *p=l.top;node * q;
	if(p==NULL) {cout<<"栈空.";return 0;}
	else
	{
		l.top=p->next;
		q= p->data;
		free(p);
		return q;

	}
}

void push(lstack & l,node * x) //入栈函数
{
	 snode * p=(snode *)malloc(sizeof(snode ));
	 p->data=x;
	 p->next=l.top;
	 l.top=p;
}



void spreorder(ltree & l)  //先根遍历的的栈辅助算法.
{
	lstack a;initstack(a);
	node * p=l.root;
	if(p!=NULL)
	{   
		push(a,p); //要首先将一个元素放进栈中的第一个位置,为后便的循环作做准备.
		do              //这里使用while()循环也可以,但是要注意循环终止的条件是栈空,所以上一步要事先将一个元素放进栈底
		{
			cout<<p->data<<" ";  //先根遍历时遇到节点时先将节点的值输出.
			if(p->lch!=NULL)       //如果左孩子存在将p指向其左孩子,并且如果其有又孩子,将又孩子进栈保存.
			{
				if(p->rch!=NULL)
				push(a,p->rch);
				p=p->lch;
			}

			else
			{
				
				if(p->rch!=NULL) p=p->rch; //如果左孩子不存在,且右孩子存在,直接指向其右孩子.若果左右孩子都不存在,则开始出栈.
				else p=pop(a);
					 
			}
		}while(a.top!=NULL);//判断条件是栈是否为空.
	}
	else cout<<"树为空."<<endl;
}

void sinorder(ltree & l)   //中根遍历的栈辅助算法.
{

 	lstack a;initstack(a);
	node * p=l.root;
	if(p!=NULL)
	{   
	    push(a,NULL);       //要首先将一个元素放进栈中的第一个位置,为后边的循环做准备.
		while(a.top!=NULL)       //判断条件是:栈是否为空.  这里使用 while()循环也可以,但是要注意循环终止的条件是栈空,所以上一步要事先将一个元素放进栈底
		{
			
			if(p->lch!=NULL)     //如果左孩子存在;
			{
				push(a,p);       //将当前的根节点入栈.
				p=p->lch;        //并且指向其左孩子.
			}

			else
			{
				cout<<p->data<<" ";
				if(p->rch!=NULL) p=p->rch; //如果右孩子存在,直接指向其右孩子.如果左右孩子都不存在,则开始出栈.
				else 	
				{
					while(a.top!=NULL)//依次从栈中弹出元素知道直到站空
					{
					p=pop(a);
					if(p==NULL) break;  //如果弹出来的元素是事先预存进去的NULL那么说明站内的的元素处理完毕，退出循环。
					cout<<p->data<<" "; //因为是中序遍历，所以出站后先输出该节点。
					if(p->rch!=NULL) {p=p->rch;break;}//如果弹出的元素具有右孩子，那么指向其右孩子并退出开始新的判断。
				
					}
				}
				
			}
			
		
				
		

		}
	}
	else cout<<"树为空."<<endl;


}


void main()
{
	ltree m;initltree(m);
	cout<<"输入数据(树的括号表示法,限100个字符以内)."<<endl;
    datatype p[max];
    cin>>p;
	cout<<p<<endl;
	creattree(m,p);
	cout<<"先根遍历-栈辅助算法."<<endl;
	spreorder(m);
	cout<<"中根遍历-栈辅助算法."<<endl;
	sinorder(m);


}