#include <iostream>
using namespace std;
#define COUNT 10

struct Node
{
	int infor;
	Node* left;
	Node* right;
};
Node* root;

void Create()
{
	root = NULL;
}

void Add(Node *&p,int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->infor = x;
		p->left = NULL;
		p->right = NULL;
	}
	else
	{
		if (p->infor == x)
			return;
		else if (p->infor < x)
			return Add(p->right, x);
		else
			return Add(p->left, x);
	} 
}

Node* Search(Node* p, int x)
{
	while (p != NULL)
	{
		if (p->infor == x)
			return p;
		else
		{
			if (  x< p->infor)
			{
				return Search(p->left, x);
			}
			else
				return Search(p->right, x);
		}
	}
	return NULL;
}

void Find(Node* &p, Node* &q)
{
	if (q->left == NULL)
	{
		p->infor = q->infor;
		p = q;
		q = q->right;
	}
	else
		Find(p, q->left);
}

int Del(Node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T->infor == x)
	{
		Node* p = T;
		if (T->left == NULL)
			T = T->right;
		else if (T->right == NULL)
			T = T->left;
		else
			Find(p, T->right);
		delete p;
		return 1;
	}
	else
	{
		if (T->infor > x)
			return Del(T->left, x);
		else
			return Del(T->right, x);
	}
}

void NLR(Node* p)
{
	if (p != NULL)
	{
		cout << p->infor << " ";
		NLR(p->left);
		NLR(p->right);
	}
}

void LNR(Node* p)
{
	if (p != NULL)
	{
		LNR(p->left);
		cout << p->infor << " ";
		LNR(p->right);
	}
}

void LRN(Node* p)
{
	if (p != NULL)
	{
		LRN(p->left);
		LRN(p->right);
		cout << p->infor << " ";
	}
}

void print2DUtil(Node *p, int space)
{
	if (p == NULL)
		return;

	space += COUNT;
	print2DUtil(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->infor << "\n";
	print2DUtil(p->left, space);
}

void Out()
{
	print2DUtil(root, 0);
}
int main()
{
	int chon, i,x,cantim;
	Node* p;
	system("cls");
	cout << "-----Bai 1------Chuong 4-----NPTK-----\n";
	cout << "1. Khoi tao cay rong\n";
	cout << "2. Them mot phan tu bang de quy\n";
	cout << "3.Tim mot phan tu bang de quy\n";
	cout << "4. Xoa mot nut bang de quy\n";
	cout << "5. Duyet cay theo LNR bang de quy\n";
	cout << "6. Duyet cay theo LRN bang de quy\n";
	cout << "7. Duyet cay theo NLR bang de quy\n";
	cout << "8. Thoat\n";
	do
	{
		cout << "Vui long nhap yeu cau: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			Create();
			cout << "Ban da khoi tao cay rong thanh cong\n";
			break;
		case 2: 
			cout << "Nhap gia tri can them vao cay: ";
			cin >> x;
			Add(root,x);
			cout << "Cay nhi phan sau khi them: \n";
			Out
			break;
		case 3: 
			cout << "Nhap phan tu muon tim trong cay: ";
			cin >> cantim;
			p = Search(root, cantim);
			if (p != NULL)
				cout << cantim << " co trong cay\n";
			else
				cout << cantim << " khong tim thay\n";
			break;
		case 4:
			cout << "Nhap phan tu muon xoa trong cay: ";
			cin >> x;
			i = Del(root, x);
			if (i == 0)
				cout << x << " khong tim thay trong cay\n";
			else
			{
				cout << "Cay sau khi xoa: " << endl;
				Out();
			}
		case 5:
			cout << "Duyet cay theo LNR bang de quy: " << endl;
			LNR(root);
			cout << endl;
			break;
		case 6:
			cout << "Duyet cay theo LRN bang de quy: " << endl;
			LRN(root);
			cout << endl;
			break;
		case 7:
			cout << "Duyet cay theo NLR bang de quy: " << endl;
			NLR(root);
			cout << endl;
			break;
		default:
			break;
		}
	} while (chon!=8);
	system("pause");
	return 0;
}