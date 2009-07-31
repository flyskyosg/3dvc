#include<iostream> //命令行传递文件信息   注：在命令行中输入如下内容：重定向 xxx.txt yyy.txt 这样就把xxx.txt 中的所有信息拷贝进了yyy.txt
#include<fstream>
using namespace std;

int  main(int argc,char ** argv)           //输入时只需要传入字符串，第一项参数不需要传入，系统自动传入
{
	
	ifstream inf(argv[1]);                   //这里的下表是1和2是因为第一个字符串是程序名，而且argc的个数包含了程序名字符串
	ofstream ouf(argv[2]);
	if(inf&&ouf) ouf<<inf.rdbuf();            //该函数从输入流缓冲区中读取字符
}