#include <iostream>
using namespace std;

//Cau 4.1
struct Node {
	int info;
	Node *link;
};
Node *first;

//Cau 4.2
void init()
{
	first = NULL;
}

void insert_last(int x)
{
	Node *p = new Node;
	p->info = x;
	p->link = NULL;
	if (first != NULL)
	{
		Node *q = first;
		while (q->link != NULL)
			q = q->link;
		q->link = p;
	}
	else
	{
		first = p;
	}
}

int check_inc()//kt tang dan
{
	int check = 1;
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		while (p->link != NULL && check==1)
		{
			q = p->link;
			if (p->info > q->info)
				check = 0;
			p = p->link;
		}
	}
	else
		check = 0;
	return check;
}

int check_desc()//kt giam dan
{
	if (first != NULL)
	{
		Node *p, *q;
		p = first;
		while (p->link != NULL)
		{
			q = p->link;
			if (p->info < q->info)
				return 0;
		}
		return 1;
	}
	else
		return 1;
}

//Cau 4.3 (tang dan)
int insert_inc(int x)
{
	int i = check_inc();
	if (i == 1)
	{
		Node *p = new Node, *q, *tam = new Node;
		p->info = x;
		q = first;
		while (q->link != NULL)
		{
			tam = q->link;
			if ((q->info < p->info) && (p->info < tam->info))//them giua ds
			{
				q->link = p;
				p->link = tam;
				return 1;
			}
			else
			{
				if ((q == first) && (p->info < q->info))//them dau ds
				{
					p->link = q;
					first = p;
					return 1;
				}
			}
			q = q->link;
		}
		if ((q->link == NULL) && (p->info > q->info))
		{
			q->link = p;
			p->link = NULL;
			return 1;
		}
		return 0;
	}
	else
		return 0;
}

//Cau 4.3 (giam dan)
int insert_desc(int x)
{
	int i = check_desc();
	if (i == 1)
	{
		Node *p = new Node, *q, *tam = new Node;
		p->info = x;
		q = first;
		while (q->link != NULL)
		{
			tam = q->link;
			if ((q->info > p->info) && (p->info > tam->info))//them giua ds
			{
				q->link = p;
				p->link = tam;
				return 1;
			}
			else
			{
				if ((q == first) && (p->info > q->info))//them dau ds
				{
					p->link = q;
					first = p;
					return 1;
				}
			}
			q = q->link;
		}
		if ((q->link == NULL) && (p->info < q->info))
		{
			q->link = p;
			p->link = NULL;
			return 1;
		}
		return 0;
	}
	else
		return 0;
}

//Cau 4.4
void out_list()
{
	Node *p;
	p = first;
	if (p == NULL)
		cout << "Danh sach rong!";
	while (p != NULL)
	{
		cout << p->info << " ";
		p = p->link;
	}
}

//Cau 4.5(tang dan)
int search_inc(int x)
{
	int i = check_inc();
	int check = 0;
	if (first != NULL)
	{
		if (i == 1)
		{
			Node *p;
			p = first;
			while (p->link != NULL && p->info != x)
			{
				p = p->link;
			}
			if (p->info == x)
				check = 1;
		}
	}
	return check;
}

//Cau 4.5(giam dan)
int search_desc(int x)
{
	int i = check_desc();
	int check = 0;
	if (first != NULL)
	{
		if (i == 1)
		{
			Node *p;
			p = first;
			while (p->link != NULL && p->info != x)
			{
				p = p->link;
			}
			if (p->info == x)
				check = 1;
		}
	}
	return check;
}

//Cau 4.6(tang dan)
int search_delete_inc(int x)
{
	int i = check_inc();
	if (first != NULL)
	{
		if (i == 1)
		{
			Node *p, *q;
			q = first;
			p = first;
			while (p->info != x && p->link != NULL)
			{
				q = p;
				p = p->link;
			}
			if (p != first && p->link != NULL)//giua ds
			{
				q->link = p->link;
				delete p;
				return 1;
			}
			else
			{
				if (p == first)//dau ds
				{
					first = p->link;
					delete p;
					return 1;
				}
				else
				{
					if (p->link == NULL && p->info == x)//cuoi ds
					{
						q->link = NULL;
						delete p;
						return 1;
					}
					else
						return 0;
				}
			}
		}
		else
			return 0;
	}
	return 0;
}

