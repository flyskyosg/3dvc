#include"namespace.h"

namespace stack        //���ƿռ���Էֿ�������ֻҪ��������ƥ��Ϳ���
{
	int max[100];      //һ�������ƿռ��ʵ���ļ��ж����������ݳ�Ա�������ͷ�ļ��Ļ�������ظ�����
	int i=-1;

}

bool stack::push(char c)
{
	if(i>99) return 0;
	i++;                    //��ͬһ�����ƿռ��ж���ĺ����Լ����ݣ����ǹ�ϵ���������ж����һ���������ں�����ֱ�ӵ�������ʹ�ã����൱�����ƿռ��е�ȫ�����ݣ��������ǵĳ�ʼ���ǲ�ȷ����
	max[i]=c;
	return 1;
}

bool stack::pop()         //����һ�������ⲿ����ʱ��Ҫ���������
{
	if(i<0) return 0;

	max[i]=0;
	i--;
	return 1;
}
void stack::print()
{
		for(int i=0;i<2;i++	)
		{
			cout<<max[i]<<endl;
		}
}