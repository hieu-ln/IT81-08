#include <iostream>
#include <stdlib.h>
#include <ctime>
using namespace std;

//Cau 1.1
#define MAX 5000
int a[MAX];
int n;

//Khoi tao danh sach nhap tu dong
void init(int a[], int n)
{
	for(int i=0;i<n;i++)
		a[i]=rand()%1000+1;

	cout<<"DANH SACH VUA NHAP"<<endl;
	for(int i=0;i<n;i++)
		cout<<a[i]<<"     ";
	cout<<endl;
}

//Cau 1.2
void insert_list(int a[], int n)
{
	for(int i=0;i<n;i++)
	{
		cout<<"Nhap phan tu thu "<<i<<": ";
		cin>>a[i];
		cout<<endl;
	}
}

void copy_array(int a[], int b[], int n)
{
	for(int i=0;i<n;i++)
		b[i]=a[i];
}

void swap(int &a, int &b)
{
	int tam;
	tam=a;
	a=b;
	b=tam;
}

//Cau 1.3
void out_list(int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<a[i]<<"   ";
	cout<<endl;
}

//Cau 1.4
void insert_sort(int a[], int n)
{
	int x, j,i=0;

	for(int i=1;i<n;i++)
	{
		x=a[i];
		j=i-1;
		while(j>=0&&a[j]>x)
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}

//Cau 1.5
void select_sort(int a[], int n)
{
	int min_pos,j;
	for(int i=0;i<n-1;i++)
	{
		min_pos=i;
		for(j=i+1;j<n;j++)
			if(a[min_pos]>a[j])
				min_pos=j;
		swap(a[min_pos],a[i]);
	}
}

//Cau 1.6
void inter_sort(int a[], int n)
{
	for(int i=0;i<n-1;i++)
	{
		for(int j=0;j<n;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
	}
}

//Cau 1.7
void bubble_sort(int a[], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=n-1;j>i;j--)
			if(a[j]<a[j-1])
				swap(a[j],a[j-1]);
}

//Cau 1.8
void quick_sort(int a[], int l, int r)
{
	int x=a[(r+l)/2],i=l,j=r;

	while(i<j)
	{
		while(a[i]<x)
			i++;
		while(a[j]>x)
			j--;
		if(i<=j)
		{
			swap(a[i],a[j]);
			i++;
			j--;
		}
		if(i<r)
			quick_sort(a,i,r);
		if(l<j)
			quick_sort(a,l,j);
	}
}

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

//Cau 1.9
void heap_sort(int a[], int n)
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
		swap(a[0],a[right]);
		right--;
		if(right>0)
			shift(a,0,right);
	}
}

int find1(int a[], int n, int x)
{
	for(int i=0;i<n;i++)
		if(a[i]==x)
			return 1;
	return 0;
}

int find2(int a[], int l, int r, int x)
{
	if(r>=1)
	{
		int mid=l+(r-1)/2;
		if(a[mid]==x)
			return mid;
		if(a[mid]>x)
			return find2(a,l,mid-1,x);
		return find2(a,mid+1,r,x);
	}
	return -1;
}

