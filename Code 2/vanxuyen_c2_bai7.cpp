//#include <iostream>
//#include <stdio.h>
//using namespace std;
//#define MAX 100
//
////cau 7.2
//void init(int a[], int &front, int &rear)
//{
//	front = -1;
//	rear = -1;
//}
//
////cau 7.3:
//int isEmpty(int a[], int &front, int &rear)
//{
//	if (front == rear)
//		return 1;
//	else
//		return 0;
//}
//
////cau7.4
//int isFull(int a[], int &front, int &rear)
//{
//	if ((front == 0 && rear == MAX - 1) || (front - rear == 1))
//		return 1;
//	else
//		return 0;
//}
//
////cau 7.5
//int push(int a[], int &front, int &rear, int x)
//{
//	if (rear - front == MAX - 1)
//		return 0;
//	else
//	{
//		if (front == -1)
//			front = 0;
//		if (rear == MAX - 1)
//		{
//			for (int i = front; i <= rear; i++)
//			{
//				a[i - front] = a[i];
//			}
//			rear = MAX - 1 - front;
//			front = 0;
//		}
//		a[++rear] = x;
//		return 1;
//	}
//	return 0;
//}
//
////cau 7.6
//int pop(int a[], int &front, int &rear, int &x)
//{
//	if (front == -1)
//		return 0;
//	else
//	{
//		x = a[front++];
//		if (front > rear)
//		{
//			front = -1;
//			rear = -1;
//		}
//		return 1;
//	}
//	return 0;
//}
//
////Xuat queue
//void process_queue(int a[], int f, int r)
//{
//	cout << "f= " << f << "\t r= "<<r<<endl;
//	if (f <= r && f != -1)
//	{
//		cout << "<--  ";
//		for (int i = f; i < r + 1; i++)
//		{
//			cout << a[i] << " ";
//		}
//		cout << "<--" << endl;
//	}
//}
//
//int main()
//{
//	int a[MAX];
//	int choice, f, r, x, i;
//	cout << "Bai tap 7-----chuong 2-----Stack" << endl;
//	cout << "1. Khoi tao queue rong"<<endl;
//	cout << "2. Theem phan tu vao queue\n";
//	cout << "3. Lay phan tu ra khoi queue\n";
//	cout << "4. Kiem tra queue co rong hay khong\n";
//	cout << "5. Kiem tra queue co day hay khong\n";
//	cout << "6. Xuat queue\n";
//	cout << "7. Thoat\n";
//	do
//	{
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//			case 1:
//				init(a, f, r);
//				cout << "Ban vua khoi tao queue thanh cong!\n";
//				break;
//			case 2:
//				cout << "Vui long nhap gia tri x: ";
//				cin >> x;
//				i = push(a, f,r,x);
//				cout << "Queue sau khi them la: ";
//				process_queue(a, f,r);
//				break;
//			case 3:
//				i = pop(a, f,r,x);
//				cout << "Phan tu lay ra tu queue la x= " << x << endl;
//				cout << "Queue sau khi lay ra la: ";
//				process_queue(a, f, r);
//				break;
//			case 4:
//				i = isFull(a, f, r);
//				if (i == 0)
//					cout << "Queue chua day!" << x << endl;
//				else
//					cout << "Queue da day!" << endl;
//				break;
//			case 5:
//				i = isEmpty(a, );
//				if (i == 0)
//					cout << "Queue khong rong!" << x << endl;
//				else
//					cout << "Queue rong!" << endl;
//				break;
//			case 6:
//				cout << "Queue hien tai la: ";
//				process_queue(a, f, r);
//				break;
//			case 7:
//				cout << "Goddbye!" << endl;
//				break;
//			default:
//				break;
//		}
//	} while (choice != 7);
//	system("pause");
//	return 0;
//}