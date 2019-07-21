//#include<iostream>
//using namespace std;
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *front,*rear;
//void init()
//{
//	front=NULL;
//	rear=NULL;
//}
//int isEmpty()
//{
//	if(front==NULL)
//		return 1;
//	return 0;
//}
//void Push(int x)
//{
//	Node *p=new Node;
//	p->info=x;
//	p->link=NULL;
//	if(rear==NULL)
//		front=p;
//	else
//		rear->link=p;
//	rear=p;
//}
//int Pop(int &x)
//{
//	if(front!=NULL)
//	{
//		Node*p=front;
//		x=p->info;
//		front=front->link;
//		if(front==NULL)
//			rear=NULL;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void output()
//{
//	Node *p;
//	p=rear;
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
//	cout<<"1.Khoi tao queue"<<endl;
//	cout<<"2.Kiem tra queue rong"<<endl;
//	cout<<"3.Them 1 phan tu co gia tri x vao queue"<<endl;
//	cout<<"4.Xoa phan tu trong queue"<<endl;
//	cout<<"5.Queue hien tai: "<<endl;
//	cout<<"6.Thoat"<<endl;
//	do{
//		cout<<"Nhap lua cho de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init();
//				cout<<"Khoi tao Queue thanh cong!"<<endl;
//				break;
//			case 2:
//				i=isEmpty();
//				if(i==1)
//					cout<<"Queue da nhap du lieu!"<<endl;
//				else
//					cout<<"Queue rong!"<<endl;
//				break;
//			case 3:
//				cout<<"Nhap phan tu can them: ";
//				cin>>x;
//				Push(x);
//				cout<<"DONE"<<endl;
//				break;
//			case 4:
//				i=Pop(x);
//				if(i==1)
//					cout<<"DONE !"<<endl;
//				else
//					cout<<"Queue rong khong co phan tu !"<<endl;
//				break;
//			case 5:
//				cout<<"DANH SACH QUEUE HIEN TAI: "<<endl;
//				output();
//				break;
//			case 6:
//				cout<<"EXIT "<<endl;
//				break;
//			default:
//				break;
//		}
//	}while(choice!=6);
//	system("pause");
//	return 0;
//}