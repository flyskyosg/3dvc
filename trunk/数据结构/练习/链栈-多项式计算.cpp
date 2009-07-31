#include<iostream>//不带.h和带.h的头文件是不一样的,这个文件用来包含mallc和free函数;
#include<string.h>
#include<iostream.h>
typedef char Datatype1;//通用数据类型1
typedef int Datatype2; 

typedef struct fstacknode//定义符号栈结点
{
    Datatype1 data;
	struct fstacknode *next;
}FLinkstack;

typedef struct dstacknode//定义数据栈结点
{
	Datatype2 data;
	struct dstacknode *next;
}DLinkstack;



void initstack(DLinkstack *& l)//初始化数据栈
{
	l=NULL;
}

void initstack(FLinkstack *& l)//初始化符号栈
{
	l=NULL;
}



	
void push(DLinkstack * & l,Datatype2 x)  //入数据栈
{
	
	DLinkstack *p=(DLinkstack *)malloc(sizeof(DLinkstack)); //这里要注意 :malloc申请的空间要进行类型转换,用(类型*)进行强制类型转换.
	if(l==NULL) p->next=NULL;
	else p->next=l;
	p->data=x;l=p;
}

void push(FLinkstack * & l,Datatype1 x)  //入符号栈()
{
    FLinkstack *p=(FLinkstack *)malloc(sizeof(FLinkstack));
	if(l==NULL) p->next=NULL;
	else p->next=l;
	p->data=x;l=p;
}
Datatype2 pop(DLinkstack * & l)  //出数据栈
{
	if(l==NULL) cout<<"站空."<<endl;
	Datatype2 x=l->data;
	DLinkstack *p=l;
	l=p->next;
	free(p);
	return x;
}

Datatype1 pop(FLinkstack * & l)  //出符号栈
{
	if(l==NULL) cout<<"站空."<<endl;
	Datatype1 x=l->data;
	FLinkstack *p=l;
	l=p->next;
	free(p);
	return x;
}
         
Datatype1 read(FLinkstack * & l)//读取符号栈的顶端元素
{
	return l->data;
}

Datatype2 read(DLinkstack * & l)//读取数据栈的的顶端元素
{
	return l->data;
}


bool recog(char x)     //判断是否为数字字符,返回1表示数字,返回0表示运算符.
{
	if(x>='0'&&x<='9') return 1;
	else return 0;
}
int quan(int i)  //计算权重
{
	int j=1;
	for(;i>0;i--)
		j*=10;
	return j;
}
int exchange(char t) //将数字字符转换为十进制整数.
{
	switch(t)
	{
	case'0':return 0;  //根据字符的asc码值进行转换为10进制整数.
	case'1':return 1;
	case'2':return 2;
	case'3':return 3;
	case'4':return 4;
	case'5':return 5;
	case'6':return 6;
	case'7':return 7;
	case'8':return 8;
	case'9':return 9;
	default:return 0;
	}
}


int  comp(char a,char b) //返回1,a<=b入栈,返回0,a>b出栈;
{
      //43 +; 42 *;45  -;47 /;

	switch(a)
	{
	case '+':switch(b)         
			{
				case 45:return 1;break;
				case 42:return 1;break;
				case 47:return 1;break;
				default:return 0;
			};
	case '-':switch(b)
			{
				case 43:return 1;break;
				case 42:return 1;break;
				case 47:return 1;break;
				default:return 0;
			};
	case '*':switch(b)
			{
				case 45:return 0;break;
				case 43:return 0;break;
				case 47:return 1;break;
				default:return 0;
			};
	case '/':switch(b)
			{
				case 45:return 0;break;
				case 42:return 1;break;
				case 43:return 0;break;
				default:return 0;
			};
	case'(':return 1;   //当a为(时,b为任何普通运算符时其优先级均大于(;当(出现时,不做判断,直接入栈.
	default:return 0;
		
	}
}
int exe(int a,char c,int b)  //执行函数,根据给出的运算符来计算栈顶的两个元素的表达式,这里要注意的是,当主函数向其传递参数时后,因为栈相当与常量相当与给该函数设置默认值,那么,在主函数中调用该函数时其参数表列时从右向左结合的.在结合栈的存储特性,先入后出,所以a,b具有以上的顺序.
{                          
	switch(c)
	{
		case '-':return a-b;break;
		case '+':return a+b;break;
		case '*':return a*b;break;
		case '/':return a/b;break;
		default:return 0;
	}
}
void initchars(char *t,int j) //初始化定义的字符串指针.
{
	for(int i=0;i<j;i++)
		*(t+i)='\0';
}

