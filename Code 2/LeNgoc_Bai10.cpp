//#include <iostream>
//using namespace std;
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *sp;
//void init()
//{
//	sp=NULL;
//}
//void Push(int &x)
//{
//	Node *p=new Node;
//	p->info=x;
//	p->link=sp;
//	sp=p;
//}
//int Pop(int &x)
//{
//	if(sp!=NULL)
//	{
//		Node*p=sp;
//		x=p->info;
//		sp=p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//int isEmpty()
//{
//	if(sp==NULL)
//		return 1;
//	return 0;
//}
//int Convert(int so)
//{
//	init();
//	int np=0;
//	while(so!=0)
//	{
//		int du=so%2;
//		(Push(du));
//		so/=2;
//	}
//	while(!isEmpty())
//	{
//		int x;
//		if(Pop(x))
//			np=np*10+x;
//	}
//	return np;
//}
//void output()
//{
//	Node *p;
//	p=sp;
//	while(p!=NULL)
//	{
//		cout<<p->info<<endl;
//		p=p->link;
//	}
//	cout<<endl;
//}
//int main()
//{
//	int x,i;
//	int choice=0;
//	system("cls");
//	cout<<"1.Khoi tao Stack"<<endl;
//	cout<<"2.Kiem tra Stack rong"<<endl;
//	cout<<"3.Them 1 phan tu co gia tri x vao Stack"<<endl;
//	cout<<"4.Xoa phan tu trong Stack"<<endl;
//	cout<<"5.Danh sach Stack hien tai"<<endl;
//	cout<<"6.Chuyen so tu he thap phan sang he nhi phan"<<endl;
//	cout<<"7.Thoat"<<endl;
//	do{
//		cout<<"Nhap lua cho de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init();
//				cout<<"Khoi tao Stack thanh cong!"<<endl;
//				break;
//			case 2:
//				i=isEmpty();
//				if(i==1)
//					cout<<"Stack da nhap du lieu!"<<endl;
//				else
//					cout<<"Stack rong!"<<endl;
//				break;
//			case 3:
//				cout<<"Nhap phan tu can them: ";
//				cin>>x;
//				i=Push(x);
//				if(i==1)
//					cout<<"DONE"<<endl;
//				break;
//			case 4:
//				i=Pop(x);
//				if(i!=0)
//					cout<<"DONE !"<<endl;
//				else
//					cout<<"Stack khong co phan tu de xoa !"<<endl;
//				break;
//			case 5:
//				cout<<"Stack hien tai: ";
//				output();
//				break;
//			case 6:
//				int np;
//				cout<<"Nhap gia tri he thap phan can chuyen: ";
//				cin>>np;
//				cout<<"Gia tri nhi phan tuong ung la: "<<Convert(np)<<endl;
//				break;
//			default:
//				break;
//		}
//	}while(choice!=7);
//	system("pause");
//	return 0;
//}
