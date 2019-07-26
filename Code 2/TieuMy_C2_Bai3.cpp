#include <iostream>
using namespace std;

struct Node
{
	int infor;
	Node* next;
};
Node* first;

void Init()
{
	first = NULL;
}

void Output()
{
	Node* p;
	p = first;
	while (p != NULL)
	{
		cout << p->infor << " ";
		p = p->next;
	}
	cout << "\n";
}

Node* Search(int PT )
{
	Node* p;
	p = first;
	while (p!=NULL&&p->infor!=PT )
	{
		p = p->next;
	}
	return p;
}

void Add(int value)
{
	Node* p = new Node;
	p->infor = value;
	p->next = first;
	if (first == NULL)
		first = p;
	else
	{
		p->next = first;
	}
	first = p;
}

int Del()
{
	if (first != NULL)
	{
		Node* p;
		p = first;
		first = p->next;
		delete p;
		return 1;
	}
	return 0;
}

void Them(int value)
{
	Node*q;
	q = new Node;
 q->infor=value;
	q->next = NULL;
	if (first == NULL)
	{
		first = q;
	}
	else
	{
		Node* p = first;
		while (p->next != NULL)
		{
			p = p->next;
		}
		p->next = q;
	}
}

int Xoa()
{
	if (first != NULL)
	{
		Node* p, *q;
		p = first;
		q = first;
		while (p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		if (p != first)
			q->next = NULL;
		else
			first = NULL;
		delete p;
		return 1;
	}
	return 0;
}

int Sad (int z)
{
	if (first != NULL)
	{
		Node* p, *q;
		p = first;
		q = first;
		while (p->infor != z && p->next != NULL)
		{
			q = p;
			p = p->next;
		}
		if (p != first && p->next != NULL)
		{
			if (p->next != NULL)
				q->next = p->next;
			delete p;
			return 1;
		}
		else if (p == first)
		{
			first = p->next;
			delete p;
			return 1;
		}
		else if (p->next == NULL && p->infor == z)
		{
			q->next = NULL;
			delete p;
			return 1;
		}
		else
			return 0;
	}
	return 0;
}

void DoiViTri(Node* p,Node* q)
{
	int tam;
	tam = p->infor;
	p->infor = q->infor;
	q->infor = tam;
}

void SapXep()
{
	Node* p, *q,*min;
	p = first;
	while (p != NULL)
	{
		min = p;
		q = p->next;
		while (q != NULL)
		{
			if (q->infor < min->infor)
				min = q;
			q = q->next;
		}
		DoiViTri(min, p);
		p = p->next;
	}
}

int main()
{
	int n, chon,cantim,x,y,z;
	cout<<"----------Bai tap 3----------Chuong 2---------MENU--------" << "\n";
	cout << "1. Khoi tao danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Tim mot phan tu trong danh sach\n";
	cout << "4. Them mot phan tu va dau danh sach\n";
	cout << "5. Xoa phan tu dau trong danh sach\n";
	cout << "6. Them phan tu vao cuoi danh sach\n";
	cout << "7. Xoa phan tu cuoi trong danh sach\n";
	cout << "8. Tim mot phan tu neu tim thay thi xoa trong danh sach\n";
	cout << "9. Sap xep danh sach\n ";
	cout << "10. Thoat\n";
	do
	{
		cout << "Nhap yeu cau cua ban: ";
		cin >> chon;
		switch (chon)
		{
			case 1:
				Init();
				cout << "Ban vua khoi tao DSLKD thanh cong\n";
				break;
			case 2:
				cout << "Xuat danh sach:\n";
				Output();
				break;
			case 3:
				cout << "Nhap phan tu can tim: ";
				cin >> cantim;
				if (Search(cantim) == NULL)
					cout << "Phan tu khong co trong danh sach\n";
				else
					cout << "Phan tu " << cantim << " nam o dia chi " << Search(cantim) << " trong danh sach\n";
				break;
			case 4:
				cout << "Vui long nhap gia tri can them: ";
				cin >> x;
				Add(x);
				cout << "Danh sach sau khi them: " << "\n" ;
				Output();
				break;
			case 5:
				if (Del() == 0)
					cout << "Danh sach rong khong the xoa\n";
				else
				{
					cout << "Xoa phan tu dau thanh cong\n";
					cout << "Danh sach sau khi xoa: " << "\n" ;
					Output();
				}
				break;
			case 6:
				cout << "Nhap gia tri can them: ";
				cin >> y;
				Them(y);
				cout << "Danh sach sau khi them cuoi: " << "\n" ;
				Output();
				break;
			case 7:
				if (Xoa() == 0)
					cout << "Danh sach rong khong the xoa\n";
				else
				{
					cout << "Xoa phan tu cuoi thanh cong\n";
					cout << "Danh sach sau khi xoa:\n";
					Output();
				}
				break;
			case 8:
				cout << "Nhap phan tu can tim trong danh sach: \n";
				cin >> z;
				if (Sad(z) == 0)
					cout << "Danh sach rong khong the thuc hien\n";
				else
				{
					cout << "Tim thay phan tu " << z << " trong danh sach va xoa thanh cong\n";
					cout << "Danh sach sau khi tim va xoa thanh cong: " << "\n" ;
					output();
				}
				break;
			case 9:
				cout << "Danh sach sau khi duoc sap xep tang dan: " << "\n" ;
				SapXep();
				Output();
				break;
			default:
				break;
		}
	} while (chon != 10);
	system("pause");
	return 0;
}
