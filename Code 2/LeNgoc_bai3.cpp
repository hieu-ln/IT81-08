//#include<iostream>
//#include<stdio.h>
//#include<iomanip>
//using namespace std;
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *first;
//void init()
//{
//	first =NULL;
//}
//void insert_last(int x)
//{
//	Node *p=new Node;
//	p->info=x;
//	p->link=NULL;
//	if(first==NULL)
//		first=p;
//	else
//	{
//		Node *q=first;
//		while(q->link!=NULL)
//		{
//			q=q->link;
//		}
//		q->link=p;
//	}
//}
//void Create_list()
//{
//	Node *p;
//	p=first;
//	while(p!=NULL)
//	{
//		cout<<setw(5)<<p->info;
//		p=p->link;
//	}
//	cout<<endl;
//}
//Node *Search( int x )
//{
//	Node*p=first;
//	while(p!=NULL && p->info!=x)
//	{
//		p=p->link;
//	}
//	return p;
//}
//void insert_first(int x)
//{
//	Node *p=new Node;
//	p->info=x;
//	p->link=first;
//	first=p;
//}
//int del_first(int x)
//{
//	if(first!=NULL)
//	{
//		Node *p=first;
//		first=first->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//
//int del_last(int x)
//{
//	if(first!=NULL)
//	{
//		Node *p,*q;
//		p=first;
//		q=first;
//		while(p->link!=NULL)
//		{
//			q=p;
//			p=p->link;
//		}
//		if(p!=first)
//			q->link=NULL;
//		else
//			first=NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int searchanddelete(int x)
//{
//	if(first!=NULL)
//	{
//		Node *p,*q;
//		p=first;
//		q=first;
//		while(p->info!= x && p->link!=NULL)
//		{
//			q=p;
//			p=p->link;
//		}
//		if(p!=first && p->link!=NULL)
//		{
//			if(p->link!=NULL)
//				q->link=p->link;
//			else
//				q->link=NULL;
//			delete p;
//			return 1;
//		}
//		else if(p->link==NULL && p->info==x)
//		{
//			q->link=NULL;
//			delete p;
//			return 1;
//		}
//		else
//			return 0;
//	}
//	return 0;
//}
////cau3.10 sap xep danh sach co thu tu tang dan
////void ascend()
////{
////	Node *p=first,*q;
////	while(p->link!=NULL)
////	{
////		q=p->link;//q=p+i
////		while(q!=NULL)
////			if(p->info > q->info)
////			{
////				int temp=p->info;
////				p->info=q->info;
////				q->info=temp;
////			}
////	}
////}
////void descend()
////{
////Node *p=first,*q;
////	while(p->link!=NULL)
////	{
////		q=p->link;
////		while(q!=NULL)
////			if(p->info < q->info)
////			{
////				int temp=p->info;
////				p->info=q->info;
////				q->info=temp;
////			}
////	}
////}
//int main()
//{
//	int choice=0;
//	int x,i,n;
//	Node *p;
//	system("cls");
//	cout<<"------- BAI TAP 3, CHUONG 2, DANH SACH LKD -------"<<endl;
//	cout<<"1.Khoi tao danh sach LKD rong"<<endl;
//	cout<<"2.Them phan tu co gia tri x vao dau danh sach"<<endl;
//	cout<<"3.Them phan tu co gia tri x vao cuoi danh sach"<<endl;
//	cout<<"4.Xoa phan tu o dau danh sach"<<endl;
//	cout<<"5.Xoa phan tu o cuoi danh sach"<<endl;
//	cout<<"6.Xuat DSLKD"<<endl;
//	cout<<"7.Tim phan tu co gia tri x trong danh sach"<<endl;
//	cout<<"8.Tim phan tu voi gia tri x va xoa neu tim thay"<<endl;
//	cout<<"9.Sap xep danh sach tang dan"<<endl;
//	cout<<"10.Sap xep danh sach giam dan"<<endl;
//	cout<<"11.Thoat"<<endl;
//
//	do{
//		cout<<"Nhap lua chon: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init();
//				cout<<"Khoi tao DSLKD thanh cong!!"<<endl;
//				break;
//			case 2:
//				cout<<"Nhap gia tri x can them vao dau: ";
//				cin>>x;
//				insert_first(x);
//				cout<<"Danh sach sau khi them: ";
//				Create_list();
//				break;
//			case 3:
//				cout<<"Nhap gia tri x can them vao cuoi: ";
//				cin>>x;
//				insert_last(x);
//				cout<<"Danh sach sau khi them: ";
//				Create_list();
//				break;
//			case 4:
//				i=del_first(x);
//				if(i==0)
//					cout<<"Danh sach rong!!"<<endl;
//				else
//				{
//
//					cout<<"Xoa thanh cong!!"<<endl;
//					cout<<"Danh sach sau khi xoa: ";
//					Create_list();
//				}
//				break;
//			case 5:
//				i=del_last(x);
//				if(i==0)
//					cout<<"Danh sach rong!!"<<endl;
//				else
//				{
//					cout<<"Da xoa thanh cong!!"<<endl;
//					cout<<"Danh sach sau khi xoa: ";
//					Create_list();
//				}
//				break;
//			case 6:
//				cout<<"danh sach hien tai: "<<endl;
//				Create_list();
//				break;
//			case 7:
//				cout<<"Nhap gia tri can tim: ";
//				cin>>x;
//				p=Search(x);
//				if(p!=NULL)
//					cout<<"FOUND"<<x<<" !!"<<endl;
//				else
//					cout<<"NOT FOUND "<<x<<" !!"<<endl;
//				break;
//			case 8:
//				cout<<"Nhap gia tri can tim: ";
//				cin>>x;
//				i=searchanddelete(x);
//				if(i==0)
//					cout<<"NOT FOUND!!!"<<endl;
//				else
//				{
//					cout<<"Tim thay "<<x<<" va da xoa thanh cong!!"<<endl;
//					cout<<"Cap nhat lai danh sach: ";
//					Create_list();
//				}
//				break;
//			/*case 9:
//				cout<<"Danh sach theo thu tu tang dan: ";
//				ascend();
//				Create_list();
//				break;
//			case 10:
//				cout<<"Danh sach theo thu tu giam dan: ";
//				descend();
//				Create_list();
//				break;*/
//			case 11:
//				cout<<"Exit"<<endl;
//				break;
//			default:
//					break;
//		}
//	} while(choice!=11);
//	system("pause");
//	return 0;
//}
