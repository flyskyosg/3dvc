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
static int GetCount(); //�κ����͵ĺ��������Է��ʾ�̬��Ա��������˽�еľ�̬��Ա����ֻ�ܱ���Ա��������//
static long GetID(Student); //��̬�������Է��ʾ�̬���ݳ�ԱҲ����ͨ��������ʷǾ�̬���ݳ�Ա��// 
static  void GetName(Student x) //��̬����ֻ���Է��ʾ�̬����Ҳ����ͨ��������ʷǾ�̬��Ա�������Լ�������ĺ���������//
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
Student Student1("CHEN SI",1101,"Ů",21);  
Student Student2=Student("CADY",1101,"Ů",20);  
Student Student3=Student("LUCY",1101,"Ů",20);  
cout<<Student1.GetID(Student1)<<' ';Student::GetName(Student1);cout<<endl;  
cout<<Student1.GetID(Student2)<<' ';Student::GetName(Student2);cout<<endl; 
cout<<Student1.GetID(Student3)<<' ';Student::GetName(Student3);cout<<endl; 
cout<<Student::GetCount()<<endl;
}   