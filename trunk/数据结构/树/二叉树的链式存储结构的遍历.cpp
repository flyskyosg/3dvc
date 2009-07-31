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


void initltree(ltree & l)   //初始化二叉树
{
	l.root=NULL;
}
void  creattree(ltree & l,datatype  str[]) ///创建二叉树
{
	node * p=NULL;  //p用来指向树的节点
	int k=0,j=0,top=-1;  //k作为一个状态标志位,根据前一个元素的值来确定一个元素是左还是右孩子.或者退栈。
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


//*********************定义链队//

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
	if(l.front==NULL)
	{
		cout<<"队空."<<endl;return 0;
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
	if(l.front==NULL)
	{
		
		l.front=l.rear=p;
	}
	else
	{
		l.rear->next=p;
		l.rear=p;
	}
}

//*********************定义链栈//	

typedef struct snode  //定义栈的数据节点
{
	node * data;
	struct snode * next;
}snode;
typedef struct  //定义链栈
{
	snode * top;
	int len;
}lstack;




void initstack(lstack & l)  //初始化栈空间
{
	l.top=NULL;
	l.len=0;
}

node * read(lstack & l) //读取栈顶元素
{
	return l.top->data;
}


node * pop(lstack & l)  //出栈,返回指向树的节点的指针.
{
	snode *p=l.top;node * q;
	if(p==NULL) {cout<<"栈空.";return 0;}
	else
	{
		l.top=p->next;
		q= p->data;
		l.len--;
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
	 l.len++;
}



//********************二叉树的遍历--递归算法//





void preorder(node *p)  //先根遍历--递归算法 ,p指向的是树的根节点
{
	
	if(p!=NULL)
	{
	cout<<p->data<<" ";   
	preorder(p->lch);
	preorder(p->rch);
	}
}

void inorder(node *p)   //中根遍历--递归算法
{
	
	if(p!=NULL)
	{
	inorder(p->lch);
	cout<<p->data<<" ";
	inorder(p->rch);
	}
}

void postorder(node *p)    //后根遍历--递归算法
{
	
	if(p!=NULL)
	{
	postorder(p->lch);
	postorder(p->rch);
	cout<<p->data<<" ";
	}
}


//********************层次遍历//


bool levelorder(ltree & l)    //层次遍历--链式存储.
{
	lqueue a;initlqueue(a);    
	node * p=NULL;
	if(l.root!=NULL) 
	{
		push(a,l.root);    //先将根节点事先入栈
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

//***************************根的遍历的栈辅助算法//


void spreorder(ltree & l)  //先根遍历的的栈辅助算法.
{
	lstack a;initstack(a);
	node * p=l.root;
	if(p!=NULL)
	{   
		push(a,NULL); //要首先将一个元素放进栈中的第一个位置,为后便的循环作做准备.
		do              //这里使用while()循环也可以,但是要注意循环终止的条件是栈空,所以上一步要事先将一个元素放进栈底。
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
				
				if(p->rch!=NULL) p=p->rch; //如果左孩子不存在,且右孩子存在,直接指向其右孩子.如果左右孩子都不存在,则开始出栈.
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

void spostorder(ltree & l)   //后根遍历的栈辅助算法.
{

 	lstack a;initstack(a);
	node * p=l.root,* q=NULL,*r=NULL;
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
			
				if(p->rch!=NULL) p=p->rch; //如果右孩子存在,直接指向其右孩子.如果左右孩子都不存在,则开始出栈.
				else 	
				{
					cout<<p->data<<" ";r=p;
					while(a.top!=NULL)//依次从栈中弹出元素直到栈空。
					{
					p=read(a);
					if(p==NULL) {pop(a);break;} //如果弹出来的元素是事先预存进去的NULL那么说明站内的的元素处理完毕，退出循环。
					if(p->rch==q&&p->rch!=r)
					{
						p=pop(a);cout<<p->data<<" ";q=p;
					}
					else
					{
					 if(p->rch!=NULL) p=p->rch;
					}

					
				
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
	cout<<"层次遍历."<<endl;
	levelorder(m); 
	cout<<endl;
	cout<<"递归遍历."<<endl;
	cout<<"先序遍历:"<<endl;
	preorder(m.root);cout<<endl;
	cout<<"中序遍历"<<endl;
	inorder(m.root);cout<<endl;
	cout<<"后序遍历"<<endl;
	postorder(m.root);cout<<endl;
	cout<<"栈辅助算法:"<<endl;
	cout<<"先序遍历-栈辅助算法."<<endl;
	spreorder(m);
	cout<<endl;
	cout<<"中序遍历-栈辅助算法."<<endl;
	sinorder(m);
	cout<<endl;
	cout<<"后序遍历-栈辅助算法."<<endl;
	spostorder(m);
	cout<<endl;
}





			














		

	
	



	