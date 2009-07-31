#include<iostream.h>   //链式存储结构
#include<iostream>  
#include<string.h>
typedef char datatype;
#define max 100

typedef struct node    //二叉链表的节点
{
	datatype data;
	struct node * lch,* rch;
	int ltag,rtag;
}node;
typedef struct         //二叉链表定义
{
	 struct node * root;
}ltree;


void initltree(ltree & l)   //初始化二叉树
{
	l.root=NULL;
}
//*****************************括号法创建二叉树******************************//
void  creattree(ltree & l,datatype  str[])  //括号法创建一颗二叉树
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
				p->data=t;p->lch=NULL;p->rch=NULL;p->ltag=0,p->rtag=0;
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



//**************************二叉树的线索化**********************//
void takeplace(node * &p,node * &pre) 
{
            cout<<p->data<<" ";
		    if(p->lch==NULL)
			{
			p->lch=pre;
			p->ltag=1;
			}
		    if(pre->rch==NULL)
			{
			pre->rch=p;
			pre->rtag=1;
			}
		    pre=p;
}


node * inthread(node * p) //l指向二叉树的根节点 //为方便算法的实现，规定把头节点的左域指向根节点，右域指向二叉树线索化的最后一个节点
{
	node * pre=NULL,*head=NULL;node * a[max],*t=p;int top=-1;//pre指向上一个线索化的节点，head为增加的头结点，最后返回该头结点，a为一个顺序栈，用来存储元素，t存储遍历二叉树的最后一个节点，用来左循环终止的条件。top为栈顶指针
	head=(node *)malloc(sizeof(node));
	pre=head;            //初始时pre指向头节点
	if(p!=NULL)           
	{
		pre->lch=p;pre->ltag=0;  //在树不空的条件下使头结点的左域指向跟节点，右域暂时复位空，
		pre->rch=NULL;pre->rtag=1; //
		
         
		
		while(t->rch!=NULL)  //找到中序输出二叉树的最后一个节点，为后面的循环左终止条件，当pre指向t即最后一个节点的时候，线索化完毕
			t=t->rch;


   		while(pre!=t)
		{
			while(p->lch!=NULL)  //先找到线索化的第一个节点，树的最左下边节点，并且把中间的节点入栈保存
			{
			top++;
			a[top]=p;
			p=p->lch;
			}
			
			takeplace(p,pre);  //找到节点后，处理p于pre;
	    	
	    	while(top>-1)      //处理后依次出栈
			{

			   p=a[top];
			   top--;
		       
			   takeplace(p,pre);
		      
			   if(p->rch!=NULL)  //当出栈的节点没有右子树的时候，继续出栈，反之转向其右子树，终止循环，重新开始判断。
			   {
			   p=p->rch;break;
			   }
			}
	 	
		}

		head->rch=pre;  //最后当pre指向最后的一个节点的时候，把pre指向头节点，把头节点的后继指向pre;(为方便算法的实现)
		head->rtag=1;
		pre->rch=head;
		pre->rtag=1;
	
	}

    return head;  //最后返回头节点，


}
//********************输出中序线索二叉树的遍历序列**********************//
node * firstnode(node * l)   //找中序线索遍历的的第一个节点，这里的l为头结点
{
	while(l->ltag==0)
		l=l->lch;
	return l;
}

node * lastnode(node * l)  //找中序线索遍历的最后一个节点 ，这里的l为头结点
{
	l=l->lch;
	while(l->rtag==0)
		l=l->rch;
	return l;
}

node * prenode(node * p)   //找当前节点的前驱节点
{
	if(p->ltag==1)
		return p->lch;
	else
	{ 
		p=p->lch;
	    while(p->rtag==0)
			p=p->rch;
		return p;
	}
}

node * postnode(node * p)   //找当前节点的后继节点
{
	if(p->rtag==1)
		return p->rch;
	else
	{ 
		p=p->rch;
	    while(p->ltag==0)
			p=p->lch;
		return p;
	}
}


void thinorder(node * l)   //顺序输出线索二叉树，l为头结点
{
	node * p=firstnode(l); //p先找到中序遍历的第一个节点，然后依次输出其后继节点
	while(p!=l)            
	{
		if(p->rtag==1)     
		{
		cout<<p->data<<" ";
		p=p->rch;
		}
     	else
		{
		cout<<p->data<<" ";
		p=postnode(p);
		}
	}
}

void uthinorder(node * l)//逆序输出线索二叉树，l为头节点。
{
	node * p=lastnode(l);  //p先找到中序遍历的最后节点，然后依次找其前驱节点
	while(p!=l)
	{
		if(p->ltag==1)
		{
		cout<<p->data<<" ";
		p=p->lch;
		}
	    else
		{
		cout<<p->data<<" ";
		p=prenode(p);
		}
	}
}


//********************************主函数************************************//		  
void main()
{ 
	
	ltree m;initltree(m);
	cout<<"输入数据(树的括号表示法,限100个字符以内)."<<endl;
    datatype p[max];
    cin>>p;
	cout<<p<<endl;
	creattree(m,p);
	cout<<endl;


	cout<<"线索化二叉树"<<endl;
	node * t;
	t=inthread(m.root);
	cout<<endl;
	cout<<"顺序输出中序线索二叉树的序列"<<endl;
	thinorder(t);
	cout<<endl;
	cout<<"逆序输出中序线索二叉树的序列"<<endl;
	uthinorder(t);
	cout<<endl;

		
}








	
