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




node * pre;              //ȫ�ֱ���,�洢��һ���������Ľڵ��ַ��
void thread(node *  p)  //�ݹ�ı�����������������������Ϊ���ĺ���������׼��
{
	if(p!=NULL)          //�������յ������½��б���
	{
		thread(p->lch);  //������ǰ������������������������ڣ��������£�֪��ĳ���ڵ�������������ڣ�ֹͣ�������жϣ�Ȼ���𼶷��ء������ջ�����㷨�ı���һ����
		if(p->lch==NULL) //���������������жϵ�ǰ�ڵ�������Ƿ�Ϊ��;
		{
			p->lch=pre;  //�������Ϊ�գ���洢pre��
			p->ltag=1;
		}
		if(pre->rch==NULL)//�����������������Ϊ�գ���洢p;
		{
			pre->rch=p;
			pre->rtag=1;
		}
		pre=p; //����Ҫע�⣺��������һ���ڵ����������Ҫ��preָ��p��Ȼ���ڱ���p������������Ϊ���и�������������ڵ�����������ȻҪ��������������������������⣬	

	    thread(p->rch);//�����ýڵ����������
	}
}
			

		

node * cthread(node *  p)  //�ڸú����д�����ǰ����ͷ�ڵ�,�����㷨��ʵ�֡������������ͷ�ڵ�ĵ�ַ,pָ�����ĸ��ڵ�
{
      node * head=(node *)malloc(sizeof(node ));
	  pre=head;      //pre��ʼʱָ��ͷ��㣬
	  if(p!=NULL)    //�������յ�������ִ�б���
	  {
		  pre->lch=p;
		  pre->ltag=0;
		  thread(p);  //����thread����
		  pre->rch=head; //��������Ϻ�Ҫpreָ�������ͷ�ڵ㣬��ʵ��ʱ��pre��p��ָ�����һ���ڵ��.
		  pre->rtag=1;   
		  head->rch=pre; //��ͷ�ڵ�Ҳָ�����һ���ڵ㣬ʹͷ�������һ���ڵ㻥��ָ��
		  head->rtag=1;
	  }
	  else       //����������ڣ����ͷ�ڵ�����Һ��������λ��.
	  {
		  head->rch=head->lch=NULL;  
		  head->ltag=head->rtag=0;
	  }
	  return head;  //��������ͷ�ڵ�ĵ�ַ��
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
	node * p=lastnode(l);  //p���ҵ�������������ڵ㣬Ȼ�����������ǰ���ڵ�
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
	t=cthread(m.root);
	cout<<"˳�������������������������"<<endl;
	thinorder(t);
	cout<<"���������������������������"<<endl;
	uthinorder(t);
		
}








	
