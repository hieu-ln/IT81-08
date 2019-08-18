//#include <stdio.h>
//#include <iostream>
//#include <fstream>
//#include <sstream>
//#include <iomanip>
//using namespace std;
//
////khai bao ma tran mang hai chieu
//#define MAX 20
//int a[MAX][MAX];
//int n;//so dinh cua do thi
//char vertex[MAX];//ten dinh
//
////khai bao Tap E
//int E1[MAX];
//int E2[MAX];
//int wE[MAX];
//int nE = 0;//so phan tu tap E
//
////khai bao Tap T
//int T1[MAX];
//int T2[MAX];
//int wT[MAX];
//int nT = 0;//so phan tu tap T
//
//void swap(int a, int b)
//{
//	int tam = a;
//	a = b;
//	b = tam;
//}
//
//void initGraph()
//{
//	n = 0;
//}
//
//void inputGraphFromText()
//{
//	string line;
//	ifstream myfile("matrantrongso1.txt");
//	if (myfile.is_open())
//	{
//		myfile >> n;
//		for (int i = 0; i < n; i++)
//			myfile >> vertex[i];
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//				myfile >> a[i][j];
//		}
//	}
//}
//
////Xuat ma tran ke cua do thi
//void outputGraph()
//{
//	cout << setw(6) << left;
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cout << a[i][j] << setw(6) << left;
//		cout << endl;
//	}
//}
//
//void taoE()
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//		{
//			if (a[i][j] != 0)
//			{
//				E1[nE] = i;
//				E2[nE] = j;
//
//				wE[nE] = a[i][j];
//				a[i][j] = 0;
//				a[j][i] = 0;
//				nE++;
//			}
//		}
//	}
//}
//
//int tontai(int d, int D[], int nD)
//{
//	for (int i = 0; i < n; i++)
//		if (D[i] == d)
//			return 1;
//	return 0;
//}
//
//void kruskal()
//{
//	taoE();
//
//	for (int i = 0; i < nE; i++)
//	{
//		if ((tontai(E1[i], T1, nT) == 1) && (tontai(E2[i], T2, nT) == 1))
//			continue;
//		if ((tontai(E1[i], T2, nT) == 1) && (tontai(E2[i], T1, nT) == 1))
//			continue;
//		T1[nT] = E1[i];
//		T2[nT] = E2[i];
//		wT[nT] = wE[i];
//		nT++;
//		if (nT == n - 1)
//			break;
//	}
//}
//
//void output(bool vertexname)
//{
//	int tong = 0;
//	for (int i = 0; i < nT; i++)
//	{
//		if (vertexname)
//			cout << endl << "(" << vertex[T1[i]] << "," << vertex[T2[i]] << ") = " << wT[i];
//		else
//			cout << endl << "(" << T1[i] << "," << T2[i] << ") = " << wT[i];
//		tong += wT[i];
//	}
//	cout << "\nTong=" << tong;
//}
//
//int main()
//{
//	int choice;
//
//	cout << "---BAI 5, CHUONG 6, TIM KIEM CAY KHUNG TOI TIEU- KRUSKAL---" << endl;
//	cout << "1.Khoi tao MA TRAN KE rong" << endl
//		<< "2.Nhap MA TRAN KE tu file text" << endl
//		<< "3.Xuat MA TRAN KE" << endl
//		<< "4.Tim CAY KHUNG TOI TIEU bang KRUSKAL" << endl
//		<< "5.Thoat" << endl;
//
//	do {
//		cout << "\nVui long chon so de thuc hien: ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			initGraph();
//			break;
//		case 2:
//			inputGraphFromText();
//			cout << "Da nhap ma tran ke tu file thanh cong!"<<endl;
//			outputGraph();
//			break;
//		case 3:
//			outputGraph();
//			break;
//		case 4:
//			kruskal();
//			cout << "Cay khung toi tieu theo KRUSKAL: ";
//			output(true);
//			break;
//		case 5:
//			cout << "Goodbye!";
//			break;
//		default:
//			break;
//		}
//	} while (choice != 5);
//
//	cout << endl;
//	system("pause");
//	return 0;
//}