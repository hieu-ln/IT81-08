//#include <iostream>
//#include <fstream>
//#include <stdio.h>
//#include <sstream>
//using namespace std;
//#define MAX 20
//
////DSLK su dung stack va queue
//struct Node
//{
//	int info;
//	Node *link;
//};
//
//Node *First[MAX];
//int n;
//char vertex[MAX];
//Node *sp;
//Node *front, *rear;
//
////STACK
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
////het stack
//
////QUEUE
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
//void initG(int &n)
//{
//	for(int i=0; i<n; i++)
//		First[i]=NULL;
//	n=0;
//}
//void insertLast(Node *&first, Node *p)
//{
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
//void inputGfromtext()
//{
//	string line;
//	ifstream myfile("danhsachke1.txt");
//	if(myfile.is_open())
//	{
//		myfile>>n;
//		for(int i=0; i<n; i++)
//			myfile>>vertex[i];
//		string str;
//		int i=0;
//		while(getline(myfile, str))
//		{
//			istringstream ss(str);
//			int u;
//			while(ss>>u)
//			{
//				Node *p=new Node;
//				p->info=u;
//				p->link=NULL;
//				insertLast(First[i-1], p);
//			}
//			i++;
//		}
//	}
//}
//void inputG()
//{
//	cout<<"Nhap so dinh do thi n: ";
//	cin>>n;
//	cout<<"Nhap ten dinh: ";
//	for(int i=0; i<n; i++)
//		cin>>vertex[i];
//	for(int i=0; i<n; i++)
//	{
//		if(i>0)
//			cout<<"Nhap DSK cua dinh thu "<<i+1<<" ("<<vertex[i-1]<<")";
//			int u;
//			string str;
//			while(getline(cin, str))
//			{
//				istringstream ss(str);
//				while(ss>>u)
//				{
//					Node *p=new Node;
//					p->info=u;
//					p->link=NULL;
//					insertLast(First[i-1], p);
//				}
//				break;
//			}
//	}
//}
//void outputG()
//{
//	for(int i=0; i<n; i++)
//	{
//		cout<<"Dinh "<<i<<" ("<<vertex[i]<<")";
//		Node *p=First[i];
//		while(p!=NULL)
//		{
//			cout<<p->info<<" ";
//			p=p->link;
//		}
//		cout<<endl;
//	}
//}
//void output(int a[], int n)
//{
//	for(int i=0; i<n; i++)
//		cout<<vertex[a[i]]<<" ";
//}
////BFS
//int C[100], bfs[100];
//int nbfs=0;
//void initC()
//{
//	for(int i=0; i<n; i++)
//		C[i]=1;
//}
//void BFS(int v)
//{
//	int p;
//	Node *w;
//	pushQ(v);
//	C[v]=0;
//	while(front!=NULL)
//	{
//		popQ(p);
//		bfs[nbfs]=p;
//		w=First[p];
//		nbfs++;
//		while(w!=NULL)
//		{
//			if(C[w->info])
//			{
//				pushQ(w->info);
//				C[w->info]=0;
//			}
//			w=w->link;
//		}
//	}
//}
////DFS
//int dfs[100];
//int ndfs=0;
//void DFS(int s)
//{
//	pushS(s);
//	dfs[ndfs]=s;
//	ndfs++;
//	C[s]=0;
//	int u=s;
//	Node *v=NULL;
//	while(isEmptyS()==0)
//	{
//		if(v==NULL)
//			popS(u);
//		v=First[u];
//		while(v!=NULL)
//		{
//			if(C[v->info]==1)
//			{
//				pushS(u);
//				pushS(v->info);
//				dfs[ndfs]=v->info;
//				ndfs++;
//				C[v->info]=0;
//				u=v->info;
//				break;
//			}
//			v=v->link;
//		}
//	}
//}
//void search(int x, int v)
//{
//	int p;
//	Node *w;
//	pushQ(v);
//	C[v]=0;
//	while(front!=NULL)
//	{
//		popQ(p);
//		if(x==p)
//		{
//			cout<<"Tim thay x="<<x<<endl;
//			return;
//		}
//		w=First[p];
//		while(w!=NULL)
//		{
//			if(C[w->info])
//			{
//				pushQ(w->info);
//				C[w->info]=0;
//			}
//			w=w->link;
//		}
//	}
//}
//int main()
//{
//	int choice, x, i;
//	cout<<"Bai tap 5-----chuong 5-----Do thi"<<endl;
//	cout<<"1. Khoi tao danh sach ke rong "<<endl;
//	cout<<"2. Nhap danh sach ke tu file text"<<endl;
//	cout<<"3. Nhap danh sach ke"<<endl;
//	cout<<"4. Xuat danh sach ke"<<endl;
//	cout<<"5. Duyet do thi theo BFS"<<endl;
//	cout<<"6. Duyet do thi theo DFS"<<endl;
//	cout<<"7. Tim dinh co gia tri x theo BFS"<<endl;
//	cout<<"8. Thoat"<<endl;
//	do
//	{
//		cout<<"\nVui long chon so de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//		case 1:
//			n=10;
//			initG(n);
//			cout<<"Ban vua khoi tao dan sach ke rong thanh cong!";
//			break;
//		case 2:
//			inputGfromtext();
//			cout<<"Ban vua nhap danh sach ke tu file\n";
//			outputG();
//			break;
//		case 3:
//			inputG();
//			break;
//		case 4:
//			outputG();
//			break;
//		case 5:
//			initQ();
//			initC();
//			cout<<"Vui long nhap dinh xuat phat: ";
//			cin>>x;
//			nbfs=0;
//			BFS(x);
//			cout<<"Thu tu dinh sau khi duyet BFS: "<<endl;
//			output(bfs, n);
//			break;
//		case 6:
//			initS();
//			initC();
//			cout<<"Vui long nhap dinh xuat phat: ";
//			cin>>x;
//			ndfs=0;
//			DFS(x);
//			cout<<"Thu tu dinh sau khi duyet DFS: "<<endl;
//			output(dfs, n);
//			break;
//		case 7:
//			initQ();
//			initC();
//			nbfs=0;
//			cout<<"Vui long nhap gia tri x can tim: ";
//			cin>>x;
//			search(x, 0);
//			break;
//		case 8:
//			cout<<"Goodbye!"<<endl;
//			break;
//		default:
//			break;
//		}
//	}while(choice!=8);
//	system("pause");
//	return 0;
//}
//
