#include<iostream.h> //头插发初始化链表//
#include<iostream>
struct xiao
{
	char data;
	struct xiao *next;
	
};
void disp(xiao * p)
{
	while(p!=NULL)
	{
		cout<<p->data<<" ";
		p=p->next;
	}
	cout<<endl;
}


void main()
{
	struct xiao *head=NULL,*p=NULL;
    int x=0;char t='\0';
	p=(xiao*)malloc(sizeof(xiao));
    cout<<"请输入数据:";
	cin>>p->data;
	p->next=NULL;
	while(t!='a')
	{
		
		if(head==NULL) 
		{
	  		
			head=p;
		}
		else
		{
            
	   		p->next=head;
			head=p;
		};	
		x++;
		p=(xiao*)malloc(sizeof(xiao));
		cout<<"请输入数据:";
    	cin>>p->data;
	    p->next=NULL;
		t=p->data;
	
	
	}
	disp(head);
}

			




	


