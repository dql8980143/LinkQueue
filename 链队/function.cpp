#include "LinkQueue.h"

//��ʼ�����Ӻ���
void LinkQueue::initStart()
{
	cout<<"ִ�����ӳ�ʼ������"<<endl;
	Q.front=Q.rear=new queueNode;
	Q.front->next=NULL;
}

//���ӵ�������Ӻ���
void LinkQueue::pushData(int e)
{
	cout<<"ִ�����ӵ�������ӹ���"<<endl;
	queueNode* p=new queueNode;
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}

//���ӵ����ݳ��Ӻ���
int LinkQueue::popData()
{
	cout<<"ִ�����ӵ����ݳ��ӹ���"<<endl;
	if(Q.front==Q.rear)
	{
		cerr<<"���ӿ�\n";
		Sleep(1000);
		exit(1);
	}
	queueNode* p=Q.front->next;
	int e=p->data;
	if(Q.rear==p)
	{
		Q.rear=Q.front;
	}
	Q.front->next=p->next;
	delete p;
	return e;
}

//���Ӷ�����˳����Ӻ���
void LinkQueue::pushLotdata(int num)
{
	cout<<"ִ�����Ӷ�����˳����ӹ���"<<endl;
	initStart();
	int i;
	queueNode* p;
	for(i=0;i<num;i++)
	{
		p=new queueNode;
		printf_s("�������%d���������:",i+1);
		scanf_s("%d",&p->data);
		p->next=NULL;
		Q.rear->next=p;
		Q.rear=p;
	}
}

//����������˳����Ӻ���
void LinkQueue::popLotdata()
{
	cout<<"ִ������������˳����ӹ���"<<endl;
	if(Q.front==Q.rear)
	{
		cerr<<"���ӿ�\n";
		Sleep(1000);
		exit(2);
	}
	queueNode* p;
	int i=0;
	while(Q.front!=Q.rear)
	{
		i++;
		p=Q.front->next;
		printf_s("��%d����������:%d\n",i,p->data);
		if(Q.rear==p)
		{
			Q.rear=Q.front;
		}
		Q.front->next=p->next;
		delete p;
	}
}

//�������ݴ洢���ı��ļ�����
void LinkQueue::storeDatatofile()const
{
	cout<<"ִ���������ݴ洢���ı��ļ�����"<<endl;
	if(Q.front==Q.rear)
	{
		cerr<<"���ӿ�\n";
		Sleep(1000);
		exit(3);
	}
	ofstream outfile;
	outfile.open("Data.txt",ios::out);
	if(!outfile)
	{
		cerr<<"�ļ���ʧ��\n";
		Sleep(1000);
		exit(4);
	}
	int i=0;
	queueNode* p=Q.front->next;
	while(p)
	{
		i++;
		outfile<<"��"<<i<<"���������:"<<p->data<<endl;
		p=p->next;
	}
	outfile.close();
}

//���ı��ļ��������ݴ������Ӻ���
void LinkQueue::getDatafromfile()
{
	cout<<"ִ�д��ı��ļ��������ݴ������ӹ���"<<endl;
	initStart();
	ifstream infile;
	infile.open("Data.txt",ios::in);
	if(!infile)
	{
		cerr<<"�ļ���ʧ��\n";
		Sleep(1000);
		exit(5);
	}
	char Array[MAX];
	int i,data;
	queueNode* p=NULL;
	while(infile.peek()!=EOF)
	{
		infile.getline(Array,sizeof(Array));
		sscanf(Array,"��%d���������:%d\n",&i,&data);
		p=new queueNode;
		p->data=data;
		Q.rear->next=p;
		Q.rear=p;
	}
}

//����ȡ��ͷ���ݺ���
int LinkQueue::getToplinkqueue()const
{
	cout<<"ִ������ȡ��ͷ���ݹ���"<<endl;
	if(Q.rear==Q.front)
	{
		cerr<<"���ӿ�\n";
		Sleep(1000);
		exit(6);
	}
	return Q.front->next->data;
}

//���ӹ��ܴ�ӡ�������
void LinkQueue::displayFunction()
{
	string str(30,'*');
	cout<<str<<endl;
	cout<<"    ���ӹ��ܲ˵�    "<<endl;
	char* p[]={"0-���ӳ�ʼ������","1-���ӵ�������ӹ���","2-���ӵ����ݳ��ӹ���",
		"3-���Ӷ�����˳����ӹ���","4-����������˳����ӹ���",
		"5-����ȡ��ͷ���ݹ���","6-�������ݴ洢���ı��ļ�����","7-���ı��ļ��������ݴ������ӹ���"};
	int i;
	int count=sizeof(p)/sizeof(char*);
	for(i=0;i<count;i++)
	{
		cout<<p[i]<<endl;
	}
	cout<<str<<endl;
}

void LinkQueue::inputJudge(bool& key)
{
	do
	{
		cin>>key;
		if(cin.fail())
		{
			cerr<<"�����keyֵ������\n";
			cin.clear();
			cin.sync();
		}
		else
			break;
		cout<<"��������key:";
	}while(true);
}



		




