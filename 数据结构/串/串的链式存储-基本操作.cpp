#include<iostream.h>
#include<iostream>
#include<iomanip.h>
#include<string.h>
typedef char datatype;

typedef struct node  //���崮�ڵ�
{
	datatype data;
	struct node * next;
}Sqnode;
typedef struct    //���崮
{
	Sqnode * head;
	int len;
}Sqlink;

void  initstr(Sqlink & l )//��ʼ������
{
	l.head=NULL;
	l.len=0;
}

void createstr(Sqlink & l)     //β�巨����
{
	Sqnode * p,* q;datatype t;
	cout<<"����������,����e����:"<<endl;
	cin>>t;
	while(t!='e')
	{
		p=(Sqnode *)malloc(sizeof(Sqnode));
		p->data=t;
		p->next=NULL;
		if(l.head==NULL)
		{
			l.head=p;
			q=p;
		}
		else
		{
			q->next=p;
			q=p;
		}
		l.len++;
	    cout<<"����������,����e����:"<<endl;
     	cin>>t;
	}

}


void assignstr(Sqlink & l,datatype a[])   //����ֵ����,��һ�������ֵ�洢�ڴ���.ʵ���Ͼ��ǽ�������.
{
	Sqnode * p,* q;int i=0;
	while(i<strlen(a))
	{
		p=(Sqnode*)malloc(sizeof(Sqnode));
		(*p).data=a[i];
		(*p).next=NULL;
		if(l.head==NULL)
		{
			l.head=p;
			q=p;
		}
		else
		{
			(*q).next=p;
			q=p;
		}
		l.len++;
	    i++;
	}
}

void copystr(Sqlink & a, Sqlink & b)   //����ֵ����,��һ������ֵ�洢����һ������.ʵ���Ͼ��ǽ�������.
{
	Sqnode * p,* q;Sqnode *r=b.head;
	while(r!=NULL)
	{
		p=(Sqnode*)malloc(sizeof(Sqnode));
		(*p).data=r->data;
		(*p).next=NULL;
		r=r->next;
		if(a.head==NULL)
		{
			a.head=p;
			q=p;
		}
		else
		{
			(*q).next=p;
			q=p;
		}
		a.len++;
	    
	}
}


void disp(Sqlink & l) //������е�����Ԫ��.
{
	Sqnode * p=l.head;
	while(p!=NULL)
	{
		cout<<setw(3)<<p->data;
		p=p->next;
	}
	cout<<endl;
}


bool recog(Sqlink & a,Sqlink & b)      //�ж��������Ƿ����,��������Ҷ�Ӧ��Ԫ����Ȳ�֤�����������.
{
	int statue=1;Sqnode * p=a.head,* q=b.head;
	if(a.len!=b.len) return 0;
	while(p!=NULL)
	{
		if(p->data!=q->data) statue=0;
		p=p->next;
		q=q->next;
	}
	return (statue==1 ? 1:0);
}


void concat(Sqlink & a,Sqlink  & b)   //���������ڴ�a�ĺ��,
{
	Sqnode* p=a.head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=b.head;
	a.len+=b.len;
}


Sqlink * substr(Sqlink & l,int i,int j) //�������дӵ�i��λ�ÿ�ʼ��j��Ԫ�ص��Ӵ�.
{
	Sqlink * p=(Sqlink * )malloc(sizeof(Sqlink));
	initstr(*p);
	Sqnode * q=l.head,*m,*n;
	while(i>1)
	{
		q=q->next;
		i--;
	}

    while(j>0)
	{
		m=(Sqnode*)malloc(sizeof(Sqnode));
		
		(*m).data=q->data;
		(*m).next=NULL;
		q=q->next;
		
		if(p->head==NULL)
		{
			p->head=m;
			n=m;
		}
		else
		{
			(*n).next=m;
			n=m;
		}
		(*p).len++;
		j--;
	    
	}
	return p; //pָ��洢��������Ƭ�洢�ռ�.
}


