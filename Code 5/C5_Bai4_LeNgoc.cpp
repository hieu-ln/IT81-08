//#include <iostream>
//#include <iomanip>
//using namespace std;
//#define Max 20
//int a[Max][Max];
//int n;// so dinh cua do thi
//char vertex[Max];
//struct Node{
//	int info;
//	Node *link;
//};
//Node *sp;
//Node *front, *rear;
/////Stack
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
//void PushS(int x)
//{
//	Node *p=new Node;
//	p->info=x;
//	p->link=sp;
//	sp=p;
//}
//int PopS(int &x)
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
//void PushQ(int x)
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
//int PopQ(int &x)
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
//void init()
//{
//	n=0;
//}
//void inputG()
//{
//	cout<<"Nhap so dinh cua do thi: ";
//	cin>>n;
//	cout<<"Nhap ten dinh cua dp thi: ";
//	for(int i=0;i<n;i++)
//		cin>>vertex[i];
//	for(int i=0;i<n;i++)
//	{
//		cout<<"Nhap dong thu "<<i+1<<": ";
//		for(int j=0;j<n;j++)
//			cin>>a[i][j];
//	}
//}
//void outputG()
//{
//	for(int i=0;i<n;i++)
//	{
//		for(int j=0;j<n;j++)
//			cout<<setw(3)<<a[i][j];
//		cout<<endl;
//	}
//}
//void output(int a[],int n)
//{
//	for(int i=0;i<n;i++)
//		cout<<setw(3)<<vertex[a[i]];
//}
////duyet do thi theo chieu rong BFS dung Queue
//int C[100],bfs[100];
//int nbfs=0;
//void initC()
//{
//	for(int i=0;i<n;i++)//n la so dinh cua do thi
//		C[i]=1;
//}
//void BFS(int v)//v la dinh bat dau
//{
//	int w,p;
//	PushQ(v);
//	C[v]=0;
//	while(front!=NULL)
//	{
//		PopQ(p);
//		bfs[nbfs]=p;
//		nbfs++;
//		for(w=0;w<n;w++)
//			if(C[w] && a[p][w]==1)
//			{
//				PushQ(w);
//				C[w]=0;
//			}
//	}
//}
////duyet do thi theo chieu sau dung Stack
//int dfs[100];
//int ndfs;
//void DFS(int s)
//{
//	PushS(s);
//	dfs[ndfs]=s;
//	ndfs++;
//	C[s]=0;
//	int v=-1;
//	int u=v;
//	while(isEmptyS()==0)
//	{
//		if(v==n)
//			PopS(u);
//		for(v=0;v<n;v++)
//			if(a[u][v]!=0 && C[v]==1)
//			{
//				PushS(u);
//				PushS(v);
//				dfs[ndfs]=v;
//				ndfs++;
//				C[v]=0;
//				u=v;
//				break;
//			}
//	}
//}
////dung BFS tim x trong do thi
//void searchbybfs(int x, int v)
//{
//	int w,p;
//	PushQ(v);
//	C[v]=0;
//	while(front!=NULL)
//	{
//		PopQ(p);
//		if(x==p)
//		{
//			cout<<x<<" Ton tai"<<endl;
//			return;
//		}
//		for(w=0;w<n;w++)
//			if(C[w] && a[p][w]==1)
//			{
//				PushQ(w);
//				C[w]=0;
//			}
//	}
//}
//int main()
//{
//	int a[Max];
//	int b[Max];
//	int choice,sp,x,i;
//	system("cls");
//	cout<<"1.Khoi tao ma tran ke"<<endl;
//	cout<<"2.Nhap ma tran ke cua do thi"<<endl;
//	cout<<"3.Xuat ma tran ke cua do thi"<<endl;
//	cout<<"4.Duyet do thi theo chieu rong - Queue"<<endl;
//	cout<<"5.Duyet do thi theo chieu sau - Stack"<<endl;
//	cout<<"6.Tim kiem mot dinh x theo BFS"<<endl;
//	cout<<"7.EXIT"<<endl;
//	do{
//		cout<<"Nhap lua chon de thuc hien: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				init();
//				cout<<"Khoi tao thanh cong"<<endl;
//				break;
//			case 2:
//				inputG();
//				break;
//			case 3:
//				outputG();
//				break;
//			case 4:
//				initQ();
//				initC();
//				cout<<"Nhap dinh bat dau: ";
//				cin>>x;
//				nbfs=0;
//				BFS(x);
//				cout<<"thu tu cac dinh cua do thi sau khi duyet BFS: ";
//				output(bfs,n);
//				cout<<endl;
//				break;
//			case 5:
//				initS();
//				initC();
//				cout<<"Nhap dinh bat dau: ";
//				cin>>x;
//				ndfs=0;
//				DFS(x);
//				cout<<"Thu tu cac dinh cua do thi sau khi duyet DFS: ";
//				output(dfs,n);
//				cout<<endl;
//				break;
//			case 6:
//				cout<<"Nhap gia tri x can tim theo BFS: ";
//				cin>>x;
//				searchbybfs(x,0);
//				break;
//			case 7:
//				cout<<"E X I T"<<endl;
//				break;
//			default:
//				break;
//		}
//	}while(choice!=7);
//	system("pause");
//	return 0;
//}
