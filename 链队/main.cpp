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
		cout<<"������Ҫִ�еĹ��ܱ��function:";
		cin>>function;
		switch(function)
		{
		case 0:
			T.initStart();break;
		case 1:
			cout<<"�����������ӵ�����e:";
			cin>>e;
			T.pushData(e);break;
		case 2:
			printf_s("�����ݳ���������:%d\n",T.popData());break;
		case 3:
			cout<<"��������������������num:";
			cin>>num;
			T.pushLotdata(num);break;
		case 4:
			T.popLotdata();break;
		case 5:
			printf("���Ӷ�ͷ����:%d\n",T.getToplinkqueue());break;
		case 6:
			T.storeDatatofile();break;
		case 7:
			T.getDatafromfile();break;
		default:
			cout<<"����Ĺ��ܱ��function������"<<endl;
		}
		cout<<"�Ƿ�ִ����������? 1-���� 0-�˳�:";
		T.inputJudge(key);
		system("cls");
	}while(key);

	system("pause");
	return 0;
}