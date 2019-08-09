#include <iostream>
#include <fstream>
#include <iomanip>
#define Max 10
using namespace std;
int a[Max][Max];
char vertex[Max];
int n;///so dinh cua do thi
int e1[Max];
int e2[Max];
int we[Max];
int ne=0;///so phan tu tap
int t1[Max];
int t2[Max];
int wt[Max];
int nt=0;//so phan tap t
void init()
{
	n=0;
}
void input()
{
	cout<<"Nhap so dinh cua do thi: ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap ten dinh cua do thi: ";
		cin>>vertex[i];
		cout<<"Nhap vao dong thu "<<i+1<<": ";
		for(int j=0;j<n;j++)
			cin>>a[i][j];
	}
}
void inputfromfile()
{
	ifstream inFile;
	inFile.open("demo.txt");
	if(inFile.is_open())
	{
		inFile >> n;
		for(int i=0;i<n;i++)
			inFile >> vertex[i];
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				inFile >> a[i][j];
		cout<<"Doc thanh cong!!"<<endl;
		inFile.close();
	}
	cout<<"Khong mo duoc file de doc"<<endl;
}
void outputG()
{ 
	cout<<"    ";
	for(int i=0;i<n;i++)
		cout<<setw(4)<<vertex[i];
	cout<<endl;
	//for(int i=0;i<4+n+n;i++)
	//	cout<<"-";
	//cout<<endl;
	for(int i=0;i<n;i++)
	{
		cout<<setw(4)<<vertex[i];
		for(int j=0;j<n;j++)
			cout<<setw(4)<<a[i][j];
		cout<<endl;
	}
}
 int tontai(int d, int D[], int nD)
 {
	 for(int i=0;i>nD;i++)
		 if(D[i]==d)
			 return 1;
	 return 0;
 }
 void xoavitrie(int i)
 {
	 for(int j=i;j<ne;j++)
	 {
		 e1[j]=e1[j+1];
		 e2[j]=e2[j+1];
		 we[j]=we[j+1];
	 }
	 ne--;
 }
 void xoacanhe( int u, int v)
 {
	 for(int i=0;i<ne;i++)
		 if(e1[i]==u && e2[i]==v)
		 {
			 xoavitrie(i);
			 break;
		 }
 }
void prim(int s)//s la dinh bat dau tim
{
	int u=s;
	int min, i, d1, d2;
	while(nt<n-1)
	{
		for(int v=0;v<n;v++)
			if(a[u][v]!=0)
				if(tontai(v, t2, nt)==0)
				{
					e1[ne]=u;
					e2[ne]=v;
					we[ne]=a[u][v];
					ne++;
				}
				for(i=0;i<ne;i++)
					if(tontai(e2[i], t2, nt)==0)
					{
						min=we[i];
						d1=e1[i];
						d2=e2[i];
						break;
					}
					for(i=0;i<ne;i++)
						if(tontai(e2[i], t2, nt)==0)
							if(min > we[i])
							{
								min=we[i];
								d1=e1[i];
								d2=e2[i];
							}
							t1[nt]=d1;
							t2[nt]=d2;
							wt[nt]=a[d1][d2];
							a[d1][d2]=0;
							a[d2][d1]=0;
							nt++;
							xoacanhe(d1,d2);
							u=d2;
	}
}
void output()
{
		int tong=0;
		for(int i=0;i<nt;i++)
		{
			cout<<endl<<"("<<t1[i]<<","<<t2[i]<<")="<<wt[i];
			tong=tong+wt[i];
		}
		cout<<"\nTong : "<<tong<<endl;
}
void swap(int &a, int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void taoe()
{
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				if(a[i][j]!=0)
				{
					e1[ne]=i;
					e2[ne]=j;
					we[ne]=a[i][j];
					a[i][j]=0;
					a[j][i]=0;
					ne++;
				}
}
void sort()
{
	for(int i=0;i<ne;i++)
		for(int j=i+1;j<ne;j++)
			if(we[i]> we[j])
			{
				swap(we[i],we[j]);
				swap(e1[i],e1[j]);
				swap(e2[i],e2[j]);
			}
}
void kruskal()
{
	for(int i=0;i<ne;i++)
	{
		if(tontai(e1[i], t1 , nt)==1 && tontai(e2[i], t2, nt)==1)
			continue;
		if(tontai(e1[i], t2, nt)==1 && tontai(e2[i], t1, nt)==1)
			continue;
		t1[nt]=e1[i];
		t2[nt]=e2[i];
		wt[nt]=we[i];
		nt++;
		if(nt==n-1)
			break;
	}
}
int main()
{
	int choice;
	system("cls");
	cout<<"1.Khoi tao ma tran trong so"<<endl;
	cout<<"2.Nhap ma tran trong so"<<endl;
	cout<<"3.Xuat ma tran trong so"<<endl;
	cout<<"4.Tim Prim"<<endl;
	cout<<"5.Tim kruskal"<<endl;
	cout<<"6.Nhap tu file"<<endl;
	cout<<"7.E X I T "<<endl;
	
	do{
		cout<<"Nhap lua chon de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				init();
				break;
			case 2:
				cout<<"NHAP MA TRAN TRONG SO !"<<endl;
				input();
				break;
			case 3:
				cout<<"MA TRAN TRONG SO VUA NHAP !"<<endl;
				outputG();
				break;
			case 4:
				int x;
				cout<<"Nhap dinh bat dau tim: ";
				cin>>x;
				prim(x);
				output();
				break;
			case 5:
				sort();
				taoe();
				kruskal();
				output();
				break;
			case 6:
				inputfromfile();
				break;
			case 7: 
				cout<<"E X I T"<<endl;
				break;
			default:
				break;
		}
	}while(choice!=7);
	system("pause");
	return 0;
}