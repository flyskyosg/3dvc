#include <iostream.h>  
#include<string.h>  
class Student  
{  
private:  
char m_name[5];  
int m_id;  
char m_sex[10];  
int m_age; 
static int  m_nCount; 
public:  
Student(char *name,int id,char *sex,int age)  
{   
 strcpy(m_name,name);  
 m_id=id;  
 strcpy(m_sex,sex);   
 m_age=age;  
 m_nCount++; 
 }  
static int GetCount(); //任何类型的函数都可以访问静态成员函数，但私有的静态成员函数只能被成员函数访问//
static long GetID(Student); //静态函数可以访问静态数据成员也可以通过对像访问非静态数据成员。// 
static  void GetName(Student x) //静态函数只可以访问静态函数也可以通过对象访问非静态成员函数，以及类以外的函数及数据//
{ 
for(int i=0;i<5;i++)
cout<<x.m_name[i];
} 
}; 
int Student::GetCount() 
{ 
return m_nCount; 
} 
long Student::GetID(Student x) 
{ 
return x.m_id; 
} 

int Student::m_nCount=0; 
void main()  
{  
Student Student1("CHEN SI",1101,"女",21);  
Student Student2=Student("CADY",1101,"女",20);  
Student Student3=Student("LUCY",1101,"女",20);  
cout<<Student1.GetID(Student1)<<' ';Student::GetName(Student1);cout<<endl;  
cout<<Student1.GetID(Student2)<<' ';Student::GetName(Student2);cout<<endl; 
cout<<Student1.GetID(Student3)<<' ';Student::GetName(Student3);cout<<endl; 
cout<<Student::GetCount()<<endl;
}   