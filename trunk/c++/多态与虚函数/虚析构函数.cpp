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

              virtual ~ stu() =0                     //���鹹���������ҳ��ѳ������������������Ϊ�����
             {     cout<<"����stu����"<<endl; }            
};

class gstu:public stu              
{
      public:
             stu & fn()             //ʵ�ֶ�̬���麯���ķ���ֵҲ����һ����������벻��Ϊ�麯�������ǵ��麯�����ֱ𷵻��Լ����͵�ָ��������õ�ʱ������в�ͬ�в�ͬ���������ͣ��ȸ��Ե�ָ����� ���� 
             {
                  cout<<"gstu"<<endl;      //��vc�з���ֵ����һ��
                  return * this;
             }
			 ~ gstu()
			 {
				 cout<<"����gstu����"<<endl;
			 }
             
}; 

int main()
{

    gstu n;
    stu & k=n;
            //ʵ�ֶ�ֻ̬���ǻ����ָ��������ã��������ǻ���Ķ��󣬻���ʹ�ó����࣬�����಻���Զ�����󣬵��ǿ��Զ���ָ������� 

    n.fn();


    system("pause");
    
    
}
 
