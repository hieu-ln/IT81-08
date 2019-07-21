//#include <iostream>
//using namespace std;
//
////Cau 5.1
//#define MAX 100
//
////Cau 5.2
//void init(int a[], int &sp)
//{
//	sp = -1;
//}
//
////Cau 5.3
//int isEmpty(int a[], int sp)
//{
//	if (sp == -1)
//		return 1;
//	return 0;
//}
//
////Cau 5.4
//int isFull(int a[], int sp)
//{
//	if (sp == MAX - 1)
//		return 1;
//	return 0;
//}
//
////Cau 5.5
//int Push(int a[], int &sp, int x)
//{
//	if (sp < MAX - 1)
//	{
//		a[++sp] = x;
//		return 1;
//	}
//	return 0;
//}
//
////Cau 5.6
//int Pop(int a[], int &sp, int &x)
//{
//	if (sp != -1)
//	{
//		x = a[sp--];
//		return 1;
//	}
//	return 0;
//}
//
////Xuat Stack
//void Process_stack(int a[], int sp)
//{
//	for (int i = 0; i < sp + 1; i++)
//	{
//		cout << a[i] << " ";
//	}
//	cout << endl;
//}
//
//int main()
//{
//	int a[MAX];
//	int sp;
//	int x, choice = 0, i;
//	cout << "---Bai 5, Chuong 2, STACK(NGAN XEP - DS DAC)---" << endl
//		<< "1. Khoi tao Stack rong" << endl
//		<< "2. Them phan tu vao Stack" << endl
//		<< "3. Lay phan tu ra khoi Stack" << endl
//		<< "4. Kiem tra Stack co rong hay khong" << endl
//		<< "5. Kiem tra Stack co day hay khong" << endl
//		<< "6. Xuat Stack" << endl
//		<< "7. Thoat" << endl;
//
//	do {
//		cout << "\nVui long chon so de tuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			init(a, sp);
//			cout << "Da tao Stack rong thanh cong!";
//			break;
//		case 2:
//			cout << "Vui long nhap gia tri x=";
//			cin >> x;
//			i = Push(a, sp,x);
//			if (i == 1)
//			{
//				cout << "Da nhap thanh cong x=" << x << " vao Stack!";
//				cout << "\nDanh sach hien tai: ";
//				Process_stack(a, sp);
//			}
//			else
//				cout << "Danh sach da day!";
//			break;
//		case 3:
//			i = Pop(a, sp, x);
//			if (i == 1)
//			{
//				cout << "Phan tu lay ra tu Stack x=" << x << "!";
//				cout << "\nDanh sach hien tai: ";
//				Process_stack(a, sp);
//			}
//			else
//				cout << "Danh sach rong, khong the lay phan tu ra!";
//			break;
//		case 4:
//			i = isEmpty(a, sp);
//			if (i == 1)
//			{
//				cout << "Stack rong!";
//			}
//			else
//				cout << "Stack khong rong!";
//			break;
//		case 5:
//			i = isFull(a, sp);
//			if (i == 1)
//				cout << "Stack da day!";
//			else
//				cout << "Stack chua day!";
//			break;
//		case 6:
//			cout << "Danh sach hien tai: ";
//			Process_stack(a, sp);
//			break;
//		case 7:
//			cout << "Goodbye!";
//			break;
//		default:
//			cout << "Loi nhap lieu!";
//			break;
//		}
//
//	} while (choice != 7);
//	cout << endl;
//	system("pause");
//	return 0;
//}