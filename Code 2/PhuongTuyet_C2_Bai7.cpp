//#include <iostream>
//using namespace std;
//#define MAX 100
//
//void init(int a[], int &front, int &rear)
//{
//	front = -1;
//	rear = -1;
//}
//
////Cau 7.2
//int isEmpty(int a[], int rear, int front)
//{
//	if (front==rear)
//		return 1;
//	return 0;
//}
//
////Cau 7.3
//int isFull(int a[], int front, int rear)
//{
//	if ((front==0&&rear==MAX-1)||(rear-front==-1))
//		return 1;
//	return 0;
//}
//
////Cau 7.4
//int Push(int a[], int &front, int &rear, int x)
//{
//	if(front==0&&rear==MAX-1)
//		return 0;
//	else
//	{
//		if (front == -1)//Queue rong
//			front = 0;
//		if (rear == MAX)//Queue tran
//		{
//			for (int i = front; i < rear; i++)
//				a[i - front] = a[i];
//			front = 0;
//			rear = MAX - 1 - front;
//		}
//		a[++rear] = x;
//		return 1;
//	}
//	return 0;
//}
//
////Cau 7.6
//int Pop(int a[], int &front, int &rear, int &x)
//{
//	if (front != -1)
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
////Xuat QUEUE
//void Process_queue(int a[], int f, int r)
//{
//	cout << "f= " << f << "\t" << "r= " << r << endl;
//	if (f <= r && f != -1)
//	{
//		cout << "<-- ";
//		for (int i = f; i < r + 1; i++)
//			cout << a[i] <<"     ";
//		cout << "<-- " << endl;
//	}
//}
//
//int main()
//{
//	int a[MAX];
//	int front, rear;
//	int x,choice=0,i;
//	cout << "---Bai 7, Chuong 2, QUEUE (HANG DOI - DS DAC)---" << endl
//		<< "1. Khoi tao Queue rong" << endl
//		<< "2. Them phan tu vao Queue" << endl
//		<< "3. Lay phan tu ra khoi Queue" << endl
//		<< "4. Kiem tra Queue co rong hay khong" << endl
//		<< "5. Kiem tra Queue co day hay khong" << endl
//		<< "6. Xuat Queue" << endl
//		<< "7. Thoat" << endl;
//
//	do {
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			init(a, front, rear);
//			cout << "Khoi tao Queue rong thanh cong!";
//			break;
//		case 2:
//			cout << "Vui long nhap gia tri x=";
//			cin >> x;
//			i = Push(a, front, rear, x);
//			if (i == 1)
//			{
//				cout << "Da nhap thanh cong gia tri x=" << x << " vao Queue!";
//				cout << "\nDanh sach hien tai: ";
//				Process_queue(a, front, rear);
//			}
//			else
//				cout << "Queue da day!";
//			break;
//		case 3:
//			i = Pop(a, front, rear, x);
//			if (i == 1)
//			{
//				cout << "Phan tu lay ra tu Queue la x=" << x;
//				cout << "\nDanh sach hien tai: ";
//				Process_queue(a, front, rear);
//			}
//			else
//				cout << "Queue rong!";
//			break;
//		case 4:
//			i = isEmpty(a, rear, front);
//			if (i == 1)
//				cout << "Queue rong!";
//			else
//				cout << "Queue chua rong!";
//			break;
//		case 5:
//			i = isFull(a, front, rear);
//			if (i == 1)
//				cout << "Queue da day!";
//			else
//				cout << "Queue chua day!";
//			break;
//		case 6:
//			cout << "Danh sach hien tai: ";
//			Process_queue(a, front, rear);
//			break;
//		case 7:
//			cout << "Goodbye!";
//			break;
//		default:
//			cout << "Loi nhap lieu!";
//			break;
//		}
//	} while (choice != 7);
//
//	cout << endl;
//	system("pause");
//	return 0;
//}