#include<iostream.h>   //��ʽ�洢�ṹ
#include<iostream>  
#include<string.h>
typedef char datatype;
#define max 50

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
//********************************���ŷ���ʾ������*****************************//
void kshow(node * p)  //pָ����ڵ�
{
	if(p!=NULL)
	{
		cout<<p->data;
		if(p->lch!=NULL) 
		{
			cout<<"(";
		    kshow(p->lch);
		}
		if(p->rch!=NULL) 
		{
			cout<<",";
		    kshow(p->rch);
		}
		if(p->lch!=NULL||p->rch!=NULL)
		  cout<<")";
	}
}
//********************************���������루���ÿ��Ҷ�ӽڵ�ĴӸ��ڵ㵽��Ҷ�ӽڵ��·����**************************//
//********************//	
int hcode[max];
int len=-1;

void haffcode(node * p)  //����������
{
	if(p!=NULL)
	{
		if(p->lch==NULL&&p->rch==NULL)
		{
			cout<<p->data<<" ";
			for(int i=0;i<=len;i++)
				cout<<hcode[i];
			len--;
			cout<<endl;

		}
		if(p->lch!=NULL) 
		{
			len++;hcode[len]=0;
			haffcode(p->lch);
		}
		
		
		if(p->rch!=NULL) 
		{
			len++;hcode[len]=1;
			haffcode(p->rch);
		}
		if(p->lch!=NULL||p->rch!=NULL)
			len--;
	}
}


//********************��������ĸ߶ȣ�Ҷ�ӽڵ�ĸ��������нڵ�ĸ���(�ݹ��㷨)**********************//

int height(node * p)   //�������ĸ߶ȣ������pָ����ڵ�
{
	int lu=0,ru=0;
	if(p!=NULL)
	{
		lu=height(p->lch); 
		ru=height(p->rch);
		return lu>ru?lu+1:ru+1;
	}
	else
	{
		return  0;
	}
}

int nodecount(node * p) //���нڵ�ĸ���
{

    int lc=0,rc=0;
	if(p!=NULL)
	{
		lc=nodecount(p->lch);
		rc=nodecount(p->rch);
		return lc+rc+1;
	}
	else
	{
		return  0;
	}
}

int leafcount(node * p) //��������Ҷ�ӽڵ�ĸ���
{
	int lc=0,rc=0;
	if(p!=NULL)
	{
		
		if(p->lch==NULL&&p->rch==NULL)
        return 1;
		else
		{
			lc=leafcount(p->lch);
			rc=leafcount(p->rch);
			return lc+rc;
		}
	
	}	
	else
	{
		return 0;
	}
 
}


//***************main()**************************//
void main()
{
	ltree a;initltree(a);
    cout<<"��������(�������ű�ʾ��,��100���ַ�����)."<<endl;
    datatype p[max];
    cin>>p;
	cout<<p<<endl;
	creattree(a,p);
	cout<<"���뷨��ʾ������:"<<endl;
	show(a);
	cout<<"���ŷ���ʾ������:"<<endl;
	kshow(a.root);
	cout<<endl;
	cout<<"����������(ÿ��Ҷ�ӽڵ��·��):"<<endl;
    haffcode(a.root);
	cout<<"���������ĸ߶�:"<<height(a.root)<<endl;
    cout<<"�������������нڵ�ĸ���:"<<nodecount(a.root)<<endl;
	cout<<"����������Ҷ�ӽڵ�ĸ���:"<<leafcount(a.root)<<endl;
}



