#include<iostream.h>   //��ʽ�洢�ṹ
#include<iostream>  
#include<string.h>
typedef char datatype;
#define max 100

typedef struct node    //��������Ľڵ�
{
	datatype data;
	struct node * lch,* rch;
	int ltag,rtag;
}node;
typedef struct         //����������
{
	 struct node * root;
}ltree;


void initltree(ltree & l)   //��ʼ��������
{
	l.root=NULL;
}
//*****************************���ŷ�����������******************************//
void  creattree(ltree & l,datatype  str[])  //���ŷ�����һ�Ŷ�����
{
	node * p=NULL;  //p����ָ�����Ľڵ�
	int k=0,j=0,top=-1;  //k��Ϊһ��״̬��־λ,����ǰһ��Ԫ�ص�ֵ��ȷ��һ��Ԫ���������Һ���.������ջ��
	node * a[max];    //��Ϊ�洢˫�׽ڵ��˳��ջʹ�á�
	datatype t=str[j];   //t��Ϊ�ݴ�����Ԫ��ֵ���м������

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



//**************************��������������**********************//
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


node * inthread(node * p) //lָ��������ĸ��ڵ� //Ϊ�����㷨��ʵ�֣��涨��ͷ�ڵ������ָ����ڵ㣬����ָ������������������һ���ڵ�
{
	node * pre=NULL,*head=NULL;node * a[max],*t=p;int top=-1;//preָ����һ���������Ľڵ㣬headΪ���ӵ�ͷ��㣬��󷵻ظ�ͷ��㣬aΪһ��˳��ջ�������洢Ԫ�أ�t�洢���������������һ���ڵ㣬������ѭ����ֹ��������topΪջ��ָ��
	head=(node *)malloc(sizeof(node));
	pre=head;            //��ʼʱpreָ��ͷ�ڵ�
	if(p!=NULL)           
	{
		pre->lch=p;pre->ltag=0;  //�������յ�������ʹͷ��������ָ����ڵ㣬������ʱ��λ�գ�
		pre->rch=NULL;pre->rtag=1; //
		
         
		
		while(t->rch!=NULL)  //�ҵ�������������������һ���ڵ㣬Ϊ�����ѭ������ֹ��������preָ��t�����һ���ڵ��ʱ�����������
			t=t->rch;


   		while(pre!=t)
		{
			while(p->lch!=NULL)  //���ҵ��������ĵ�һ���ڵ㣬���������±߽ڵ㣬���Ұ��м�Ľڵ���ջ����
			{
			top++;
			a[top]=p;
			p=p->lch;
			}
			
			takeplace(p,pre);  //�ҵ��ڵ�󣬴���p��pre;
	    	
	    	while(top>-1)      //��������γ�ջ
			{

			   p=a[top];
			   top--;
		       
			   takeplace(p,pre);
		      
			   if(p->rch!=NULL)  //����ջ�Ľڵ�û����������ʱ�򣬼�����ջ����֮ת��������������ֹѭ�������¿�ʼ�жϡ�
			   {
			   p=p->rch;break;
			   }
			}
	 	
		}

		head->rch=pre;  //���preָ������һ���ڵ��ʱ�򣬰�preָ��ͷ�ڵ㣬��ͷ�ڵ�ĺ��ָ��pre;(Ϊ�����㷨��ʵ��)
		head->rtag=1;
		pre->rch=head;
		pre->rtag=1;
	
	}

    return head;  //��󷵻�ͷ�ڵ㣬


}
//********************������������������ı�������**********************//
node * firstnode(node * l)   //���������������ĵĵ�һ���ڵ㣬�����lΪͷ���
{
	while(l->ltag==0)
		l=l->lch;
	return l;
}

node * lastnode(node * l)  //�������������������һ���ڵ� �������lΪͷ���
{
	l=l->lch;
	while(l->rtag==0)
		l=l->rch;
	return l;
}

node * prenode(node * p)   //�ҵ�ǰ�ڵ��ǰ���ڵ�
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

node * postnode(node * p)   //�ҵ�ǰ�ڵ�ĺ�̽ڵ�
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


void thinorder(node * l)   //˳�����������������lΪͷ���
{
	node * p=firstnode(l); //p���ҵ���������ĵ�һ���ڵ㣬Ȼ������������̽ڵ�
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

void uthinorder(node * l)//�������������������lΪͷ�ڵ㡣
{
	node * p=lastnode(l);  //p���ҵ�������������ڵ㣬Ȼ����������ǰ���ڵ�
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


//********************************������************************************//		  
void main()
{ 
	
	ltree m;initltree(m);
	cout<<"��������(�������ű�ʾ��,��100���ַ�����)."<<endl;
    datatype p[max];
    cin>>p;
	cout<<p<<endl;
	creattree(m,p);
	cout<<endl;


	cout<<"������������"<<endl;
	node * t;
	t=inthread(m.root);
	cout<<endl;
	cout<<"˳�������������������������"<<endl;
	thinorder(t);
	cout<<endl;
	cout<<"���������������������������"<<endl;
	uthinorder(t);
	cout<<endl;

		
}








	
