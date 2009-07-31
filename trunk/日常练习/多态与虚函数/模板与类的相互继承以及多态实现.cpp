#include<iostream>
using namespace std;

//从模板中派生模板

  template<   typename   T   >   
  class   A   
  {   
  public:   
  virtual   void   B()   =   0;       //纯虚函数实现多态
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
    
   
  //从普通类派生模板

  class   AA   
  {   
  public:   
  virtual   void   B()   =   0;       //纯虚函数--实现多态
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
  
  
  //从模板派生普通类

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


//主函数
  
  int   main()   
  {   
  C<   int   >   c;   
  D<   int   >   d;   
  
  cout<<"从模板中派生模板"<<endl;
  A<int> & a=c;A<int> * p=& d;
  c.B();p->B();
  
  
  cout<<"从普通类中派生模板"<<endl;
  DD dd;EE ee;
  AA & b=dd;
  AA * t=& ee;
  b.B();
  t->B();


  cout<<"从模板派生普通类"<<endl;
  E e;F f;
  A<int> & q=e;
  q.B();
  A<int> * o=& f;
  o->B();


  system("pause");
  
    
  return   0;   
  }   