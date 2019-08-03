#include <iostream>
using namespace std;
#define COUNT 10
//cau 2.1
struct Node
{
	int infor;
	Node* left;
	Node* right;
};
Node* root;
//cau 2.2
void khoitao()
{
	root = NULL;
}
//cau 2.3
void them(Node* a, int x)
{
	Node* tempNode = (Node*)malloc(sizeof(Node));
	Node* b;
	tempNode->infor = x;
	tempNode->left = NULL;
	tempNode->right = NULL;
	if (root == NULL)
	{
		root = tempNode;
	}
	else
	{
		b = NULL;
		while (true)
		{
			b = a;
			if (x < b->infor)
			{
				a = a->left;
				if (a == NULL)
				{
					b->left = tempNode;
					return;
				}
			}
			else
			{
				a = a->right;
				if (a == NULL)
				{
					b->right = tempNode;
					return;
				}
			}
		}
	}
}
void nhap(Node* p, int space)
{
	if (p == NULL)
		return;
	space += COUNT;
	nhap(p->right, space);
	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->infor << " \n";
	nhap(p->left, space);
}
void xuat()
{
	nhap(root, 0);
}
int main()
{
	int i, chon, x;
	system("cls");
	cout << "-----Bai 2------Chuong 4-----NPTK-----\n";
	cout << "1. Khoi tao cay rong\n";
	cout << "2. Them mot phan tu vao cay\n";
	cout << "3. Thoat\n";
	do
	{
		cout << "Vui long nhap yeu cau: ";
		cin >> chon;
		switch (chon)
		{
			case 1:
				khoitao();
				cout << "Khoi tao cay rong thanh cong\n";
				break;
			case 2:
				cout << "Nhap gia tri can them vao cay NPTK: ";
				cin >> x;
				them(root, x);
				cout << "Cay NPTK sau khi duoc them: \n";
				xuat();
				break;
			case 3:
				cout << "Bai~~~~~~~~~~\n";
				break;
		default:
			break;
		}
	} while (chon != 3);
	system("pause");
	return 0;
}