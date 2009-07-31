#ifndef STACK_H
#define STACK_H

#include"stdafx.h"

template<typename T>              //��ģ��
class c_stack
{
	T * stack;
	int m;
	public:
		c_stack(int n)
		{
			
			stack=new T [n];
			m=-1;
		}

		void push(T a);
	

		void pop();
	

};		

template<typename T>
void c_stack<T> ::pop()
{
	m--;	
}
template<typename T>
void c_stack<T>:: push(T a)
{
	cout<<"����һ��ģ��"<<endl;		
	m++;
	stack[m]=a;
}


                                     //��ģ���ػ�
template<>
class c_stack<char>
{

	char * stack;
	int m;
	public:
		c_stack(int n)
		{
			
			stack=new char [n];
			m=-1;
		}

		void push(char a);
	

		void pop();
	

};		


void c_stack<char>::pop()
{
	m--;	
}

void c_stack<char>:: push(char a)
{
	cout<<"�����ػ�"<<endl;		
	m++;
	stack[m]=a;
}




template<class T,class T1>               //����ģ��
void c_push(T & a,T1 b)
{
	cout<<"���ú���ģ��"<<endl;   
	a.push(b);
}


void c_push(c_stack<int> & a,int b)        //����ģ���ػ�
{
	cout<<"���ú���ģ���ػ�"<<endl;
}


#endif