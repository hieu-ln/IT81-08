#include <iostream>
#include <ctime>
using namespace std;
const int mx = 100;
int A[mx];
void Xuat(int A[mx], int size)
{
	for (int i = 0; i < size; i++)
		cout << A[i] << "    ";
}
void Nhap(int A[mx], int size)
{
	for (int i = 0; i < size; i++)
	{
		cout << "Nhap phan tu so " << i + 1 << ": ";
		cin >> A[i];
	}
}
bool KTtang(int a[mx], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] < a[j])
				return false;
	return true;
}
bool KTgiam(int a[mx], int n)
{
	for (int i = 0; i < n; i++)
		for (int j = i + 1; j < n; j++)
			if (a[i] > a[j])
				return false;
	return true;
}
void ThemSo(int A[mx], int &n, int x)
{
	int vt;
	if (KTtang(A, n))
	{
		for (int i = 0; i < n; i++)
		{
			if (A[i] > n && A[i + 1] < n)
			{
				vt = i;
				for (int j = n; j > vt; j--)
					A[j] = A[j - 1];
				A[vt] = x;
				n++;
			}
		}
	}
	if (KTgiam(A, n))
	{
		for (int i = 0; i < n; i++)
		{
			if (A[i] < n && A[i + 1] > n)
			{
				vt = i;
				for (int i = n; i > vt; i--)
					A[i] = A[i - 1];
				A[vt] = x;
				n++;
			}
			}
	}
}
int Search(int x, int A[mx], int size)
{
	int i = 0;
	while ((i < size) && A[i] != x)
		i++;
	if (i < size)
		return i + 1;
	return -1;
}
int Search2(int x, int A[mx], int size)
{
	int left = 0, right = size - 1;
	while (left <= right)
	{
		int mid = (left + right) / 2;
		if (A[mid] == x)
			return mid +1;
		if (x > A[mid])
			left = A[mid + 1];
		else
			right = mid - 1;
	}
	return -1;
}
void SAD(int A[], int &n, int x)
{
	int m = Search(x, A, n);
	if (m != -1)
	{

		for (int i = m; i < n; i++)
			A[i] = A[i + 1];
		n--;
		cout << "Da xoa thanh cong" << endl;
	}
	else
		cout << "So khong co trong mang" << endl;
}
int main()
{
	int A[mx], x, choice, size;
	double duration;
	clock_t start;
	cout << "CIAO~~~~~~~~~";
	cout << "Menu" << endl;
	cout << "1.Khoi tao va nhap danh sach" << endl;
	cout << "2. Them 1 phan tu vao danh sach co thu tu" << endl;
	cout << "3. Xuat phan tu trong DS" << endl;
	cout << "4. Tim 1 phan tu trong danh sach (dung tim kiem tuan tu)" << endl;
	cout << "5. Tim 1 phan tu trong danh sach da sap xep (dung tim kiem nhi phan)" << endl;
	cout << "6. Tim va xoa 1 phan tu " << endl;
	cout << "7. Thoat<3" << endl;
	do
	{

		cout << "\nHay chon so de thuc hien thao tac: ";
		cin >> choice;
		switch (choice)
		{
		case 1:
		{
			cout << "Hay nhap so phan tu cua danh sach: ";
			cin >> size;
			Nhap(A, size);
			break;
		}
		case 2:
		{
			cout << "Nhap phan tu muon them vao danh sach: ";
			cin >> x;
			if (KTgiam(A, size) || KTtang(A, size))
				ThemSo(A, size, x);
			else
				cout << "Mang chua duoc sap xep, moi thu lai" << endl;
			break;
		}
		case 3:
		{
			cout << "Danh sach da duoc xuat ra: " << endl;
			Xuat(A, size);
			break;
		}
		case 4:
		{
			cout << "Moi nhap so muon tim trong DS: ";
			cin >> x;
			start = clock();
			if (Search(x, A, size) == -1)
				cout << "So khong co trong mang" << endl;
			else
				cout << "So " << x << " duoc tim thay o vi tri " << Search(x, A, size) << endl;
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "Thoi gian hao ton: " << duration * 100000 << " microseconds " << endl;
			break;
		}
		case 5:
		{
			cout << "Moi nhap so can tim vao DS: ";
			cin >> x;
			start = clock();
			if (KTgiam(A, size) || KTtang(A, size))
				if (Search2(x, A, size) == -1)
					cout << "So khong co trong mang" << endl;
				else
					cout << "So " << x << " duoc tim thay o vi tri " << Search2(x, A, size) << endl;
			duration = (clock() - start) / (double)CLOCKS_PER_SEC;
			if (duration > 0)
				cout << "Thoi gian hao ton: " << duration * 100000 << " microseconds " << endl;
			break;
		}
		case 6:
		{
			cout << "Nhap phan tu can tim va xoa";
			cin >> x;
			SAD(A, size, x);
			break;
		}
		case 7:
		{
			cout << "Ban da chon thoat" << endl;
			break;
		}
		}
	} while (choice != 7);
	system("pause");
	return 0;


}