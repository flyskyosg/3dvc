#include<iostream>

using namespace std;

class stu
{
      public:
             virtual stu & fn()
             {
                 cout<<"stu"<<endl;
                 return *this;
             }

            // virtual ~             
};

class gstu:public stu              
{
      public:
             gstu & fn()             //ʵ�ֶ�̬���麯���ķ���ֵҲ����һ����������벻��Ϊ�麯�������ǵ��麯�����ֱ𷵻��Լ����͵�ָ��������õ�ʱ������в�ͬ�в�ͬ���������ͣ��ȸ��Ե�ָ����� ���� 
             {
                  cout<<"gstu"<<endl;
                  return * this;
             }
             
}; 

int main()
{
    stu  m;
    gstu n;
    stu & k=n;
    stu o=n;           //ʵ�ֶ�ֻ̬���ǻ����ָ��������ã��������ǻ���Ķ��󣬻���ʹ�ó����࣬�����಻���Զ�����󣬵��ǿ��Զ���ָ������� 
    o.fn();
    n.fn();
    stu * l=& m;
    l->fn();
    system("pause");
    
    
}
 
