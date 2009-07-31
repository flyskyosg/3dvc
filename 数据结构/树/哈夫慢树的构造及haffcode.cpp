#define max 50
#include<iostream>
#include<iostream.h>
#include<string.h>
typedef char datatype; 

typedef struct node  //����ڵ�
{
	datatype data;
	int weight;
	struct node * lch,* rch;
}node;
//***********************************����Ҷ������*************************//
node * st[max];  //ȫ�����飬���ڴ�����е�Ҷ�ӽڵ�
int top=-1;      //topΪ����ĳ��ȣ�Ҳ����Ϊ��ǰջ����ָ�� 

void creatleaf()  //����Ҷ�ӽڵ������
{
	node *p=NULL;
	datatype data;
	int weight;
	cout<<"������Ҷ�ӽڵ�����ݼ�Ȩֵ(��ʽ:����+�س� Ȩֵ+�س�),����$��������:"<<endl;
	cin>>data;cin>>weight;
	cout<<data<<" "<<weight<<endl;
	while(data!='$')
	{
		p=(node *)malloc(sizeof(node));
		p->data=data;
		p->weight=weight;
		p->lch=p->rch=NULL;
		top++;
		st[top]=p;
		cout<<"������Ҷ�ӽڵ�����ݼ�Ȩֵ(��ʽ:����+�س� Ȩֵ+�س�),����$��������:"<<endl;
    	cin>>data;cin>>weight;
    	cout<<data<<" "<<weight<<endl;
	}
	for(int i=0;i<=top;i++)
		cout<<st[i]->data<<" "<<st[i]->weight;
	cout<<endl;
	cout<<"����������"<<endl;
}
//***********************������*******************************//
void px()  //�Ը�������������ɴ�С����
{
	int i=0,j=0;node * t;static int k=1; //i��jΪѭ��������kΪ��̬������������ʾ״̬
	for(;i<top;i++)
		for(j=0;j<top-i;j++)
		{
			if(st[j]->weight<st[j+1]->weight)  //����Ȩֵ�ɴﵽС����
			{
				t=st[j];
				st[j]=st[j+1];
				st[j+1]=t;
			}
		}
		cout<<"��"<<k<<"��"<<"����."<<endl;k++;  //�����鿴�����״̬
		for( i=0;i<=top;i++)
		cout<<st[i]->data<<" "<<st[i]->weight;
		cout<<endl;

}
//***********�������*****************//
void preorder(node * p)
{
	if(p!=NULL)
	{
		cout<<p->data<<" ";
		preorder(p->lch);
		preorder(p->rch);
	}
}
//*****************************�����������***********************//
node * creathaff()  //�����������
{
	creatleaf();
    cout<<"����Ҷ�ӽڵ����."<<endl;
	node * r;
	while(top>=0)    //�����鲻�յ�������ѭ��
	{ 
	px();           //�������ɴ�С����
	r=(node *)malloc(sizeof(node)); //��������������Ԫ�طֱ���ڵ�ǰ���ڵ������������
	r->data='A';
	r->lch=st[top];
	if(top-1>=0) r->rch=st[top-1];  //����Ҫע����top-1>0��ʱ��ִ�С�
	else   break;                  
	
	r->weight=st[top]->weight+st[top-1]->weight;//������������Ȩ�غʹ����µĸ��ڵ���
	if(top-2<0) break;    //�����ǰ��������ֻʣ������Ԫ�أ����ýڵ��ֱ���˳��������ٽ����õ��½ڵ�������

	top--;                //������ĳ��ȼ�һ
	st[top]=r;             //�������õĽڵ��������
	}
	return r;
}


//********************************����������**************************//
//********************//	
int hcode[max];
int len=-1;

void haffcode(node * p)  //����������  �������ȸ������ĵݹ��㷨���졣
{
	if(p!=NULL)    //�������յ�������ִ�У�ͬʱҲ�ǵݹ�ĳ���
	{
		if(p->lch==NULL&&p->rch==NULL)   //��һ���ڵ������������ʱ��˵���ýڵ�ΪҶ�ӽڵ㣬Ӧ�������haffcode��
		{
			cout<<p->data<<" ";
			for(int i=0;i<=len;i++)         //�����д�ŵ������������������haffcode��
				cout<<hcode[i];
			len--;             //����ע������������Ϊ�ǵݹ�ĵ��ã�Ҫ����һ��������Ҫ�������е�Ԫ��ɾ��һ���������ʾΪ������ĳ��ȼ���1           
			cout<<endl;

		}
		if(p->lch!=NULL)       
		{
			len++;hcode[len]=0;        //������������ڣ���һ��0ѹ�����飬Ȼ�����������
			haffcode(p->lch);
		}
		
		
		if(p->rch!=NULL)              
		{
			len++;hcode[len]=1;           //������������ڣ���һ��1ѹ�����飬Ȼ�����������
			haffcode(p->rch);
		}
		if(p->lch!=NULL||p->rch!=NULL)    //���Ҫע�⣬��Ϊ�ݹ飬��һ���ڵ������Ϻ�Ҫ�����ϼ���ʱ��Ҫ�����鳤�ȼ�1����ʵ�Ǵ��������������1
			len--;
	}
}


//************************������********************//
void main()
{
	node * root;
    cout<<"�����������:"<<endl;
	root=creathaff();
	cout<<"����Ĺ�������Ϊ:"<<endl;
    preorder(root);
	cout<<"����Ĺ���������Ϊ:"<<endl;
	haffcode(root);



}













	













