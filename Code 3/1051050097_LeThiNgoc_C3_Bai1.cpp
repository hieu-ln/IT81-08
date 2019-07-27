#include <iostream>
#include <iomanip>
#define Max 100
using namespace std;
int n;
int a[Max];
void init(int a[], int &n)
{
	cout<<"Nhap so luong phan tu: "<<endl;
	cin>>n;
	for(int i=0;i<n;i++)
		a[i]=rand()%100+1;
	cout<<"Danh sach duoc nhap ngau nhien"<<endl;
	for(int i=0;i<n;i++)
		cout<<setw(4)<<a[i];
	cout<<endl;
}
void output(int a[], int n)
{
	for(int i=0;i<n;i++)
		cout<<setw(4)<<a[i];
	cout<<endl;
}
void swap(int &a,int &b)
{
	int temp=a;
	a=b;
	b=temp;
}
void temp( int a[], int b[], int n)
{
	for(int i=0;i<n;i++)
		b[i]=a[i];
}
void insertionsort(int a[],int n)
{
	int x,j;
	for(int i=1;i<n;i++)
	{
		x=a[i];
		j=i-1;
		while(0<=j && x<a[j])
		{
			a[j+1]=a[j];
			j--;
		}
		a[j+1]=x;
	}
}
void selectionsort(int a[], int n)
{
	int min;
	for(int i=0;i<n-1;i++)
	{
		min=i;
		for(int j=i+1;j<n;j++)
			if(a[j]<a[min])
				min=j;
		swap(a[min],a[i]);
	}
}
void interchangesort(int a[], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=i+1;j<n;j++)
			if(a[i]>a[j])
				swap(a[i],a[j]);
}
void bubblesort(int a[], int n)
{
	for(int i=0;i<n-1;i++)
		for(int j=n-1;j>i;j--)
			if(a[j-1]>a[j])
				swap(a[j],a[j-1]);
}
void quicksort(int a[], int left,int right)
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
			i++;
			j--;
		}
	}
	if(left<i)
		quicksort(a,left,j);
	if(i<right)
		quicksort(a,i,right);
}
void shift(int a[],int n,int i)
{
	int largest=i;
	int l=2*i+1;
	int r=2*i+2;
	if(l<n && a[l]>a[largest])
		largest=l;
	if(r<n && a[r]>a[largest])
		largest=r;
	if(largest!=i)
	{
		swap(a[i],a[largest]);
		shift(a,n,largest);
	}
}
void heapsort(int a[], int n)
{
	for(int i=n/2-1;i>=0;i--)
		shift(a,n,i);
	for(int i=n-1;i>=0;i--)
	{
		swap(a[0],a[i]);
		shift(a,i,0);
	}
}

int search(int a[], int n,int x)
{
	int i=0;
	while(i<n && a[i]!=x)
	{
		i++;
	}
	if(i<n)
		return 1;
	return -1;
}
int binarysearch( int a[], int n, int x)
{
	int left=0,right=n-1,mid;
	while(left<=right)
	{
		mid=(left+right)/2;
		if(a[mid]==x)
			return mid;
		if(x>a[mid])
			left=mid+1;
		else
			right=mid-1;
	}
	return -1;
}
int main()
{
	int b[Max];
	int x,i;
	int choice;
	system("cls");
	cout<<"0.Khoi tao danh sach ngau nhien"<<endl;
	cout<<"1.Nhap danh sach"<<endl;
	cout<<"2.Xuat danh sach"<<endl;
	cout<<"3.Insertion Sort"<<endl;
	cout<<"4.Selection Sort"<<endl;
	cout<<"5.Interchange Sort"<<endl;
	cout<<"6.Bubble Sort"<<endl;
	cout<<"7.Quick Sort"<<endl;
	cout<<"8.Heap Sort"<<endl;
	cout<<"9.Tim kiem phan tu bang phuong phap tim kiem tuan tu"<<endl;
	cout<<"10.Tim kiem phan tu bang phuong phap tim tim nhi phan"<<endl;
	cout<<"11.EXIT"<<endl;
	do{
		cout<<"choice: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				init(a,n);
				break;
			case 2:
				cout<<"DANH SACH CAN XEP THU TU"<<endl;
				output(a,n);
				break;
			case 3:
				temp(a,b,n);
				insertionsort(b,n);
				cout<<"Danh sach sau khi thuc hien Insertion Sort: ";
				output(b,n);
				break;
			case 4:
				temp(a,b,n);
				selectionsort(b,n);
				cout<<"danh sach sau khi thuc hien Selection Sort: ";
				output(b,n);
				break;
			case 5:
				temp(a,b,n);
				interchangesort(b,n);
				cout<<"Danh sach sau khi thuc hien Interchange Sort: ";
				output(b,n);
				break;
			case 6:
				temp(a,b,n);
				bubblesort(b,n);
				cout<<"Danh sach sau khi thuc hien Bubble Sort: ";
				output(b,n);
				break;
			case 7:
				temp(a,b,n);
				quicksort(b,0,n-1);
				cout<<"Danh dach phan tu sau khi thuc hien Quick Sort: ";
				output(b,n);
				break;
			case 8:
				temp(a,b,n);
				heapsort(b,n);
				cout<<"Danh sach sau khi thuc hien Heap Sort: ";
				output(b,n);
				break;
			case 9:
				cout<<"Nhap phan tu x can tim kiem: ";
				cin>>x;
				i=search(a,n,x);
				if(i!=-1)
					cout<<"Phan tu "<<x<<" duoc tim thay"<<endl;
				else
					cout<<"Khong tim thay"<<endl;
				break;
			case 10:
				cout<<"Nhap phan tu x can tim: ";
				cin>>x;
				i=binarysearch(a,n,x);
				if(i!=-1)
					cout<<"Tim thay "<<x<<""<<endl;
				else 
					cout<<"Khong tim thay"<<endl;
				break;
			case 11:
				cout<<"EXIT !!"<<endl;
			default:
				break;
		}
	}while(choice!=11);
	system("pause");
	return 0;
}
