//#include<iostream>
//#include<stdio.h>
//#include<iomanip>
//using namespace std;
//#define MAX 100
//int a[MAX];
//int n;
//void input(int a[],int &n)
//{
//	cout<<"Nhap so luong phan tu cua danh sach: ";
//	cin>>n;
//	cout<<"Nhap cac phan tu cua danh sach: ";
//	for(int i=0;i<n;i++)
//	{
//		cout<<"a["<<i<<"]=";
//		cin>>a[i];
//	}
//}
//void output(int a[],int n)
//{
//	for(int i=0;i<n;i++)
//	{
//		cout<<setw(5)<<a[i];
//	}
//	cout<<endl;
//}
//int search(int a[],int n,int x)
//{
//	int i=0;
//	while(i<n&& a[i]!=x)
//	{
//		i++;
//		if(i==x)
//			return -1;
//	}
//	return i;
//}
//int insert_last(int a[],int &n,int x)
//{
//	if(n<MAX)
//	{
//		a[n]=x;
//		n++;
//		return 1;
//	}
//	return 0;
//}
//int delete_last(int a[],int &n)
//{
//	if(n>0)
//	{
//		n--;
//		return 1;
//	}
//	return 0;
//}
//int Delete(int a[],int &n,int i)
//{
//	if(i>=0 && i<n)
//	{
//		for(int j=i;j<n;j++)
//			a[j]=a[j+1];
//	}
//	n--;
//	return 1;
//return 0;
//}
//int searchanddelete(int a[],int &n,int x)
//{
//	for(int i=0;i<n;i++)
//	{
//		if(a[i]==x)
//		{
//			Delete(a,n,i);
//			return 1;
//		}
//	}
//	return 0;
//}
//int main()
//{
//	int choice=0;
//	int x,i;
//	system("cls");
//	cout<<"------- BAI TAP 1, CHUONG 2, DANH SACH DAC -------"<<endl;
//	cout<<"1.Nhap danh sach"<<endl;
//	cout<<"2.Xuat danh sach"<<endl;
//	cout<<"3.Tim phan tu cos gia tri x trong danh sach"<<endl;
//	cout<<"4.Xoa phan tu cuoi danh sach"<<endl;
//	cout<<"5.Xoa phan tu cuoi danh sach"<<endl;
//	cout<<"6.Xoa phan tu tai vi tri i"<<endl;
//	cout<<"7.Tim phan tu voi gia tri x va xoa neu tim thay"<<endl;
//	cout<<"8.Thoat"<<endl;
//
//	do{
//		cout<<"Nhap lua chon: ";
//		cin>>choice;
//		switch(choice)
//		{
//			case 1:
//				input(a,n);
//				cout<<"Nhap danh sach thanh cong!\n";
//				break;
//			case 2:
//				cout<<"Danh sach vua nhap: "<<endl;
//				output(a,n);
//				break;
//			case 3:
//				cout<<"Nhap gia tri x can tim: ";
//				cin>>x;
//				i=search(a,n,x);
//				if(i==-1)
//					cout<<"Gia tri "<<x<<" khong ton tai"<<endl;
//				else
//					cout<<"Tim thay tai vi tri: "<<i<<""<<endl;
//				break;
//			case 4:
//				cout<<"Nhap gia tri can them vao cuoi danh sach: ";
//				cin>>x;
//				i=insert_last(a,n,x);
//				if(i==0)
//					cout<<"Danh sach day, khong the them!!!"<<endl;
//				else
//				{
//					cout<<"DONE!!"<<endl;
//					cout<<"Danh sach sau khi them vao cuoi: ";
//					output(a,n);
//				}
//				break;
//			case 5:
//				i=delete_last(a,n);
//				if(i>0)
//				{
//					cout<<"DONE!!"<<endl;
//					cout<<"Danh sach sau khi xoa cuoi: ";
//					output(a,n);
//				}
//				else
//					cout<<"Danh sach rong, khong co phan tu de xoa!"<<endl;
//				break;
//			case 6:
//				cout<<"Nhap vi tri can xoa: "<<endl;
//				cin>>i;
//				i=Delete(a,n,i);
//				if(i==1)
//				{
//					cout<<"DONE!!!"<<endl;
//					cout<<"Danh sach sau khi xoa: ";
//					output(a,n);
//				}
//				else
//					cout<<"Khong co phan tu de xoa tai vi tri "<<i<<""<<endl;
//				break;
//			case 7:
//				cout<<"Nhap gia tri can xoa: ";
//				cin>>x;
//				i=searchanddelete(a,n,x);
//				if(i==1)
//				{
//					cout<<"DONE!!!"<<endl;
//					cout<<"Danh sach sau khi xoa "<<x<<""<<endl;
//					output(a,n);
//				}
//				else
//					cout<<"Gia tri "<<x<<" khong ton tai!!"<<endl;
//				break;
//			default:
//				break;
//		}
//	}while(choice!=8);
//	system("pause");
//	return 0;
//}