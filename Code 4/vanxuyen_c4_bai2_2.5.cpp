//#include <iostream>
//using namespace std;
//
//#define COUNT 100  
////cau 2.1
//struct Node
//{
//	int info;
//	Node *left;
//	Node *right;
//};
//Node *root;
//
////cau 2.2
//void tree_empty()
//{
//	root = NULL;
//}
//
////cau 2.3
//void insertNode(Node *&p, int x)
//{
//	if (p == NULL)
//	{
//		p = new Node;
//		p->info = x;
//		p->left = NULL;
//		p->right = NULL;
//	}
//	else
//	{
//		if (p->info == x)
//			return;
//		else
//			if (p->info > x)
//				return insertNode(p->left, x);
//			else
//				return insertNode(p->right, x);
//	}
//}
// //cau 2.5
//void searchStandFor(Node *&p, Node *&q)
//{
//	if (q->left == NULL)
//	{
//		p->info = q->info;
//		p = q;
//		q = q->right;
//	}
//	else
//		searchStandFor(p, q->left);
//}
//
//int Delete(Node *&T, int x)
//{
//	if (T == NULL)
//		return 0;
//	if (T->info == x)
//	{
//		Node *p = T;
//		if (T->left == NULL)
//			T = T->right;
//		else
//			if (T->right == NULL)
//				T = T->left;
//			else
//				searchStandFor(p, T->right);
//		delete p;
//		return 1;
//	}
//	if (T->info < x)
//		return Delete(T->right, x);
//	if (T->info > x)
//		return Delete(T->left, x);
//}
////xuat cay
//void print2DUtil(Node *p, int space)
//{
//	if (p == NULL)
//		return;
//	space += COUNT;
//	print2DUtil(p->right, space);
//	cout << endl;
//	for (int i = COUNT; i < space; i++)
//		cout << " ";
//	cout << p->info << "\n";
//	print2DUtil(p->left, space);
//}
//void process_tree()
//{
//	print2DUtil(root, 0);
//}
//int main()
//{
//	int choice = 0;
//	int x, i;
//	Node *p;
//	cout << "Bai Tap 1-----Chuong 4-----CNPTK" << endl;
//	cout << "1. Khoi tao cay nhi phan rong " << endl;
//	cout << "2. Them phan tu vao cay" << endl;
//	cout << "3. Xoa phan tu co gia tri x trong cay" << endl;
//	cout << "4. Thoat" << endl;
//	do
//	{
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			tree_empty();
//			cout << "Ban vua khoi tao cay NPTK thanh cong\n";
//			break;
//		case 2:
//			cout << "Vui long nhap gia tri x can them: ";
//			cin >> x;
//			insertNode(root, x);
//			cout << "Cay NPTK sau khi them la: ";
//			process_tree();
//			break;
//		case 3:
//			cout << "Vui long nhap gia tri x can xoa: ";
//			cin >> x;
//			i = Delete(root, x);
//			if (i == 0)
//				cout << "Khong tim thay!";
//			else
//			{
//				cout << "Da xoa thanh cong x=" << x << " trong cay NPTK";
//				cout << "Cay NPTK sau khi xoa la: ";
//				process_tree();
//			}
//			break;
//		case 4:
//			cout << "Goodbye!" << endl;
//			break;
//		default:
//			break;
//		}
//	} while (choice != 4);
//	system("pause");
//	return 0;
//}
