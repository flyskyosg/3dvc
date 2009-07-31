#include<iostream>                                //模板的多态--静多态

using namespace std;




template <typename T>
void open(T & n)
{
	n.disp();
	n.disp1();
}

class stu                                         //抽象类 ，作为接口使用 
{

      public:
             virtual stu * fn()
             {
                 cout<<"stu"<<endl;
                 return this;
             }

              virtual ~ stu()                    //虚析构函数，并且长把抽象类的析构函数声明为纯虚的
             {
				  cout<<"调用stu析构"<<endl;
			  }    
			  

			  virtual void  disp()=0;
			  virtual void  disp1()=0; 
			 


};

class gstu: public  stu              
{
      public:
             stu * fn()                         //实现多态的虚函数的返回值也必须一样，否则编译不视为虚函数，但是当虚函数都分别返回自己类型的指针的时候可以有不同有不同的数据类型，既各自的指针或者 引用 
             {
                  cout<<"gstu"<<endl;           //在vc中返回值必须一样
                  return  this;
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


class ggstu: virtual public stu
{
      public:
            void disp1()                     //这里实现了disp1纯虚函数 ，不再存在没有被实现的纯虚函数，所以ggstu不是抽象类，而gstu则是抽象类  
             {
                  cout<<"ggstu"<<endl;
              }
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
            /* void disp()
			 {
				 cout<<"gggstu"<<endl;
 			 
			 }*/
};



int main()
{
    //stu k;  抽象类不能定义变量，只能定义引用以及指针 
    //ggstu n;   //ggstu和gggstu都是gstu的子类，同时他们也都是stu的间接子类，这里因为gstu从stu里边继承了一个纯虚函数，所以gstu也是抽象类，
               //而ggstu和gggstu类中都把 这两个纯虚函数实现了， 
    gggstu n1;
    //gstu m;
    stu & l=n1;
    stu * m=& n1;
    //gstu * o=& n1;
      //n1.disp();
      //n1.disp1();
      l.disp1();   
      l.disp();
	  m->disp1();
	  (*m).disp();         //对抽象类的在指针做间防操作时，返回的是捆绑在该接口上的基类的对象，而接口的引用就代表捆绑的对象

     /* gstu u;
	  stu * q=& u;
      gstu * p=dynamic_cast<gstu *>(q);          //这里使用动态转换会产生二义性
	  p->disp();
	  p->disp1(); */
	
       

    // o->disp();
    // o->disp();


    // gggstu p;
    // stu & q=p;
    // q.disp(); 
    // p.disp();        //gggstu中没有实现disp函数，但是从他的父类中继承了这个函数，然而在他的父类的父类中也实现了这个函数，这个时候系统依然选择里他最近的父类的函数 
                        //不管使用接口调用还是用该类的对象调用这个函数 
  
    open(n1); //使用模板函数实现静多态，因为模板函数可以处理任意的数据类型，包括自定义数据类型，所以只要open函数中有和自定义类型同名的函数，就可以实现静多台，静多态是在编译期就实现的，而动多态是在连接期实现的


    system("pause");


    return 0;
 
    
}
 
