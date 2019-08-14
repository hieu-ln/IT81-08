#include <stdio.h>
#include <iostream>
#include <fstream>
#include <sstream>
#include <iomanip>
using namespace std;

//khai bao ma tran bang mang 2 chieu
#define MAX 20
int a[MAX][MAX];
int n;//so dinh cua do thi
char vertex[MAX];//ten dinh

void initGraph()
{
	n = 0;
}

void inputGraphFromText()
{
	string line;
	ifstream myfile("matrantrongso1.txt");
	if (myfile.is_open())
	{
		myfile >> n;
		for (int i = 0; i < n; i++)
			myfile >> vertex[i];
		for (int i = 0; i < n; i++)
		{
			for (int j = 0; j < n; j++)
				myfile >> a[i][j];
		}
	}
}

//Xuat ma tran ke cua do thi
void outputGraph()
{
	cout << setw(6) << left;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < n; j++)
			cout << a[i][j] << setw(6) << left;
		cout << endl;
	}
}

//khai bao Tap E
int E1[MAX];
int E2[MAX];
int wE[MAX];
int nE = 0;//so phan tu tap

//Khai bao Tap T
int T1[MAX];
int T2[MAX];
int wT[MAX];
int nT = 0;//so phan tu tap T

int tontai(int d, int D[], int nD)
{
	for (int i = 0; i < n; i++)
		if (D[i] == d)
			return 1;
	return 0;
}

void xoavitriE(int i)
{
	for (int j = i; j < nE; j++)
	{
		E1[j] = E1[j + 1];
		E2[j] = E2[j + 1];
		wE[j] = wE[j + 1];
	}
	nE--;
}

void xoacanhE(int u, int v)
{
	for (int i = 0; i < nE; i++)
		if (E1[i] == u && E2[i] == v)
		{
			xoavitriE(i);
			break;
		}
}

void prim(int s)//s la dinh bat dau
{
	int u = s, min, i, d1, d2;
	while (nT < n - 1)
	{
		for (int v = 0; v < n; v++)
		{
			if (a[u][v] != 0)
			{
				if (tontai(v, T2, nT) == 0)
				{
					E1[nE] = u;
					E2[nE] = v;
					wE[nE] = a[u][v];
					nE++;
				}
			}
		}
		for (i = 0; i < nE; i++)
		{
			if (tontai(E2[i], T2, nT) == 0)
			{
				min = wE[i];
				d1 = E1[i];
				d2 = E2[i];
				break;
			}
		}
		for (int i = 0; i < nE; i++)
		{
			if (tontai(E2[i], T2, nT) == 0)
			{
				if (min > wE[i])
				{
					min = wE[i];
					d1 = E1[i];
					d2 = E2[i];
				}
			}
		}
		T1[nT] = d1;
		T2[nT] = d2;
		wT[nT] = a[d1][d2];
		a[d1][d2] = 0;
		a[d2][d1] = 0;
		nT++;
		xoacanhE(d1, d2);
		u = d2;
	}
}

void output(bool vertexname)
{
	int tong = 0;
	for (int i = 0; i < nT; i++)
	{
		if (vertexname)
			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") = " << wT[i];
		else
			cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
		tong += wT[i];
	}
	cout << "\nTong=" << tong;
}

int main()
{
	int choice, x;

	cout << "---BAI 4, CHUONG 6, TIM KIEM CAY KHUNG TOI TIEU- PRIM---" << endl;
	cout << "1.Khoi tao MA TRAN KE rong" << endl
		<< "2.Nhap MA TRAN KE tu file text" << endl
		<< "3.Xuat MA TRAN KE" << endl
		<< "4.Tim CAY KHUNG TOI TIEU bang PRIM" << endl
		<< "5.Thoat" << endl;

	do {
		cout << "\nVui long nhap so de thuc hien: ";
		cin >> choice;

		switch (choice)
		{
		case 1:
			initGraph();
			cout << "Ban vua khoi tao MA TRAN KE rong thanh cong!";
			break;
		case 2:
			inputGraphFromText();
			cout << "Ban vua nhap MA TRAN KE tu file: \n";
			outputGraph();
			break;
		case 3:
			outputGraph();
			break;
		case 4:
			cout << "Vui long nhap dinh xuat phat: ";
			cin >> x;
			prim(x);
			cout << "Cay khung toi tieu coi PRIM: " << endl;
			output(true);
			break;
		case 5:
			cout << "Goodbye!";
			break;
		default:
			cout << "loi nhap lieu!";
			break;
		}
	} while (choice != 5);

	cout << endl;
	system("pause");
	return 0;
}