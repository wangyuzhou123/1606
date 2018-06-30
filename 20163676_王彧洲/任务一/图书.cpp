#include <iostream> 
#include <iomanip> 
#include <string> 
#include <fstream>
#include "tou.h"
//main() ������ʵ�֣����������������� 
void main()
{
	char choice;
	int bookid, readerid;
	RDatabase ReaderDB;
	Reader *r;
	BDatabase BookDB;
	Book *b;
	while (choice != '0')
	{
		cout << endl << endl << "\t\t\t ͼ �� �� �� ϵ ͳ\n\n\n";
		cout << "\t\t\t1 �� ��\n\n\t\t\t2 �� �� \n\n\t\t\t3 ͼ �� ά ��\n\n\t\t\t4 �� �� ά ��\n\n\t\t\t0 �� ��" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << " ���� ���߱��:";
			cin >> readerid;
			cout << " ͼ���ţ� ";
			cin >> bookid;
			r = ReaderDB.query(readerid);//����Ų��� 
			if (NULL == r)
			{
				cout << " �����ڸö��ߣ����ܽ���" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << " �����ڸ�ͼ�飬���ܽ���" << endl;
				break;
			}
			if (b->borrowbook() == 0)
			{
				cout << " ��ͼ���ѽ�������ܽ���" << endl;
				break;
			}
			r->borrowbook(b->getno());
			break;
		case '2':
			cout << "����\n ���߱��:";
			cin >> readerid;
			cout << " ͼ����:";
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << " �����ڸö��ߣ����ܻ���" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << " �����ڸ�ͼ�飬���ܻ���" << endl;
				break;
			}
			b->retbook();
			r->retbook(b->getno());
			break;
		case '3':
			BookDB.bookdata();
			break;
		case '4':
			ReaderDB.readerdata();
			break;
		default:cout << "���������������룺";
		}
	}
}