#include<iostream.h>   //��ʽ�洢�ṹ
#include<iostream>
#define max 50 
typedef char datatype;

typedef struct node    //��������Ľڵ�
{
	datatype data;
	struct node * lch;
	struct node * rch;
}node;
typedef struct         //����������
{
	 struct node * root;
}ltree;


void initltree(ltree & l)   //��ʼ��������
{
	l.root=NULL;
}
//********************************���ŷ�����������*********************//

void  creattree(ltree & l,datatype  str[])  //���ŷ�����������
{
	node * p=NULL;  //p����ָ�����Ľڵ�
	int k=0,j=0,top=-1;  //k��Ϊһ��״̬��־λ,����ǰһ��Ԫ�ص�ֵ��ȷ��һ��Ԫ���������Һ���.������ջ
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

//*********************���뷨��ʾ������*********************************//
void show(ltree & l) //�����㷨��������ջ���ڵ㣬Ȼ��ѭ�����жϵ�ǰ�ڵ��������������ջ��������վ˳Ѱʵ���˰��뷨���ص�
{
	node * p=l.root,* st[max];        //pΪ��ʱ�洢�ڵ�ı���,��ʼʱָ����ڵ㣬stΪ�洢�ڵ��ջ
	int top=-1,elem[max][2],w=4,n=0;  //topջ��ָ�룬elem����洢�ڵ�Ԫ�صĲ�����0��Ϊ�洢�ڵ�����ͣ���������������������,1��Ϊ�洢�ڵ�֮ǰ��Ҫ����Ŀո�ĸ�����wΪ�����趨�ĵ�λ�����ȣ�nΪ�����ȵ���ʱ������
	char type='\0';      //type��������ڵ�����ͣ�����elem�����0��λ��ȡֵλ��L-��������R-��������B-���ڵ㣩
	if(p!=NULL)  
	{
		top++;          
		st[top]=p;               //���Ƚ����ڵ���ջ��
		elem[top][0]=2;          //������elem��������Ӧ��λ�ô��뵱ǰ�ڵ����Ϣ�����ͣ������ȣ�
		elem[top][1]=w;
		while(top>-1)            //��ջ���յ�������ѭ��
		{
			p=st[top];           //��ջ
			n=elem[top][1];      //������n���洢��ȣ�
			for(int i=1;i<=n;i++) //����ڵ�ǰ�Ŀ��
				cout<<" ";
			switch(elem[top][0])  //����0��λȷ��type��ֵ
			{
			case 0:type='L';break;
			case 1:type='R';break;
            case 2:type='B';break; 
			}
			cout<<p->data<<"("<<type<<")"; //���Ԫ�غ�ġ�-����
			for(i=1;i<=max-n;i++)
				cout<<"-";
			cout<<endl;
			top--;  //��ջ
			if(p->rch!=NULL)  //������������ջ��������elem�洢��Ӧ����Ϣ
			{
				top++;
		        st[top]=p->rch;
	            elem[top][0]=1;
		        elem[top][1]=n+w;
			}
			if(p->lch!=NULL) //������������ջ��������elem�洢��Ӧ����Ϣ
			{
				top++;
		        st[top]=p->lch;
	            elem[top][0]=0;
		        elem[top][1]=w+n;
			}
		}
	}
}

//*****************����������ÿ���ڵ��������������*************//

void exchange(node *p)  //�ȸ���������ÿ���ڵ����������--�ݹ��㷨 ,pָ��������ĸ��ڵ�
{
	node * t; 
	if(p!=NULL)
	{
     t=p->lch;
	 p->lch=p->rch;
	 p->rch=t;
	 exchange(p->lch);
	 exchange(p->rch);
	}
	
}

void main()
{
	ltree a;a.root=NULL;
    cout<<"��������(�������ű�ʾ��,��100���ַ�����)."<<endl;
    datatype p[max];
    cin>>p;
	cout<<p<<endl;
	creattree(a,p);
	cout<<"������Ķ�����:"<<endl;
    show(a);
    cout<<endl;
    exchange(a.root);
	cout<<"������Ķ�����:"<<endl;
	show(a);
}


