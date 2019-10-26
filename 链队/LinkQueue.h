#include <iostream>
#include <Windows.h>
#include <fstream>
#include <string>
#define MAX 100
using namespace std;

struct queueNode
{
	int data;
	struct queueNode* next;
};

typedef struct linkqueue
{
	queueNode* front;
	queueNode* rear;
};

class LinkQueue
{
private:
	linkqueue Q;
public:
	void initStart();//初始化链队函数

	void pushData(int e);//链队单数据入队函数

	int popData();//链队单数据出队函数

	void pushLotdata(int num);//链队多数据顺序入队函数

	void popLotdata();//链队总数据顺序出队函数

	void storeDatatofile()const;//链队数据存储至文本文件函数

	void getDatafromfile();//从文本文件导入数据创建链队函数

	void displayFunction();//链队功能打印输出函数

	int getToplinkqueue()const;//链队取队头数据函数

	void inputJudge(bool& key);//输入判断函数

};