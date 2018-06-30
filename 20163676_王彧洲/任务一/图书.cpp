#include <iostream> 
#include <iomanip> 
#include <string> 
#include <fstream>
#include "tou.h"
//main() 函数的实现，程序的主界面的引导 
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
		cout << endl << endl << "\t\t\t 图 书 管 理 系 统\n\n\n";
		cout << "\t\t\t1 借 书\n\n\t\t\t2 还 书 \n\n\t\t\t3 图 书 维 护\n\n\t\t\t4 读 者 维 护\n\n\t\t\t0 离 开" << endl;
		cin >> choice;
		switch (choice)
		{
		case '1':
			cout << " 借书 读者编号:";
			cin >> readerid;
			cout << " 图书编号： ";
			cin >> bookid;
			r = ReaderDB.query(readerid);//按编号查找 
			if (NULL == r)
			{
				cout << " 不存在该读者，不能借书" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << " 不存在该图书，不能借书" << endl;
				break;
			}
			if (b->borrowbook() == 0)
			{
				cout << " 该图书已借出，不能借书" << endl;
				break;
			}
			r->borrowbook(b->getno());
			break;
		case '2':
			cout << "还书\n 读者编号:";
			cin >> readerid;
			cout << " 图书编号:";
			cin >> bookid;
			r = ReaderDB.query(readerid);
			if (r == NULL)
			{
				cout << " 不存在该读者，不能还书" << endl;
				break;
			}
			b = BookDB.query(bookid);
			if (b == NULL)
			{
				cout << " 不存在该图书，不能还书" << endl;
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
		default:cout << "输入错误，请从新输入：";
		}
	}
}