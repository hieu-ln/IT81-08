//#include <iostream>
//using namespace std;
//
////Cau 3.1
//struct Node {
//	int info;
//	Node *link;
//};
//Node *first;
//
////Cau 3.2
//void init()
//{
//	first = NULL;
//}
//
////Cau 3.3
//void out_list()
//{
//	Node *p;
//	p = first;
//	if (p == NULL)
//		cout << "Danh sach rong!";
//	while (p != NULL)
//	{
//		cout << p->info << " ";
//		p = p->link;
//	}
//}
//
////Cau 3.4
//Node * search(int x)
//{
//	Node *p;
//	p = first;
//	while (p->link != NULL && p->info != x)
//	{
//		p = p->link;
//	}
//	return p;
//}
//
////Cau 3.5
//void insert_first(int x)
//{
//	Node *p=new Node;
//	p->info=x;
//	p->link = first;
//	first = p;
//}
//
////Cau 3.6
//int delete_first()
//{
//	if (first != NULL)
//	{
//		Node *p;
//		p = first;
//		first = first->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//
//}
//
////Cau 3.7
//void insert_last(int x)
//{
//	Node *p=new Node;
//	p->info = x;
//	p ->link = NULL;
//	if (first != NULL)
//	{
//		Node *q = first;
//		while (q->link != NULL)
//			q = q->link;
//		q ->link = p;
//	}
//	else
//	{
//		first = p;
//	}
//}
//
////Cau 3.8
//int delete_last()
//{
//	if (first != NULL)
//	{
//		Node *p, *q;
//		p = first;
//		q = first;
//		while (p->link != NULL)
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p != first)
//			q->link = NULL;
//		else
//			first = NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
////Cau 3.9
//int search_delete(int x)
//{
//	if(first!=NULL)
//	{
//		Node *p,*q;
//		q = first;
//		p=first;
//		while (p->info != x && p->link != NULL)
//		{
//			q = p;
//			p = p->link;
//		}
//		if (p != first && p->link != NULL)//giua ds
//		{
//			q->link = p->link;
//			delete p;
//			return 1;
//		}
//		else
//		{
//			if (p == first)//dau ds
//			{
//				first = p->link;
//				delete p;
//				return 1;
//			}
//			else
//			{
//				if (p->link == NULL&&p->info==x)//cuoi ds
//				{
//					q->link = NULL;
//					delete p;
//					return 1;
//				}
//				else
//					return 0;
//			}
//		}
//	}
//	return 0;
//}
//
//void swap(Node *a, Node *b)
//{
//	Node *tam=new Node;
//	tam->info = a->info;
//	a->info = b->info;
//	b->info = tam->info;
//}
//
////Cau 3.9 (sap xep ds tang dan)
//void sort()
//{
//	Node *p, *q;
//	p = first;
//	//interchange sort
//	while (p != NULL)
//	{
//		q = p->link;
//		while (q != NULL)
//		{
//			if (q->info < p->info)
//				swap(p, q);
//			q = q->link;
//		}
//		p = p->link;
//	}
//}
//
////Cau 3.9 (sap xep ds giam dan)
//void sort_desc()
//{
//	Node *p, *q;
//	p = first;
//	//interchange sort
//	while (p != NULL)
//	{
//		q = p->link;
//		while (q != NULL)
//		{
//			if (q->info > p->info)
//				swap(p, q);
//			q = q->link;
//		}
//		p = p->link;
//	}
//}
//
//int main()
//{
//	int x,choice=0,i;
//	Node *p;
//
//	cout << "---Bai 3, Chuong 2, DANH SACH LIEN KET DON---" << endl
//		<< "1. Khoi tao DSLK don rong" << endl
//		<< "2. Xuat danh sach" << endl
//		<< "3. Tim 1 phan tu gia tri x trong danh sach" << endl
//		<< "4. Them 1 phan tu vao dau danh sach" << endl
//		<< "5. Xoa 1 phan tu dau danh sach" << endl
//		<< "6. Them 1 phan tu vao cuoi danh sach" << endl
//		<< "7. Xoa 1 phan tu cuoi danh sach" << endl
//		<< "8.Tim va xoa 1 phan tu trong danh sach (neu co)" << endl
//		<< "9.Sap xep DSLK don tang dan" << endl
//		<< "10.Sap xep DSLK don giam dan" << endl
//		<< "11.Thoat" << endl;
//
//	do {
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//		
//		switch (choice)
//		{
//		case 1:
//			init();
//			cout << "Khoi tao DSLK Don rong thanh cong!"<<endl;
//			break;
//		case 2:
//			cout << "Danh sach hien tai: ";
//			out_list();
//			break;
//		case 3:
//			cout << "Vui long nhap gia tri x=";
//			cin >> x;
//			p = search(x);
//			if (p != NULL)
//				cout << "Tim thay gia tri vua nhap!"<<endl;
//			else
//				cout << "Khong tim thay gia tri vua nhap!"<<endl;
//			break;
//		case 4:
//			cout << "Vui long nhap gia tri x=";
//			cin >> x;
//			insert_first(x);
//			cout << "Danh sach sau khi them: ";
//			out_list();
//			break;
//		case 5:
//			i = delete_first();
//			if (i == 1)
//			{
//				cout << "Da xoa thanh cong phan tu dau cua DSLK Don!" << endl;
//				cout << "Danh sach sau khi xoa: ";
//				out_list();
//			}
//			else
//				cout << "Danh sach rong, khong the xoa!";
//			break;
//		case 6:
//			cout << "Vui long nhap gia tri x=";
//			cin >> x;
//			insert_last(x);
//			cout << "Danh sach sau khi them: ";
//			out_list();
//			break;
//		case 7:
//			i = delete_last();
//			if (i == 1)
//			{
//				cout << "Da xoa phan tu cuoi DSLK Don!" << endl;
//				cout << "Danh sach sau khi xoa: ";
//				out_list();
//			}
//			else
//				cout << "Danh sach rong, khong the xoa!";
//			break;
//		case 8:
//			cout<< "Vui long nhap gia tri x=";
//			cin >> x;
//			i=search_delete(x);
//			if (i == 1)
//			{
//				cout << "Da tim thay va xoa thanh cong x=" << x << "!";
//				cout << "\nDanh sach da xoa: ";
//				out_list();
//			}
//			else
//				cout << "Khong tim thay phan tu co gia tri x=" << x << "!";
//			break;
//		case 9:
//			sort();
//			cout << "Danh sach sau khi sap xep theo thu tu tang dan: ";
//			out_list();
//			break;
//		case 10:
//			sort_desc();
//			cout << "Danh sach sau khi sap xep theo thu tu giam dan: ";
//			out_list();
//			break;
//		case 11:
//			cout << "Goodbye!";
//			break;
//		default:
//			cout << "Loi nhap lieu!";
//			break;
//		}
//	} while (choice != 11);
//
//	cout << endl;
//	system("pause");
//	return 0;
//}