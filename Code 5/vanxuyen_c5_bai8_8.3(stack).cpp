//#include <iostream>
//#include <stdio.h>
//#include <fstream>
//using namespace std;
//
//#define MAX 20
//int A[MAX][MAX];
//int n;
//char vertex[MAX];
//
////DSLK su dung cho STACK va QUEUE
//struct Node
//{
//	int info;
//	Node *link;
//};
//Node *sp;
//Node *front, *rear;
//
////stack
//void initS()
//{
//	sp=NULL;
//}
//int isEmptyS()
//{
//	if(sp==NULL)
//		return 1;
//	return 0;
//}
//void pushS(int x)
//{
//	Node *p=new Node;
//	p->info=x;
//	p->link=sp;
//	sp=p;
//}
//int popS(int &x)
//{
//	if(sp!=NULL)
//	{
//		Node *p=sp;
//		x=p->info;
//		sp=p->link;
//		delete p;
//		return 1;
//	}
//	return 0;
//}
////queue
//void initQ()
//{
//	front=NULL;
//	rear=NULL;
//}
//int isEmptyQ()
//{
//	if(front==NULL)
//		return 1;
//	return 0;
//}
//void pushQ(int x)
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
//int popQ(int &x)
//{
//	if(front!=NULL)
//	{
//		Node *p=front;
//		front=p->link;
//		x=p->info;
//		if(front==NULL)
//		{
//			rear=NULL;
//		}
//		delete p;
//		return 1;
//	}
//	return 0;
//}
//void initG()
//{
//	n=0;
//}
//void inputGfromtext()
//{
//	string line;
//	ifstream myfile("matranke1.txt");
//	if(myfile.is_open())
//	{
//		myfile>>n;
//		for(int i=0; i<n; i++)
//			myfile>>vertex[i];
//		for(int i=0; i<n; i++)
//		{
//			for(int j=0; j<n; j++)
//				myfile>>A[i][j];
//		}
//	}
//}
//void outputG()
//{
//	for(int i=0; i<n; i++)
//	{
//		for(int j=0; j<n; j++)
//			cout<<A[i][j]<<" ";
//		cout<<endl;
//	}
//}
//void output(int a[], int n)
//{
//	for(int i=0; i<n; i++)
//		cout<<vertex[a[i]]<<" ";
//}
////duyet BFS
//int C[100], bfs[100];
//int nbfs=0;
//void initC()
//{
//	for(int i=0; i<n; i++)
//		C[i]=1;
//}
//void BFS(int v)
//{
//	int w,p;
//	pushQ(v);
//	C[v]=0;
//	while(front!=NULL)
//	{
//		popQ(p);
//		bfs[nbfs]=p;
//		nbfs++;
//		for(w=0; w<n; w++)
//			if(C[w]&&A[p][w]==1)
//			{
//				pushQ(w);
//				C[w];
//			}
//	}
//}
//int main()
//{
//	int a[MAX], b[MAX];
//	int choice, sp, sp_b, x, i;
//	cout<<"Bai tap 4-----chuong 5-----Do thi"<<endl;
//	cout<<"1. Khoi tao ma tran ke rong "<<endl;
//	cout<<"2. Nhap ma tran ke tu file text"<<endl;
//	cout<<"3. Xuat ma tran ke"<<endl;
//	cout<<"4. Duyet do thi theo BFS"<<endl;
//  cout<<"5. Thoat" << endl;
//do
//	{
//		cout<<"\nVui long chon so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			initG();
//			cout<<"Ban vua khoi tao ma tran ke rong thanh cong!";
//			break;
//		case 2:
//			inputGfromtext();
//			cout<<"Ban vua nhap ma tran ke tu file\n";
//			outputG();
//			break;
//		case 3:
//			outputG();
//			break;
//		case 4:
//			initQ();
//			initC();
//			cout<<"Vui long nhap dinh xuat phat: ";
//			cin>>x;
//			nbfs=0;
//			BFS(x);
//			cout<<"Thu tu dinh sau khi duyet BFS: "<<endl;
//			output(bfs, n);
//			break;
//		case 5:
//			cout<<"Goodbye!"<<endl;
//			break;
//		default:
//			break;
//		}
//	}while(choice!=5);
//	system("pause");
//	return 0;
//}
//
