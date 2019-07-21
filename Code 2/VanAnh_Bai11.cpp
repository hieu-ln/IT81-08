//#include <iostream>
//using namespace std;
//struct Node
//{
//	int info;
//	Node* link;
//};
//Node* front, *rear;
//void init()
//{
//	front = NULL;
//	rear = NULL;
//}
//void push(int x)
//{
//	Node* p = new Node;
//	p->info = x;
//	p->link = NULL;
//	if (rear == NULL)
//		front = p;
//	else
//		rear->link = p;
//	rear = p;
//}
//int pop(int &x)
//{
//	if (front != NULL)
//	{
//		Node* p = front;
//		front = p->link;
//		x = p->info;
//		if (front = NULL)
//		{
//			rear = NULL;
//		}
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void output()
//{
//	if (front != NULL)
//	{
//		Node* p = front;
//		cout << "<---";
//		do 
//		{
//			cout << p->info << " ";
//			p = p->link;
//		} while (p != NULL);
//		cout << "<---" << endl;
//	}
//}
//int main()
//{
//	int choice, x, i;
//	system("cls");
//	cout << "1. Khoi tao queue rong\n";
//	cout << "2. Them phan tu vao queue\n";
//	cout << "3. Xuat phan tu\n";
//	cout << "4. Queue hien tai\n";
//	cout << "5. Thoat\n";
//	do
//	{
//		cout << "Ban chon: ";
//		cin >> choice;
//		switch (choice)
//		{
//			case 1:
//				init();
//				cout << "Khoi tao thanh cong\n";
//				break;
//			case 2:
//				cout << "Nhap gia tri can them vao Queue\n";
//				cin >> x;
//				push(x);
//				cout << "Queue sau khi them: \n";
//				output();
//				break;
//			case 3:
//				i = pop(x);
//				if (i == 1)
//				{
//					cout << "Phan tu lay ra tu queue x= " << x << endl;
//				}
//				cout << "QUEUE SAU KHI DUOC LAY RA: " << endl;
//				output();
//				cout << endl;
//				break;
//			case 4:
//				cout << "Danh sach Queue hien tai: " << endl;
//				output();
//				cout << endl;
//				break;
//		default:
//			cout << "Bai Bai\n";
//			break;
//		}
//	} while (choice != 5);
//	system("pause");
//	return 0;
//}