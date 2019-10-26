#include "LinkQueue.h"

int main()
{
	LinkQueue T;
	bool key;
	int function;
	int num;
	int e;
	do
	{
		T.displayFunction();
		cout<<"请输入要执行的功能编号function:";
		cin>>function;
		switch(function)
		{
		case 0:
			T.initStart();break;
		case 1:
			cout<<"请输入入链队单数据e:";
			cin>>e;
			T.pushData(e);break;
		case 2:
			printf_s("单数据出链队数据:%d\n",T.popData());break;
		case 3:
			cout<<"请输入入链队数据总数num:";
			cin>>num;
			T.pushLotdata(num);break;
		case 4:
			T.popLotdata();break;
		case 5:
			printf("链队队头数据:%d\n",T.getToplinkqueue());break;
		case 6:
			T.storeDatatofile();break;
		case 7:
			T.getDatafromfile();break;
		default:
			cout<<"输入的功能编号function不合理"<<endl;
		}
		cout<<"是否执行其他功能? 1-继续 0-退出:";
		T.inputJudge(key);
		system("cls");
	}while(key);

	system("pause");
	return 0;
}