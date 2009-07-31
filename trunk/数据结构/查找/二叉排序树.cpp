#define max 50                         
#include<iostream.h>
#include<iostream>
typedef char datatype;
typedef int keytype;
typedef struct node                    //定义节点的类型（关键字以及数据）
{
	keytype key;
	datatype data;
	struct node *lch,*rch;
}node;
typedef struct array
{
	keytype key;
	datatype data;
}array;                                         
//*******************创建二叉排序树*********************//

void creattree(node * & l,array st[])
{
	int i=1;node * p=NULL;            //这里把st数组的0号为作为一个标准为，其key存放了st数组中元素的个数,所以i取1

	if(l==NULL)                       //处理树空的情况
	{
	   p=(node *)malloc(sizeof(node));
       p->key=st[i].key; p->data=st[i].data; p->lch=NULL; p->rch=NULL;
	   l=p;i=2;
	}
    int status=-1;                    //处理根节点,并且设置一个状态为，记录根树的左右子树那个为空
	node *q=NULL,*r=NULL;                    
	for(i;i<=st[0].key;i++)           //这里把st数组的0号为作为一个标准为，其key存放了st数组中元素的个数
	{
		q=l,r=NULL;                   //每次都要把q指向头节点并且把r值为空，
		while(q!=NULL)                //找寻节点应该存放的位置
		{
			r=q;                      //r始终指向当前节点的父亲节点 
			if(st[i].key<q->key)      //比根节点小，挂在左子树上
			{q=q->lch;status=1;}
			else                      //比根节点大或相等，挂在右子树上
			{q=q->rch;status=0;}
		}
	   p=(node *)malloc(sizeof(node));
       p->key=st[i].key; p->data=st[i].data; p->lch=NULL; p->rch=NULL;
	   switch(status)
	   {
	   case 1: r->lch=p;break;
	   case 0: r->rch=p;break;
	   default:break;
	   }
	   
	   
	}
}


//************中根遍历输出二叉排序树**********************//
void inorder(node * p)
{

	if(p!=NULL)
	{
	
		if(p->lch!=NULL) inorder(p->lch);
		cout<<p->key<<"_"<<p->data<<" ";
		if(p->rch!=NULL) inorder(p->rch);
	}
}

//*****************插入元素****************//


void insert(node * & l)
{
	node * p=NULL;p=(node *)malloc(sizeof(node));
	cout<<"输入插入元素的关键字以及数据(form:key_data):";
	cin>>p->key>>p->data;
    p->lch=NULL; p->rch=NULL;

	if(l==NULL)  l=p;                 //处理树空的情况
	else
	{                                
	    
	    int status=-1;                //树不空的条件下，处理根节点,并且设置一个状态为，记录根树的左右子树那个为空
    	node *q=l,*r=NULL;                    
 	              
		while(q!=NULL)                //找寻节点应该存放的位置
		{
			r=q;                      //r始终指向当前节点的父亲节点 
			if(p->key<q->key)         //比根节点小，挂在左子树上
			{q=q->lch;status=1;}
			else                      //比根节点大或相等，挂在右子树上
			{q=q->rch;status=0;}
		}
	   
	   switch(status)                 //根据状态为确定插在节点的左子树还是右子树  
	   {
	   case 1: r->lch=p;break;
	   case 0: r->rch=p;break;
	   default:break;
	   }
	   
	   
	}
}
//****************按关键字查找元素*********************//
int flag=0;                                 //增加一个标志位，来减少函数调用的次数，当flag==1时变停止调用函数

void order(node * p,keytype n)              //用先序遍历来查找
{
	if(p!=NULL&&flag==0)
	{
		if(p->key==n) {cout<<"查找的元素是"<<p->data<<" ";flag=1;}
	    if(p->lch!=NULL) order(p->lch,n);
		if(p->rch!=NULL) order(p->rch,n);
	}
}

void  search(node * p)
{
	flag=0;
	keytype n;
	cout<<"请输入要查找的关键字:";
	cin>>n;
	order(p,n);
	if(flag==0)                   //如果上一步调用order后flag==0说明查找的元素不再树中
	{
		cout<<"查找的元素不存在."<<endl;
	}
}
//********************删除元素（按关键字）**************//
node * i=NULL,              //存当前节点的父亲节点的地址
     * j=NULL;              //存放当前节点的地址 
int  f=0;                   //标记元素是否找到，用来减少函数调用的次数                
    



void dorder(node * p,keytype n)          //先序遍历找到要删除的节点以及其父亲节点，并存放在全局变量i,j中
{
	if(p!=NULL&&f==0)
	{
		if(p->key!=n) 
		{
			i=p;
			if(p->lch!=NULL&&p->key>n)  dorder(p->lch,n);
		    if(p->rch!=NULL&&p->key<=n)  dorder(p->rch,n);
		}
		else  
		{
			f=1;j=p;
		}
		
	}
}






node * rf(node * p)                     //找到当前要删除节点的右子树上的最左的节点
{
	node * q=NULL;
	while(p!=NULL)
	{   
		q=p;
		p=p->lch;
	}
	return q;
}



void delelem(node * & p)                //调用的函数
{
    keytype n;
	cout<<"输入要删除元素的关键字:";
	cin>>n;

	i=p;j=NULL;f=0;                    //全局变量，每次调用函数都要进行初始化
	dorder(p,n); 

	node * q=NULL,*l=NULL,*r=NULL;int s=-1;
	if(f==0) cout<<"删除的元素不再树中."<<endl;
	else                               //在删除的元素在树中的前提下
	{
		l=j->lch;r=j->rch;
		if(j==p)                       //删除元素等于根节点的情况
		{
			if(l==NULL&&r!=NULL) {p=r;}
			if(l!=NULL&&r==NULL) {p=l;}
			if(l==NULL&&r==NULL) {p=NULL;}
			if(l!=NULL&&r!=NULL)      //左右子树都存在的情况
			{
				q=rf(r);
				q->lch=l;
				p=r;
				
			}
			delete j ;
		
		}
		else
		{
			if(j==i->lch) s=1;
			if(j==i->rch) s=0;

			if(l==NULL&&r!=NULL) {if(s==1) i->lch=r;else i->rch=r;}
			if(l!=NULL&&r==NULL) {if(s==1) i->lch=l;else i->rch=l;}
			if(l==NULL&&r==NULL) {if(s==1) i->lch=NULL;else i->rch=NULL;}
			if(l!=NULL&&r!=NULL) 
			{
				q=rf(r);
				q->lch=l;
				if(s==1) i->lch=r;else i->rch=r;
				
			}
			delete j ;
		}
	}
}
			


//*************主函数***********************//			

void main()
{
	
	array st[max];              
	node * l=NULL;                 //树
	
	cout<<"创建二叉排序树:"<<endl;
	int i=1;
	for(i;i<max;i++)
	{
		cout<<"输入int型关键字char型数据,输入0_0结束操作:";
		cin>>st[i].key>>st[i].data;
		if(st[i].key==0) break;
		
	}
	st[0].key=i-1;
   
	creattree(l,st);
	cout<<"显示二叉排序树:"<<endl;
    inorder(l);
	cout<<"插入元素:"<<endl;
	insert(l);inorder(l);
	cout<<"查找元素:"<<endl;
	search(l);
	cout<<"删除元素:"<<endl;
	delelem(l);
	inorder(l);



}