int index(Sqlink & a,Sqlink & b)  //�����Ӵ�b������a�е�λ��.
{

	Sqnode *p,*q,*m,*n;int statue=1,i=1; //statue Ϊ���õ�״̬��־.
	p=a.head;q=b.head;
	while(p!=NULL)           //�����ѭ��,����������ʼ���ҵ�λ��,һ�δӵ�һ��Ԫ�ص����һ��Ԫ��.
	{
		
		if(p->data==q->data)    //���ݴ��Ƚ�Ԫ���Ƿ����Ӵ��ĵ�һ��Ԫ�����,�������Ƿ���к��ıȽ�.
		{
			m=p;n=q;
			while(n!=NULL)
			{
				if(m->data!=n->data) statue=0; 
				m=m->next;
				n=n->next;
			}
			if(statue==1)  return i;
		}
		p=p->next;
		i++; //��¼�ҵ��Ӵ�ʱ��λ��.
	}
	return 0;
	
}



void insert(Sqlink & a,int i,Sqlink & b) //���Ӵ�b���뵽�����ĵ�i��λ��.
{
	Sqnode *p=a.head,*q,*r=b.head;
	
	while(r->next!=NULL)
	{
		r=r->next;
	}
	
	if(i==1) {r->next=a.head;a.head=b.head;}
	else
	{
	while(i>2)   
	{
		p=p->next;
		i--;
	}
	q=p->next;
	p->next=b.head;
	r->next=q;
	}
	a.len+=b.len;
}


void deletstr(Sqlink & l,int i,int j)  //�Ӵ���ɾ����i��λ�ÿ�ʼ��j��Ԫ��.
{
	Sqnode *p=l.head,*q,*r;
	while(i>2)
	{
		p=p->next;
		i--;
	}
	if(i==1)
	{
	q=l.head;
	while(j>0)
	{
		r=q;
		q=q->next;
		free(r);
		j--;
	}
	l.head=q;

		
	}
	else
	{
	q=p->next;
	while(j>0)
	{
		r=q;
		q=q->next;
		free(r);
		j--;
	}
	p->next=q;
	}
}



void replace(Sqlink & a,Sqlink & b,Sqlink & c)  //���������ҵ�b��������λ��,Ȼ����c��������.
{
    

	int i=index(a,b);
	if(i==0) {cout<<"�Ӵ�����������."<<endl;}
	else
	{
	while(i!=0)
	{
	deletstr(a,i,b.len);
	insert(a,i,c);
	i=index(a,b);
	}
	}
}

void main()
{
	Sqlink a,b,c,*d,e,f;datatype m[4]={"abc"};
	
	initstr(a);initstr(b);initstr(c);initstr(e); initstr(f);//��ʼ��a.b.c��
	cout<<"��ʼ�����a����:";
	disp(a);

    cout<<"����a��:"<<endl; //����a��
	createstr(a);
	cout<<"�������a����:";
	disp(a);

	cout<<"�������a������:"<<a.len<<endl;


	cout<<"��a�еĵ�2��λ����ȡ3��Ԫ��Ϊ:";
	d=substr(a,2,3);
	disp(*d);

	cout<<"����b��:"<<endl; //����b��
	createstr(b);
	cout<<"�������b����:";
	disp(b);

	if(recog(a,b)==1) cout<<"a����b�����."<<endl; //�ж�a����b���Ƿ����.
	else
	{
		cout<<"a����b�������."<<endl;
	}

	cout<<"b����a���ĵ�."<<index(a,b)<<"λ"<<endl; //����b����a���е�λ��.

    
	cout<<"��b�����뵽a���ĵ�2��λ�ú�,a��Ϊ:";
	insert(a,2,b);
	disp(a);

	cout<<"��a���ĵ�2��λ�ú��"<<b.len<<"���ַ�ɾ����"<<"a��Ϊ:";
    deletstr(a,2,b.len);
	disp(a);

    cout<<"����f��:"<<endl; 
    createstr(f);
	cout<<"�������f����:"; 
	disp(f);


	cout<<"��f������c��:"<<endl; 
    copystr(c,f);
	cout<<"�������c����:"; 
	disp(c);

	cout<<"����e��:"<<endl; 
    assignstr(e,m);
	cout<<"�������e����:";
	disp(e);

    cout<<"��a���е�����f����e�������,a��Ϊ:";
	replace(a,f,e);
	disp(a);


	cout<<"��f�����ӵ�c������ߺ�,c����:";
	concat(c,f);
	disp(c);

}





















		








    

























































	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
















			


	
	







