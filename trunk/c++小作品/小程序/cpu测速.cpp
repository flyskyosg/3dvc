
#include "time.h" 
#include "iostream.h" 
#include<stdio.h>
void main()
{  

	time_t begin,end;
begin = clock ();
for(int i=0;i<10000000;i++) 
end = clock ();
cout<<"����CPU�ٶ�Ϊ:"<<(end - begin )/18.2<<"\n\a";

cout<<"^_^ллʹ��^_^"<<endl;
cout<<"   ����:СС"<<endl;
cout<<"��������˳�"<<endl;
getchar();
}