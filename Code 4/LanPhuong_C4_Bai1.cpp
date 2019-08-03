//#include <iostream>
//using namespace std;
//struct Node
//#define COUNT 10
//{
//	int infor;
//	Node *left, *right;
//};
//Node *root;
//void Emty_Tree()
//{
//	root = NULL;
//}
//void Insert_Leaf(Node *&p, int x)
//{
//	if(p == NULL)
//	{
//		p = new Node;
//		p ->infor = x;
//		p ->left = NULL;
//		p ->right = NULL;
//	}
//	else
//	{
//		if(p->infor==x)
//		{
//			cout<<"Da co node gia tri x"<<endl;
//			return;
//		}
//		else
//			if(p->infor>x)
//				return Insert_Leaf(p->left,x);
//			else
//				return Insert_Leaf(p->right,x);
//	}
//}
//Node *Search(Node *p, int x)
//{
//	if(p!=NULL)
//	{
//		if(p->infor==x)
//			return p;
//		else
//			if(x>p->infor)
//				return Search(p->right,x);
//			else
//				return Search(p->left,x);
//	}
//	return NULL;
//}
//void SearchStandFor(Node *&p, Node *&q)
//{
//	if(q ->left== NULL)
//	{
//		p ->infor== q->infor;
//		q = p;
//		q = q ->right;
//	}
//	else
//		SearchStandFor(p, q ->left);
//}
//int Delete(Node *&T, int x)
//{
//	if(T==NULL)
//		return 0;
//	if(T->infor==x)
//	{
//		Node *p = T;
//		if(T ->left ==NULL)
//			T = T->right;
//		else
//			if(T ->right == NULL)
//				T = T->left;
//			else
//				SearchStandFor(p, T->right);
//		delete p;
//		return 1;
//	}
//	if(T ->infor<x)
//		Delete(T -> right,x);
//	if(T ->infor>x)
//		Delete(T ->left,x);
//}
//void LNR(Node *p)
//{
//	if(p!=NULL)
//	{
//		LNR(p->left);
//		cout<<p->infor<<"     ";
//		LNR(p->right);
//	}
//}
//void NLR(Node *p)
//{
//	if(p!=NULL)
//	{
//		cout<<p ->infor<<"    ";
//		LNR(p->left);
//		LNR(p->right);
//	}
//}
//void LRN(Node *p)
//{
//	if(p!=NULL)
//	{
//		LRN(p->left);
//		LRN(p->right);
//		cout<<p ->infor<<"    ";
//	}
//}
//void PrintTree(Node *p, int space)
//{
//	if(p == NULL)
//		return;
//	space += COUNT;
//	PrintTree(p->right, space);
//	cout<<endl;
//	for ( int i = COUNT; i < space; i++)
//		cout<<"   ";
//	cout<<p ->infor<<"\n";
//
//}
//void Process_Tree()
//{
//	PrintTree(root,0);
//}
//int main()
//{
//	Node *p = new Node;
//	int choice, x;
//	cout<<"BTTH chuong 4"<<endl;
//	cout<<"1.Khoi tao cay rong"<<endl;
//	cout<<"2.Them 1 phan tu vao cay"<<endl;
//	cout<<"3.Tim 1 phan tu trong cay"<<endl;
//	cout<<"4.Xoa 1 phan tru trong cay"<<endl;
//	cout<<"5.Duyet cay theo thu tu NLR"<<endl;
//	cout<<"6.Duyet cay theo thu tu LNR"<<endl;
//	cout<<"7.Duyet cay theo thu tu LRN"<<endl;
//	do
//	{
//		cout<<"\nMoi nhap so de thao tac: ";
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			Emty_Tree();
//			cout<<"Khoi tao cay rong thanh cong";
//			break;
//		case 2:
//			cout<<"Moi nhap phan tu can de them vao cay: ";
//			cin>>x;
//			Insert_Leaf(root,x);
//			cout<<"Them vao cay thanh cong"<<endl;
//			cout<<"Cay bay gio la"<<endl;
//			Process_Tree();
//			break;
//		case 3:
//			cout<<"Moi nhap phan tu muon tim trong cay: ";
//			cin>>x;
//			if(Search(root,x)==NULL)
//				cout<<"Phan tu khong co trong cay"<<endl;
//			else
//				cout<<"Tim thay "<<x<<" trong cay"<<endl;
//			break;
//		case 4:
//			cout<<"Moi nhap phan tu can xoa: ";
//			cin>>x;
//			if(Delete(p,x)== NULL)
//				cout<<"Phan tu khong co trong cay"<<endl;
//			else
//			{	cout<<"Xoa phan tu "<<x<<" tren cay thanh cong"<<endl;
//				cout<<"Cay nhi phan hien tai"<<endl;
//				Process_Tree();
//			}
//			break;
//		case 5:
//			cout<<"Cay duyet theo thu tu NLR la: "<<endl;
//			NLR(root);
//			break;
//		case 6:
//			cout<<"Cay duyet theo thu tu LNR la: "<<endl;
//			LNR(root);
//			break;
//		case 7:
//			cout<<"Cay duyet theo thu tu LRN la: "<<endl;
//			LRN(root);
//			break;
//		}
//	}while(choice !=7);
//	system ("pause");
//	return 0;
//
//}