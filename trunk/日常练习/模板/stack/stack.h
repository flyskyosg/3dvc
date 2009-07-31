#ifndef STACK_H
#define STACK_H

#include"stdafx.h"

template<typename T>              //类模板
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
	cout<<"调用一般模板"<<endl;		
	m++;
	stack[m]=a;
}


                                     //类模板特化
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
	cout<<"调用特化"<<endl;		
	m++;
	stack[m]=a;
}




template<class T,class T1>               //函数模板
void c_push(T & a,T1 b)
{
	cout<<"调用函数模板"<<endl;   
	a.push(b);
}


void c_push(c_stack<int> & a,int b)        //函数模板特化
{
	cout<<"调用函数模板特化"<<endl;
}


#endif