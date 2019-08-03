#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

#define maxsize 3000
int a[maxsize];
int n;

void Input(int a[], int &n)
{
	do
	{
		cout << "Nhap so luong so nguyen can nhap trong danh sach: ";
		cin >> n;
		if (n <= 0 || n > maxsize)
			cout << "Khong hop le, thu lai!\n";
	} while (n <= 0 || n > maxsize);
	for (int i = 0; i < n; i++)
	{
		cout << "a[" << i<<"]= ";
		cin >> a[i];
	}
}

void Random(int a[], int &n)
{
	do
	{
		cout << "Nhap so luong so nguyen can nhap trong danh sach: ";
		cin >> n;
		if (n <= 0 || n > maxsize)
			cout << "Khong hop le, thu lai!\n";
	} while (n <= 0 || n > maxsize);
	for (int i = 0; i < n; i++)
	{
		a[i] = rand() % 100 + 1;
	}
}

void Output(int a[], int n)
{
	cout << "\t~~~~~DANH SACH~~~~\n";
	for (int i = 0; i < n; i++)
		cout << a[i] << "\t";
}

void Switch(int &a, int &b)
{
	int tam = a;
	a = b;
	b = tam;
}

void Insertionsort(int a[], int n)
{
	int x,j;
	for (int i = 1; i < n; i++)
	{
		x = a[i];
		j = i - 1;
		while (0 <= j && x < a[j])
		{
			a[j + 1] = a[j];
			j--;
		}
		a[j + 1] = x;
	}
}

void Selectionsort(int a[], int n)
{
	int x,min,j;
	for (int i = 0; i < n-1; i++)
	{
		min = i;
		for(j=i+1;j<n;j++)
			if (a[j] < a[min])
			{
				min = j;
			}
		Switch(a[min], a[i]);
	}
}

void Interchangesort(int a[], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[j] < a[i])
				Switch(a[j], a[i]);
}

void Bubblesort(int a[], int n)
{
	for (int i = 0; i < n - 1; i++)
		for (int j = n - 1; j > i; j--)
			if (a[j - 1] > a[j])
				Switch(a[j], a[j-1]);
}

void Quicksort(int a[], int left,int right)
{
	int i,j, x;
	i = left;
	j = right;
	x = a[(left + right) / 2];
	while (i<j)
	{
		while (a[i] < x)
			i++;
		while (a[j] > x)
			j--;
		if (i <= j)
		{
			Switch(a[i], a[j]);
			i++;
			j--;
		}
	}
	if (left < i)
		Quicksort(a, left, j);
	if (i < right)
		Quicksort(a, i, right);
}

void Shift(int a[], int i, int n)
{
	int j = 2 * i + 1;
	if (j >= n)
		return;
	if (j + 1 < n)
		if (a[j] < a[j + 1])
			j++;
	if (a[i] >= a[j])
		return;
	else
	{
		int x = a[i];
		a[i] = a[j];
		a[j] = x;
		Shift(a,j, n);
	}
}

void Heapsort(int a[], int n)
{
	int i = n / 2-1;
	while (i >= 0)
	{
		Shift(a, i, n);
		i--;
	}
	int right = n - 1;
	while (right > 0)
	{
		Switch(a[0], a[right]);
		right--;
		if (right > 0)
			Shift(a, 0, right);
	}
}

int TKTT(int a[], int n, int x)
{
	for (int i = 0; i < n; i++)
		if (x == a[i])
			return 1;
}

int TKNP(int a[], int n, int y)
{
	Insertionsort(a, n);
	int left=0, right=n-1, mid;
	while (left <= right)
	{
		mid = (left + right) / 2;
		if (a[mid] == y)
			return mid;
		if (y > a[mid])
			left = mid + 1;
		else
			right = mid - 1;
	}
	return 0;
}

int main()
{
	int chon,x, i;
	system("cls");
	cout << "-----Bai 1-----Chuong 3-----Xep thu tu-----\n";
	cout << "1. Nhap danh sach\n";
	cout << "2. Nhap danh sach ngau nhien\n";
	cout << "3. Xuat danh sach\n";
	cout << "4. Xep danh sach tang dan bang Insertion Sort \n";
	cout << "5. Xep danh sach tang dan bang Selection Sort\n";
	cout << "6. Xep danh sach tang dan bang Interchange Sort\n";
	cout << "7. Xep danh sach tang dan bang Quick Sort\n";
	cout << "8. Xep danh sach tang dan bang Heap Sort\n";
	cout << "9.Xep danh sach tang dan bang Bubble Sort\n";
	cout << "10. Tim kiem tuan tu mot phan tu trong danh sach\n";
	cout << "11. Tim kiem nhi phan mot phan tu trong danh sach\n";
	cout << "12. Thoat\n";
	do
	{
		cout << "Ban chon: ";
		cin >> chon;
		switch (chon)
		{
			case 1:
				Input(a, n);
				break;
			case 2:
				Random(a, n);
				break;
			case 3:
				Output(a, n);
				cout << endl;
				break;
			case 4:
				Insertionsort(a, n);
				cout << "Danh sach xep thu tu tang dan theo Insertion Sort\n";
				Output(a, n);
				cout << endl;
				break;
			case 5:
				Selectionsort(a, n);
				cout << "Danh sach xep thu tu tang dan theo Selection Sort\n";
				Output(a, n);
				cout << endl;
				break;
			case 6:
				Interchangesort(a, n);
				cout << "Danh sach xep thu tu tang dan theo Inte	rchange Sort\n";
				Output(a, n);
				cout << endl;
				break;
			case 7:
				Quicksort(a, 0,n-1);
				cout << "Danh sach xep thu tu tang dan theo Quick Sort\n";
				Output(a, n);
				cout << endl;
				break;
			case 8:
				Heapsort(a, n);
				cout << "Danh sach xep thu tu tang dan theo Heap Sort\n";
				Output(a, n);
				cout << endl;
				break;
			case 9:
				Bubblesort(a, n);
				cout << "Danh sach xep thu tu tang dan theo Bubble Sort\n";
				Output(a, n);
				cout << endl;
				break;
			case 10:
				cout << "Nhap phan tu can tim trong danh sach: ";
				cin >> x;
				i = TKTT(a, n, x);
				if (i == 1)
					cout << "Tim thay " << x << " trong danh sach\n";
				else
					cout << "Khong tim thay "<<x<<" trong danh sach\n";
				break;
			case 11:
				cout << "Nhap phan tu can tim trong danh sach: ";
				cin >> x;
				i = TKNP(a, n, x);
				if (i != 0)
					cout << "Tim thay " << x << " trong danh sach\n";
				else
					cout<< "Khong tim thay " << x << " trong danh sach\n";
				break;
		default:
			break;
		}
	} while (chon != 12);
	system("pause");
	return 0;
}