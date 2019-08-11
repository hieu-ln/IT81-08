#include <stdio.h>
#include <iostream>
#include <fstream>
using namespace std;
#define MAX 20
int A[MAX][MAX];
int n; //dinh
char vertex[MAX]; //DSLK su dung cho Stack va QUEUE
struct Node
{
	int infor;
	Node* link;
};
Node *sp;
Node *front, *raer;
//STACK
void IntitStack()
{
	sp = NULL;
}
int isEmptyS()
{
	if(sp == NULL)
		return 1;
	return 0;
}
void PushS(int x)
{
	Node *p = new Node;
	p ->infor = x;
	p -> link = sp;
	sp = p;
}
int PopS(int &x)
{
	if(sp!= NULL)
	{
		Node *p = sp;
		x = p->infor;
		sp = p ->link;
		delete p;
		return 1;
	}
	return 0;
}
//End Stack

//QUEUE
void IntitQUEUE()
{
	front = NULL;
	raer = NULL;
}
int IsEmpty()
{
	if(front == NULL)
		return 1;
	return 0;
}
void PushQ(int x)
{
	Node *p = new Node;
	p ->infor = x;
	p ->link= NULL;
	if(raer == NULL)
	{
		front = p;
	}
	else
		raer ->link = p;
	raer = p;
}
int PopQ(int &x)
{
	if(front != NULL)
	{
		Node *p=front;
		front = p ->link;
		x = p ->infor;
		if(front == NULL)
			raer = NULL;
		delete p;
		return 1;
	}
	return 0;
}
//End QUEUE


void InputGrap()
{
	n = 0;
}
void InputGrapFromText()
{
	string line;
	ifstream myFile ("matranke1.text");
	if(myFile.is_open())
	{
		myFile>>n;
		for(int i = 0; i <n; i++)
			myFile>>vertex[i];
		for(int i = 0; i< n; i++)
		{
			for(int j = 0; j<n;i++)
				myFile>>A[i][j];
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

//Cau 4.3: Duyet do thi theo BFS
int C[100], bfs[1100];
int nbfs = 0;
void Init()
{
	for(int i = 0; i <n; i++)
		C[i]=1;
}
void BFS(int v)
{
	int w,p;
	PushQ(v);
	C[v] = 0;
	while (front != NULL)
	{
		PopQ(p);
		bfs[nbfs]=p;
		nbfs++;
		for(int w = 0; w , n; w++)
			if(C[w]&&A[p][w]==1)
			{
				PushQ(w);
				C[w]=0;
			}
	}
}
//Cau 4.4: Duyet DFS
int dfs[100];
int ndfs=0;
void DFS(int s)
{
	PushS(s);
	dfs[ndfs]=s;
	ndfs++;
	C[s]=0;
	int v = -1, u = s;
	while(isEmptyS()==0)
		{	if(v == n)
				PopS(u);
		for(int i =0; i <n; i++)
			if(A[u][v]!=0 && C[v]==-1)
			{
				PushS(u);
				PushS(v);
				dfs[ndfs]=v;
				C[v]=0;
				u = v;
				break;
		}
	}
}
//4.5 Dung BFS tim x
void Search_By_BFS(int x, int v)//v la dinh bat dau
{
	int w,p;
	PushQ(v);
	C[v]=0;
	while(front != NULL)
	{
		PopQ(p);
		if(x==p)
		{
			cout<<"Tim thay x="<<x<<endl;
			return;
		}
		for(w=0; w<n; w++)
			if(C[w]&&A[p][w]==1)
			{
				PushQ(w);
				C[w]=0;
			}
	}
}

int main()
{
	int choice, sp, sp_b, x,i;
	int A[MAX], B[MAX];
	cout<<"Bai 4 _ Chuong5"<<endl;
	cout<<"1.Khoi tao ma tran ke"<<endl;
	cout<<"2.Nhap ma tran ke tu file text"<<endl;
	cout<<"3.Nhap ma tran ke"<<endl;
	cout<<"4.Xuat ma tran ke"<<endl;
	cout<<"5.Duyet do thi theo BFS"<<endl;
	cout<<"6.Duyet do thi theo DFS"<<endl;
	cout<<"7.Tim dinh x co gia tri theo BFS"<<endl;
	cout<<"8.Thoat"<<endl;
	do
	{
		cout<<"\n Vui long chon so de thuc hien thao tac"<<endl;
		cin>>choice;
		switch (choice)
		{
		case 1:
			IntitGraph();
			cout<<"Ban vua khoi tao ma tran ke thanh cong"<<endl;
			break;
		case 2:
			InputGrapFromText();
			cout<<"Ban vua nhap ma tran ke tu file"<<endl;
			outputGraph();
			break;
		case 3:
			inputGraph();
			break;
		case 4:
			outputGraph();
			break;
		case 5:
			IntitQUEUE();
			Init();
			cout<<"vui long nhap dinh xuat phat: ";
			cin>>x;
			nbfs=0;
			BFS(x);
			cout<<"thu tu dinh sau khi duyet BFS: "<<endl;
			output(bfs,n);
			break;
		case 6:
			IntitStack();
			Init();
			cout<<"vui long nhap dinh xuat phat: ";
			cin>>x;
			ndfs=0;
			DFS(x);
			cout<<"thu tu dinh sau khi duyet DFS: "<<endl;
			output(dfs,n);
			break;
		case 7:
			InitQUEUE();


		}
	}
}