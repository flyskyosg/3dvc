#include<iostream>                                //��̬�ڶ��μ̳��е�Ӧ�� 

using namespace std;

class stu                                         //������ ����Ϊ�ӿ�ʹ�� 
{

      public:
             virtual stu & fn()
             {
                 cout<<"stu"<<endl;
                 return *this;
             }

              virtual ~ stu()                    //���������������ҳ��ѳ������������������Ϊ�����
             {
				  cout<<"����stu����"<<endl;
			  }    
			  

			  virtual void  disp()=0;
			  virtual void  disp1()=0; 
			 


};

class gstu:public stu              
{
      public:
             stu & fn()                         //ʵ�ֶ�̬���麯���ķ���ֵҲ����һ����������벻��Ϊ�麯�������ǵ��麯�����ֱ𷵻��Լ����͵�ָ��������õ�ʱ������в�ͬ�в�ͬ���������ͣ��ȸ��Ե�ָ����� ���� 
             {
                  cout<<"gstu"<<endl;           //��vc�з���ֵ����һ��
                  return * this;
             }

             void disp()                        //����ʵ����disp���麯�� �����Ǽ̳���stu��disp1���麯����������Ҳ�ǳ����࣬Ҳͬ��������Ϊ�ӿ� �����ܺ�stuһ�� 
			 {                                  //�����ں�ߵ����������������û��ʵ�����е�ĳ�����麯�������ø���������ʼ���ĳ�����Ľӿڶ��� �ڵ��� �ô��麯����
                                                //��ʱ������ȵ������������ʵ�ָô��麯������ĸú��������������ǳ�����Ҳ���Բ��ǳ�����  
				 cout<<"gstu"<<endl;
 			 
			 }
			 void disp1()            
              {
                   cout<<"gstu"<<endl;
              }




			 ~ gstu()
			 {
				 cout<<"����gstu����"<<endl;
			 }
             
}; 


class ggstu:public gstu
{
      public:
            /* void disp1()                     //����ʵ����disp1���麯�� �����ٴ���û�б�ʵ�ֵĴ��麯��������ggstu���ǳ����࣬��gstu���ǳ�����  
             {
                  cout<<"ggstu"<<endl;
              }*/
              void disp()               
			 {
				 cout<<"ggstu"<<endl;
 			 
			 }
};

class gggstu:public ggstu
{
      public:
             void disp1()
             {
                  cout<<"gggstu"<<endl;
              }
            /*  void disp()
			 {
				 cout<<"gggstu"<<endl;
 			 
			 }*/
};



int main()
{
    //stu k;  �����಻�ܶ��������ֻ�ܶ��������Լ�ָ�� 
    //ggstu n;   //ggstu��gggstu����gstu�����࣬ͬʱ����Ҳ����stu�ļ�����࣬������Ϊgstu��stu��߼̳���һ�����麯��������gstuҲ�ǳ����࣬
               //��ggstu��gggstu���ж��� ���������麯��ʵ���ˣ� 
    ggstu n1;
    //gstu m;
    stu & l=n1;
    
    //gstu * o=& n1;
      n1.disp();
      n1.disp1();
      l.disp1();   
      l.disp();
    // o->disp();
    // o->disp();

// 

  
  
    


    system("pause");



 
    
}
 
