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
	void initStart();//��ʼ�����Ӻ���

	void pushData(int e);//���ӵ�������Ӻ���

	int popData();//���ӵ����ݳ��Ӻ���

	void pushLotdata(int num);//���Ӷ�����˳����Ӻ���

	void popLotdata();//����������˳����Ӻ���

	void storeDatatofile()const;//�������ݴ洢���ı��ļ�����

	void getDatafromfile();//���ı��ļ��������ݴ������Ӻ���

	void displayFunction();//���ӹ��ܴ�ӡ�������

	int getToplinkqueue()const;//����ȡ��ͷ���ݺ���

	void inputJudge(bool& key);//�����жϺ���

};