#include <iostream>
using namespace std;
#define max 100

int a[max];
int sp;

void Init(int a[], int &sp)
{
	sp = -1;
}

int Rong(int a[], int sp)
{
	if (sp == -1)
		return 1;
	return 0;
}

int Day (int a[], int sp)
{
	if (sp == max - 1)
		return 1;
	return 0;
}

void Add(int a[], int &sp,int x)
{
	if (sp<max-1)
	{
		a[++sp]=x;
	}
}

int Del(int a[], int &sp,int &x)
{
	if (Rong(a,sp) == 0)
	{
		x = a[sp--];
		return 1;
	}
	return 0;
}
void Output(int a[], int sp)
{
	for (int i = 0; i < sp+1 ; i++)
	{
		cout << a[i] << " ";
	}
	cout << "\n" ;
}
int main()
{
	int sp, chon, x, y;
	do
	{
		cout << "----------Bai tap 5----------Chuong 2---------MENU--------" << "\n" ;
		cout << "1. Khoi tao stack rong\n";
		cout << "2. Kiem tra stack rong\n";
		cout << "3. Kiem tra stack day\n";
		cout << "4. Them mot phan tu vao stack\n";
		cout << "5. Xoa mot phan tu trong stack\n";
		cout << "6. THOAT!\n";
		cout << "Vui long nhap yeu cau can thuc hien: ";
		cin >> chon;
		switch (chon)
		{
		case 1:
			Init(a, sp);
			cout << "Khoi tao stack rong thanh cong\n";
			break;
		case 2:
			if (Rong(a, sp) == 0)
				cout << "Stack khong rong\n";
			else
				cout << "Stack rong\n";
			break;
		case 3:
			if (Day(a, sp) == 1)
				cout << "STACK DAY!!\n";
			else
				cout << "Stack van chua day\n";
			break;
		case 4:
			cout << "Nhap phan tu can them vao stack\n";
			cin >> x;
			Add(a, sp, x);
			cout << "Danh sach stack sau khi duoc them: " << "\n";
			Output(a, sp);
			break;
		case 5:
			cout << "Nhap phan tu muon xoa trong stack\n";
			cin >> y;
			if (Del(a, sp, y) == 1)
			{
				cout << "Xoa thanh cong\n";
			}
			else
				cout << "Xoa that bai\n";
			Output(a, sp);
			break;
		default:
			break;
		}
	} while (chon != 6);
	system("pause");
	return 0;
}  