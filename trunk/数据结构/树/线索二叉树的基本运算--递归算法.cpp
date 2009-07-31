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




node * pre;              //全局变量,存储上一个遍历过的节点地址。
void thread(node *  p)  //递归的遍历二叉树，并且线索化，为后便的函数调用做准备
{
	if(p!=NULL)          //在树不空的条件下进行遍历
	{
		thread(p->lch);  //遍历当前树的左子树，如果左子树存在，依次向下，知道某个节点的左子树不存在，停止，进行判断，然后逐级返回。这个和栈辅助算法的本质一样。
		if(p->lch==NULL) //遍历完左子树后判断但前节点的左域是否为空;
		{
			p->lch=pre;  //如果子树为空，则存储pre。
			p->ltag=1;
		}
		if(pre->rch==NULL)//如果左子树的又子树为空，则存储p;
		{
			pre->rch=p;
			pre->rtag=1;
		}
		pre=p; //这里要注意：当遍历完一个节点的左子树后要把pre指向p；然后在遍历p的右子树，因为是中跟遍历，遍历完节点的左字数后必然要遍历右子树，所以这个语句放在这，	

	    thread(p->rch);//遍历该节点的右子树，
	}
}
			

		

node * cthread(node *  p)  //在该函数中创建当前树的头节点,方便算法的实现。这个函数返回头节点的地址,p指向树的根节点
{
      node * head=(node *)malloc(sizeof(node ));
	  pre=head;      //pre初始时指向头结点，
	  if(p!=NULL)    //在树不空的条件下执行遍历
	  {
		  pre->lch=p;
		  pre->ltag=0;
		  thread(p);  //调用thread函数
		  pre->rch=head; //线索化完毕后要pre指向的树的头节点，其实这时候pre和p是指向最后一个节点的.
		  pre->rtag=1;   
		  head->rch=pre; //把头节点也指向最后一个节点，使头结点和最后一个节点互相指向
		  head->rtag=1;
	  }
	  else       //如果树不存在，则把头节点的左右孩子域均复位空.
	  {
		  head->rch=head->lch=NULL;  
		  head->ltag=head->rtag=0;
	  }
	  return head;  //返回树的头节点的地址，
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
	node * p=lastnode(l);  //p先找到中序遍历的最后节点，然后依次输出其前驱节点
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
	t=cthread(m.root);
	cout<<"顺序输出中序线索二叉树的序列"<<endl;
	thinorder(t);
	cout<<"逆序输出中序线索二叉树的序列"<<endl;
	uthinorder(t);
		
}








	
