#include <iostream>
#include <fstream>
using namespace std;

#define MAX 20
int A[MAX][MAX];//mang 2 chieu
int n;// so dinh cua do thi
char vertex[MAX];

//DSLK suwr dujng cho STACK vaf QUEUE
struct Node
{
	int info;
	Node *link;
};

Node *sp;
Node *front, *rear;

//STACK
void InitStack()
{
	sp=NULL;
}
int isEmptyS()
{
	if(sp==NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=sp;
	sp=p;
}
int PopS(int &x)
{
	if(sp!=NULL)
	{
		Node *p=sp;
		x=p->info;
		sp=p->link;
		delete p;
		return 1;
	}
	return 0;
}
//end Stack

//QUEUE
void InitQueue()
{
	front=NULL;
	rear=NULL;
}
int isEmptyQ()
{
	if(front==NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=NULL;
	if(rear==NULL)
		front=p;
	else
		rear->link=p;
	rear=p;
}
int PopQ(int &x)
{
	if(front!=NULL)
	{
		Node *p=front;
		front=p->link;
		x=p->info;
		if(front==NULL)
			rear=NULL;
		delete p;
		return 1;
	}
	return 0;
}
//end Queue

void InitGraph()
{
	n=0;
}

void inputGraphFromText()
{
	string line;
	ifstream myfile ("matranke1.txt");
	if(myfile.is_open())
	{
		myfile>>n;
		for(int i=0;i<n;i++)
			myfile>>vertex[i];
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<n;j++)
				myfile>>A[i][j];
		}
	}
}

//Cau 4.1:Nhap ma tran ke cua do thi
void inputGraph()
{
	cout<<"Nhap so dinh do thi n: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap ten dinh: ";
		cin>>vertex[i];
		cout<<"Nhap vao do thi thu "<<i+1<<": ";
		for(int j=0;j<n;j++)
			cin>>A[i][j];
	}
}

//Cau 4.2:Xuat ma tran ke cua do thi
void outputGraph()
{
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
			cout<<A[i][j]<<"  ";
		cout<<endl;
	}
}

void output(int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<vertex[a[i]]<<"   ";
}

//Cau 4.3: Duyet do thi theo chieu rong BFS (Dung QUEUE)
int C[100], bfs[100];
int nbfs=0;
void Init()
{
	for(int i=0;i<n;i++)//n la so dinh cua do thi
		C[i]=1;
}
void BFS(int v)// v la dinh bat dau
{
	int w, p;
	PushQ(v);
	C[v]=0;
	while(front!=NULL)
	{
		PopQ(p);
		bfs[nbfs]=p;
		nbfs++;
		for(w=0;w<n;w++)
			if(C[w]&&A[p][w]==1)
			{
				PushQ(w);
				C[w]=0;
			}
	}
}

//Cau 4.4: Duyet do thi theo chieu sau DFS(Dung Stack)
int dfs[100];
int ndfs=0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs]=s;
	ndfs++;
	C[s]=0;
	int v=-1,u=s;
	while(isEmptyS()!=0)
	{
		if(v==n)
			PopS(u);
		for(int i=0;i<n;i++)
			if(A[u][v]!=0&&C[v]==1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs]=v;
				ndfs++;
				C[v]=0;
				u=v;
				break;
			}
	}
}

//Cau 4.5: Dung BFS tim x tren do thi
void Search_by_BFS(int x, int v)//v la dinh bat dau
{
	int w,p;
	PushQ(v);
	C[v]=0;
	while(front!=NULL)
	{
		PopQ(p);
		if(x==p)
		{
			cout<<"Tim thay x="<<x<<endl;
			return;
		}
		for(w=0;w<n;w++)
			if(C[w]&&A[p][w]==1)
			{
				PushQ(w);
				C[w]=0;
			}
	}
}

int main()
{
	int choice,sp,sp_b,x,i;
	int a[MAX];
	int b[MAX];

	cout<<"---Bai 4, CHUONG 5, DO THI---"<<endl;
	cout<<"1.Khoi tao MA TRAN KE rong"<<endl
		<<"2.Nhap MA TRAN KE tu file text"<<endl
		<<"3.Nhap MA TRAN KE"<<endl
		<<"4.Xuat MA TRAN KE"<<endl
		<<"5.Duyet do thi theo chieu rong BFS - DSLK"<<endl
		<<"6.Duyet do thi theo chieu sau DFS - DSLK"<<endl
		<<"7. Tim dinh x co gia tri x theo BFS"<<endl
		<<"8.Thoat"<<endl;

	do{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			InitGraph();
			cout<<"Ban vua khoi tao MA TRAN KE ron thanh cong!";
			break;
		case 2:
			inputGraphFromText();
			cout<<"Ban vua nhap MA TRAN KE tu ifle: \n";
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			InitQueue();
			Init();
			cout<<"Vui long nhap dinh xuat phat: ";
			cin>>x;
			nbfs=0;
			BFS(x);
			cout<<"Thu tu dinh sau khi duyet BFS: "<<endl;
			output(bfs,n);
			break;
		case 6:
			InitStack();
			Init();
			cout<<"Vui long nhap dinh xuat phat: ";
			cin>>x;
			ndfs=0;
			DFS(x);
			cout<<"Thu tu dinh sau khi duyet DFS: "<<endl;
			output(dfs,n);
			break;
		case 7:
			InitQueue();
			Init();
			nbfs=0;
			cout<<"Vui long nhap dinh x can tim: ";
			cin>>x;
			Search_by_BFS(x,0);
			break;
		case 8:
			cout<<"Goodbye!";
			break;
		default:
			cout<<"Loi nhap lieu!";
			break;
		}
	}while(choice!=8);

	cout<<endl;
	system("pause");
	return 0;
}