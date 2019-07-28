//#include <iostream>
//using namespace std;
//
//#define COUNT 10
//
////Cau 1.1
//struct Node
//{
//	int info;
//	Node *left;
//	Node *right;
//};
//Node *root;
//
////Cau 1.2
//void tree_empty()
//{
//	root=NULL;
//}
//
////Cau 1.3
//void InsertNode(Node *&p,int x)
//{
//	if(p==NULL)
//	{
//		p=new Node;
//		p->info=x;
//		p->left=NULL;
//		p->right=NULL;
//	}
//	else
//	{
//		if(p->info==x)
//			return;
//		else
//		{
//			if(p->info>x)
//				return InsertNode(p->left,x);
//			else
//				return InsertNode(p->right,x);
//		}
//	}
//}
//
////Cau 1.4
//Node *search(Node *p,int x)
//{
//	if(p!=NULL)
//	{
//		//cout<<p->info;
//		if(p->info==x)
//			return p;
//		else
//		{
//			if(x>p->info)
//				return search(p->right,x);
//			else
//				return search(p->left,x);
//		}
//	}
//	return NULL;
//}
//
////Cau 1.5
//void searchStandFor(Node *&p, Node *&q)
//{
//	if(q->left==NULL)
//	{
//		p->info=q->info;
//		p=q;
//		q=q->right;
//	}
//	else
//		searchStandFor(p,q->left);
//}
//
//int Delete(Node *&T, int x)
//{
//	if(T==NULL)
//		return 0;
//	if(T->info==x)
//	{
//		Node *p=T;
//		if(T->left==NULL)
//			T=T->right;
//		else
//		{
//			if(T->right==NULL)
//				T=T->left;
//			else
//				searchStandFor(p,T->right);
//			delete p;
//			return 1;
//		}
//	}
//	if(T->info<x)
//			return Delete(T->right,x);
//	if(T->info>x)
//			return Delete(T->left,x);
//}
//
////Cau 1.6
//void duyetNLR(Node *p)
//{
//	if(p!=NULL)
//	{
//		cout<<p->info<<"  ";
//		duyetNLR(p->left);
//		duyetNLR(p->right);
//	}
//}
//
////Cau 1.7
//void duyetLNR(Node *p)
//{
//	if(p!=NULL)
//	{
//		duyetLNR(p->left);
//		cout<<p->info<<"  ";
//		duyetLNR(p->right);
//	}
//}
//
////Cau 1.8
//void duyetLRN(Node *p)
//{
//	if(p!=NULL)
//	{
//		duyetLRN(p->left);
//		duyetLRN(p->right);
//		cout<<p->info<<"  ";
//	}
//}
//
////Xuat
//void print2DUtil(Node *p, int space)
//{
//	//Base case
//	if(p==NULL)
//		return;
//	
//	//Increase distance between levels
//	space+=COUNT;
//
//	//Process right child first
//	print2DUtil(p->right,space);
//
//	//print current node after space
//	//count
//	cout<<endl;
//	for(int i=COUNT;i<space;i++)
//		cout<<"  ";
//	cout<<p->info<<"\n";
//
//	//Process left child
//	print2DUtil(p->left,space);
//}
//
////Wrapper over tree
//void process_tree()
//{
//	print2DUtil(root,0);
//}
//
//int main()
//{
//	int choice=0,x,i;
//	Node *p;
//
//	cout<<"---Bai 1 - CHUONG 4, CAY NHI PHAN TIM KIEM---"<<endl;
//	cout<<"1.Khoi tao cay nhi phan tim kiem rong"<<endl
//		<<"2.Them 1 phan tu x vao cay"<<endl
//		<<"3.Tim 1 phan tu x trong cay"<<endl
//		<<"4.Xoa 1 phan tu x trong cay"<<endl
//		<<"5.Duyet cay theo thu tu NLR"<<endl
//		<<"6.Duyet cay theo thu tu LNR"<<endl
//		<<"7.Duyet cay theo thu tu LRN"<<endl
//		<<"8.Xuat cay"<<endl
//		<<"9.Thoat"<<endl;
//
//	do{
//		cout<<"\nVui long nhap so de thuc hien: ";
//		cin>>choice;
//
//		switch(choice)
//		{
//		case 1:
//			tree_empty();
//			cout<<"Da khoi tao cay NPTK thanh cong!";
//			break;
//		case 2:
//			cout<<"Vui long nhap gia tri x=";
//			cin>>x;
//			InsertNode(root, x);
//			cout<<"Cay NPTK sau khi them:"<<endl;
//			process_tree();
//			break;
//		case 3:
//			cout<<"Vui long nhap gia tri x=";
//			cin>>x;
//			p=search(root,x);
//			if(p!=NULL)
//				cout<<"Tim thay gia tri x="<<x<<"!";
//			/*else
//				cout<<"Khong tim thay!";*/
//			break;
//		case 4:
//			cout<<"Vui long nhap gia tri x=";
//			cin>>x;
//			i=Delete(root,x);
//			if(i==0)
//				cout<<"Xoa khong thanh cong!";
//			else
//			{
//				cout<<"Da tim thay gia tri x="<<x<<"trong cay NPTK"<<endl;
//				cout<<"Cay NPTK sau khi xoa: "<<endl;
//				process_tree();
//			}
//			break;
//		case 5:
//			cout<<"Cay NPTK duyet theo NLR: ";
//			duyetNLR(root);
//			break;
//		case 6:
//			cout<<"Cay NPTK duyet theo LNR: ";
//			duyetLNR(root);
//			break;
//		case 7:
//			cout<<"Cay NPTK duyet theo LRN: ";
//			duyetLRN(root);
//			break;
//		case 8:
//			cout<<"Cay NPTK:"<<endl;
//			process_tree();
//			break;
//		case 9:
//			cout<<"Goodbye!";
//			break;
//		default:
//			cout<<"Loi nhap lieu!";
//			break;
//		}
//	}while(choice!=9);
//
//	system("pause");
//	return 0;
//}