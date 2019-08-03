//#include <iostream>
//using namespace std;
//#define COUNT 10
//
////cau 1.1
//struct Node
//{
//	int infor;
//	Node* left;
//	Node* right;
//};
//Node* root;
////cau 1.2
//void khoitao()
//{
//	root = NULL;
//}
////cau 1.3
//void them(Node *&p,int x)
//{
//	if (p == NULL)
//	{
//		p = new Node;
//		p->infor = x;
//		p->left = NULL;
//		p->right = NULL;
//	}
//	else
//	{
//		if (p->infor == x)
//			return;
//		else if (p->infor < x)
//			return them(p->right, x);
//		else
//			return them(p->left, x);
//	} 
//}
////cau 1.4
//Node* search(Node* p, int x)
//{
//	while (p != NULL)
//	{
//		if (p->infor == x)
//			return p;
//		else
//		{
//			if (  x< p->infor)
//			{
//				return search(p->left, x);
//			}
//			else
//				return search(p->right, x);
//		}
//	}
//	return NULL;
//}
////cau 1.5
//void tim(Node* &p, Node* &q)
//{
//	if (q->left == NULL)
//	{
//		p->infor = q->infor;
//		p = q;
//		q = q->right;
//	}
//	else
//		tim(p, q->left);
//}
//int xoa(Node *&T, int x)
//{
//	if (T == NULL)
//		return 0;
//	if (T->infor == x)
//	{
//		Node* p = T;
//		if (T->left == NULL)
//			T = T->right;
//		else if (T->right == NULL)
//			T = T->left;
//		else
//			tim(p, T->right);
//		delete p;
//		return 1;
//	}
//	else
//	{
//		if (T->infor > x)
//			return xoa(T->left, x);
//		else
//			return xoa(T->right, x);
//	}
//}
////cau 1.6
//void NLR(Node* p)
//{
//	if (p != NULL)
//	{
//		cout << p->infor << " ";
//		NLR(p->left);
//		NLR(p->right);
//	}
//}
////cau 1.7
//void LNR(Node* p)
//{
//	if (p != NULL)
//	{
//		LNR(p->left);
//		cout << p->infor << " ";
//		LNR(p->right);
//	}
//}
////cau 1.8
//void LRN(Node* p)
//{
//	if (p != NULL)
//	{
//		LRN(p->left);
//		LRN(p->right);
//		cout << p->infor << " ";
//	}
//}
//
//void print2DUtil(Node *p, int space)
//{
//	// Base case
//	if (p == NULL)
//		return;
//
//	// Increase distance between levels
//	space += COUNT;
//
//	// Process right child first
//	print2DUtil(p->right, space);
//
//	//Print current node after space
//	//count
//	cout << endl;
//	for (int i = COUNT; i < space; i++)
//		cout << " ";
//	cout << p->infor << "\n";
//
//	//Process left child
//	print2DUtil(p->left, space);
//}
//void xuat()
//{
//	print2DUtil(root, 0);
//}
//int main()
//{
//	int chon, i,x,cantim;
//	Node* p;
//	system("cls");
//	cout << "-----Bai 1------Chuong 4-----NPTK-----\n";
//	cout << "1. Khoi tao cay rong\n";
//	cout << "2. Them mot phan tu bang de quy\n";
//	cout << "3.Tim mot phan tu bang de quy\n";
//	cout << "4. Xoa mot nut bang de quy\n";
//	cout << "5. Duyet cay theo LNR bang de quy\n";
//	cout << "6. Duyet cay theo LRN bang de quy\n";
//	cout << "7. Duyet cay theo NLR bang de quy\n";
//	cout << "8. Thoat\n";
//	do
//	{
//		cout << "Vui long nhap yeu cau: ";
//		cin >> chon;
//		switch (chon)
//		{
//		case 1:
//			khoitao();
//			cout << "Ban da khoi tao cay rong thanh cong\n";
//			break;
//		case 2: 
//			cout << "Nhap gia tri can them vao cay: ";
//			cin >> x;
//			them(root,x);
//			cout << "Cay nhi phan sau khi them: \n";
//			xuat();
//			break;
//		case 3: 
//			cout << "Nhap phan tu muon tim trong cay: ";
//			cin >> cantim;
//			p = search(root, cantim);
//			if (p != NULL)
//				cout << cantim << " co trong cay\n";
//			else
//				cout << cantim << " khong tim thay\n";
//			break;
//		case 4:
//			cout << "Nhap phan tu muon xoa trong cay: ";
//			cin >> x;
//			i = xoa(root, x);
//			if (i == 0)
//				cout << x << " khong tim thay trong cay\n";
//			else
//			{
//				cout << "Cay sau khi xoa: " << endl;
//				xuat();
//			}
//		case 5:
//			cout << "Duyet cay theo LNR bang de quy: " << endl;
//			LNR(root);
//			cout << endl;
//			break;
//		case 6:
//			cout << "Duyet cay theo LRN bang de quy: " << endl;
//			LRN(root);
//			cout << endl;
//			break;
//		case 7:
//			cout << "Duyet cay theo NLR bang de quy: " << endl;
//			NLR(root);
//			cout << endl;
//			break;
//		case 8:
//			cout << "Bai~~~~~~~~~~~~";
//		default:
//			break;
//		}
//	} while (chon!=8);
//	system("pause");
//	return 0;
//}