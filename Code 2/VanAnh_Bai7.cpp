//#include <iostream>
//using namespace std;
////cau 7.1	
//#define max 100
//int a[max];
//int front, rear;
////cau 7.2
//void init(int a[], int &front, int &rear)
//{
//	front = -1;
//	rear = -1;
//}
////cau 7.3
//int isempty(int a[], int front, int rear)
//{
//	if (front==rear)
//		return 1;
//	return 0;
//}
////cau 7.4
//int isfull(int a[], int front, int rear)
//{
//	if ((front == 0 && rear == max - 1)||(rear-front==-1))
//		return 1;
//	return 0;
//}
////cau 7.5
//int add(int a[], int &front, int &rear, int value)
//{
//	if (front==0&&rear==max-1)
//		return 0;
//	else
//	{
//		if (front == -1)
//			front = 0;
//		if (rear == max - 1)
//		{
//			for (int i = front; i <= rear; i++)
//				a[i - front] = a[i];
//			rear = max - 1 - front;
//			front = 0;
//		}
//		a[++rear] = value;
//		return 1;
//	}
//	return 0;
//}
////cau 7.6
//int pop(int a[], int &front, int &rear, int &x)
//{
//	if (front != -1)
//	{
//		x = a[front];
//		if (front == rear)
//		{
//			front = -1;
//			rear = -1;
//		}
//		else
//		{
//			front++;
//			if (front > max - 1)
//				front = 0;
//		}
//		return 1;
//	}
//	return 0;
//}
//void output(int a[], int front,int rear)
//{
//	if (front <= rear && front != -1)
//	{
//		cout << "<---";
//		for (int i = front; i <= rear; i++)
//		{
//			cout << a[i] << "<---";
//		}
//	}
//}
//int main()
//{
//	int chon,i,x; 
//	cout << "------Bai 7------Chuong 2------Queue------\n";
//	cout << "1. Khoi tao queue rong\n";
//	cout << "2. Kiem tra queue rong\n";
//	cout << "3. Kiem tra queue day\n";
//	cout << "4. Them mot phan tu vao queue\n";
//	cout << "5. Xoa mot phan tu queue\n";
//	cout << "6. Xuat danh sach\n";
//	cout << "7. Thoat\n";
//	do
//	{
//		cout << "Vui long nhap yeu cau: ";
//		cin >> chon;
//		switch (chon)
//		{
//			case 1:
//				 init( a,front,rear);
//					cout << "Khoi tao Queue rong thanh cong\n";
//				break;
//			case 2:
//				i = isempty(a, front, rear);
//				if (i == 1)
//					cout << "Queue rong\n";
//				else
//					cout << "Queue khong rong\n";
//				break;
//			case 3:
//				i = isfull(a, front, rear);
//				if (i == 1)
//					cout << "Queue day\n";
//				else
//					cout << "Queue chua day\n";
//				break;
//			case 4:
//				cout << "Nhap gia tri can them vao danh sach: \n";
//				cin >> x;
//				i = add(a, front, rear,x);
//				if (i == 0)
//					cout << "Danh sach da day them that bai\n";
//				else
//				{
//					cout << "Them thanh cong\n";
//				}
//				cout << "Danh sach sau khi them: \n";
//				output(a, front, rear);
//				break;
//			case 5:
//				i = pop(a, front, rear, x);
//				if (i == 1)
//					cout << "Xoa thanh cong\n";
//				else
//					cout << "Khong the xoa\n";
//				cout << "Danh sach sau khi them: \n";
//				output(a,front,rear);
//				break;
//			case 6:
//				cout << "Xuat danh sach: \n";
//				output(a, front, rear);
//				cout << endl;
//				break;
//		default:
//			cout << "~~~Bai bai~~~\n";
//			break;
//		}
//	} while (chon!=7);
//	system("pause");
//	return 0;
//}