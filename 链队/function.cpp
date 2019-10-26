#include "LinkQueue.h"

//初始化链队函数
void LinkQueue::initStart()
{
	cout<<"执行链队初始化功能"<<endl;
	Q.front=Q.rear=new queueNode;
	Q.front->next=NULL;
}

//链队单数据入队函数
void LinkQueue::pushData(int e)
{
	cout<<"执行链队单数据入队功能"<<endl;
	queueNode* p=new queueNode;
	p->data=e;
	p->next=NULL;
	Q.rear->next=p;
	Q.rear=p;
}

//链队单数据出队函数
int LinkQueue::popData()
{
	cout<<"执行链队单数据出队功能"<<endl;
	if(Q.front==Q.rear)
	{
		cerr<<"链队空\n";
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

//链队多数据顺序入队函数
void LinkQueue::pushLotdata(int num)
{
	cout<<"执行链队多数据顺序入队功能"<<endl;
	initStart();
	int i;
	queueNode* p;
	for(i=0;i<num;i++)
	{
		p=new queueNode;
		printf_s("请输入第%d个入队数据:",i+1);
		scanf_s("%d",&p->data);
		p->next=NULL;
		Q.rear->next=p;
		Q.rear=p;
	}
}

//链队总数据顺序出队函数
void LinkQueue::popLotdata()
{
	cout<<"执行链队总数据顺序出队功能"<<endl;
	if(Q.front==Q.rear)
	{
		cerr<<"链队空\n";
		Sleep(1000);
		exit(2);
	}
	queueNode* p;
	int i=0;
	while(Q.front!=Q.rear)
	{
		i++;
		p=Q.front->next;
		printf_s("第%d个出队数据:%d\n",i,p->data);
		if(Q.rear==p)
		{
			Q.rear=Q.front;
		}
		Q.front->next=p->next;
		delete p;
	}
}

//链队数据存储至文本文件函数
void LinkQueue::storeDatatofile()const
{
	cout<<"执行链队数据存储至文本文件功能"<<endl;
	if(Q.front==Q.rear)
	{
		cerr<<"链队空\n";
		Sleep(1000);
		exit(3);
	}
	ofstream outfile;
	outfile.open("Data.txt",ios::out);
	if(!outfile)
	{
		cerr<<"文件打开失败\n";
		Sleep(1000);
		exit(4);
	}
	int i=0;
	queueNode* p=Q.front->next;
	while(p)
	{
		i++;
		outfile<<"第"<<i<<"个入队数据:"<<p->data<<endl;
		p=p->next;
	}
	outfile.close();
}

//从文本文件导入数据创建链队函数
void LinkQueue::getDatafromfile()
{
	cout<<"执行从文本文件导入数据创建链队功能"<<endl;
	initStart();
	ifstream infile;
	infile.open("Data.txt",ios::in);
	if(!infile)
	{
		cerr<<"文件打开失败\n";
		Sleep(1000);
		exit(5);
	}
	char Array[MAX];
	int i,data;
	queueNode* p=NULL;
	while(infile.peek()!=EOF)
	{
		infile.getline(Array,sizeof(Array));
		sscanf(Array,"第%d个入队数据:%d\n",&i,&data);
		p=new queueNode;
		p->data=data;
		Q.rear->next=p;
		Q.rear=p;
	}
}

//链队取队头数据函数
int LinkQueue::getToplinkqueue()const
{
	cout<<"执行链队取队头数据功能"<<endl;
	if(Q.rear==Q.front)
	{
		cerr<<"链队空\n";
		Sleep(1000);
		exit(6);
	}
	return Q.front->next->data;
}

//链队功能打印输出函数
void LinkQueue::displayFunction()
{
	string str(30,'*');
	cout<<str<<endl;
	cout<<"    链队功能菜单    "<<endl;
	char* p[]={"0-链队初始化功能","1-链队单数据入队功能","2-链队单数据出队功能",
		"3-链队多数据顺序入队功能","4-链队总数据顺序出队功能",
		"5-链队取队头数据功能","6-链队数据存储至文本文件功能","7-从文本文件导入数据创建链队功能"};
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
			cerr<<"输入的key值不合理\n";
			cin.clear();
			cin.sync();
		}
		else
			break;
		cout<<"重新输入key:";
	}while(true);
}



		




