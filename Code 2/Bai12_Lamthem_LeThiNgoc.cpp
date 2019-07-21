#include<iostream>
#include <iomanip>
using namespace std;
struct Node
{
	int info;
	Node*next,*previous;
};
Node*first,*last;
void init()
{
	first=NULL;
	last=NULL;
}
void process_list()
{
	Node *p;
	p=first;
	while(p!=NULL)
	{
		cout<<p->info<<endl;
		p=p->next;
	}
	cout<<endl;
}
void insert_first(int x)
{
	Node *p=new Node;
	p->info=x;
	p->next=first;
	p->previous=NULL;
	if(first!=NULL)
	{
		first->previous=p;
		last=p;
	}
	first=p;
}
void insert_last(int x)
{
	Node *p=new Node;
	p->info=x;
	p->next=NULL;
	p->previous=last;
	if(last!=NULL)
	{
		last->next=p;
		first=p;
	}
	last=p;
}
int Del_first()
{
	if(first!=NULL)
	{
		Node *p=first;
		first=first->next;
		delete p;
		if(first!=NULL)
			first->previous=NULL;
		else
			last=NULL;
		return 1;
	}
	return 0;
}
int Del_last()
{
	if(last!=NULL)
	{
		Node *p=last;
		last=last->previous;
		if(last!=NULL)
			last->next=NULL;
		else
			first=NULL;
		delete p;
		return 1;
	}
	return 0;
}
Node *search(int x)
{
	Node *p;
	p=first;
	while(p!=NULL && p->info!=x)
		p=p->previous;
	return p;
}
int Del(int x)
{
	Node *p=search(x);
	if(p==first)
	{
		if(Del_first())
			return 1;
		else
			return 0;
	}
	else if(p==last)
	{
		if(Del_last())
			return 1;
		else
			return 0;
	}
	else
	{
		Node *q,*r;
		q=p->previous;
		q->next=p->next;
		r=p->next;
		r->previous=q;
		delete p;
		return 1;
	}
	return 0;
}
//int searchandinsert(int x,int n)
//{
//	Node *p=search(x);
//	if(p!=NULL)
//	{
//		if(p==first)
//			insert_first(n);
//		else if(p==last)
//			insert_last(n);
//		else
//		{
//			Node *truocx,*saux;
//			x=truocx->next;
//			saux->previous=x;
//		}
//		return 1;
//	}
//	else
//	{
//		Node*k=search(n);
//		if(k>n)
//		{
//			Node *truocn,*saun;
//			n=truocn->next;
//			saun->previous=n;
//			return 1;
//		}
//	}
//	return 0;	
//}
int main()
{
	int i,x;
	int choice;
	system("cls");
	cout<<"1.Tao danh sach lien ket doi rong"<<endl;
	cout<<"2.Xuat ca phan tu trong danh sach"<<endl;
	cout<<"3.Them phan tu vao dau danh sach"<<endl;
	cout<<"4.Them phan tu vao cuoi danh sach"<<endl;
	cout<<"5.Xoa phan tu o dau danh sach"<<endl;
	cout<<"6.Xoa phan tu o cuoi danh sach"<<endl;
	cout<<"7.Tim va xoa 1 phan tu neu tim duoc trong danh sach"<<endl;
	cout<<"8.Tim"<<endl;
	cout<<"9.Danh sach hien tai"<<endl;
	cout<<"10.EXIT"<<endl;
	do
	{
		cout<<"Choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				init();
				cout<<"Danh sach lien ket kep da duoc khoi tao"<<endl;
				break;
			case 2:
				cout<<"Danh sach phan tu"<<endl;
				process_list();
				break;
			case 3:
				cout<<"Nhap phan tu can them vao dau danh sach: ";
				cin>>x;
				insert_first(x);
				break;
			case 4:
				cout<<"Nhap phan tu can them vao cuoi danh sach: ";
				cin>>x;
				insert_last(x);
				break;
			case 5:
				i=Del_first();
				if(i!=0)
				{
					cout<<"Da xoa phan tu nam dau danh sach"<<endl;
					cout<<"Danh sach duoc cap nhat: "<<endl;
					process_list();
				}
				else
					cout<<"Danh sach rong, khong co phan tu de xoa"<<endl;
				break;
			case 6:
				i=Del_last();
				if(i!=0)
				{
					cout<<"Da xoa phan tu nam cuoi danh sach"<<endl;
					cout<<"Danh sach hien tai: "<<endl;
					process_list();
				}
				else
					cout<<"Danh sach rong, khong co phan tu de xoa"<<endl;
				break;
			case 7:
				cout<<"Nhap gia tri x can tim va xoa: ";
				cin>>x;
				i=Del(x);
				if(i!=0)
					cout<<"Xoa thanh cong !!"<<endl;
				else
					cout<<"Khong tim thay trong danh sach !!"<<endl;
				break;
			case 8:
				cout<<"Nhap phan tu x can tim: ";
				cin>>x;
				int n;
				cout<<"Nhap phan tu can them sau khi tim x: ";
				cin>>n;
				//i=searchandinsert(x,n);
				//if(i!=0)
				//	cout<<"Them thanh cong !"<<endl;
				//else
				//	cout<<"Loi ki thuat :)"<<endl;
				//break;
			case 9:
				cout<<"Danh sach hien tai: "<<endl;
				process_list();
				break;
			default:
				break;
		}
	}while(choice!=10);
	system("pause");
	return 0;
}