#include<iostream.h>
#include<string.h>
#include<iomanip.h>
typedef int datatype;
#define size 10                           //��Ҫ��д����һЩ���Ӳ���,�Դ���˳��洢�ṹΪ��.
typedef struct 
{
	datatype data[size];
	int len;
}sqstring;


void initstring(sqstring & l) //��ʼ����
{
	for(int i=0;i<size;i++)
	{
		l.data[i]=0;
	}
	l.len=0;
}

void creatstring( sqstring & l) //������
{
	int i=0,j=0;
	for(;i<size;i++)
	{
		cout<<"�����"<<i<<"��Ԫ��,����0����.";
		cin>>j;
		if(j==0) break;
		l.data[i]=j;
		l.len++;
	}
}


bool recog(sqstring  a,sqstring  b) //�ж��������Ƿ����,
{
	int i=a.len,statue=0;
	if(i==b.len)
	{
		for(i--;i>=0;i--)
		{
			if(a.data[i]!=b.data[i]) statue=0;
		}
		if(statue==1) return 1;
	}
	else return  0;
}


void concat(sqstring a,sqstring b,sqstring & d)     //����������
{
	int i=0,j=0;
	if((a.len+b.len)>size) cout<<"���ݳ��ȳ�����Χ,�޷�����."<<endl;
	else
	{
		for(;j<a.len;i++,j++)
			d.data[i]=a.data[j];
		for(j=0;j<b.len;i++,j++)
			d.data[i]=b.data[j];
	}
	d.len=a.len+b.len;
	
}

	
	
	
	
void substr(sqstring & l,int i,int j,sqstring & c)  //��ȡ�ӵ�i��λ�ÿ�ʼ�����ΰ���j��Ԫ�ص��Ӵ�,//
{         

	
	initstring(c);
    int k=0,m=0;
    if((i+j+1)>size)
	{
		cout<<"������Χ."<<endl;
	}
	else
	{    
		m=--i;
		for(k;k<j-1;k++,m++)
		{
			c.data[k]=l.data[m];
			c.len++;
		}
		
	}
}



int index(sqstring a,sqstring b)            //�����Ӵ�b������a�е�λ��. //��ʵ���Ӵ���ɾ��,����,�滻,�����Ļ���.
{
	int i=0,j=0,statue=0;
	for(;i<a.len;i++)
	{
		if(a.data[i]==b.data[0])
		{
			for(j=0;j<b.len;j++,i++)
			{
				if(a.data[i]==b.data[j]) statue=1;
				else statue=0;
			}
			if(statue==1) return i-b.len+1;//i���Ӵ�����������ʼλ��.
		}

	}
	if(statue==0) return 0;
}


void deletestr(sqstring & l,int i,int j)   //ɾ�������дӵ�i��λ�����j��Ԫ��.
{
	int n=i+j-1;
	if(j>l.len) cout<<"������Χ."<<endl;
	else
	{
		for(;n<=l.len-1;n++)
		{
		l.data[n-j]=l.data[n];
		
		}
		l.len-=j;
	
	}
}



void insert (sqstring & a ,int k,sqstring b)  //���Ӵ����뵽�����ĵ�k��λ��.
{
	int i=a.len-1,j=0;k--;
	if((a.len+b.len)>size) cout<<"������Χ."<<endl; 
	else
	{
		for(i;i>=k;i--) //�����һ��Ԫ����ֱ�����ƶ�j��λ��,��b�ڳ��ռ�.
		{
			a.data[i+b.len]=a.data[i];
		}
		i++;
		for(;j<b.len;j++,i++)
		{
			a.data[i]=b.data[j];
			a.len++;
		}
	}

}

void replace1(sqstring & a,sqstring b,sqstring c) //���Ӵ�b������Ԫ���滻Ϊc,Ҫ��b��cһ����.
{
	int p=index(a,b);
	if(b.len!=c.len) cout<<"������һ��."<<endl;
	else
	{

	for(int i=0;i<c.len;i++,p++)
		a.data[p]=c.data[i];
	}
}

void replace2(sqstring & a,sqstring b,sqstring c)
{
	if((a.len-b.len+c.len)>size) cout<<"������Χ."<<endl;
	else
	{
		int p=1;
	while(p!=0)
	{
		p=index(a,b);
		if(p==0) break;
	    deletestr( a,p,b.len);
	    insert( a,p,c);
	}

	
	}
}


void disp(sqstring l)
{
	int i=0;
	for(;i<l.len;i++)
		cout<<setw(3)<<l.data[i];
	cout<<endl;
}

void main()
{
	sqstring a,b,c,d;
	initstring(a);initstring(b);initstring(c);initstring(d);//��ʼ����
	cout<<"��ʼ����a����:";
	disp(a);
	
	cout<<"����a��."<<endl; //������a��b.
    creatstring(a);
	cout<<"����b��."<<endl;
	creatstring(b);
	
	cout<<"a����:";
	disp(a);
	cout<<"b����:";
	disp(b);

	
	if(recog(a,b)==1) cout<<"a��b���."<<endl; //�ж�a��b�Ƿ����.
	else
	{
		cout<<"a��b�����."<<endl;
	}
	
	cout<<"�Ӵ�b������a�ĵ�"<<index(a,b)<<"λ"<<endl;//���Ҵ�b�ڴ�a�е�λ��.

	cout<<"��a��ɾ���ӵ�1��λ�����3��Ԫ�غ�aΪ:";
	deletestr(a,1,3);                                         //������ɾ��������a��ɾ���ӵ�i��λ�����k��Ԫ��.
	disp(a);

	cout<<"��b���뵽a�ĵ�1��λ��."<<endl;
	insert(a,1,b);
	disp(a);
	
	cout<<"����c��."<<endl; //����c��.
	creatstring(c);
	cout<<"c����:";
	disp(c);

	cout<<"����b��c��."<<endl; 
    concat(b,c,d);      //��b��c��������.
	cout<<"���Ӻ���:";
	cout<<endl;
	disp(d);

    cout<<"��a�е�b��ȫ���滻Ϊc."<<endl;
	replace2(a,b,c);
	cout<<"�滻��aΪ:";
	disp(a);

    



	

}





















		   
			






	











