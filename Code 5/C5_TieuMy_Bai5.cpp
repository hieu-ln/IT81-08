#include <iostream>
#include <stdio.h>
#include <fstream>
using namespace std;

#define MAX 20
int n;
int A[MAX][MAX];
char vec[MAX];

struct Node {
	int infor;
	Node* link;
};
Node* sp;

void khoitaoS()
{
	sp = NULL;
}
int ktrongS()
{
	if (sp == NULL)
		return 1;
	return 0;
}

void themS(int x)
{
	Node* p = new Node;
	p->infor = x;
	p->link = sp;
	sp = p;
}
int xoaS(int &x)
{
	if (sp != NULL)
	{
		Node* p = sp;
		x = p->infor;
		sp = p->link;
		delete p;
		return 1;
	}
	return 0;
}

Node* front, *rear;

void khoitaoQ()
{
	rear = NULL;
	front = NULL;
}
int ktrongQ()
{
	if (rear == NULL)
		return 1;
	return 0;
}

void themQ(int x)
{
	Node* p = new Node;
	p->infor = x;
	p->link = NULL;
	if (rear == NULL)
		front = p;
	else
		rear->link = p;
	rear = p;
}
int xoaQ(int &x)
{
	if (front != NULL)
	{
		Node* p = front;
		front = p->link;
		x = p->infor;
		if (front == NULL)
			rear = NULL;
		delete p;
		return 1;
	}
	return 0;
}

void nhapfile()
{
	string line;
	ifstream myfile("matranke1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0  ; i < n; i++)
		{
			myfile >> vec[i];
		}
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				myfile >> A[i][j];
	}
}

void nhap()
{
	cout << "Nhap so dinh cho do thi: ";
	cin >> n;
	for (int i = 0; i < n; i++)
	{
		cout << "Nhap ten dinh cho do thi: ";
		cin >> vec[i];
		for (int j = 0; j < n; j++)
		{
			cout << "Nhap vao dong thu " << i + 1 << ": ";
			cin >> A[i][j];
		}
	}
}

void xuatG()
{
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << A[i][j] << " ";
		cout << endl;
	}
}

void xuat(int a[],int n)
{
	for (int i = 0; i < n; i++)
		cout << vec[a[i]]<<" ";
}

void khoitaoG()
{
	n = 0;
}

int C[100], bfs[100];
int nbfs = 0;

void khoitaoC()
{
	for (int i = 0; i < n; i++)
		C[i] = 1;
}

void BFS(int q)
{
	int w, p;
	themQ(q);
	C[q] = 0;
	while (front != NULL)
	{
		xoaQ(p);
		bfs[nbfs] = p;
		nbfs++;
		for (int w = 0; w < n; w++)
		{
			if (C[w] == 1 && A[p][w] == 1)
			{
				themQ(w);
				C[w] = 0;
			}
		}
	}
}

int dfs[100];
int ndfs = 0;
void DFS(int s)
{
	themS(s);
	C[s] = 0;
	dfs[ndfs] = s;
	ndfs++;
	int v = -1, u = s;
	while (ktrongS() == 0)
	{
		if (v == u)
			xoaS(u);
		for (int v = 0; v < n; v++)
		{
			if (C[v] == 1 && A[u][v] != 0)
			{
				themS(u);
				themS(v);
				dfs[ndfs] = v;
				ndfs++;
				C[v] = 0;
				u = v;
				break;
			}
		}
	}
}

void kt(int x, int q)
{
	int w, p;
	themQ(q);
	C[q] = 0;
	while (front != NULL)
	{
		xoaQ(p);
		if (x == p)
		{
			cout << "Tim thay " << x << " trong do thi\n";
			return;
		}
		for(w=0;w<n;w++)
			if (C[w] && A[p][w] == 1)
			{
				themQ(w);
				C[w] = 0;
			}
	}
}

int main()
{
	int chon, x;
	system("cls");
	cout << " ---------- BAI TAP 4 , CHUONG 5 , DO THI ----------" << endl;
	cout << "1. khoi tao MA TRAN KE rong" << endl;
	cout << "2. Nhap MA TRAN KE tu file text" << endl;
	cout << "3. Nhap MA TRAN KE " << endl;
	cout << "4. Xuat MA TRAN KE " << endl;
	cout << "5. Duyet do thi theo chieu rong BFS _ DSLK " << endl;
	cout << "6. Duyet do thi theo chieu sau DFS _ DSLK " << endl;
	cout << "7. Tim dinh co gia tri x theo BFS" << endl;
	cout << "8. Thoat" << endl;
	do {
		cout << "\nVui long chon so de thuc hien: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			khoitaoG();
			cout << "ban vua khoi tao MA TRAN KE rong thanh cong\n";
			break;
		case 2:
			nhapfile();
			cout << "Ban vua nhap MA TRAN KE tu file: \n";
			xuatG();
			break;
		case 3:
			nhap();
			break;
		case 4:
			xuatG();
			break;
		case 5:
			khoitaoQ();
			khoitaoC();
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			nbfs = 0;
			BFS(x);
			cout << "Thu tu dinh sau duyet BFS: " << endl;
			xuat(bfs, n);
			break;
		case 6:
			khoitaoS();
			khoitaoC();
			cout << "Vui long nhap dinh xuat phat: " << endl;
			cin >> x;
			ndfs = 0;
			DFS(x);
			cout << "Thu tu dinh sau khi duyet DFS: " << endl;
			xuat(dfs, n);
			break;
		case 7:
			cout << "Vui long nhap gia tri x can tim: ";
			cin >> x;
			kt(x, 0);
			break;
		default:
			break;
		}
	} while (chon != 8);
	system("pause");
	return 0;
}