#include<iostream>

using namespace std;

class student
{
      int num;
      public:
             
		  student(){}
             
			 student(int n):num(n){}
             
			 void disp() //在类的内部，成员函数间的相互调用默认二者调用同一个对象的数据成员
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