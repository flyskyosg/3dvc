#include<iostream>//����.h�ʹ�.h��ͷ�ļ��ǲ�һ����,����ļ���������mallc��free����;
#include<string.h>
#include<iostream.h>
typedef char Datatype1;//ͨ����������1
typedef int Datatype2; 

typedef struct fstacknode//�������ջ���
{
    Datatype1 data;
	struct fstacknode *next;
}FLinkstack;

typedef struct dstacknode//��������ջ���
{
	Datatype2 data;
	struct dstacknode *next;
}DLinkstack;



void initstack(DLinkstack *& l)//��ʼ������ջ
{
	l=NULL;
}

void initstack(FLinkstack *& l)//��ʼ������ջ
{
	l=NULL;
}



	
void push(DLinkstack * & l,Datatype2 x)  //������ջ
{
	
	DLinkstack *p=(DLinkstack *)malloc(sizeof(DLinkstack)); //����Ҫע�� :malloc����Ŀռ�Ҫ��������ת��,��(����*)����ǿ������ת��.
	if(l==NULL) p->next=NULL;
	else p->next=l;
	p->data=x;l=p;
}

void push(FLinkstack * & l,Datatype1 x)  //�����ջ()
{
    FLinkstack *p=(FLinkstack *)malloc(sizeof(FLinkstack));
	if(l==NULL) p->next=NULL;
	else p->next=l;
	p->data=x;l=p;
}
Datatype2 pop(DLinkstack * & l)  //������ջ
{
	if(l==NULL) cout<<"վ��."<<endl;
	Datatype2 x=l->data;
	DLinkstack *p=l;
	l=p->next;
	free(p);
	return x;
}

Datatype1 pop(FLinkstack * & l)  //������ջ
{
	if(l==NULL) cout<<"վ��."<<endl;
	Datatype1 x=l->data;
	FLinkstack *p=l;
	l=p->next;
	free(p);
	return x;
}
         
Datatype1 read(FLinkstack * & l)//��ȡ����ջ�Ķ���Ԫ��
{
	return l->data;
}

Datatype2 read(DLinkstack * & l)//��ȡ����ջ�ĵĶ���Ԫ��
{
	return l->data;
}


bool recog(char x)     //�ж��Ƿ�Ϊ�����ַ�,����1��ʾ����,����0��ʾ�����.
{
	if(x>='0'&&x<='9') return 1;
	else return 0;
}
int quan(int i)  //����Ȩ��
{
	int j=1;
	for(;i>0;i--)
		j*=10;
	return j;
}
int exchange(char t) //�������ַ�ת��Ϊʮ��������.
{
	switch(t)
	{
	case'0':return 0;  //�����ַ���asc��ֵ����ת��Ϊ10��������.
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


int  comp(char a,char b) //����1,a<=b��ջ,����0,a>b��ջ;
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
	case'(':return 1;   //��aΪ(ʱ,bΪ�κ���ͨ�����ʱ�����ȼ�������(;��(����ʱ,�����ж�,ֱ����ջ.
	default:return 0;
		
	}
}
int exe(int a,char c,int b)  //ִ�к���,���ݸ����������������ջ��������Ԫ�صı��ʽ,����Ҫע�����,�����������䴫�ݲ���ʱ��,��Ϊջ�൱�볣���൱����ú�������Ĭ��ֵ,��ô,���������е��øú���ʱ���������ʱ���������ϵ�.�ڽ��ջ�Ĵ洢����,������,����a,b�������ϵ�˳��.
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
void initchars(char *t,int j) //��ʼ��������ַ���ָ��.
{
	for(int i=0;i<j;i++)
		*(t+i)='\0';
}

