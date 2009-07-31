#include<iostream.h>      //输入两个单链表,要求使用另外的表c储存这两个表的元素,并且要按照由大到小的顺序排列,要求c使用原有的两个表的存储空间,允许由重复的元素
                                

typedef struct node
{
	int data;
	struct node *next;
}Node;
typedef struct list
{
	Node *head;
	int length;
}List;
void initlist(List &l)
{
	l.head=NULL;
	l.length=0;
}
void creatlist(List &l)
{
	int i=1,j;Node *p,*q;
	cout<<"输入您要存储的数据,输入0结束操作:"<<endl;
	while(i!=0)
	{
		if(l.head==NULL)
		{
	  
		p=new Node;
		cin>>j;
		if(j==0) break;
		p->data=j;
		p->next=NULL;
		l.head=q=p;
		
		}
    	else
		{
		p=new Node;
		cin>>j;
        if(j==0) break;
		p->data=j;
       	p->next=NULL;
		q->next=p;
		q=p;
       
		}
	    l.length++;
		
	}
}
void add(List &a,List &b,int *p)         //将输入的两个线性表存储在一个数组中//
{
	
	int i,j=0;Node *ah=a.head,*bh=b.head;
	
	for(i=1;i<=a.length;i++)
	{
	
		p[j]=ah->data;
		j++;
		ah=ah->next;
	}
	for(i=1;i<=b.length;i++)
	{
        p[j]=bh->data;
		j++;
		bh=bh->next;
	}

}
void px(int *p,int i)        //将得到的数组进行排序//
{
	int t;
	for(int j=1;j<i;j++)
	
		for(int k=0;k<i-j;k++)
		{
			if(p[k]<p[k+1]) {t=p[k+1];p[k+1]=p[k];p[k]=t;};
		}
	
}
void link(List &a,List &b,List &c)    //将表c的头指针连接到第一个表的头上,使c表指向a雨b的存储空间;
{
	
   int i=1;Node *ah=a.head, *bh=b.head;
   c.head=ah;c.length=a.length+b.length;
   for(;i<a.length;i++)
   {
	   ah=ah->next;
   }
   ah->next=b.head;
}
 void exchange(List &l,int *p)     //将排序后的元素存于表c所指向的原来的a与b 的存储空间.
 {  
	 Node *q=l.head;
	 
   for(int i=0;i<l.length;i++)
   {
	   q->data=p[i];
	   q=q->next;
	   
   }
   
}
 
void disp(List &l)      //将链表的元素显示在显示器上//
{
	Node *p;p=l.head;
  for(int i=1;i<=l.length;i++)
  {
	  cout<<p->data;
	  cout<<' ';
	  
	  p=p->next;
  }
  cout<<endl;
}
   
	

void main()
{
	List l1,l2,l3;int *p;	
	initlist(l1);initlist(l2);initlist(l3);
	cout<<"创建表一:"<<endl;
	creatlist(l1);disp(l1);
	cout<<"创建表二:"<<endl;
	creatlist(l2);disp(l2);
    p=new int [l1.length+l2.length];//p指针用来暂存a与b的元素,也可一直接在两个线性表中直接进行排序,不需要在开辟存储空间,但速度较慢.这里牺牲空间提高速度,但不违背要求,使用原有的空间存储表c.
	add(l1,l2,p); //将表a与表b的元素暂存与p中,
	px(p,l1.length+l2.length);//将p中的元素进行排序.
	
	

	link(l1,l2,l3); //将c表连到表a的头节点上,
	exchange(l3,p);//将p中已经排序的元素存储在原有的空间中//
	cout<<"表三:"<<endl;
	disp(l3);

	
}



	   







		





 

		
