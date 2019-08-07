#include <iostream>
using namespace std;
#define count 10
struct Node
{
	int infor;
	Node *left, *right;
};


Node *root;
void emptyTree()
{
	root = NULL;
}



void insertNode(Node *&p, int x) //p la node goc root
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
		if (p->infor = x)
			return;
		else
			if (p->infor > x)
				return insertNode(p->left, x);
			else
				return insertNode(p->right, x);
	}
}




void searchStandFor(Node *&p, Node *&q)
{
	if (q->left == NULL)
	{
		p->infor = q->infor;
		p = q;
		q = q->right;
	}
	else
		searchStandFor(p, q->left);
}


void printTree(Node *p, int space)
{
	if (p == NULL)
		return;
	space += count;
	printTree(p->right, space);
	cout << endl;
	for (int i = count; i < space; i++)
		cout << "  ";
	cout << p->infor << "\n";
	printTree(p->left, space);
}
void processTree()
{
	printTree(root, 0);
}

int Delete(Node *&T, int x)
{
	if (T == NULL)
		return 0;
	if (T->infor == x)
	{
		Node *p = T;
		if (T->left == NULL)
			T = T->right;
		else
			if (T->right == NULL)
				T = T->left;
			else
				searchStandFor(p, T->right);
		delete p;
		return 1;
	}
	if (T->infor < x)
		Delete(T->right, x);
	if (T->infor > x)
		Delete(T->left, x);
}
void outputNLR(Node *p)
{
	Node *stack[50];
	p = root;
	int numofele = 0, conti = 1;
	while (p&&conti)
	{
		printf("%d ", p->infor);
		if (p->right)
			stack[numofele++] = p->right;
		if (p->left)
			p = p->left;
		else
		{
			if (numofele != 0)
				p = stack[--numofele];
			else 
				conti = 0;
		}
	}
}


int main()
{
	Node *p = new Node;
	int choice, x;
	cout << "BTLT chuong 4 -  Duyet LNR khong dung de quy" << endl;
	cout << "1.Khoi tao cay rong" << endl;
	cout << "2.Them 1 phan tu vao cay" << endl;
	cout << "3.Xoa 1 phan tru trong cay" << endl;
	cout << "4. Duyet mang theo NLR" << endl;
	cout << "5.Thoat" << endl;
	
	do
	{
		cout << "\nMoi nhap so de thao tac: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
			emptyTree();
			cout << "Khoi tao cay rong thanh cong";
			break;
		case 2:
			cout << "Moi nhap phan tu can de them vao cay: ";
			cin >> x;
			insertNode(root, x);
			cout << "Them vao cay thanh cong" << endl;
			cout << "Cay bay gio la" << endl;
			processTree();
			break;
		case 3:
			cout << "Moi nhap phan tu can xoa: ";
			cin >> x;
			if (Delete(p, x) == NULL)
				cout << "Phan tu khong co trong cay" << endl;
			else
			{
				cout << "Xoa phan tu " << x << " tren cay thanh cong" << endl;
				cout << "Cay nhi phan hien tai" << endl;
				processTree();
			}
			break;
		case 4:
			cout << "Cay sau khi duoc duyet la: " << endl;
			outputNLR(root);
		}
	} while (choice != 5);
	system("pause");
	return 0;

}