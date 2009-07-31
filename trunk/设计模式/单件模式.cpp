///单件模式
#include<iostream>
#include<string>
using namespace std;

class SceneMgr
{
	static SceneMgr * mSceneMgr;
	SceneMgr(){}
public:
	static SceneMgr * getSceneMgr()
	{
		return new SceneMgr;
	}

	void createNode()
	{
		cout << "create node success " << endl;
	}
};

int main()
{
	SceneMgr * pSceneMgr = SceneMgr::getSceneMgr();
	pSceneMgr->createNode();
	getchar();
}
