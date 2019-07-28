#include <stdio.h>
#include<iostream>
using namespace std;
const int MAX = 100;
//Stack rong
void intit(int A[], int &sp)
{
	sp = -1;
}
//KT rong
int isEmpty(int A[], int sp)
{
	if (sp == -1)
		return 1;
	else
		return 0;
}
//KT day
int isFull(int A[], int sp)
{
	if (sp = MAX - 1)
		return 1;
	else return 0;
}
//Them pt
int Push(int A[], int sp, int x)
{
	if (sp < MAX - 1)
	{
		A[++sp] = x;
		return 1;
	}
	else
		return 0;
}
//Xoa pt
int Pop(int A[], int &sp, int &x)
{
	if (sp != -1)
	{
		x = A[sp--];
		return 1;
	}
	else
		return 0;
}
//Xuat
int Processs_stack(int A[], int sp)
{
	for (int i = 0; i <= sp; i++)
	{
		cout << A[i] << "    ";
	}
	cout << endl;
}
int main()
{
	int A[MAX], choice, x, size, sp, i;
	system("cls");
	cout << "Menu" << endl;
	cout << "1. Khoi tao stack rong" << endl;
	cout << "2. Them phan tu vao STACK" << endl;
	cout << "3. Lay phan tu ra khoi stack" << endl;
	cout << "4. Kiem tra xem Stack co rong hay khong" << endl;
	cout << "5.KIem tra xem stack co day hay khong" << endl;
	cout << "6. Xuat stack" << endl;
	cout << "7.Thoat" << endl;
	do
	{
		cout << "Moi chon so de thuc hien thao tac: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			intit(A, sp);
			cout << "Ban vua khoi tao Stack rong thanh cong";
			break;
		}
		case 2:
		{
			cout << "Vui long nhap gia tri muon them:" << endl;
			cin >> x;
			i = Push(A, sp, x);
			cout << "Stack sau khi them la" << endl;
			Processs_stack(A, sp);
			break;
		}
		case 3:
		{
			i = Pop(A, sp, x);
			cout << "Phan tu lay ra tu stack la " << x << endl;
			cout << "Stack sau khi lay phan tu" << endl;
			Processs_stack(A, sp);
			break;
		}
		case 4:
		{
			i = isFull(A, sp);
			if (i == 1)
				cout << "Stack day" << endl;
			else cout << "Stack chua day";
			break;

		}
		case 5:
		{
			i = isEmpty(A, sp);
			if (i == 1)
				cout << "Stack rong" << endl;
			else cout << "Stack khong rong";
			break;

		}
		case 6:
		{
			cout << "Stack hien tai la: " << endl;
			Processs_stack(A, sp);
			break;
		}
		case 7:
		{
			cout << "Ban da chon thoat" << endl;
		}
		default:
			break;
		}

	} while (choice != 7);
	system("pause");
	return 0;
}