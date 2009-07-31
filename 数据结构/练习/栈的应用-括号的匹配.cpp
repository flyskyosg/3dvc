#include<iostream.h>
#include<string.h>
typedef char datatype;    //使用定义命令,当需要改变所需处理的元素类型时,只需要改这里就可以改变整个程序//
#define stacksize 10       //同上,可以方便的改掉程序中的所有值//
typedef struct stack
{
	datatype p[stacksize];
	int top;
}Stack;
void initstack(Stack & l)
{
    
    l.top=-1;
}


void  push(Stack &l,datatype u) //入栈//
{	
	l.top++;
	l.p[l.top]=u;
	cout<<"压入数据成功."<<endl;
	if(l.top==stacksize-1) cout<<"栈满."<<endl;


}
void pop(Stack & l)  //出栈//
{
	cout<<"输出元素:"<<l.p[l.top]<<endl;
	l.top--;

	

}
int recog(datatype u)//给不同的元素设置一个编号,相匹配的元素具有相差3的特定关系//
{
	switch(u)
	{
	case'(':return 0;break; //(为0,)为3;二者满足差为3的关系,以便以后用来判断/栈顶元素和当前元素是否匹配/
	case'[':return 1;break;
	case'{':return 2;break;
	case')':return 3;break;
	case']':return 4;break;
	case'}':return 5;break;
	default:break;
	}
}

bool comp(int i,int j)  //比较栈顶元素是否与当前所需匹配的元素匹配//
{
	if(i==j-3) return 1;//当满足关系式时,说明匹配.否则不匹配//
	else return 0;
}

int  main()
{
	Stack a;initstack(a);
	datatype b[stacksize+1];
	cout<<"请输入一串括号字符序列:";
	cin>>b;
	if(b[0]=='}'||b[0]==']'||b[0]==')') {cout<<"括号序列不匹配."<<endl;return 0;}//检验第一个元素是否是开括号,如果是,则序列不满足匹配//
	int i=1,s;       //设置状态标志s用来记录当前栈顶元素的编号//
	for(;i<=strlen(b);i++) //循环的次数根据字符序列的长度而定//
	{
		if(a.top==-1)    //如果栈为空栈,则要第一个元素压入站内,并当前栈顶的编号存入s//
		{
			push(a,b[i-1]);
			s=recog(b[i-1]);
		}
		else
		{
			if(comp(s,recog(b[i-1]))) pop(a); //comp函数比较当前元素是否与栈顶匹配,返回一则出栈,返回0则入栈//
			else push(a,b[i-1]);
			s=recog(a.p[a.top]);//不管是出栈还是入栈,操作完后都要吧s指向当前的栈顶元素//
		}
		
	}
	if(a.top!=-1) {cout<<"括号序列不匹配"<<endl;return 0;}//当执行完所有的元素后,栈顶应指向-1;如果不是,则说明栈内还存有元素,则序列不匹配//
	else{cout<<"括号序列匹配"<<endl;return 1;};//如果匹配,站内应为空//
}

		
		
		




		










