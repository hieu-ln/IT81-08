#include <iostream>
#include <string>
#include <stdio.h>
#define Max 20
using namespace std;

struct Node{
	int info;
	Node *link;//DSLK Don
};
Node *first[Max];
int n;//so dinh

void initG()
{
	for(int i=0;i<n;i++)
		first[i]=NULL;
}
void insert_first(Node *&f, int x)
{
	Node *p=new Node;
	p->info=x;
	p->link=f;
	f=p;
}
//Nhap mang danh sach gom n danh sach
void input()
{
	int d,x,m;
	cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
			cout<<"Nhap DSK cua dinh thu "<<i+1<<": ";
			cin>>d;
			insert_first(first[i],d);
			cout<<"Nhap vao so dinh ke cua "<<d<<": "<<endl;
			cin>>m;
			for(int j=0;j<m;j++)
			{
				cin>>x;
				insert_first(first[i],x);
			}
	}
}
//Xuat thong tin cua 1 danh sach
void output_list(Node *f)
{
	if(f!=NULL)
	{
		Node *p=f;
		while(p!=NULL)
		{
			cout<<p->info<<" ";
			p=p->link;
		}
	}
}
//Xuat thong tin cua mang danh sach
void output()
{
	if(n>0)
		for(int i=0;i<n;i++)
		{
			cout<<endl<<"Danh sach thu"<<i+1<<": ";
			output_list(first[i]);
		}
	else
		cout<<"DANH SACH RONG !"<<endl;
}
// Queue
int a[Max];
int front,rear;
int C[Max];
void init(int a[],int &front, int&rear)
{
	front=-1;
	rear=-1;
}
int isEmpty( int a[], int front, int rear)
{
	if(front==-1)
		return 1;
	return 0;
}
int isFull(int a[], int front, int rear)
{
	if((rear-front)==Max-1)
		return 1;
	return 0;
}
int Push(int a[], int &front, int &rear, int x)
{
	if(rear-front==Max-1)
		return 0;
	else
	{
		if(front==-1)
			front=0;
		if(rear==Max-1)
		{
			for(int i=front;i<=rear;i++)
				a[i-front]=a[i];
			rear=Max-1-front;
			front=0;
		}
		a[++rear]=x;
		return 1;
	}
}
int Pop(int a[], int &front, int &rear, int &x)
{ 
	if(front==-1)
		return 0;
	else
	{
		x=a[front++];
		if(front>rear)
		{
			front=-1;
			rear=-1;
		}
		return 1;
	}
}
void BFS0DeQuy(int v, int Q[Max], int &front, int &rear)
{
	init(a,front,rear);
    Pop(a,front,rear,v);           //Dua dinh v vao QUEUE, xem no nhu la da xet
    C[v] = 1;

 
     while (isEmpty==0)       //Lap trong khi QUEUE khac rong
     {
		 v =    //Lay dinh v tu day cua QUEUE

    

                 for (int u=0; u<V; u++)

                             if ( A[v][u] != 0 )                                       //The hien u ke voi dinh v

                                         if ( ChuaXet[u]==0 )

                                         {

                                                     QUEUE[topQ++] = u;      // Dua u vao dinh cua QUEUE

                                                     ChuaXet[u] = 1;

                                         }

     }

 
}
int main()
{
	int a[Max];
	int b[Max];
	int c[Max];
	int choice,sp,x,i;
	system("cls");
	cout<<"1.Khoi tao danh sach ke"<<endl;
	cout<<"2.Nhap Danh sach ke cua do thi"<<endl;
	cout<<"3.Xuat danh sach ke cua do thi"<<endl;
	cout<<"4.Duyet do thi theo chieu rong - Queue"<<endl;
	cout<<"5.Duyet do thi theo chieu sau - Stack"<<endl;
	cout<<"6.Tim kiem mot dinh x theo BFS"<<endl;
	cout<<"7.EXIT"<<endl;
	do{
		cout<<"Nhap lua chon de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				initG();
				cout<<"Khoi tao thanh cong"<<endl;
				break;
			case 2:
				input();
				break;
			case 3:
				output();
				break;
			case 4:
				init();
				cout<<"Nhap dinh bat dau: ";
				cin>>x;
				nbfs=0;
				B(x);
				cout<<"Thu tu cac dinh cua do thi sau khi duyet BFS: ";
				output(bfs,n);
				cout<<endl;
				break;
			case 7:
				cout<<"E X I T"<<endl;
				break;
			default:
				break;
		}
	}while(choice!=7);
	system("pause");
	return 0;
}