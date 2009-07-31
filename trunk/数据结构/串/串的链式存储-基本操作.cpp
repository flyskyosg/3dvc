#include<iostream.h>
#include<iostream>
#include<iomanip.h>
#include<string.h>
typedef char datatype;

typedef struct node  //定义串节点
{
	datatype data;
	struct node * next;
}Sqnode;
typedef struct    //定义串
{
	Sqnode * head;
	int len;
}Sqlink;

void  initstr(Sqlink & l )//初始化链串
{
	l.head=NULL;
	l.len=0;
}

void createstr(Sqlink & l)     //尾插法建串
{
	Sqnode * p,* q;datatype t;
	cout<<"请输入数据,输入e结束:"<<endl;
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
	    cout<<"请输入数据,输入e结束:"<<endl;
     	cin>>t;
	}

}


void assignstr(Sqlink & l,datatype a[])   //串赋值运算,将一个数组的值存储在串中.实质上就是建立串表.
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

void copystr(Sqlink & a, Sqlink & b)   //串赋值运算,将一个串的值存储在另一个串中.实质上就是建立串表.
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


void disp(Sqlink & l) //输出串中的所有元素.
{
	Sqnode * p=l.head;
	while(p!=NULL)
	{
		cout<<setw(3)<<p->data;
		p=p->next;
	}
	cout<<endl;
}


bool recog(Sqlink & a,Sqlink & b)      //判断两个串是否相等,长度相等且对应的元素相等才证明两个串相等.
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


void concat(Sqlink & a,Sqlink  & b)   //将串连接在串a的后边,
{
	Sqnode* p=a.head;
	while(p->next!=NULL)
	{
		p=p->next;
	}
	p->next=b.head;
	a.len+=b.len;
}


Sqlink * substr(Sqlink & l,int i,int j) //求主串中从第i个位置开始的j个元素的子串.
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
	return p; //p指向存储连串的那片存储空间.
}


int index(Sqlink & a,Sqlink & b)  //查找子串b在主串a中的位置.
{

	Sqnode *p,*q,*m,*n;int statue=1,i=1; //statue 为设置的状态标志.
	p=a.head;q=b.head;
	while(p!=NULL)           //最外层循环,控制主串开始查找的位置,一次从第一个元素到最后一个元素.
	{
		
		if(p->data==q->data)    //根据带比较元素是否与子串的第一个元素相等,来决定是否进行后便的比较.
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
		i++; //记录找到子串时的位置.
	}
	return 0;
	
}



void insert(Sqlink & a,int i,Sqlink & b) //将子串b插入到主串的第i个位置.
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


void deletstr(Sqlink & l,int i,int j)  //从串中删除第i个位置开始的j个元素.
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



void replace(Sqlink & a,Sqlink & b,Sqlink & c)  //从主串中找到b串的所有位置,然后用c串赖代替.
{
    

	int i=index(a,b);
	if(i==0) {cout<<"子串不再主串中."<<endl;}
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
	
	initstr(a);initstr(b);initstr(c);initstr(e); initstr(f);//初始化a.b.c串
	cout<<"初始化后的a串是:";
	disp(a);

    cout<<"创建a串:"<<endl; //创建a串
	createstr(a);
	cout<<"创建后的a串是:";
	disp(a);

	cout<<"创建后的a串长是:"<<a.len<<endl;


	cout<<"从a中的第2个位置提取3个元素为:";
	d=substr(a,2,3);
	disp(*d);

	cout<<"创建b串:"<<endl; //创建b串
	createstr(b);
	cout<<"创建后的b串是:";
	disp(b);

	if(recog(a,b)==1) cout<<"a串与b串相等."<<endl; //判断a串与b串是否相等.
	else
	{
		cout<<"a串与b串不相等."<<endl;
	}

	cout<<"b串在a串的第."<<index(a,b)<<"位"<<endl; //查找b串在a串中的位置.

    
	cout<<"将b串插入到a串的第2个位置后,a串为:";
	insert(a,2,b);
	disp(a);

	cout<<"将a串的第2个位置后的"<<b.len<<"个字符删除后"<<"a串为:";
    deletstr(a,2,b.len);
	disp(a);

    cout<<"创建f串:"<<endl; 
    createstr(f);
	cout<<"创建后的f串是:"; 
	disp(f);


	cout<<"用f串创建c串:"<<endl; 
    copystr(c,f);
	cout<<"创建后的c串是:"; 
	disp(c);

	cout<<"创建e串:"<<endl; 
    assignstr(e,m);
	cout<<"创建后的e串是:";
	disp(e);

    cout<<"将a串中的所有f串用e串代替后,a串为:";
	replace(a,f,e);
	disp(a);


	cout<<"将f串连接到c串到后边后,c串是:";
	concat(c,f);
	disp(c);

}





















		








    

























































	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
	
















			


	
	







