#define max 50                         
#include<iostream.h>
#include<iostream>
typedef char datatype;
typedef int keytype;
typedef struct node                    //����ڵ�����ͣ��ؼ����Լ����ݣ�
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
//*******************��������������*********************//

void creattree(node * & l,array st[])
{
	int i=1;node * p=NULL;            //�����st�����0��Ϊ��Ϊһ����׼Ϊ����key�����st������Ԫ�صĸ���,����iȡ1

	if(l==NULL)                       //�������յ����
	{
	   p=(node *)malloc(sizeof(node));
       p->key=st[i].key; p->data=st[i].data; p->lch=NULL; p->rch=NULL;
	   l=p;i=2;
	}
    int status=-1;                    //������ڵ�,��������һ��״̬Ϊ����¼���������������Ǹ�Ϊ��
	node *q=NULL,*r=NULL;                    
	for(i;i<=st[0].key;i++)           //�����st�����0��Ϊ��Ϊһ����׼Ϊ����key�����st������Ԫ�صĸ���
	{
		q=l,r=NULL;                   //ÿ�ζ�Ҫ��qָ��ͷ�ڵ㲢�Ұ�rֵΪ�գ�
		while(q!=NULL)                //��Ѱ�ڵ�Ӧ�ô�ŵ�λ��
		{
			r=q;                      //rʼ��ָ��ǰ�ڵ�ĸ��׽ڵ� 
			if(st[i].key<q->key)      //�ȸ��ڵ�С��������������
			{q=q->lch;status=1;}
			else                      //�ȸ��ڵ�����ȣ�������������
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


//************�и������������������**********************//
void inorder(node * p)
{

	if(p!=NULL)
	{
	
		if(p->lch!=NULL) inorder(p->lch);
		cout<<p->key<<"_"<<p->data<<" ";
		if(p->rch!=NULL) inorder(p->rch);
	}
}

//*****************����Ԫ��****************//


void insert(node * & l)
{
	node * p=NULL;p=(node *)malloc(sizeof(node));
	cout<<"�������Ԫ�صĹؼ����Լ�����(form:key_data):";
	cin>>p->key>>p->data;
    p->lch=NULL; p->rch=NULL;

	if(l==NULL)  l=p;                 //�������յ����
	else
	{                                
	    
	    int status=-1;                //�����յ������£�������ڵ�,��������һ��״̬Ϊ����¼���������������Ǹ�Ϊ��
    	node *q=l,*r=NULL;                    
 	              
		while(q!=NULL)                //��Ѱ�ڵ�Ӧ�ô�ŵ�λ��
		{
			r=q;                      //rʼ��ָ��ǰ�ڵ�ĸ��׽ڵ� 
			if(p->key<q->key)         //�ȸ��ڵ�С��������������
			{q=q->lch;status=1;}
			else                      //�ȸ��ڵ�����ȣ�������������
			{q=q->rch;status=0;}
		}
	   
	   switch(status)                 //����״̬Ϊȷ�����ڽڵ������������������  
	   {
	   case 1: r->lch=p;break;
	   case 0: r->rch=p;break;
	   default:break;
	   }
	   
	   
	}
}
//****************���ؼ��ֲ���Ԫ��*********************//
int flag=0;                                 //����һ����־λ�������ٺ������õĴ�������flag==1ʱ��ֹͣ���ú���

void order(node * p,keytype n)              //���������������
{
	if(p!=NULL&&flag==0)
	{
		if(p->key==n) {cout<<"���ҵ�Ԫ����"<<p->data<<" ";flag=1;}
	    if(p->lch!=NULL) order(p->lch,n);
		if(p->rch!=NULL) order(p->rch,n);
	}
}

void  search(node * p)
{
	flag=0;
	keytype n;
	cout<<"������Ҫ���ҵĹؼ���:";
	cin>>n;
	order(p,n);
	if(flag==0)                   //�����һ������order��flag==0˵�����ҵ�Ԫ�ز�������
	{
		cout<<"���ҵ�Ԫ�ز�����."<<endl;
	}
}
//********************ɾ��Ԫ�أ����ؼ��֣�**************//
node * i=NULL,              //�浱ǰ�ڵ�ĸ��׽ڵ�ĵ�ַ
     * j=NULL;              //��ŵ�ǰ�ڵ�ĵ�ַ 
int  f=0;                   //���Ԫ���Ƿ��ҵ����������ٺ������õĴ���                
    



void dorder(node * p,keytype n)          //��������ҵ�Ҫɾ���Ľڵ��Լ��丸�׽ڵ㣬�������ȫ�ֱ���i,j��
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






node * rf(node * p)                     //�ҵ���ǰҪɾ���ڵ���������ϵ�����Ľڵ�
{
	node * q=NULL;
	while(p!=NULL)
	{   
		q=p;
		p=p->lch;
	}
	return q;
}



void delelem(node * & p)                //���õĺ���
{
    keytype n;
	cout<<"����Ҫɾ��Ԫ�صĹؼ���:";
	cin>>n;

	i=p;j=NULL;f=0;                    //ȫ�ֱ�����ÿ�ε��ú�����Ҫ���г�ʼ��
	dorder(p,n); 

	node * q=NULL,*l=NULL,*r=NULL;int s=-1;
	if(f==0) cout<<"ɾ����Ԫ�ز�������."<<endl;
	else                               //��ɾ����Ԫ�������е�ǰ����
	{
		l=j->lch;r=j->rch;
		if(j==p)                       //ɾ��Ԫ�ص��ڸ��ڵ�����
		{
			if(l==NULL&&r!=NULL) {p=r;}
			if(l!=NULL&&r==NULL) {p=l;}
			if(l==NULL&&r==NULL) {p=NULL;}
			if(l!=NULL&&r!=NULL)      //�������������ڵ����
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
			


//*************������***********************//			

void main()
{
	
	array st[max];              
	node * l=NULL;                 //��
	
	cout<<"��������������:"<<endl;
	int i=1;
	for(i;i<max;i++)
	{
		cout<<"����int�͹ؼ���char������,����0_0��������:";
		cin>>st[i].key>>st[i].data;
		if(st[i].key==0) break;
		
	}
	st[0].key=i-1;
   
	creattree(l,st);
	cout<<"��ʾ����������:"<<endl;
    inorder(l);
	cout<<"����Ԫ��:"<<endl;
	insert(l);inorder(l);
	cout<<"����Ԫ��:"<<endl;
	search(l);
	cout<<"ɾ��Ԫ��:"<<endl;
	delelem(l);
	inorder(l);



}