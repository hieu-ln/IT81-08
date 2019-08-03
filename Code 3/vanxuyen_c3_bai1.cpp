#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;
#define MAX 3000

//cau 1.1: khai bao ds
int a[MAX];
int n;

//cau 1.2: nhap ds
void init(int a[], int &n)
{
	cout<<"Nhap so luong phan tu vao danh sach: ";
	cin>>n;
	for(int i=0; i<n; i++)
		a[i]=rand()%1000;
}

//cau 1.3: xuat ds
void outlist(int a[], int n)
{
	for(int i=0; i<n; i++)
		cout<<a[i]<<" ";
	cout<<endl;
}
void copyarray (int a[], int b[], int n)
{
	for(int i=0; i<n; i++)
		b[i]=a[i];
}

//cau 1.4: InsertionSort
void InsertionSort(int a[], int n)
{
	int i, key, j;
	for(i=0; i<n; i++)
	{
		key=a[i];
		j=i-1;
		while(j>=0 && a[j] > key)
		{
			a[j+1]=a[j];
			j=j-1;
		}
		a[j+1]=key;
	}
}
 //ham doi cho hai so nguyen
void swap(int &a, int &b)
{
	int t=a;
	a=b;
	b=t;
}

//cau 1.5: SelectionSort
void SelectionSort(int a[], int n)
{
	int i,j, min_idx;
	for(i=0; i<n-1; i++)
	{
		min_idx=i;
		for(j=i+1; j<n; j++)
			if(a[j]<a[min_idx])
				min_idx=j;
		swap(a[min_idx],a[i]);
	}
}
 //cau1.6: InterchangeSort
void InterchangeSort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=i+1; j<n; j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
}
//cau 1.7: BubbleSort
void BubbleSort(int a[], int n)
{
	for(int i=0; i<n-1; i++)
		for(int j=n-1; j<i; j--)
			if(a[j-1]>a[j])
				swap(a[j],a[j-1]);
}
//cau 1.8: QuickSort
void QuickSort(int a[], int left, int right)
{
	int x=a[(left+right)/2];
	int i=left;
	int j=right;
	while(i<j)
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;j--;
		}
	}
	if(left<j)
		QuickSort(a,left,j);
	if(i<right)
		QuickSort(a,i,right);
}
//cau 1.9 HeapSort
void shift(int a[], int i, int n)
{
	int j=2*i+1;
	if(j>=n)
		return;
	if(j+1<n)
		if(a[j]<a[j+1])
			j++;
	if(a[i]>=a[j])
		return;
	else
	{
		int x=a[i];
		a[i]=a[j];
		a[j]=x;
		shift(a,j,n);
	}
}
void HeapSort(int a[], int n)
{
	int i=n/2;
	while(i>=0)
	{
		shift(a,i,n-1);
		i--;
	}
	int right=n-1;
	while(right>0)
	{
		swap(a[0], a[right]);
		right--;
		if(right>0)
			shift(a, 0, right);
	}
}

//cau 1.10 tim kiem tuan tu
void TKTT(int a[], int n, int x)
{
	int i=0;
	while(i<n && a[i]!=x)
	{
		i++;
	}
	if(i==n)
	{
		cout<<"Khong tim thay!\n";
	}
	else
		cout<<"Tim thay tai vi tri "<<i<<endl;
}

//cau 1.11 Tim kiem nhi phan
int TKNP(int a[], int l, int r, int x)
{
	if(r>=1)
	{
		int mid=l+(r-1)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid]>x)
			return TKNP(a, 1, mid-1, x);
		return TKNP(a, mid+1, r, x);
	}
	return -1;
}

