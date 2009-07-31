#include<iostream.h>
#include<string.h>
class student
{
	static int sum1, sum2,j;
public:
	
	int i;char name[5];long m_score;long y_score;
	student(int o,char *p,long q,long r)
	{
		i=o;strcpy(name,p);m_score=q;y_score=r;
		j++;
		sum1+=m_score;sum2+=y_score;
		 
	}
	void shuchu()
	{
		cout<<i<<" ";nam();cout<<" "<<y_score<<" "<<m_score<<endl;
	}
     
	void nam()
	{
		for(int l=0;l<=4;l++)
			cout<<name[l];
	}
		
		static void average()
		{
		sum1/=j;sum2/=j;
		cout<<"数学平均成绩"<<":"<<sum1<<endl;
        cout<<"语文平均成绩"<<":"<<sum2<<endl;
		}
};  
int student::sum1=0; int student::  sum2=0; int student::  j=0;
 
void main()
 {
	 student g[2]={student(1,"li na",90,80),student(2,"li si",80,88)};
	 for(int i=0;i<=1;i++)
		g[i].shuchu();
	    g[0].average();
 }
	 


  






 


