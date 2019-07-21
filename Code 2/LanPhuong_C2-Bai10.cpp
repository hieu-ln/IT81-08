//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
////cau 10.1
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *sp;
//
////cau 10.2
//void init()
//{
//	sp = NULL;
//}
//
////cau 10.3
//int isEmpty()
//{
//	if (sp == NULL)
//		return 1;
//	return 0;
//}
//
////cau 10.4
//void push(int x)
//{
//	Node *p = new Node;
//	p->info = x;
//	p->link = sp;
//	sp = p;
//}
//
////cau 10.5
//int pop(int &x)
//{
//	if (sp != NULL)
//	{
//		Node *p = sp;
//		x = p->info;
//		sp = p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
////xuat stack
//void process_satck()
//{
//	Node *p = sp;
//	do
//	{
//		cout << p->info << " ";
//		p = p->link;
//	} while (p != NULL);
//	cout << endl;
//}
//
//int main()
//{
//	int choice,x, i;
//	cout << "Bai tap 10---chuong 2-----Stack" << endl;
//	cout << "1. Khoi tao stack rong" << endl;
//	cout << "2. Theem phan tu vao stack\n";
//	cout << "3. Lay phan tu ra khoi stack\n";
//	cout << "4. Xuat stack\n";
//	cout << "5. Thoat\n";
//	do
//	{
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			init();
//			cout << "Ban vua khoi tao stack thanh cong!\n";
//			break;
//		case 2:
//			cout << "Vui long nhap gia tri x: ";
//			cin >> x;
//			push(x);
//			cout << "Stack sau khi them la: ";
//			process_satck();
//			break;
//		case 3:
//			pop(x);
//			cout << "Phan tu lay ra tu stack la x= " << x << endl;
//			cout << "Stack sau khi lay ra la: ";
//			process_satck();
//		case 4:
//			cout << "Stack hien tai la: ";
//			process_satck();
//			break;
//		case 5:
//			cout << "Goddbye!" << endl;
//			break;
//		default:
//			break;
//		}
//	} while (choice != 5);
//	system("pause");
//	return 0;
//}
//
