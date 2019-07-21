//#include <iostream>
//#include <iomanip>
//#include <stdlib.h>
//using namespace std;
////cau1.1
//#define MAX 100
//int a[MAX];
//int n;
////cau 1.2
//void input(int a[], int &n)
//{
//	for (int i = 0; i < n; i++)
//	{
//		cout << "a[" << i << "]=";
//		cin >> a[i];
//	}
//}
////cau 1.3
//void output(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << a[i] << endl;
//}
////cau 1.4
//int search(int a[], int n, int x)
//{
//	int i = 0;
//	while (i < n && a[i] != x)
//		i++;
//	if (i == n)
//		return -1;
//	else
//		return i;
//}
////cau 1.5
//int insert_last(int a[], int &n, int x)
//{
//	n++;
//	a[n - 1] = x;
//	return 1;
//}
////cau 1.6
//void delete_last(int a[], int &n)
//{
//	n--;
//}
////cau 1.7
//int Delete(int a[], int &n, int i)
//{
//	if (i >= 0 && i < n)
//	{
//		for (int j = i; j < n - 1; j++)
//			a[j] = a[j + 1];
//		n--;
//		return 1;
//	}
//	return 0;
//}
////cau 1.8
//int search_delete(int a[], int &n, int x)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == x)
//		{
//			Delete(a, n, i);
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int choice = 0;
//	int x;
//	int i;
//	system("cls");
//	cout << "-------  Bai Tap 1 , Chuong 2 , Dang Sach Dac  ---------" << endl;
//	cout << "1. Nhap danh sach" << endl;
//	cout << "2. Xuat danh sach" << endl;
//	cout << "3. Tim phan tu co gia tri x trong danh sach" << endl;
//	cout << "4. Them phan tu vao cuoi danh sach" << endl;
//	cout << "5. Xoa phan tu cuoi danh sach" << endl;
//	cout << "6. Xoa phan tu tai vi tri i" << endl;
//	cout << "7. Tim phan tu x va xoa neu co" << endl;
//	cout << "8. Thoat" << endl;
//	do
//	{
//		cout << "Vui long chon so de thuc hien: ";
//		cin >> choice;
//		switch (choice)
//		{
//		case 1:
//			input(a, n);
//			cout << "Ban vua nhap danh sach thanh cong\n";
//			break;
//		case 2:
//			cout << "Danh sach da nhap la: \n";
//			output(a, n);
//			break;
//		case 3:
//			cout << "Vui long nhap so x can tim: \n";
//			cin >> x;
//			i = search(a, n, x);
//			if (i = -1)
//				cout << "Khong tim thay phan tu x=" << x << endl;
//			else
//				cout << "Tim thay phan tu x=" << i << endl;
//			break;
//		case 4:
//			cout << "Vui long nhap x can them vao cuoi danh sach: ";
//			cin >> x;
//			i = insert_last(a, n, x);
//			if (i == 0)
//				cout << "Danh sach da day, khong the them!" << x << endl;
//			else
//				cout << "Them thanh cong!" << i << endl;
//			break;
//		case 5:
//			cout << "Xoa phan tu cuoi danh sach: ";
//			delete_last(a, n);
//			break;
//		case 6:
//			cout << "Vui long nhap vi tri can xoa i= ";
//			cin >> i;
//			i = Delete(a, n, i);
//			if (i == 1)
//			{
//				cout << "Xoa thanh cong!" << endl;
//				cout << "Danh sach sau khi xoa la: ";
//				output(a, n);
//			}
//			else
//				cout << "Khong co phan tu nao de xoa!" << endl;
//			break;
//		case 7:
//			cout << "Vui long nhap gia tri can xoa x=: ";
//			cin >> x;
//			i = search_delete(a, n, x);
//			if (i == 1)
//			{
//				cout << "Xoa thanh cong!" << x << endl;
//				cout << "Danh sach sau khi xoa la: ";
//				output(a, n);
//			}
//			else
//				cout << "Khong co phan tu nao de xoa!" << endl;
//			break;
//		case 8:
//			cout << "\nGoodbye!\n";
//			break;
//		default:
//			break;
//		}
//	} while (choice != 8);
//	system("pause");
//	return 0;
//}