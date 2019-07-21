//#include <iostream>
//using namespace std;
//
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *first;
//void init()
//{
//	first = NULL;
//}
//void Process_list()
//{
//	Node *p;
//	p = first;
//	while (p != NULL)
//	{
//		cout << p->link << "\t";
//		p = p->link;
//	}
//	cout << endl;
//}
//Node *Search(int x)
//{
//	Node *p = first;
//	while (p != NULL && p->info != x)
//	{
//		p = p->link;
//	}
//	return p;
//}
//void insert_first(int x)
//{
//	Node *p;
//	p = new Node;
//	p->info = x;
//	p->link = first;
//	first = p;
//}
//int delete_first()
//{
//	if (first != NULL)
//	{
//		Node *p = first;
//		first = first->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void insert_last(int x)
//{
//	Node *p;
//	p = new Node;
//	p->info = x;
//	p->link = NULL;
//	if (first == NULL)
//	{
//		first = p;
//	}
//	else
//	{
//		Node *q = first;
//		while (q->link != NULL)
//		{
//			q = q->link;
//		}
//		q->link = p;
//	}
//}
//int delete_last()
//{
//	if (first != NULL)
//	{
//		Node *p, *q;
//		p = first;
//		q = first;
//		while (p->link != NULL)
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p != first)
//		{
//			q->link = NULL;
//		}
//		else
//			first = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int search_delete(int x)
//{
//	if (first != NULL)
//	{
//		Node *p, *q;
//		p = first;
//		q = first;
//		while (p->info != x && p->link != NULL)
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p != first && p->link != NULL)
//		{
//			if (p->link != NULL)
//				q->link = p->link;
//			else
//				q->link = NULL;
//			delete p;
//			return 1;
//		}
//		else if (p->link == NULL && p->info == x)
//		{
//			q->link = NULL;
//			delete p;
//			return 1;
//		}
//		else if (p == first)
//		{
//			first = p->link;
//			delete p;
//			return 1;
//		}
//	}
//	else
//		return 0;
//}
//int main()
//{
//	int choice = 0;
//	int x, i;
//	Node *p;
//	system("cls");
//	cout << "---  Bai Tap 3, Chuong 2, Danh Sach Lien Ket  ---" << endl;
//	cout << "1. Khoi tao DSLKD rong" << endl;
//	cout << "2. Them phan tu vao dau" << endl;
//	cout << "3. Them phan tu vao cuoi" << endl;
//	cout << "4. Xoa phan tu vao dau" << endl;
//	cout << "5. Xoa phan tu cuoi" << endl;
//	cout << "6. Xuat DSLK Don" << endl;
//	cout << "7. Tim mot phan tu gia tri x" << endl;
//	cout << "8. Tim phan tu x va xoa neu co" << endl;
//	cout << "9. Thoat" << endl;
//	do
//	{
//		cout << "Vui long chon so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			init();
//			cout << "Ban vua nhap danh sach thanh cong\n";
//			break;
//		case 2:
//			cout << "Vui long nhap so x : \n";
//			cin >> x;
//			insert_first(x);
//			cout << "Danh sach sau khi them la: ";
//			Process_list();
//		case 3:
//			cout << "Vui long nhap x can them vao cuoi danh sach: ";
//			cin >> x;
//			insert_last();
//			cout << "Danh sach sau khi them la: ";
//			Process_list();
//			break;
//		case 4:
//			i = delete_first();
//			if (i == 0)
//				cout << "Danh sach rong khong the xoa!" << x << endl;
//			else
//			{
//				cout << "Xoa thanh cong!" << endl;
//				cout << "Danh sach sau khi xoa la: ";
//				Process_list();
//			}
//			break;
//		case 5:
//			i = delete_last();
//			if (i == 0)
//				cout << "Danh sach rong khong the xoa!" << x << endl;
//			else
//			{
//				cout << "Xoa thanh cong!" << x << endl;
//				cout << "Danh sach sau khi xoa la: ";
//				Process_list();
//			}
//			break;
//		case 6:
//			cout << "Danh sach hien tai la: ";
//			Process_list();
//			break;
//		case 7:
//			cout << "Vui long nhap gia tri x can tim: ";
//			cin >> x;
//			p = Search(x);
//			if (p != NULL)
//				cout << "Tim thay x=" << x << endl;
//			else
//				cout << "khong tim thay!" << endl;
//			break;
//		case 8:
//			cout << "Vui long nhap so x can tim: \n";
//			cin >> x;
//			i = search_delete(x);
//			if (i = = 1)
//			{
//				cout << " tim thay phan tu x=" << x << " va da xoa thanh cong" << endl;
//				cout << "Danh sach da xoa la: ";
//				Process_list();
//
//			}
//			else
//				cout << "khong tim thay!" << endl;
//			break;
//		case 9:
//			cout << "\nGoodbye!\n";
//			break;
//		default:
//			break;
//		}
//	} while (choice != 9);
//	system("pause");
//	return 0;
//}