//main
int main()
{
	int i, chon, x, b[MAX];
	clock_t start;
	double duration;
	cout<<"Bai 1-----Chuong 3-----Xep Thu Tu\n";
	cout<<"1. Nhap danh sach\n";
	cout<<"2. Xuat danh sach\n";
	cout<<"3. Xep thu tu danh sach bang InsertionSort\n";
	cout<<"4. Xep thu tu danh sach bang SelectionSort\n";
	cout<<"5. Xep thu tu danh sach bang InterchangeSort\n";
	cout<<"6. Xep thu tu danh sach bang BubbleSort\n";
	cout<<"7. Xep thu tu danh sach bang QuickSort\n";
	cout<<"8. Xep thu tu danh sach bang HeapSort\n";
	cout<<"9. Tim kiem phan tu x bang Tim Kiem Tuan Tu\n";
	cout<<"10. Tim kiem phan tu x bang Tim Kiem Nhi Phan\n";
	cout<<"11. Thoat\n";
	do
	{
		cout<<"Vui long chon so de thuc hien: \n";
		cin>>chon;
		switch(chon)
		{
		case 1:
			init(a, n);
			break;
		case 2:
			cout<<"Danh sach la: "<<endl;
			outlist(a, n);
			break;
		case 3:
			copyarray(a, b, n);
			start=clock();
			InsertionSort(b, n);
			duration=(clock()-start)/ (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi xep thu tu voi InsertionSort la: "<<endl;
				outlist(b, n);
			}
			if(duration>0)
			{
				cout<<"Thoi gian InsertionSort: "<<duration*1000000<<"Microseconds"<<endl;
			}
			break;
		case 4:
			copyarray(a, b, n);
			start=clock();
			SelectionSort(b, n);
			duration=(clock()-start)/ (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi xep thu tu voi SelectionSort la: "<<endl;
				outlist(b, n);
			}
			if(duration>0)
			{
				cout<<"Thoi gian SelectionSort: "<<duration*1000000<<"Microseconds"<<endl;
			}
			break;
		case 5:
			copyarray(a, b, n);
			start=clock();
			InterchangeSort(b, n);
			duration=(clock()-start)/ (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi xep thu tu voi InterchangeSort la: "<<endl;
				outlist(b, n);
			}
			if(duration>0)
			{
				cout<<"Thoi gian InterchangeSort: "<<duration*1000000<<"Microseconds"<<endl;
			}
			break;
		case 6:
			copyarray(a, b, n);
			start=clock();
			BubbleSort(b, n);
			duration=(clock()-start)/ (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi xep thu tu voi BubbleSort la: "<<endl;
				outlist(b, n);
			}
			if(duration>0)
			{
				cout<<"Thoi gian BubbleSort: "<<duration*1000000<<"Microseconds"<<endl;
			}
			break;
		case 7:
			copyarray(a, b, n);
			start=clock();
			QuickSort(b, 0, n-1);
			duration=(clock()-start)/ (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi xep thu tu voi QuickSort la: "<<endl;
				outlist(b, n);
			}
			if(duration>0)
			{
				cout<<"Thoi gian QuickSort: "<<duration*1000000<<"Microseconds"<<endl;
			}
			break;
		case 8:
			copyarray(a, b, n);
			start=clock();
			HeapSort(b, n);
			duration=(clock()-start)/ (double) CLOCKS_PER_SEC;
			if(n<100)
			{
				cout<<"Danh sach sau khi xep thu tu voi HeapSort la: "<<endl;
				outlist(b, n);
			}
			if(duration>0)
			{
				cout<<"Thoi gian HeapSort: "<<duration*1000000<<"Microseconds"<<endl;
			}
			break;
		case 9:
			cout<<"Vui long nhap gia tri x: ";
			cin>>x;
			start=clock();
			TKTT(b, n, x);
			duration=(clock()-start)/ (double) CLOCKS_PER_SEC;
			if(duration>0)
			{
				cout<<"Thoi gian tim kiem tuan tu: "<<duration*1000000<<"Microseconds"<<endl;
			}
			break;
		case 10:
			cout<<"Vui long nhap gia tri x: ";
			cin>>x;
			start=clock();
			TKNP(b, 0, n, x);
			duration=(clock()-start)/ (double) CLOCKS_PER_SEC;
			if(i==-1)
				cout<<"Khong tim thay x: "<<x<<" trong day!\n";
			else
				cout<<"Tim thay x: "<<x<<" tai vi tri i="<<i<<endl;
			if(duration>0)
			{
				cout<<"Thoi gian tim kiem nhi phan: "<<duration*1000000<<"Microseconds"<<endl;
			}
			break;
		case 11:
			cout<<"Goodbye!\n";
			break;
		default:
			break;
		}
	}while(chon!=11);
	system("pause");
	return 0;
}