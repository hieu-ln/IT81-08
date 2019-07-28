#include <iostream>
#include <stack>
using namespace std;

struct Node
{
	int infor;
	Node* next;
};
Node* sp;

void Init()
{
	sp = NULL;
}

int Rong()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void Push(int x)
{
	Node* p;
	p = new Node;
	p->infor = x;
	p->next = sp;
	sp = p;
}
int Pop(int &x)
{
	if (sp != NULL)
	{
		Node* p;
		p = sp;
		x = p->infor;
		sp = sp->next;
		delete p;
		return 1;
	}
	return 0;
}

void Output()
{
	Node * p;
	p = sp;
	while (p != NULL)
	{
		cout << p->infor << "\t";
		p = p->next;
	}
	cout << "\n" ;
}

void Conv(int n)
{
	stack <int> s;
	int tam = 0;
	for (int i = 0; n > 0; i++)
	{
		tam = n % 2;
		s.push(tam);
		n = n / 2;
	}
	while (!s.empty())
	{
		cout << s.top();
		s.pop();
	}
}
int main()
{
	int choice, i, x;
	cout << "----------Bai tap 5----------Chuong 2---------MENU--------" << "\n" ;
	cout << "1. Khoi tao stack rong\n";
	cout << "2. Kiem tra stack rong\n";
	cout << "3. Them mot phan tu vao stack\n";
	cout << "4. Xoa mot phan tu trong stack\n";
	cout << "5. Chuyen stack da xay dung qua nhi phan\n";
	cout << "6. Stack hien tai\n";
	cout << "7. THOAT!\n";
	do
	{
		cout << "Vui long nhap yeu cau: \n";
		cin >> choice;
		switch (choice)
		{
			case 1:
				init();
				cout << "Khoi tao stack rong thanh cong\n";
				break;
			case 2:
				i = Rong();
				if (i == 1)
					cout << "Stack rong\n";
				else
					cout << "Stack khong rong\n";
				break;
			case 3:
				cout << "Nhap phan tu muon them vao stack\n";
				cin >> x;
				Push(x);
					cout << "Them thanh cong\n";
				cout << "Danh sach sau khi them \n";
				Output();
				break;
			case 4:
				i = Pop(x);
				if (i == 1)
				{
					cout << "Xoa phan tu thanh cong\n";
					cout << "Danh sach sau khi xoa/lay ra \n";
					Output();
				}
				else
					cout << "Xoa/lay that bai\n";
			case 5:
				int n;
				cout << "Nhap so thap phan muon chuyen sang nhi phan:\n";
				cin >> n;
				cout << "So thap phan " << n << " sau khi duoc chuyen qua nhi phan: ";
				Conv(n);
				cout << "\n" ;
				break;
		default:
		break;
		}
	} while (choice!=7);
	system("pause");
	return 0;
}