void main()
{
	DLinkstack *number;FLinkstack *sign;
	initstack(number);initstack(sign);
	push(number,100);push(number,200);cout<<read(number)<<endl;cout<<pop(number)<<endl;cout<<pop(number)<<endl;//测试栈是否可以正常的出入栈.
    
	int  * size=new int;
	cout<<"输入表达式所需空间的大小:";cin>>*size;
	if(!size)cout<<"申请空间失败."<<endl;
	else
	{
		cout<<"成功申请"<<(*size)<<"个字符空间"<<endl;
	};
	
	char *expre=new char[*size];
	initchars(expre,*size);                                  //将其指向的空间的每个值复位为'\0';安全;
	cout<<"初始化后字符串的值为:"<<strlen(expre)<<endl;//测试字符串是否初始化;
	cout<<"请输入多项式表达式,只能包含+-*/和()且必须以#作为结束符."<<endl;
	cin>>expre;
	cout<<expre<<endl;
	
    char *t=new char [*size]; //暂存辅助字符串,
    initchars(t,*size);
	cout<<"初始化后辅助字符串的值为:"<<strlen(t)<<endl;//测试字符串是否初始化;//将其指向的空间的每个值复位为'\0';安全;
	                                        
	int i=0;
	while(expre[i]!='\0')             //到整个表达式的结束符为止.
	{
		if(recog(expre[i]))           //判断是数字字符还是符号字符,真值为数字字符,0为字符字符.
		{
			int k=0;   //k 用来作为辅助字符数组t的参数,
			for(;recog(expre[i])==1;i++,k++)
				t[k]=expre[i];
		    int add=0, j=0;	//add作为存储转化后的字符串的累加的值.
	                    //j 用在做后便循环的变量,以k为结束量,
    	    for( ;j<k;j++)
			{
			  
		      add+=quan(k-j-1)*exchange(t[j]);
			}
	  
            push(number,add);
	        cout<<"当前栈顶元素:"<<read(number)<<endl; //转换结束后这里查看一下是否转换正确.
		}
		else  //当expre[i]为符号字符时执行;
		{
			if(sign==NULL) push(sign,expre[i]);  //判断符号栈是否为空,为空,直接入栈.
			else                                 //当符号栈不为空时执行.
			{
				if(expre[i]=='#') //遇到结束符时的处理情况.
				{
					
							do
							{
								int m=0;char c=pop(sign);
								m=exe(pop(number),c,pop(number));
						        
						        push(number,m);
								
								
						        
							} while(sign!=NULL); //遇到结束符时把符号战中的所有符号一次弹出进行运算,所得的结果仍然存在数据栈中.直到站空为止.


				}
				else
				{
					if(expre[i]=='(') push(sign,expre[i]);//遇到(直接入栈.
				    else 
					{
					if(expre[i]==')') //遇到)时将符号栈内直到(结束的符号全部弹出进行运算.
					{
					   do
					   {
					   int sd; //存储运算后的数据.
					   sd=exe(pop(number),pop(sign),pop(number));
					   push(number,sd);//运算后仍然将数据存储与数据栈中.
					   } while(sign->data!='(');
				  	   pop(sign);
					   
					}
					else
					{
						char sf=read(sign);
				        if(comp(sf,expre[i])) push(sign,expre[i]);//遇到一般的符号时与符号栈的顶端元素进行比较,如果高于顶端元素,入栈反之,出栈运算.
				        else
						{
							int m=0;
							do
							{
								m=exe(pop(number),pop(sign),pop(number));//存储运算后的数据.
						        
						        push(number,m); //仍然存储与数据栈中.
								if(sign==NULL) break;//这里注意,前边出栈后可能导致站空,当运算完后要判断一下是否站空,否则下边的读取会出错,如果expre只偶那个还有元素,则需要继续循环.
								sf=read(sign);
								if(sf=='(') break;//当左边遇到(时,任何的运算符的优先级均大于(;直接跳出,把该运算符入栈操作.
								
						        
							} while(!comp(sf,expre[i]));//这里一直运算到符号栈内的符号的优先级小于等于该符号位置,停止后将该运算符入栈操作.
							push(sign,expre[i]);

					        
							
						}
						
						
					}
				
					
				 
					}
				}
				
				
					
			}
    	i++;
		}
	
	}
	cout<<"多项式的值为:"<<read(number)<<endl;//当所有的运算结束后,数据栈中应该只剩一个元素,即是表达式的值.
}






			






















		

	




	


