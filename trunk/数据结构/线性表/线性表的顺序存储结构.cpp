#include<iostream.h>
#include<stdio.h>

#define Listsize 3
#define	Listadd 1
typedef char elemtype;
typedef struct
{
	int listsize;
	elemtype *elem;
	int length;
}sqlist;
void  malloc(sqlist &p,int i)
{
	
	p.elem=new elemtype [i];
	
}
void remalloc(sqlist &p,int i)
{
	elemtype *q=new elemtype[i];
	for(int j=0;j<i-1;j++)
		q[j]=p.elem[j];
	delete p.elem;
	p.elem=new elemtype [i];
	for(j=0;j<i;j++)
		p.elem[j]=q[j];
}



void initlist_sq(sqlist &L)
{
	malloc(L,Listsize);
	if(!L.elem){printf("overflow");};
	L.length=0;
    L.listsize=Listsize;

}
void creatlist(sqlist &L)
{
	char x;int i=0,h=0;
	cout<<"input int type data,endof $"<<endl;
	cin>>x;
	
	
		while(x!='$'&&i<L.listsize)
		{
			L.elem[i]=x;i++;cin>>x;
		}
		if(x!='$')
		{
			remalloc(L,Listsize+Listadd);
			if(!L.elem) {printf("overflow");};
			
			L.listsize+=Listadd;
			L.elem[i]=x;i++;cin>>x;
		}
		else
		{ L.length=i;return ;};
	
}

void display(sqlist &L)
{
	int i=0;cout<<"\n";
	cout<<"元素列表:";
	for(i;i<L.length;i++)
	{
		cout<<L.elem[i]<<" ";
	}
	cout<<"元素个数:"<<L.length<<" "<<"空间大小:"<<L.listsize<<endl;
}

void deleteList(sqlist &L,int i)
{
	int j;
	if(i<1||i>L.length)
	{
		printf("position error");
		return ;
	}

		for(j=i+1;j<=L.length;j++)
			L.elem[j-2]=L.elem[j-1];
        L.length--;
}

void Insert(sqlist &L,elemtype x,int i) //在表中第i个位置之前插入新元素x//
{
	elemtype *q,*p;
	if(i<1||i>L.length+1) {printf("position error"); return ;};
	if(L.length>=L.listsize)
	{
		remalloc(L,(Listsize+Listadd));	
        if(!L.elem) {printf("overflow");}; 
       
        L.listsize+=Listadd;
	};
	q=&(L.elem[i-1]);  //q为插入位置//
	for(p=&(L.elem[L.length-1]);p>=q;p--)
		*(p+1)=*p;
	*q=x;
	L.length++;
	  //插入成功//
}

int Locate_sq(sqlist &L,elemtype x)
{
	int i=1; //按序列下标//
	while(i<=L.length && L.elem[i-1]!=x)
		i++;
	if (i<=L.length) return i;
	else return -1;
}

int  main()
{
	int i;char x;
	sqlist L;
	initlist_sq(L);
	creatlist(L);
	display(L);
	cout<<"input  delet elem i=";
	cin>>i;
	deleteList(L,i);
	display(L);
	cout<<"\ninput insert elem i=";
	cin>>i;
	cout<<"\ninput insert elem x=";
	cin>>x;
    Insert(L,x,i);
	display(L);
    cout<<"\ninput search elem valu x=";
	cin>>x;
	if(Locate_sq(L,x)==1) {cout<<"no exist"<<endl;}
	else cout<<Locate_sq(L,x)<<endl;
	return 0;
}
  