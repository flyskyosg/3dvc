#include<iostream>      //�Զ������͵Ķ��ת�� 

using namespace std;

class xiao
{
      int a;
      public:
             xiao(int x):a(x){}
};

class da
{
      char a;
      public:
             da(xiao a)
             {}
};

void f(da a)
{}

int main()
{
    //f('c');    //�ȴ�char ��  xiao ,�ٴ�xiao �� da; ������ת�������� 
    f(da('c'));  //ֱ������da����ʱ����  ��Ҳ���ȴ�char ��  xiao ,�ٴ�xiao �� da�� ���������﷨���� 
    f(xiao(10)); //�������������һ��ת��ֱ�ӵõ�xiao�ı��� 
}
              
