//#include <iostream>
//using namespace std;
//
////Cau 10.1
//struct Node {
//	int info;
//	Node *link;
//};
//Node *sp;
//
////Cau 10.2
//void init()
//{
//	sp = NULL;
//}
//
////Cau 10.3
//int isEmpty()
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//
////Cau 10.4
//void Push(int x)
//{
//	Node *p = new Node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//
////Cau 10.5
//int Pop(int &x)
//{
//	if (sp != NULL)
//	{
//		Node *p;
//		p = sp;
//		x = p->info;
//		sp = sp->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
////Xuat Stack
//void Process_stack()
//{
//	Node *p = sp;
//	while (p != NULL)
//	{
//		cout << p->info << "     ";
//		p = p->link;
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int x, choice=0, i;
//
//	cout << "---Bai 10, Chuong 2, STACK (NGAN XEP - DS LIEN KET DON)---" << endl
//				<< "1. Khoi tao Stack rong" << endl
//				<< "2. Them phan tu vao Stack" << endl
//				<< "3. Lay phan tu ra khoi Stack" << endl
//				<< "4. Kiem tra Stack co rong hay khong" << endl
//				<< "5. Xuat Stack" << endl
//				<< "6. Thoat" << endl;
//
//	do {
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			init();
//			cout << "Khoi tao Stack rong thanh cong!";
//			break;
//		case 2:
//			cout << "Vui long nhap gia tri x=";
//			cin >> x;
//			Push(x);
//			cout << "\nDanh sach hien tai: ";
//			Process_stack();
//			break;
//		case 3:
//			i = Pop(x);
//			if (i == 1)
//			{
//				cout << "Phan tu lay ra tu Stack x=" << x;
//				cout << "\nDanh sach hien tai: ";
//				Process_stack();
//			}
//			else
//				cout << "Stack rong!";
//			break;
//		case 4:
//			i = isEmpty();
//			if (i == 1)
//				cout << "Stack rong!";
//			else
//				cout << "Stack khong rong!";
//			break;
//		case 5:
//			cout << "Danh sach hien tai: ";
//			Process_stack();
//			break;
//		case 6:
//			cout << "Goobye!";
//			break;
//		default:
//			break;
//		}
//	} while (choice != 6);
//
//	cout << endl;
//	system("pause");
//	return 0;
//}