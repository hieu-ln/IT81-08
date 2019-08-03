#include <iostream>
using namespace std;
int count=10;
struct Node{
	int info;
	Node *left;
	Node *right;
};
Node *root;
void tree_empty()
{
	root=NULL;
}
void out(Node *p,int space)
{
	if(p==NULL)
		return;
	space=space + count;
	out(p->right,space);
	cout<<endl;
	for(int i=count;i<space;i++)
		cout<<" ";
	cout<<p->info<<endl;
	out(p->left,space);
}
void process_out()
{
	out(root,0);
}
Node *search (Node *p,int x)
{
	while(p!=NULL)
	{
		if(p->info==x)
			return p;
		else
			if(p->info>x)
				p=p->left;
			else
				p=p->right;
	}
	return NULL;
}
void insert( Node *&p, int x)
{
	if(p==NULL)
	{
		p=new Node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if(p->info==x)
			return;
		else if(p->info>x)
			return insert(p->left,x);
		else
			return insert(p->right,x);
	}
}
void LNR(Node *p)
{
	if(p!=NULL)
	{
		LNR(p->left);
		cout<<p->info<<" ";
		LNR(p->right);
	}
}
void NLR( Node *p)
{
	if(p!=NULL)
	{
		cout<<p->info<<" ";
		NLR(p->left);
		NLR(p->right);
	}
}
void LRN( Node *p)
{
	if(p!=NULL)
	{
		LRN(p->left);
		LRN(p->right);
		cout<<p->info<<" ";
	}
}
void searchstandfor( Node *&p,Node *&q)
{
	if(q->left==NULL)
	{
		p->info=q->info;
		p=q;
		q=q->right;
	}
	else
		searchstandfor(p,q->left);
}

int del( Node *&p, int x)
{
	if(p==NULL)
		return 0;
	if(p->info==x)
	{
		Node *q=p;
		if(p->left ==NULL)
			p=p->right;
		else if(p->right==NULL)
			p=p->left;
		else 
			searchstandfor(q,p->right);
		delete q;
		return 1;
	}
	if(p->info<x)
		return del(p->right,x);
	if(p->info>x)
		return del(p->left,x);
}
int countnode( Node *p)
{
	if(p==NULL)
		return 0;
	else
		return 1+countnode(p->left)+countnode(p->right);
}
int searchmax( Node *p)
{
	if(p==NULL)
		return INT_MIN;
	else
	{
		while(p->right !=NULL)
			p=p->right;
		return p->info;
	}
}
int countleft(Node *p)
{
	if(p==NULL || p->left==NULL)
		return 0;
	else
		return countleft(p->left);
}
int main()
{
	int x,i;
	int choice;
	cout<<"1.Khoi tao cay nhi phan"<<endl;
	cout<<"2.Them phan tu vao cay nhi phan"<<endl;
	cout<<"3.Tim phan tu vao cay nhi phan"<<endl;
	cout<<"4.Xoa node trong cay"<<endl;
	cout<<"5.Duyet theo NLR"<<endl;
	cout<<"6.Duyet theo LNR"<<endl;
	cout<<"7.Duyet theo LRN"<<endl;
	cout<<"8.Xuat cay nhi phan"<<endl;
	cout<<"9.Dem so node trong cay nhi phan"<<endl;
	cout<<"10.Tim node lon nhat trong cay"<<endl;
	cout<<"11.Dem so node ben trai cua cay"<<endl;
	cout<<"12.Exit"<<endl;
	do{
		cout<<"\nNhap lua chon de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Khoi tao cay nhi phan";
				tree_empty();
				break;
			case 2:
				cout<<"Nhap phan tu can them: ";
				cin>>x;
				insert(root,x);
				cout<<"Da them vao cay"<<endl;
				break;
			case 3:
				cout<<"Nhap phan tu can tim trong cay: ";
				cin>>x;
				if(search(root,x))
					cout<<"FOUND !"<<endl;
				else
					cout<<"NOT FOUND !"<<endl;
				break;
			case 4:
				cout<<"Nhap phan tu can xoa : ";
				cin>>x;
				if(del(root,x))
					cout<<"Xoa thanh cong !"<<endl;
				else 
					cout<<"Khong tim thay x de xoa !"<<endl;
				break;
			case 5:
				cout<<"Cay nhi phan duyet theo trinh tu NLR: "<<endl;
				NLR(root);
				break;
			case 6:
				cout<<"Cay nhi phan  duyet theo trinh tu LNR: "<<endl;
				LNR(root);
				break;
			case 7:
				cout<<"Cay nhi phan duyet theo trinh tu LRN: "<<endl;
				LRN(root);
				break;
			case 8:
				cout<<"Cay nhi phan: "<<endl;
				process_out();
			case 9:
				cout<<"So node trong cay co :"<<countnode(root)<<endl;
				break;
			case 10:
				cout<<"Node lon nhat cua cay nhi phan: "<<searchmax(root)<<endl;
				break;
			case 11:
				cout<<"So node ben nhanh trai cua cay : "<<countleft(root)<<endl;
				break;
			case 12:
				cout<<"EXIT"<<endl;
				break;
			default:
				break;
		}
	}while(choice!=11);
	system("pause");
	return 0;
}