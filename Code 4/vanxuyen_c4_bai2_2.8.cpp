#include <iostream>
using namespace std;
#define COUNT 10

//Cau 2.1
struct Node
{
	int info;
	Node *right, *left;
};
Node *root;

//Cau 2.2
void init()
{
	root = NULL;
}

void insert_tree(Node *&p, int x)
{
	if (p == NULL)
	{
		p = new Node;
		p->info = x;
		p->left = NULL;
		p->right = NULL;
	}

	if (p->info == x)
		return;
	else
	{
		if (p->info > x)
			return insert_tree(p->left, x);
		else
			return insert_tree(p->right, x);
	}
}

void print2DUntil(Node *p, int space)
{
	if (p == NULL)
		return;

	space += COUNT;

	print2DUntil(p->right, space);

	cout << endl;
	for (int i = COUNT; i < space; i++)
		cout << " ";
	cout << p->info << "\n";

	print2DUntil(p->left, space);
}

void process_tree()
{
	print2DUntil(root, 0);
}

//Queue
struct NodeQ {
	int info;
	NodeQ *link;
};
NodeQ *front;
NodeQ *rear;

void initQ()
{
	front = NULL;
	rear = NULL;
}

void Push(Node *a)
{
	NodeQ *p = new NodeQ;
	p->info = a->info;
	p->link = NULL;
	if (rear != NULL)
		rear->link = p;
	else
		front = p;
	rear = p;
}

int Pop(int &x)
{
	if (front != NULL)
	{
		NodeQ *p = front;
		x = p->info;
		front = front->link;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

//Duyệt LRN (queue)
void LRN(Node *p)
{
	if (p != NULL)
	{
		LRN(p->left);
		LRN(p->right);
		Push(p);
	}
}

void printLRN()
{
	int x;

	LRN(root);//duyet cay theo LNR

	while (front != NULL)
	{
		if (Pop(x) == 1)
			cout << x << " ";
	}
}
//End Stack

int main()
{
	int x, choice, i;

	cout << "---Bai 2, Cau 3, CHUONG 4 - XOA PHAN TU TRONG CAY NPTK---" << endl;
	cout << "1.Khoi tao cay NPTK rong" << endl
		<< "2.Nhap phan tu vao cay" << endl
		<< "3.Duyet cay theo thu tu LNR (stack)" << endl
		<< "4.Xuat cay" << endl
		<< "5.Thoat" << endl;

	do {
		cout << "\nVui long nhap so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			init();
			cout << "Da khoi tao cay NPTK rong thanh cong!";
			break;
		case 2:
			cout << "Vui long nhap gia tri x=";
			cin >> x;
			insert_tree(root, x);
			cout << "CAY NPTK SAU KHI THEM X: " << endl;
			process_tree();
			break;
		case 3:
			cout << "Duyet cay theo thu tu LRN: ";
			printLRN();
			break;
		case 4:
			cout << "CAY NPTK:" << endl;
			process_tree();
			break;
		case 5:
			cout << "Goodbye!";
			break;
		default:
			cout << "Loi nhap lieu!";
			break;
		}

	} while (choice != 5);
	cout << endl;
	system("pause");
	return 0;
}