void main()
{
	DLinkstack *number;FLinkstack *sign;
	initstack(number);initstack(sign);
	push(number,100);push(number,200);cout<<read(number)<<endl;cout<<pop(number)<<endl;cout<<pop(number)<<endl;//����ջ�Ƿ���������ĳ���ջ.
    
	int  * size=new int;
	cout<<"������ʽ����ռ�Ĵ�С:";cin>>*size;
	if(!size)cout<<"����ռ�ʧ��."<<endl;
	else
	{
		cout<<"�ɹ�����"<<(*size)<<"���ַ��ռ�"<<endl;
	};
	
	char *expre=new char[*size];
	initchars(expre,*size);                                  //����ָ��Ŀռ��ÿ��ֵ��λΪ'\0';��ȫ;
	cout<<"��ʼ�����ַ�����ֵΪ:"<<strlen(expre)<<endl;//�����ַ����Ƿ��ʼ��;
	cout<<"���������ʽ���ʽ,ֻ�ܰ���+-*/��()�ұ�����#��Ϊ������."<<endl;
	cin>>expre;
	cout<<expre<<endl;
	
    char *t=new char [*size]; //�ݴ渨���ַ���,
    initchars(t,*size);
	cout<<"��ʼ�������ַ�����ֵΪ:"<<strlen(t)<<endl;//�����ַ����Ƿ��ʼ��;//����ָ��Ŀռ��ÿ��ֵ��λΪ'\0';��ȫ;
	                                        
	int i=0;
	while(expre[i]!='\0')             //���������ʽ�Ľ�����Ϊֹ.
	{
		if(recog(expre[i]))           //�ж��������ַ����Ƿ����ַ�,��ֵΪ�����ַ�,0Ϊ�ַ��ַ�.
		{
			int k=0;   //k ������Ϊ�����ַ�����t�Ĳ���,
			for(;recog(expre[i])==1;i++,k++)
				t[k]=expre[i];
		    int add=0, j=0;	//add��Ϊ�洢ת������ַ������ۼӵ�ֵ.
	                    //j ���������ѭ���ı���,��kΪ������,
    	    for( ;j<k;j++)
			{
			  
		      add+=quan(k-j-1)*exchange(t[j]);
			}
	  
            push(number,add);
	        cout<<"��ǰջ��Ԫ��:"<<read(number)<<endl; //ת������������鿴һ���Ƿ�ת����ȷ.
		}
		else  //��expre[i]Ϊ�����ַ�ʱִ��;
		{
			if(sign==NULL) push(sign,expre[i]);  //�жϷ���ջ�Ƿ�Ϊ��,Ϊ��,ֱ����ջ.
			else                                 //������ջ��Ϊ��ʱִ��.
			{
				if(expre[i]=='#') //����������ʱ�Ĵ������.
				{
					
							do
							{
								int m=0;char c=pop(sign);
								m=exe(pop(number),c,pop(number));
						        
						        push(number,m);
								
								
						        
							} while(sign!=NULL); //����������ʱ�ѷ���ս�е����з���һ�ε�����������,���õĽ����Ȼ��������ջ��.ֱ��վ��Ϊֹ.


				}
				else
				{
					if(expre[i]=='(') push(sign,expre[i]);//����(ֱ����ջ.
				    else 
					{
					if(expre[i]==')') //����)ʱ������ջ��ֱ��(�����ķ���ȫ��������������.
					{
					   do
					   {
					   int sd; //�洢����������.
					   sd=exe(pop(number),pop(sign),pop(number));
					   push(number,sd);//�������Ȼ�����ݴ洢������ջ��.
					   } while(sign->data!='(');
				  	   pop(sign);
					   
					}
					else
					{
						char sf=read(sign);
				        if(comp(sf,expre[i])) push(sign,expre[i]);//����һ��ķ���ʱ�����ջ�Ķ���Ԫ�ؽ��бȽ�,������ڶ���Ԫ��,��ջ��֮,��ջ����.
				        else
						{
							int m=0;
							do
							{
								m=exe(pop(number),pop(sign),pop(number));//�洢����������.
						        
						        push(number,m); //��Ȼ�洢������ջ��.
								if(sign==NULL) break;//����ע��,ǰ�߳�ջ����ܵ���վ��,���������Ҫ�ж�һ���Ƿ�վ��,�����±ߵĶ�ȡ�����,���expreֻż�Ǹ�����Ԫ��,����Ҫ����ѭ��.
								sf=read(sign);
								if(sf=='(') break;//���������(ʱ,�κε�����������ȼ�������(;ֱ������,�Ѹ��������ջ����.
								
						        
							} while(!comp(sf,expre[i]));//����һֱ���㵽����ջ�ڵķ��ŵ����ȼ�С�ڵ��ڸ÷���λ��,ֹͣ�󽫸��������ջ����.
							push(sign,expre[i]);

					        
							
						}
						
						
					}
				
					
				 
					}
				}
				
				
					
			}
    	i++;
		}
	
	}
	cout<<"����ʽ��ֵΪ:"<<read(number)<<endl;//�����е����������,����ջ��Ӧ��ֻʣһ��Ԫ��,���Ǳ��ʽ��ֵ.
}






			






















		

	




	