//Cau 4.6(giam dan)
int search_delete_desc(int x)
{
	int i = check_desc();
	if (first != NULL)
	{
		if (i == 1)
		{
			Node *p, *q;
			q = first;
			p = first;
			while (p->info != x && p->link != NULL)
			{
				q = p;
				p = p->link;
			}
			if (p != first && p->link != NULL)//giua ds
			{
				q->link = p->link;
				delete p;
				return 1;
			}
			else
			{
				if (p == first)//dau ds
				{
					first = p->link;
					delete p;
					return 1;
				}
				else
				{
					if (p->link == NULL && p->info == x)//cuoi ds
					{
						q->link = NULL;
						delete p;
						return 1;
					}
					else
						return 0;
				}
			}
		}
		else
			return 0;
	}
	return 0;
}

int main()
{
	int x, choice = 0, i;
	/*Node *p;*/

	cout << "---Bai 4, Chuong 2, DANH SACH LIEN KET DON---" << endl
		<< "1. Khoi tao DSLK don rong" << endl
		<< "2. Them phan tu vao cuoi danh sach (theo thu tu tang dan)" << endl
		<< "3. Them phan tu vao cuoi danh sach (theo thu tu giam dan)" << endl
		<< "4. Them phan tu co gia tri x vao vi tri phu hop trong danh sach (tang dan)" << endl
		<< "5. Them phan tu co gia tri x vao vi tri phu hop trong danh sach (giam dan)" << endl
		<< "6. Tim 1 phan tu co gia tri x trong danh sach (tang dan)" << endl
		<< "7. Tim 1 phan tu co gia tri x trong danh sach (giam dan)" << endl
		<< "8. Tim va xoa 1 phan tu trong danh sach (neu co)(tang dan)" << endl
		<< "9. Tim va xoa 1 phan tu trong danh sach (neu co)(giam dan)" << endl
		<< "10.Xuat danh sach" << endl
		<< "11.Thoat" << endl;

	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			init();
			cout << "Khoi tao DSLK Don rong thanh cong!" << endl;
			break;
		case 2:
			cout << "\nVui long nhap gia tri x=";
			cin >> x;
			insert_last(x);
			cout << "Da nhap danh sach thanh cong!";
			cout << "\nDanh sach hien tai: ";
			out_list();
			break;
		case 3:
			cout << "\nVui long nhap gia tri x=";
			cin >> x;
			insert_last(x);
			cout << "Da nhap danh sach thanh cong!";
			cout << "\nDanh sach hien tai: ";
			out_list();
			break;
		case 4:
			cout << "Vui long nhap gia tri x=";
			cin >> x;
			i = insert_inc(x);
			if (i == 1)
			{
				cout << "Da them thanh cong x=" << x << " vao danh sach!";
				cout << "\nDanh sach sau khi them: ";
				out_list();
			}
			else
				cout << "Danh sach rong!";
			break;
		case 5:
			cout << "Vui long nhap gia tri x=";
			cin >> x;
			i = insert_desc(x);
			if (i == 1)
			{
				cout << "Da them thanh cong x=" << x << " vao danh sach!";
				cout << "\nDanh sach sau khi them: ";
				out_list();
			}
			else
				cout << "Danh sach rong!";
			break;
		case 6:
			cout << "Vui long nhap gia tri x=";
			cin >> x;
			i = search_inc(x);
			if (i == 1)
				cout << "Da tim thay x=" << x << " trong danh sach!";
			else
				cout << "Tim kiem khong thanh cong!";
			break;
		case 7:
			cout << "Vui long nhap gia tri x=";
			cin >> x;
			i = search_desc(x);
			if (i == 1)
				cout << "Da tim thay x=" << x << " trong danh sach!";
			else
				cout << "Tim kiem khong thanh cong!";
			break;
		case 8:
			cout << "Vui long nhap gia tri x=";
			cin >> x;
			i = search_delete_inc(x);
			if (i == 1)
			{
				cout << "Da tim thay va xoa thanh cong gia tri x=" << x << "!";
				cout << "\nDanh sach sau khi xoa: ";
				out_list();
			}
			else
				cout << "Khong thanh cong!";
			break;
		case 9:
			cout << "Vui long nhap gia tri x=";
			cin >> x;
			i = search_delete_desc(x);
			if (i == 1)
			{
				cout << "Da tim thay va xoa thanh cong gia tri x=" << x << "!";
				cout << "\nDanh sach sau khi xoa: ";
				out_list();
			}
			else
				cout << "Khong thanh cong!";
			break;
		case 10:
			cout << "Danh sach hien tai: ";
			out_list();
			break;
		case 11:
			cout << "Goodbye!";
			break;
		default:
			cout << "Loi nhap lieu!";
			break;
		}
	} while (choice != 11);

	cout << endl;
	system("pause");
	return 0;
}