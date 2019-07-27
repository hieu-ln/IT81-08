#include <iostream>
#include <cstdlib>
#include <ctime>
using namespace std;
const int mx = 100;
int A[mx], B[mx];
void Insert_Arr_Rand(int A[mx], int &size)
{
	cout<<"Moi nhap so phan tu cua mang >.<: ";
	cin>>size;
	for (int i =0; i < size; i++)
		A[i] = rand()%10000;
	cout<<"Mang da duoc khoi tao ngau nhien la: "<<endl;
	for (int i =0; i < size; i++)
		cout<<A[i]<<"     ";
}
void Insert_Arr(int A[mx], int &size)
{
	cout<<"Moi nhap so phan tu cua mang >.< : ";
	cin>>size;
	for (int i =0; i < size; i++)
	{
		cout<<"Moi nhap phan tu thu "<<i+1<<": ";
		cin>>A[i];
	}
	cout<<"Mang da duoc khoi tao la: "<<endl;
	for (int i =0; i < size; i++)
		cout<<A[i]<<"     ";
}
void output (int A[mx], int size)
{
	for (int i =0; i < size; i++)
		cout<<A[i]<<"     ";
}
void Change (int A[mx], int B[mx], int size)
{
	for (int i =0; i < size; i++)
		B[i] = A[i];
}
void Swap( int &a, int &b)
{
	int c;
	c=a;
	a=b;
	b =c;
}
//Inter_Sort
void Insertion_Sort (int A[], int n)
{
	int x, i, j;
	for (int i = 1; i <n; i++)
	{
		x = A[i];
		j = i-1;
		while(j>=0 && A[j]>x)
		{
			A[j+1] = A[j];
			j--;
		}
		A[j+1] =x;
	}
}
//Selec_Sort
void Selection_Sort (int A[], int n)
{
	int min_position;
	for(int i = 0; i <n-1; i++)
	{
		min_position = i;
		for( int j = 0; j <n; j++)
		{
			if(A[j]>A[min_position])
			{	min_position = j;
				swap(A[i], A[min_position]);
			}
		}
	}
}
//Interchange_Sort
void Interchange_Sort (int A[], int n)
{
	for(int i = 0; i <n-1; i++)
		for( int j = 0; j <n; j++)
		{
			if(A[j]>A[j])
				swap(A[i], A[j]);
		}
}
//Buuble
void Buuble_Sort (int A[], int n)
{
	int i =0, j = n-1;
	for( i = 0; i < n-1; i++)
	{
		while (j>i)
		{
			if(A[j]<A[j+1])
				swap(A[j],A[j+1]);
			j--;
		}
	}
}
//Qiuck
void Quick_Sort(int A[], int left, int right)
{
	int x = A[(left+right)/2], i = left, j = right;
	while (i <j)
	{
		while (A[i]< x)
			i++;
		while (A[j] > x)
			j--;
		if(i<=j)
		{
			swap(A[i],A[j]);
			i++;
			j--;
		}
		if (left <j)
			Quick_Sort(A,left,j);
		if (right>i)
			Quick_Sort(A,i, right);
	}
}
void shift(int A[], int i, int n)
{
	int j = 2*i +1;
	if (j>=n)
		return ;
	if (j+1 <n)
		if(A[j]<A[j+1])
			j++;
	if(A[i] >= A[j])
		return;
	else
	{
		int x = A[i];
		A[i] =A[j];
		A[j] = x;
		shift(A,j,n);
	}
}
void Heap_Sort(int A[], int n)
{
	int i = n/2;
	while (i>=0)
	{
		shift(A,i, n-1);
		i--;
	}
	int right = n-1;
	while(right>0)
	{
		swap(A[0],A[right]);
		right--;
		if(right>0)
			shift(A,0,right);
	}
}
bool Search_1(int A[], int size, int x)
{
	for (int i = 0; i < size; i++)
		if(A[i] == x)
		{	return true;
			break;
		}
	return false;
}
int Search_2(int A[], int l, int r, int x)
{
	if(r=-1)
	{
		int mid = l +(r-1)/2;
		if(A[mid]==x)

		if(A[mid]>x)
			return Search_2(A,l, mid-1,x);
		return Search_2(A,mid+1,r,x);
	}
}
//MAIN
int main()
{
	int x, size,choice;
	clock_t start;
	double duration;
	cout<<"CIAO~~~~~~~~~~~~~~"<<endl;
	cout<<"Menu"<<endl;
	cout<<"1.  Tao danh sach random ✿◕ ‿ ◕✿"<<endl;
	cout<<"2.  Nhap danh sach ಠ~ಠ"<<endl;
	cout<<"3.  Xuat danh sach (●´ω｀●)"<<endl;
	cout<<"4.  Sap xep danh sach bang thuat toan Insertion Sort (^o^)y"<<endl;
	cout<<"5.  Sap xep danh sach bang thuat toan Selection Sort (O.O)"<<endl;
	cout<<"6.  Sap xep danh sach bang thuat toan Interchange Sort (▰˘◡˘▰) "<<endl;
	cout<<"7.  Sap xep danh sach bang thuat toan Buuble Sort >.<"<<endl;
	cout<<"8.  Sap xep danh sach bang thuat toan Quick Sort (*^ -^*) "<<endl;
	cout<<"9.  Sap xep danh sach bang thuat toan Heap Sort  (`･ω･´) "<<endl;
	cout<<"10. Tim kiem phan tu trong DS co thu tu (tim kiem tuan tu)"<<endl;
	cout<<"11. Tim kiem phan tu trong DS co thu tu (tim kiem nhi phan)"<<endl;
	cout<<"12. Thoat"<<endl;
	do
	{
		cout<<"\nMoi nhap do de chon thao tac: ";
		cin>>choice;
		switch(choice)
		{
		case 1:
			{
				Insert_Arr_Rand(A,size);
				break;
			}
		case 2:
			{
				Insert_Arr(A,size);
				break;
			}
		case 3:
			{
				cout<<"Ban da chon xuat danh sach"<<endl;
				output(A,size);
				break;
			}
		case 4:
			{
				Change(A,B,size);
				start = clock();
				Insertion_Sort(A,size);
				duration = (clock() - start)/(double) CLOCKS_PER_SEC;
				if(size < 100)
				{
					cout<<"Danh sach sau khi xep thu tu voi Insertion Sort la:"<<endl;
					output(B,size);
				}
				if(duration>0)
					cout<<"Thoi gian hao ton: "<<duration*100000<<" microseconds "<<endl;
				cout<<"Da sap xep"<<endl;
				cout<<"Mang sau khi sap xep: "<<endl;
				output(B,size);
				break;
			}
		case 5:
			{
				Change(A,B,size);
				start = clock();
				Selection_Sort(A,size);
				duration = (clock() - start)/(double) CLOCKS_PER_SEC;
				if(size < 100)
				{
					cout<<"Danh sach sau khi xep thu tu voi Selection Sort la:"<<endl;
					output(B,size);
				}
				if(duration>0)
					cout<<"Thoi gian hao ton: "<<duration*100000<<" microseconds "<<endl;
				cout<<"Da sap xep"<<endl;
				cout<<"Mang sau khi sap xep: "<<endl;
				output(B,size);
				break;
			}
		case 6:
			{
				Change(A,B,size);
				start = clock();
				Interchange_Sort(A,size);
				duration = (clock() - start)/(double) CLOCKS_PER_SEC;
				if(size < 100)
				{
					cout<<"Danh sach sau khi xep thu tu voi Interchange Sort la:"<<endl;
					output(B,size);
				}
				if(duration>0)
					cout<<"Thoi gian hao ton: "<<duration*100000<<" microseconds "<<endl;
				cout<<"Da sap xep"<<endl;
				cout<<"Mang sau khi sap xep: "<<endl;
				output(B,size);
				break;
			}
		case 7:
			{
				Change(A,B,size);
				start = clock();
				Buuble_Sort(A,size);
				duration = (clock() - start)/(double) CLOCKS_PER_SEC;
				if(size < 100)
				{
					cout<<"Danh sach sau khi xep thu tu voi Buuble Sort la:"<<endl;
					output(B,size);
				}
				if(duration>0)
					cout<<"Thoi gian hao ton: "<<duration*100000<<" microseconds "<<endl;
				cout<<"Da sap xep"<<endl;
				cout<<"Mang sau khi sap xep: "<<endl;
				output(B,size);
				break;
			}
		case 8:
			{
				Change(A,B,size);
				start = clock();
				Quick_Sort(A,0,size-1);
				duration = (clock() - start)/(double) CLOCKS_PER_SEC;
				if(size < 100)
				{
					cout<<"Danh sach sau khi xep thu tu voi Quick Sort la:"<<endl;
					output(B,size);
				}
				if(duration>0)
					cout<<"Thoi gian hao ton: "<<duration*100000<<" microseconds "<<endl;
				cout<<"Da sap xep"<<endl;
				cout<<"Mang sau khi sap xep: "<<endl;
				output(B,size);
				break;
			}
		case 9:
			{
				Change(A,B,size);
				start = clock();
				Heap_Sort(A,size);
				duration = (clock() - start)/(double) CLOCKS_PER_SEC;
				if(size < 100)
				{
					cout<<"Danh sach sau khi xep thu tu voi Heap Sort la:"<<endl;
					output(B,size);
				}
				if(duration>0)
					cout<<"Thoi gian hao ton: "<<duration*100000<<" microseconds "<<endl;
				cout<<"Da sap xep"<<endl;
				cout<<"Mang sau khi sap xep: "<<endl;
				output(B,size);
				break;
			}
		case 10:
			{
				cout<<"Moi nhap gia tri can tim: ";
				cin>>x;
				Change(A,B,size);
				start = clock();
				if(Search_1(A,size,x))
					cout<<"So co trong mang"<<endl;
				else cout<<"So khong co trong mang"<<endl;
				duration = (clock() - start)/(double) CLOCKS_PER_SEC;
				if(duration>0)
					cout<<"Thoi gian hao ton: "<<duration*100000<<" microseconds "<<endl;
				break;
			}
		case 11:
			{
				cout<<"Moi nhap gia tri can tim: ";
				cin>>x;
				Change(A,B,size);
				start = clock();
				if(Search_2(A,size,x))
					cout<<"So co trong mang"<<endl;
				else cout<<"So khong co trong mang"<<endl;
				duration = (clock() - start)/(double) CLOCKS_PER_SEC;
				if(duration>0)
					cout<<"Thoi gian hao ton: "<<duration*100000<<" microseconds "<<endl;
				break;
			}
		case 12:
			{
				cout<<"Ban da chon thoat"<<endl;
			}
		}
	}while (choice !=12);
	system("pause");
	return 0;

}
