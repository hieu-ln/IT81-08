//#include <iostream>
//#include <iomanip>
//using namespace std;
//
////Cau 1.1
//#define MAX 100
//int a[MAX];
//int n;
//
////Cau 1.2
//void insert_list(int a[], int &n)
//{
//	for (int i = 0; i < n; i++)
//		a[i] = rand() % 10;
//}
//
////Cau 1.3
//void out_list(int a[], int n)
//{
//	for (int i = 0; i < n; i++)
//		cout << setw(6) << a[i];
//}
//
////Cau 1.4
//int search1(int a[], int n, int x)
//{
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == x)
//			return 1;
//	}
//	return 0;
//}
//
////Cau 1.5
//int insert_last(int a[], int &n, int x)
//{
//	n++;
//	if (n < MAX)
//	{
//		a[n-1] = x;
//		return 1;
//	}
//	else
//		return 0;
//}
//
////Cau 1.6
//void delete_last(int a[], int &n)
//{
//	n--;
//}
//
////Cau 1.7
//int delete_i(int a[], int &n, int vt)
//{
//	if (vt < n)
//	{
//		for (int i = vt; i < n; i++)
//			a[i] = a[i + 1];
//		n--;
//		return 1;
//	}
//	else
//		return 0;		
//}
//
////Cau 1.8
//int search_delete(int a[], int &n, int x)
//{
//	int dem = 0;
//	for (int i = 0; i < n; i++)
//	{
//		if (a[i] == x)
//		{
//			dem++;
//			for (int j = i; j < n; j++)
//				a[j] = a[j + 1];
//			i--;
//			n--;
//		}
//	}
//	return dem;
//}
//
//int main()
//{
//	int vt, x,choice=0;
//
//	cout << "---Bai 1, Chuong 2, DANH SACH DAC---" << endl
//		<< "1. Nhap danh sach" << endl
//		<< "2. Xuat danh sach" << endl
//		<< "3. Tim 1 phan tu gia tri x trong danh sach" << endl
//		<< "4. Them 1 phan tu vao cuoi danh sach" << endl
//		<< "5. Xoa 1 phan tu o cuoi danh sach" << endl
//		<< "6. Xoa phan tu o vi tri nhap" << endl
//		<< "7. Tim va xoa phan tu trong danh sach (neu co)" << endl
//		<< "8. Thoat" << endl;
//	do {
//		cout << "Nhap so phan tu cho danh sach: ";
//		cin >> n;
//		if (n <= 0 || n > MAX)
//			cout << "Loi nhap lieu! Nhap lai!";
//	} while (n <= 0 || n > MAX);
//	do {
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//
//		switch (choice) 
//		{
//		case 1:
//			insert_list(a, n);
//			break;
//		case 2:
//			cout<<"Danh sach hien tai: ";
//			out_list(a, n);
//			break;
//		case 3:
//			cout << "Nhap gia tri phan tu muon tim: ";
//			cin >> x;
//			if (search1(a, n, x) == 1)
//				cout << "\nTim thay " << x << " trong danh sach!";
//			else
//				cout << "\nKhong tim thay gia tri vua nhap!";
//			break;
//		case 4:
//			cout << "Nhap gia tri phan tu muon them vao: ";
//			cin >> x;
//			if (insert_last(a, n, x) == 1)
//				cout << "\nDa them " << x << " vao danh sach!";
//			else
//				cout << "\nVuot qua so luong toi da!!!";
//			break;
//		case 5:
//			delete_last(a, n);
//			out_list(a, n);
//			break;
//		case 6:
//			cout << "Nhap vi tri muon xoa: ";
//			cin >> vt;
//			if (delete_i(a, n, vt) == 1)
//				cout << "\nDa xoa phan tu o vi tri " << vt << "!";
//			else
//				cout << "\nLoi nhap lieu!";
//			break;
//		case 7:
//			cout << "Nhap gia tri phan tu muon xoa: ";
//			cin >> x;
//			if (search_delete(a, n, x) != 0)
//				out_list(a, n);
//			else
//				cout << "Khong co gia tri vua nhap trong danh sach!";
//			break;
//		case 8:
//			cout << "Goodbye!";
//			break;
//		default:
//			cout << "Loi nhap lieu! Nhap lai!";
//			break;
//		}
//	} while (choice != 8);
//	
//	cout << endl;
//	system("pause");
//	return 0;
//}