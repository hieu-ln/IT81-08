//#include <iostream>
//#define MAX 100
//using namespace std;
//int a[MAX];
//int front,rear;
//void init(int a[],int &front, int&rear)
//{
//	front=-1;
//	rear=-1;
//}
//int isEmpty( int a[], int front, int rear)
//{
//	if(front==-1)
//		return 1;
//	return 0;
//}
//int isFull(int a[], int front, int rear)
//{
//	if((rear-front)==MAX-1)
//		return 1;
//	return 0;
//}
//int Push(int a[], int &front, int &rear, int x)
//{
//	if(rear-front==MAX-1)
//		return 0;
//	else
//	{
//		if(front==-1)
//			front=0;
//		if(rear==MAX-1)
//		{
//			for(int i=front;i<=rear;i++)
//				a[i-front]=a[i];
//			rear=MAX-1-front;
//			front=0;
//		}
//		a[++rear]=x;
//		return 1;
//	}
//}
//int Pop(int a[], int &front, int &rear, int &x)
//{ 
//	if(front==-1)
//		return 0;
//	else
//	{
//		x=a[front++];
//		if(front>rear)
//		{
//			front=-1;
//			rear=-1;
//		}
//		return 1;
//	}
//}
//void View()
//{
//	if(front==-1)
//		cout<<"EMPTY!"<<endl;
//	else
//	{
//		for(int i=rear;i>=front;i--)
//			cout<<a[i]<<endl;
//		cout<<endl;
//	}
//}
//int main()
//{
//int x,i;
//	int choice=0;
//	system("cls");
//	cout<<"1.Khoi tao Queue"<<endl;
//	cout<<"2.Kiem tra Queue rong"<<endl;
//	cout<<"3.Kiem tra Queue day"<<endl;
//	cout<<"4.Them 1 phan tu co gia tri x vao Queue"<<endl;
//	cout<<"5.Xoa phan tu trong Queue"<<endl;
//	cout<<"6.Queue hien tai"<<endl;
//	cout<<"7.EXIT"<<endl;
//	do{
//		cout<<"Nhap lua cho de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init(a,front,rear);
//				cout<<"Khoi tao thanh cong!!"<<endl;
//				break;
//			case 2:
//				i=isEmpty(a,front,rear);
//				if(i==1)
//					cout<<"Queue day!!"<<endl;
//				else
//					cout<<"Queue chua day!!"<<endl;
//				break;
//			case 3:
//				i=isFull(a,front,rear);
//				if(i==1)
//					cout<<"Queue da day!!"<<endl;
//				else
//					cout<<"Queue chua day!"<<endl;
//				break;
//			case 4:
//				cout<<"Nhap gia tri can tham vao Stack: ";
//				cin>>x;
//				i=Push(a,front,rear,x);
//				if(i!=1)
//					cout<<"Khong the them vao Queue!!"<<endl;
//				else
//				{
//					cout<<"Da them "<<x<<" vao Queue!!"<<endl;
//				}
//				break;
//			case 5:
//				i=Pop(a,front,rear,x);
//				if(i!=1)
//					cout<<"Queue dang rong!!"<<endl;
//				else
//				{
//					cout<<"Da xoa phan tu ra kho Queue!"<<endl;
//				}
//				break;
//			case 6:
//				cout<<"Danh sach hien tai cua Queue: "<<endl;
//				View();
//				break;
//			case 7:
//				cout<<"EXIT"<<endl;
//				break;
//			default:
//				break;
//		}
//	}while(choice!=7);
//	system("pause");
//	return 0;
//}