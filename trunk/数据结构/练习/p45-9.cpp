#include<iostream.h>      //��������������,Ҫ��ʹ������ı�c�������������Ԫ��,����Ҫ�����ɴ�С��˳������,Ҫ��cʹ��ԭ�е�������Ĵ洢�ռ�,�������ظ���Ԫ��
                                

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
	cout<<"������Ҫ�洢������,����0��������:"<<endl;
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
void add(List &a,List &b,int *p)         //��������������Ա�洢��һ��������//
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
void px(int *p,int i)        //���õ��������������//
{
	int t;
	for(int j=1;j<i;j++)
	
		for(int k=0;k<i-j;k++)
		{
			if(p[k]<p[k+1]) {t=p[k+1];p[k+1]=p[k];p[k]=t;};
		}
	
}
void link(List &a,List &b,List &c)    //����c��ͷָ�����ӵ���һ�����ͷ��,ʹc��ָ��a��b�Ĵ洢�ռ�;
{
	
   int i=1;Node *ah=a.head, *bh=b.head;
   c.head=ah;c.length=a.length+b.length;
   for(;i<a.length;i++)
   {
	   ah=ah->next;
   }
   ah->next=b.head;
}
 void exchange(List &l,int *p)     //��������Ԫ�ش��ڱ�c��ָ���ԭ����a��b �Ĵ洢�ռ�.
 {  
	 Node *q=l.head;
	 
   for(int i=0;i<l.length;i++)
   {
	   q->data=p[i];
	   q=q->next;
	   
   }
   
}
 
void disp(List &l)      //�������Ԫ����ʾ����ʾ����//
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
	cout<<"������һ:"<<endl;
	creatlist(l1);disp(l1);
	cout<<"�������:"<<endl;
	creatlist(l2);disp(l2);
    p=new int [l1.length+l2.length];//pָ�������ݴ�a��b��Ԫ��,Ҳ��һֱ�����������Ա���ֱ�ӽ�������,����Ҫ�ڿ��ٴ洢�ռ�,���ٶȽ���.���������ռ�����ٶ�,����Υ��Ҫ��,ʹ��ԭ�еĿռ�洢��c.
	add(l1,l2,p); //����a���b��Ԫ���ݴ���p��,
	px(p,l1.length+l2.length);//��p�е�Ԫ�ؽ�������.
	
	

	link(l1,l2,l3); //��c��������a��ͷ�ڵ���,
	exchange(l3,p);//��p���Ѿ������Ԫ�ش洢��ԭ�еĿռ���//
	cout<<"����:"<<endl;
	disp(l3);

	
}



	   







		





 

		
