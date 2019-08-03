//#include <iostream>
//using namespace std;
//#define COUNT 10
//
////Cau 2.1
//struct Node {
//	int info;
//	Node *left, *right;
//};
//Node *root;
//
////Cau 2.2
//void init() 
//{
//	root = NULL;
//}
//
//void insert_tree(Node *&p, int x)
//{
//	if (p == NULL)
//	{
//		p = new Node;
//		p->info = x;
//		p->right = NULL;
//		p->left = NULL;
//	}
//	else
//	{
//		if (p->info == x)
//			return;
//		else
//		{
//			if (p->info > x)
//				return insert_tree(p->left, x);
//			else
//				return insert_tree(p->right, x);
//		}
//	}
//}
//
////Cau 2.4
//Node *search(Node *p, int x)
//{
//	while (p != NULL)
//	{
//		if (p->info == x)
//			return p;
//		else
//		{
//			if (p->info > x)
//				p = p->left;
//			else
//				p = p->right;
//		}
//	}
//	return NULL;
//}
//
//void print2DUntil(Node *p, int space)
//{
//	if (p == NULL)
//		return;
//
//	space += COUNT;
//
//	print2DUntil(p->right, space);
//	cout << endl;
//
//	for (int i = COUNT; i < space; i++)
//		cout << " ";
//	cout << p->info << "\n";
//
//	print2DUntil(p->left, space);
//}
//
//void process_tree()
//{
//	print2DUntil(root, 0);
//}
//
//int main()
//{
//	int x,choice;
//	Node *p;
//	cout << "---Bai 2, Cau 4, CHUONG 5 - TIM PHAN TU TRONG CAY NHI PHAN---"<<endl;
//	cout << "1.Tao cay NPTK rong" << endl
//		<< "2.Nhap phan tu cho cay NPTK" << endl
//		<< "3.Tim phan tu x trong cay NPTK" << endl
//		<< "4.Xuat cay NPTK" << endl
//		<< "5.Thoat" << endl;
//	
//	do {
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			init();
//			cout << "Khoi tao cay NPTK rong thanh cong!";
//			break;
//		case 2:
//			cout << "Vui long nhap x=";
//			cin >> x;
//			insert_tree(root, x);
//			cout << "Cay NPTK sau khi them x:" << endl;
//			process_tree();
//			break;
//		case 3:
//			cout<< "Vui long nhap x=";
//			cin >> x;
//			p = search(root, x);
//			if (p == NULL)
//				cout << "Khong tim thay gia tri x!";
//			else
//				cout << "Tim thay gia tri x trong cay!";
//			break;
//		case 4:
//			cout << "CAY NHI PHAN TIM KIEM:" << endl;
//			process_tree();
//			break;
//		case 5:
//			cout << "Goodbye!";
//			break;
//		default:
//			cout << "Loi nhap lieu!";
//			break;
//		}
//	} while (choice != 5);
//
//	cout << endl;
//	system("pause");
//	return 0;
//}