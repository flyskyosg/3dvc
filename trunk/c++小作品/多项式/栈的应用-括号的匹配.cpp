#include<iostream.h>
#include<string.h>
typedef char datatype;    //ʹ�ö�������,����Ҫ�ı����账���Ԫ������ʱ,ֻ��Ҫ������Ϳ��Ըı���������//
#define stacksize 10       //ͬ��,���Է���ĸĵ������е�����ֵ//
typedef struct stack
{
	datatype p[stacksize];
	int top;
}Stack;
void initstack(Stack & l)
{
    
    l.top=-1;
}


void  push(Stack &l,datatype u) //��ջ//
{	
	l.top++;
	l.p[l.top]=u;
	cout<<"ѹ�����ݳɹ�."<<endl;
	if(l.top==stacksize-1) cout<<"ջ��."<<endl;


}
void pop(Stack & l)  //��ջ//
{
	cout<<"���Ԫ��:"<<l.p[l.top]<<endl;
	l.top--;

	

}
int recog(datatype u)//����ͬ��Ԫ������һ�����,��ƥ���Ԫ�ؾ������3���ض���ϵ//
{
	switch(u)
	{
	case'(':return 0;break; //(Ϊ0,)Ϊ3;���������Ϊ3�Ĺ�ϵ,�Ա��Ժ������ж�/ջ��Ԫ�غ͵�ǰԪ���Ƿ�ƥ��/
	case'[':return 1;break;
	case'{':return 2;break;
	case')':return 3;break;
	case']':return 4;break;
	case'}':return 5;break;
	default:break;
	}
}

bool comp(int i,int j)  //�Ƚ�ջ��Ԫ���Ƿ��뵱ǰ����ƥ���Ԫ��ƥ��//
{
	if(i==j-3) return 1;//�������ϵʽʱ,˵��ƥ��.����ƥ��//
	else return 0;
}

int  main()
{
	Stack a;initstack(a);
	datatype b[stacksize+1];
	cout<<"������һ�������ַ�����:";
	cin>>b;
	if(b[0]=='}'||b[0]==']'||b[0]==')') {cout<<"�������в�ƥ��."<<endl;return 0;}//�����һ��Ԫ���Ƿ��ǿ�����,�����,�����в�����ƥ��//
	int i=1,s;       //����״̬��־s������¼��ǰջ��Ԫ�صı��//
	for(;i<=strlen(b);i++) //ѭ���Ĵ��������ַ����еĳ��ȶ���//
	{
		if(a.top==-1)    //���ջΪ��ջ,��Ҫ��һ��Ԫ��ѹ��վ��,����ǰջ���ı�Ŵ���s//
		{
			push(a,b[i-1]);
			s=recog(b[i-1]);
		}
		else
		{
			if(comp(s,recog(b[i-1]))) pop(a); //comp�����Ƚϵ�ǰԪ���Ƿ���ջ��ƥ��,����һ���ջ,����0����ջ//
			else push(a,b[i-1]);
			s=recog(a.p[a.top]);//�����ǳ�ջ������ջ,�������Ҫ��sָ��ǰ��ջ��Ԫ��//
		}
		
	}
	if(a.top!=-1) {cout<<"�������в�ƥ��"<<endl;return 0;}//��ִ�������е�Ԫ�غ�,ջ��Ӧָ��-1;�������,��˵��ջ�ڻ�����Ԫ��,�����в�ƥ��//
	else{cout<<"��������ƥ��"<<endl;return 1;};//���ƥ��,վ��ӦΪ��//
}

		
		
		




		










