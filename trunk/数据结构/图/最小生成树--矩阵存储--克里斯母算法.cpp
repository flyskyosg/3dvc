#include<iostream.h>            // ͼ���ڽӾ���洢�ṹ
#define max 50
typedef char datatype;
typedef struct node 
{
	int number;             //�ڵ�Ҫ�洢���ż�����
	datatype inf;
}node;
typedef struct graph
{
	int n,e;
	node vex[max];         //�洢�ڵ����Ϣ
	int edge[max][max];      //�洢�ߵ���Ϣ
}G;

void creatgraph(G & l)
{
	int i=0,j=0,b=0,t=0,w=0;
	cout<<"����ͼ�Ķ����������:";
	cin>>l.n>>l.e;
	cout<<"��ͼ��"<<l.n<<"������"<<l.e<<"����"<<endl;
	for(;i<l.n;i++)
	{
		cout<<"�������"<<i<<"���ڵ����Ϣ,�������_�ڵ�����:";
		cin>>l.vex[i].number>>l.vex[i].inf;
	}
	for(i=0;i<l.n;i++)
		for(j=0;j<l.n;j++)
			l.edge[i][j]=0;

    for(j=0;j<l.e;j++)
	{
		cout<<"����ߵ���Ϣ,������_�յ�_Ȩֵ:";
		cin>>b>>t>>w;
        
		if(b<0||b>=l.n) cout<<"��㲻��������Χ��."<<endl;
        
		if(t<0||t>=l.n) cout<<"�յ㲻��������Χ��."<<endl;

		l.edge[b][t]=w;
	}
	cout<<"�����������."<<endl;
}


void disp(G  l)
{
	int i=0,j=0;
	for(i;i<l.n;i++)
	{
		for(j=0;j<l.n;j++)
		{
			if(l.edge[i][j]!=0)
			cout<<" "<<l.edge[i][j];
		}
		cout<<endl;
	}
}



//*******************��С����������³˹�����㷨��***********************//

typedef struct edge
{
	int number0, //ͷ�ڵ�
		number1, //β�ڵ�
		weight;  //Ȩֵ
}edge;

edge l[max];        //��űߵ���Ϣ
int visited[max];   //�洢��Ӧ�ڵ����ڵ���ͨ�����ı��

void px(int n) //�Դ�űߵ����鰴����С����������� ,nΪ�ߵĸ���
{
	edge t;int i=0,j=0;
	for(i=0;i<n-1;i++)
		for(j=0;j<n-i-1;j++)
		{
			if(l[j].weight>l[j+1].weight)   
			{
				t=l[j];
				l[j]=l[j+1];
				l[j+1]=t;
			}
		}
}

void exchange(G & t,G & mt) //�ú������������ã�һ�����ô��ڵ�ͼ�Ľڵ������ʼ����С�������Ľڵ����飨�������ڽӾ���洢��С��������
{                           //��һ���ǰ�ͼ�ı�����ת����l[max]���飬������������Լ�����ʹ��
	int i=0,j=0,k=0;        //ѭ������
	for(i=0;i<t.n;i++)
	{
		mt.vex[i]=t.vex[i]; //�ô��ڵ�ͼ�Ľڵ������ʼ����С�������Ľڵ����飨�������ڽӾ���洢��С��������

		for(j=0;j<t.n;j++)
		{

			if(t.edge[i][j]!=0)  //�鵽�ñߺ����l[max]
			{
				l[k].number0=i;
				l[k].number1=j;
				l[k].weight=t.edge[i][j];
				k++;
			}
		
		}
	}
}




void mintree(G & t ,G & mt)
{
    
	exchange(t,mt);              
	px(t.n);
	for(int i=0;i<t.n;i++)	  //��ʾ��visited���飬ÿ���ڵ����ڵ���ͨ������ų�ʼ��Ϊ���ڵ����ţ����ʺ󽫶�Ӧ��visited����Ķ�Ӧλ����Ϊ-1����ʾ����ͬ����-1��ŵ���ͨ������
	   visited[i]=i;
	
	int j=0,k=0;              //ѭ������
   	
	for(i=0;i<t.n;i++)        //��ʼ��mt�ı����飬ȫ����Ϊ0;
	for(j=0;j<t.n;j++)
 	 mt.edge[i][j]=0;

    j=0;   //����ע��Ҫ��j��ʼ��Ϊ0����Ϊ�±ߵ�ѭ�����λ 



	while(j!=t.n-1)           //������j=n-1��ʱ����ֹѭ������ʾҪ�ҵ�n-1���ߣ��Ǹ������ͼ����С��������n-1����
	{
		if(visited[l[k].number0]!=visited[l[k].number1])        //�ڸñߵ������ڵ㲻��ͬһ����ͨ�����е�ʱ�򽫸ı����mt�ı����顣
		{
			mt.edge[l[k].number0][l[k].number1]=l[k].weight;    //����mt�ı�����
			j++;
			visited[l[k].number0]=-1;visited[l[k].number1]=-1;  //����Ҫע�������Ҫ�ѱߵ������ڵ�Ķ�Ӧ����ͨ����״̬λ��Ϊ-1��
		}
		k++;   //Ȼ��һ������жϱߣ�֪��j�ﵽn-1��
	}
	mt.n=t.n;  //���Ҫ�Ѷ�Ӧ�Ľڵ���Ŀ��ʼ��


	


}
//**************************************//


void main()
{
	G t,l;
	cout<<"����ͼ:"<<endl;
	creatgraph(t);
	cout<<"�������ͼ:"<<endl;
	disp(t);
	cout<<"������С������:"<<endl;
	mintree(t,l);
	cout<<"��С������:"<<endl;
	disp(l);
}






