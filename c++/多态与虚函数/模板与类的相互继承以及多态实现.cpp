#include<iostream>
using namespace std;

//��ģ��������ģ��

  template<   typename   T   >   
  class   A   
  {   
  public:   
  virtual   void   B()   =   0;       //���麯��ʵ�ֶ�̬
  };   
    
  
  template<   typename   T   >   
  class   C   :   public   A<   T   >    
  {   
  public:   
  void   B()   
  { 
	cout<<"c"<<endl;  
  }   
  }; 
  

  template<   typename   T   >   
  class   D   :   public C <T>   
  {   
  public:   
  void   B()   
  { 
	  cout<<"d"<<endl;
  }   
  };   
    
   
  //����ͨ������ģ��

  class   AA   
  {   
  public:   
  virtual   void   B()   =   0;       //���麯��--ʵ�ֶ�̬
  };   
  
  class   DD   :   public   AA  
  {   
  public:   
  void   B()   
  { 
	  cout<<"dd"<<endl;
  }   
  }; 
  
  class   EE   :   public   AA  
  {   
  public:   
  void   B()   
  { 
	  cout<<"ee"<<endl;
  }   
  };   
  
  
  //��ģ��������ͨ��

  class E :public A<int>
  {
  public:
	  void B()
	  {
		  cout<<"e"<<endl;
	  }

  };
  
  class F:public E
  {
  public:
	  void B()
	  {
		  cout<<"F"<<endl;
	  }
  };


//������
  
  int   main()   
  {   
  C<   int   >   c;   
  D<   int   >   d;   
  
  cout<<"��ģ��������ģ��"<<endl;
  A<int> & a=c;A<int> * p=& d;
  c.B();p->B();
  
  
  cout<<"����ͨ��������ģ��"<<endl;
  DD dd;EE ee;
  AA & b=dd;
  AA * t=& ee;
  b.B();
  t->B();


  cout<<"��ģ��������ͨ��"<<endl;
  E e;F f;
  A<int> & q=e;
  q.B();
  A<int> * o=& f;
  o->B();


  system("pause");
  
    
  return   0;   
  }   