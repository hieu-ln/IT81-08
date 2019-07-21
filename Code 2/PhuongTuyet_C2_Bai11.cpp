//#include <iostream>
//using namespace std;
//
////Cau 11.1
//struct Node {
//	int info;
//	Node *link;
//};
//Node *front, *rear;
//
////Cau 11.2
//void init()
//{
//	front = NULL;
//	rear = NULL;
//}
//
////Cau 11.3
//int isEmpty()
//{
//	if (front == NULL)
//		return 1;
//	return 0;
//}
//
////Cau 11.4
//void Push(int x)
//{
//	Node *p=new Node;
//	p->info = x;
//	p->link = NULL;
//	if (rear != NULL)
//		rear->link = p;
//	else
//		front = p;
//	rear = p;
//}
//
////Cau 11.5
//int Pop(int &x)
//{
//	if (front != NULL)
//	{
//		Node *p = front;
//		x = p->info;
//		front = front->link;
//		if (front == NULL)//Ds 1 phan tu sau khi lay ra 
//			rear = NULL;
//		delete p;
//		return 1;
//	}
//	else
//		return 0;
//}
//
////Xuat Queue
//void Process_queue()
//{
//	if (front != NULL)
//	{
//		Node *p = front;
//		cout << "<-- ";
//		while (p != NULL)
//		{
//			cout << p->info << "     ";
//			p = p->link;
//		}
//		cout << "<--"<<endl;
//	}
//}
//
//int main()
//{
//	int x, i, choice = 0;
//
//	cout << "---Bai 11, Chuong 2, QUEUE (HANG DOI - DS LIEN KET DON)---" << endl
//						<< "1. Khoi tao Queue rong" << endl
//						<< "2. Them phan tu vao Queue" << endl
//						<< "3. Lay phan tu ra khoi Queue" << endl
//						<< "4. Kiem tra Queue co rong hay khong" << endl
//						<< "5. Xuat Queue" << endl
//						<< "6. Thoat" << endl;
//
//	do {
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			init();
//			cout << "Khoi tao Queue thanh cong!";
//			break;
//		case 2:
//			cout << "Vui long nhap gia tri x=";
//			cin >> x;
//			Push(x);
//			cout << "\nDanh sach sau khi them: ";
//			Process_queue();
//			break;
//		case 3:
//			i = Pop(x);
//			if (i == 1)
//			{
//				cout << "Phan tu lay ra tu Queue x=" << x;
//				cout << "\nDanh sach hien tai: ";
//				Process_queue();
//			}
//			else
//				cout << "Queue rong!";
//			break;
//		case 4:
//			i = isEmpty();
//			if (i == 1)
//				cout << "Queue rong!";
//			else
//				cout << "Queue khong rong!";
//			break;
//		case 5:
//			cout << "Danh sach hien tai: ";
//			Process_queue();
//			break;
//		case 6:
//			cout << "Goobye!";
//			break;
//		default:
//			cout << "Loi nhap lieu!";
//			break;
//		}
//	} while (choice != 6);
//
//	cout << endl;
//	system("pause");
//	return 0;
//}