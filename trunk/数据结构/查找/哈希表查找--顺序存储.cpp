#include<iostream.h>  //��ϣ��Ŀ����Խ����ͻ
#define max 50

typedef struct node
{
	int key;
	char data;
}node;

node st[max];      //�洢��


int sol(int key)   //+1��ɢ��(��ͻ����)
{
	return (key+1)%max;
}


int hax(int key)   //��ϣ����
{
	int n=-1;
	n=key%45;
	while(st[n].data!='\0')   //�����ͻ
	{
		n++;
		n=sol(n);
	}
	return n;
}


void main()
{  
	int i=0;
	for(i;i<max;i++)
		st[i].data='\0';


	int key,n;char data='\0';
	cout<<"����ؼ���������(key_data),����0_0��������:";
	cin>>key>>data;

    while(data!='0')
	{
	if(key>max||key<0) cout<<"�ؼ��ֳ�����Χ."<<endl;
	else
	{
		n=hax(key);
		st[n].data=data;
		st[n].key=key;
	}
	cout<<"����ؼ���������(key_data):";
	cin>>key>>data;
	}
	cout<<"�������:";
	for(i=0;i<max;i++)
	{
		if(st[i].data!='\0') cout<<st[i].key<<"_"<<st[i].data<<" ";
	}
}
		





