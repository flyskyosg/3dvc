#include<iostream.h>
#include<iostream>
#define max 50

typedef struct lnode
{
	int key;
	char data;
	struct lnode * next;
}lnode;


lnode * st[max];
//***��ϣ����******************//
int hax(int key)
{
	return key%45;
}
//**********������******************//
void creat()
{
	int i=0;
	for(i;i<max;i++)
		st[i]=NULL;


	int key,n;char data='\0';lnode * p=NULL,*q=NULL;
	cout<<"����ؼ���������(key_data),����0_0��������:";
	cin>>key>>data;

    while(data!='0')
	{
	if(key>max||key<0) cout<<"�ؼ��ֳ�����Χ."<<endl;
	else
	{
		p=(lnode *)malloc(sizeof(lnode));
		p->data=data;
		p->key=key;
		p->next=NULL;
		n=hax(key);
		if(st[n]!=NULL) p->next=q;
			
	    st[n]=p;q=p;
		
	
	}
	cout<<"����ؼ���������(key_data):";
	cin>>key>>data;
	}


	
}
//*************�������******************//
void disp()
{
	lnode * p=NULL;int i=0;
	cout<<"�������:";
	for( i=0;i<max;i++)
	{
		p=st[i];
		while(p!=NULL)
		{
			cout<<p->key<<"_"<<p->data<<" ";
			p=p->next;
		}
		cout<<"   ";
	
		
	}
}




//*************���ұ�Ԫ��*****************//

void search()
{   
	int key;
	cout<<"������ҵĹؼ���:";
	cin>>key;
	int n=0;lnode * p=NULL;
	n=hax(key);
	p=st[n];
	while(p->key!=key)	p=p->next;
    cout<<"Ҫ���ҵ�Ԫ����:";
    cout<<p->key<<"_"<<p->data<<endl;
}
//*************����Ԫ��****************//

void insert()
{
	int key,n;char data='\0';lnode * p=NULL,*q=NULL;
	cout<<"����Ҫ����Ĺؼ���������(key_data):";
	cin>>key>>data;
	if(key>max||key<0) cout<<"�ؼ��ֳ�����Χ."<<endl;
	else
	{
	    n=hax(key);
		p=(lnode *)malloc(sizeof(lnode));
		p->data=data;
		p->key=key;
		p->next=NULL;
		if(st[n]!=NULL) p->next=q;
			
	    st[n]=p;q=p;
	}
}
		
//************ɾ��Ԫ��***********************//
void delelem()
{
    int key=0,n=0;
	cout<<"����ɾ���Ĺؼ���:";
	cin>>key;

    n=hax(key);
	lnode * p=NULL,*q=NULL;
	p=st[n];

	while(p->key!=key)
	{
		q=p;
		p=p->next;
	}
	if(q==NULL) st[n]=p->next;
	else q=p->next;
	delete p;
}


//**********������*****//
void main()
{
	creat();
	disp();
	insert();
	disp();
	search();
	delelem();
	disp();

}







