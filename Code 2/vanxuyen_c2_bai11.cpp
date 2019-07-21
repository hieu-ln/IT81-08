//#include <iostream>
//#include <stdio.h>
//using namespace std;
//
////cau 11.1
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *front, *rear;
//
////cau 11.2
//void init()
//{
//	front = NULL;
//	rear = NULL;
//}
//
////Kiem tra queue rong
//int isEmpty()
//{
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//
//
////cau 11.4
//void push(int x)
//{
//	Node *p = new Node;
//	p->info = x;
//	p->link = NULL;
//	if (rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//
////cau11.5
//int pop(int &x)
//{
//	if (front != NULL)
//	{
//		Node *p = front;
//		front = p->link;
//		x = p->info;
//		if (front == NULL)
//		{
//			rear = NULL;
//		}
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
////xuat queue
//void process_queue()
//{
//	if (front != NULL)
//	{
//		Node *p = front;
//		cout << "<--  ";
//		do
//		{
//			cout << p->info <<"  ";
//			p = p->link;
//		} while (p != NULL);
//		cout << "<--" << endl;
//	}
//}
//
//int main()
//{
//	int choice, x, i;
//	cout << "Bai tap 11----chuong 2-----Stack" << endl;
//	cout << "1. Khoi tao queue rong" << endl;
//	cout << "2. Theem phan tu vao queue\n";
//	cout << "3. Lay phan tu ra khoi queue\n";
//	cout << "4. Kiem tra queue co rong hay khong\n";
//	cout << "5. Xuat queue\n";
//	cout << "6. Thoat\n";
//	do
//	{
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			init();
//			cout << "Ban vua khoi tao queue thanh cong!\n";
//			break;
//		case 2:
//			cout << "Vui long nhap gia tri x: ";
//			cin >> x;
//			push(x);
//			cout << "Queue sau khi them la: ";
//			process_queue();
//			break;
//		case 3:
//			pop(x);
//			cout << "Phan tu lay ra tu queue la x= " << x << endl;
//			cout << "Queue sau khi lay ra la: ";
//			process_queue();
//			break;
//		case 4:
//			i = isEmpty();
//			if (i == 0)
//				cout << "Queue khong rong!" << x << endl;
//			else
//				cout << "Queue rong!" << endl;
//			break;
//		case 5:
//			cout << "Queue hien tai la: ";
//			process_queue();
//			break;
//		case 6:
//			cout << "Goodbye"<< endl;
//			break;
//		default:
//			break;
//		}
//	} while (choice != 6);
//	system("pause");
//	return 0;
//}