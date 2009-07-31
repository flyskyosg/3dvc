#include<iostream>                                //多态在多层次继承中的应用 

using namespace std;

class stu                                         //抽象类 ，作为接口使用 
{

      public:
             virtual stu & fn()
             {
                 cout<<"stu"<<endl;
                 return *this;
             }

              virtual ~ stu()                    //虚析构函数，并且长把抽象类的析构函数声明为纯虚的
             {
				  cout<<"调用stu析构"<<endl;
			  }    
			  

			  virtual void  disp()=0;
			  virtual void  disp1()=0; 
			 


};

class gstu:public stu              
{
      public:
             stu & fn()                         //实现多态的虚函数的返回值也必须一样，否则编译不视为虚函数，但是当虚函数都分别返回自己类型的指针或者引用的时候可以有不同有不同的数据类型，既各自的指针或者 引用 
             {
                  cout<<"gstu"<<endl;           //在vc中返回值必须一样
                  return * this;
             }

             void disp()                        //这里实现了disp纯虚函数 ，但是继承了stu的disp1纯虚函数，所以他也是抽象类，也同样可以作为接口 ，工能和stu一样 
			 {                                  //而且在后边的子类中如果子类中没有实现其中的某个纯虚函数，而用该子类对象初始化的抽象类的接口对象 在调用 该纯虚函数的
                                                //的时候会优先调用离他最近的实现该纯虚函数的类的该函数，这个类可以是抽象类也可以不是抽象类  
				 cout<<"gstu"<<endl;
 			 
			 }
			 void disp1()            
              {
                   cout<<"gstu"<<endl;
              }




			 ~ gstu()
			 {
				 cout<<"调用gstu析构"<<endl;
			 }
             
}; 


class ggstu:public gstu
{
      public:
            /* void disp1()                     //这里实现了disp1纯虚函数 ，不再存在没有被实现的纯虚函数，所以ggstu不是抽象类，而gstu则是抽象类  
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
    //stu k;  抽象类不能定义变量，只能定义引用以及指针 
    //ggstu n;   //ggstu和gggstu都是gstu的子类，同时他们也都是stu的间接子类，这里因为gstu从stu里边继承了一个纯虚函数，所以gstu也是抽象类，
               //而ggstu和gggstu类中都把 这两个纯虚函数实现了， 
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
 
