#include <iostream>
#include <cstdlib>
using namespace std;
const int mx = 100;
int A[mx], n, x, choose, lo;
void Nhap (int A[mx], int &n)
{
	do
	{
		cout<<"Nhap so phan tu: ";
		cin>>n;
		if ( n >mx && n <0)
			cout<<"Nhap sai hoac vuot qua muc cho phep, hay nhap lai: ";
	} while (n> mx && n<0);
	cout<<"Bat dau nhap so phan tu cua danh sach: ";
	for (int i = 0; i <n; i++)
	{
		cout<<"Nhap so thu "<<i+1<<": ";
		cin>>A[i];
	}
}
void random (int A[mx], int &n)
{
	do
	{
		cout<<"Nhap so phan tu: ";
		cin>>n;
		if ( n >mx && n <0)
			cout<<"Nhap sai hoac vuot qua muc cho phep, hay nhap lai: ";
	} while (n> mx && n<0);
	for (int i = 0; i <n; i++)
	{
		A[i] = rand()%1000;
	}
}
void Output (int A[mx], int n)
{
	cout<<"danh sach da khoi tao la: "<<endl;
	for (int i = 0; i <n; i++)
		cout<<A[i]<<"  ";
}void Search ( int A[mx], int n, int x)
{
	int k;
	for (int i =0; i <n; i++)
		if(A[i]== x)
			cout<<"Tim thay "<<x<<" o vi tri "<<i<<endl;
		
}
void insert_last (int A[mx], int &n, int x)
{
	if (n < mx)
	{
		A[n] = x;
		n++;
		cout<<"Them vao DS thanh cong";
	}
	else 
		cout<<"That bai, hay kiem ra do lon DS va thu lai";
}
void Delete_last(int A[mx], int &n)
{
	if (n>0)
	{
		n--;
		cout<<"Xoa thanh cong";
	}
	else 
		cout<<"Xoa that bai, hay xem lai mang co phai rong hay khong";
}
void Delete (int A[mx], int &n, int i)
{
	if (i>0 && i <n)
		for ( int j = i+1; j < n; j++)
		{
			A[j] = A[j+1];
			n--;
		}
	else
		cout<<"Khong thanh cong, hay kiem tra va thu lai";

}
int SAD (int a[mx], int &n, int x)
{
	for ( int i = 0; i < n; i++)
		if ( A[i] == x)
		{
			Delete(A,n,i);
			return 1;
		}
		else
			return 0;
}
int main()
{
		cout<<"\nCIAO~~~~~\n";
		cout<<"---------Menu----------\n";
		cout<<"1. Nhap DS\n";
		cout<<"2. Random DS\n";
		cout<<"3. Xuat DS\n";
		cout<<"4. Tim phan tu x\n";
		cout<<"5. Them phan tu vao cuoi DS\n";
		cout<<"6. Xoa phan tu cuoi DS\n";
		cout<<"7. Xoa 1 phan tu tai vi tri i\n";
		cout<<"8. Tim va xoa phan tu\n";
		cout<<"9. Thoat\n";
		
		do
		{
			cout<<"\nChon de thuc hien: ";
			cin>>choose;
			switch (choose)
			{
			case 1:
				Nhap(A,n);
				break;
			case 2: 
				random (A,n);
				break;
			case 3:
				Output(A,n);
				break;
			case 4:
				{
					cout<<"Nhap so can tim: ";
					cin>>x;
					Search(A,n,x);
					break;
				}
			case 5:
				{
					cout<<"Nhap phan tu can them";
					cin>>x;
					insert_last(A,n,x);
					break;
				}
			
			case 6:
				{
					Delete_last(A,n);
					break;
				}
			case 7:
				{
					cout<<"Nhap vi tri can xoa: ";
					cin>>lo;
					Delete(A,n,lo);
					break;
				}
			case 8:
				{
					cout<<"Nhap phan tu can tim va xoa: ";
					cin>>x;
					if(SAD(A,n,x)==0)
						cout<<"Phan tu khong co trong mang";
					else 
						cout<<"Xoa thanh cong";
					break;
				}
			case 9:
				cout<<"Ban da chon thoat chuong trinh\n";
			} 
	}while (choose !=9);
	system ("pause");
	return 0;	


}