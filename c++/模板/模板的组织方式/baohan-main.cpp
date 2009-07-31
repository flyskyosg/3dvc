#include"template.h"    //模板的包含组织方式，还有模板的分离组织方式，
//不过现在的编译器都没有实现
   
                        
 
int main()
{
	//char const * a="aaaa";
	//char const * b="bbbb";
	//cout<<max(a,b);
	//cout<<max(10.0,100.0);
	
	int a=10;
	xiao<int> m;
	m.disp(a);
	xiao<double> n;
	n.disp(a);
	
	
	
	system("pause");
	return 0;
}
