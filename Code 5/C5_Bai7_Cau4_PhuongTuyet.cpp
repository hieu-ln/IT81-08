//#include <iostream>
//#include <fstream>
//using namespace std;
//
//#define MAX 20
//int A[MAX][MAX];
//int n;
//char vertex[MAX];
//
//void initGraph()
//{
//	n = 0;
//}
//
//void inputGraphFromText()
//{
//	string line;
//	ifstream myfile("matranke51.txt");
//	if (myfile.is_open())
//	{
//		myfile >> n;
//		for (int i = 0; i < n; i++)
//			myfile >> vertex[i];
//		for (int i = 0; i < n; i++)
//		{
//			for (int j = 0; j < n; j++)
//				myfile >> A[i][j];
//		}
//	}
//}
//
//void outputGraph()
//{
//	for (int i = 0; i < n; i++)
//	{
//		for (int j = 0; j < n; j++)
//			cout << A[i][j] << "  ";
//		cout << endl;
//	}
//}
//
////STACK
//int a[MAX];//Khai bao stack - ds dac
//int sp;
//
//void initS(int a[], int &sp)
//{
//	sp = -1;
//}
//
//void Push(int a[], int &sp, int x)
//{
//	if (sp < MAX - 1)
//		a[++sp] = x;
//}
//
//void Pop(int a[], int &sp, int &x)
//{
//	if (sp != -1)
//		x = a[sp--];
//}
//
//int isEmpty(int a[], int sp)
//{
//	if (sp == -1)
//		return 1;
//	return 0;
//}
//
////End STACK
//
////Duyet DFS
//int C[7];
//int dfs[MAX];
//int ndfs = 0;
//
//void init()
//{
//	for (int i = 0; i < n; i++)//n la so dinh cua do thi
//		C[i] = 1;
//}
//
//void DFS(int s)//s la dinh bat dau
//{
//	Push(a,sp,s);
//	dfs[ndfs] = s;
//	ndfs++;
//	C[s] = 0;
//	int v = -1, u = s;
//	while (isEmpty(a,sp)!= 1)
//	{
//		if (v == n)
//			Pop(a,sp,u);
//		for (v = 0; v < n; v++)
//		{
//			if (A[u][v] != 0 && C[v] == 1)
//			{
//				Push(a,sp,u);
//				Push(a,sp,v);
//				dfs[ndfs] = v;
//				ndfs++;
//				C[v] = 0;
//				u = v;
//				break;
//			}
//		}
//	}
//}
//
////Xuat tap dfs
//void output()
//{
//	for (int i = 0; i < ndfs; i++)
//		cout << vertex[dfs[i]]<<"  ";
//}
//
//int main()
//{
//	int choice, x;
//	cout << "---BAI 6, CAU 5, CHUONG 5, DUYET DFS---" << endl;
//	cout << "1.Khoi tao ma tran rong" << endl
//		<< "2.Nhap ma tran ke cua do thi 5.1" << endl
//		<< "3.Xuat ma tran ke" << endl
//		<< "4.Duyet do thi theo DFS" << endl
//		<< "5.Thoat" << endl;
//
//	do {
//		cout << "\nVui long nhap so de thuc hien: ";
//		cin >> choice;
//
//		switch (choice)
//		{
//		case 1:
//			initGraph();
//			cout << "Khoi tao ma tran rong thanh cong!";
//			break;
//		case 2:
//			inputGraphFromText();
//			cout << "Ma tran ke" << endl;
//			outputGraph();
//			break;
//		case 3:
//			cout << "Ma tran ke" << endl;
//			outputGraph();
//			break;
//		case 4:
//			cout << "Chon dinh bat dau: ";
//			cin >> x;
//			init();
//			initS(a,sp);
//			DFS(x);
//			output();
//			break;
//		case 5:
//			cout << "Goodbye!";
//			break;
//		default:
//			cout << "Loi nhap lieu!";
//			break;
//		}
//	} while (choice != 5);
//
//	cout << endl;
//	system("pause");
//	return 0;
//}