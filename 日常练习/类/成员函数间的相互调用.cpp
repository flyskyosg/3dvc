#include<iostream>

using namespace std;

class student
{
      int num;
      public:
             
		  student(){}
             
			 student(int n):num(n){}
             
			 void disp() //������ڲ�����Ա��������໥����Ĭ�϶��ߵ���ͬһ����������ݳ�Ա
             {disp1();}
             
			 void disp1()
             {
                  cout<<num<<endl;
             }
};

int main()
{
  
     student stu1(10);
     stu1.disp();
     return 1;
     getchar();
} 