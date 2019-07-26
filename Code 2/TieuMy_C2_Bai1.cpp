#include <iostream>
#include <stdlib.h>
using namespace std;
#define max 100
int a[max];
int n;

void Input(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i << "]= ";
		cin >> a[i];
	}
}

void Output(int a[], int n)
{
	for (int i = 0; i < n; i++)
		cout << a[i] << " ";
}

void NgauNhien(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 10;
	}
}

int Search(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (a[i] == x)
			return 1;
	return 0;
}

int Add(int a[], int &n, int value)
{
	n++;
	for (int i = n - 1; i < n; i++)
	{
		a[n - 1] = value;
		return 1;
	}
	return 0;
}

int Xoa(int a[], int &n)
{
	for (int i = 0; i < n; i++)
	{
		n--;
		return 1;
	}
	return 0;
}

int Del(int a[],int &n,int VT )
{
	if (VT >= 0 && VT < n)
	{
		for (int j = VT-1; j < n - 1; j++)
		{
			a[j] = a[j + 1];
		}
		n--;
		return 1;
	}
	return 0;
}

int Sad(int a[], int &n, int Tim )
{
	for (int i = 0; i < n; i++)
	{
		if (a[i] == Tim )
		{
			for(int j=i;j<n-1;j++)
			a[j] = a[j + 1];
			n--;
			return 1;
		}
	}
	return 0;
}
int main()
{
	int n, VT, x, y, chon, gt;
	cout << "----------Bai tap 1----------Chuong 2----------MENU--------" << "\n";
	cout << "1. Nhap phan tu cho danh sach\n";
	cout << "2. Xuat danh sach\n";
	cout << "3. Nhap ngau nhien phan tu cho danh sach\n";
	cout << "4. Tim mot phan tu trong danh sach\n";
	cout << "5. Them mot phan tu vao cuoi danh sach\n";
	cout << "6. Xoa phan tu cuoi danh sach\n";
	cout << "7. Xoa phan tu tai vi tri thu i trong danh sach\n";
	cout << "8. Tim phan tu va xoa trong danh sach\n";
	cout << "9. Thoat\n";
	do
	{
		cout << "\nVui long chon yeu cau: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			do
			{
				cout << "Nhap so luong phan tu cho danh sach: ";
				cin >> n;
				if (n <= 0 || n > max)
					cout << "Nhap sai nhap lai\n";
			} while (n <= 0 || n > max);
			Input(a, n);
			break;
		case 2:
			Output(a, n);
			break;
		case 3:
			do
			{
				cout << "Nhap so luong phan tu cho danh sach: ";
				cin >> n;
				if (n <= 0 || n > max)
					cout << "Nhap sai nhap lai\n";
			} while (n <= 0 || n > max);
			NgauNhien(a, n);
			break;
		case 4:
			cout << "Nhap gia tri can tim trong danh sach: ";
			cin >> x;
			if (Search(a, n, x) == 1)
				cout << "Tim thay gia tri " << x << " trong danh sach\n";
			else
				cout << x << " khong tim thay trong danh sach\n";
			break;
		case 5:
			cout << "Nhap gia tri cho phan tu them cuoi: ";
			cin >> gt;
			if (Add(a, n, gt) == 1)
				cout << "Them thanh cong\n";
			else
				cout << "Them phan tu that bai\n";
			break;
		case 6:
			Xoa(a, n);
			break;
		case 7:
			cout << "Nhap vi tri can xoa trong danh sach: ";
			cin >> VT;
			if (Del(a, n, VT) == 1)
				cout << "Xoa thanh cong\n";
			else
				cout << "Xoa that bai\n";
			break;
		case 8:
			cout << "Nhap gia tri can tim trong danh sach va xoa gia tri do: ";
			cin >> y;
			if (Sad(a, n, y) == 1)
				cout << "Thanh cong\n";
			else
				cout << "That bai\n";
			break;
		default:
			break;
		}
	} while (chon != 9);
	system("pause");
	return 0;
}