int main()
{
	int b[MAX], choice=0,x,i;
	clock_t start;
	double duration;
	cout<<"Bai 1, Chuong 3, XEP THU TU - DANH SACH DAC"<<endl;
	cout<<"1. Nhap danh sach"<<endl
		<<"2. Nhap danh sach tu dong"<<endl
		<<"3. Copy danh sach"<<endl
		<<"4. Sap xep danh sach theo thuat toan Insertion Sort"<<endl
		<<"5. Sap xep danh sach theo thuat toan Selection Sort"<<endl
		<<"6. Sap xep danh sach theo thuat toan Interchange Sort"<<endl
		<<"7. Sap xep danh sach theo thuat toan Bubble Sort"<<endl
		<<"8. Sap xep danh sach theo thuat toan Quick Sort"<<endl
		<<"9. Sap xep danh sach theo thuat toan Heap Sort"<<endl
		<<"10. Tim kiem 1 phan tu gia tri x bang tim kiem tuan tu"<<endl
		<<"11. Tim kiem 1 phan tu gia tri x bang tim kiem nhi phan"<<endl
		<<"12. Xuat danh sach"<<endl
		<<"13.Thoat"<<endl;

	cout<<"Nhap so luong phan tu cho dnah sach: ";
	cin>>n;

	do{
		cout<<"\nVui long chon so de thuc hien: ";
		cin>>choice;

		switch(choice)
		{
		case 1:
			insert_list(a,n);
			break;
		case 2:
			init(a,n);
			break;
		case 3:
			copy_array(a,b,n);
			break;
		case 4:
			copy_array(a,b,n);
			start=clock();
			insert_sort(b,n);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			cout<<"Danh sach hien tai: ";
			out_list(b,n);
			if(duration>0)
				cout<<"\nThoi gian sap xep theo INSERTION SORT la: "<<duration*1000000<<"Microseconds"<<endl;
			break;
		case 5:
			copy_array(a,b,n);
			start=clock();
			select_sort(b,n);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			cout<<"Danh sach hien tai: ";
			if(duration>0)
				cout<<"\nThoi gian sap xep theo SELECTION SORT la: "<<duration*1000000<<"Microseconds"<<endl;
			out_list(b,n);
			break;
		case 6:
			copy_array(a,b,n);
			start=clock();
			inter_sort(b,n);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			cout<<"Danh sach hien tai: ";
			out_list(b,n);
			if(duration>0)
				cout<<"\nThoi gian sap xep theo INTERCHANGE SORT la: "<<duration*1000000<<"Microseconds"<<endl;
			break;
		case 7:
			copy_array(a,b,n);
			start=clock();
			bubble_sort(b,n);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			cout<<"Danh sach hien tai: ";
			out_list(b,n);
			if(duration>0)
				cout<<"\nThoi gian sap xep theo BUBBLE SORT la: "<<duration*1000000<<"Microseconds"<<endl;
			break;
		case 8:
			copy_array(a,b,n);
			start=clock();
			quick_sort(b,0,n-1);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			cout<<"Danh sach hien tai: ";
			out_list(b,n);
			if(duration>0)
				cout<<"\nThoi gian sap xep theo QUICK SORT la: "<<duration*1000000<<"Microseconds"<<endl;
			break;
		case 9:
			copy_array(a,b,n);
			start=clock();
			heap_sort(b,n);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			cout<<"Danh sach hien tai: ";
			out_list(b,n);
			if(duration>0)
				cout<<"\nThoi gian sap xep theo HEAP SORT la: "<<duration*1000000<<"Microseconds"<<endl;
			break;
		case 10:
			cout<<"Vui long nhap gia tri x=";
			cin>>x;
			start=clock();
			i=find1(a,n,x);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			cout<<"Danh sach hien tai: ";
			out_list(a,n);
			if(i==1)
				cout<<"Tim thay gia tri x="<<x<<" trong danh sach!";
			else
				cout<<"Khong tim thay!";
			if(duration>0)
				cout<<"\nThoi gian tim kiem TUAN TU la: "<<duration*1000000<<"Microseconds"<<endl;
			break;
		case 11:
			cout<<"Vui long nhap gia tri x=";
			cin>>x;
			start=clock();
			copy_array(a,b,n);
			i=find2(b,0,n-1,x);
			duration=(clock()-start)/(double)CLOCKS_PER_SEC;
			if(i==-1)
				cout<<"Khong tim thay x="<<x<<" trong day!"<<endl;
			else
				cout<<"Tim thay x="<<x<<" tai vi tri i="<<i<<endl;
			if(duration>0)
				cout<<"\nThoi gian tim kiem NHI PHAN la: "<<duration*1000000<<"Microseconds"<<endl;
			break;
		case 12:
			cout<<"DANH SACH HIEN TAI"<<endl;
			out_list(b,n);
			break;
		case 13:
			cout<<"Goodbye!";
			break;
		default:
			cout<<"Loi nhap lieu!";
			break;
		}
	}while(choice!=13);

	cout<<endl;
	system("pause");
	return 0;
}