//#include <iostream>
//using namespace std;
//#define maxsize 100
//int n, m, chon;
//int a[maxsize];
//int b[maxsize];
//void nhap(int a[], int &n)
//{
//	do
//	{
//		cout << "Nhap so luong phan tu cho danh sach (0 <= n <=100 ): \n";
//		cin >> n;
//		if (n <= 0 || n > maxsize)
//			cout << "Nhap sai moi nhap lai\n";
//	} while (n <= 0 || n > maxsize);
//	for (int i = 0; i < n; i++)
//	{
//		cout << "a[" << i << "]= ";
//		cin >> a[i];
//	}
//}
//void nhap1(int b[], int &m)
//{
//	do
//	{
//		cout << "Nhap so luong phan tu cho danh sach (0 <= m <=100 ): \n";
//		cin >> m;
//		if (m <= 0 || m > maxsize)
//			cout << "Nhap sai moi nhap lai\n";
//	} while (m <= 0 || m > maxsize);
//	for (int i = 0; i < m; i++)
//	{
//		cout << "b[" << i << "]= ";
//		cin >> b[i];
//	}
//}
//void xuatds(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << a[i] << " ";
//}
//void giao(int a[], int b[], int n, int m)
//{
//	int i = 0, j = 0;
//	while (i < n&&j < m)
//	{
//		if (a[i] < b[j])
//			i++;
//		else
//			if (b[j] < a[i])
//				j++;
//			else
//			{
//				cout << a[i] << "\t";
//				i++;
//				j++;
//			}
//	}
//}
//void Bu(int a[], int b[], int n, int m)
//{
//	int i = 0, j = 0;
//	while (i < n&&j < m)
//	{
//		if (b[j] != a[i])
//		{
//			cout << b[j] << "\t ";
//			j++;
//		}
//		else
//		{
//			i++;
//			j++;
//		}
//	}
//}
//int main()
//{
//	cout << "-----Bai tap 15-----Chuong 2-----Giao va Phan Bu hai danh sach\n";
//	cout << "1. Nhap danh sach thu 1\n";
//	cout << "2. Nhap danh sach thu 2\n";
//	cout << "3. Xuat danh sach thu 1\n";
//	cout << "4. Xuat danh sach thu 2\n";
//	cout << "5. Giao 2 danh sach\n";
//	cout << "6. Phan bu cua 2 danh sach\n";
//	cout << "7. Thoat\n";
//	do
//	{
//		cout << "\nBan chon: ";
//		cin >> chon;
//		switch (chon)
//		{
//			case 1:
//				nhap(a, n);
//				break;
//			case 2:
//				nhap1(b, m);
//				break;
//			case 3:
//				cout << "Danh sach sau khi nhap: " << endl;
//				xuatds(a, n);
//				break;
//			case 4:
//				cout << "Danh sach sau khi nhap: " << endl;
//				xuatds(b, m);
//				break;
//			case 5:
//				cout << "Cac phan tu thuoc tap giao cua hai danh sach:\n";
//				giao(a, b, n, m);
//				break;
//			case 6:
//				cout << "Phan bu cua 2 danh sach: " << endl;
//				Bu(a, b, n, m);
//				break;
//		default:
//			cout << "Baiiiiiii~~~~~~~~" << endl;
//			break;
//		}
//		
//	} while (chon!=7);
//	system("pause");
//	return 0;
//}