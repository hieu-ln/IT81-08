#include <iostream>
#define MAX 100
using namespace std;
int a[MAX];
int sp;
void init(int a[],int &sp)
{
	sp=-1;
}
int isEmpty(int a[],int sp)
{
	if(sp==-1)
		return 1;
	return 0;
}
int isFull(int a[], int sp)
{
	if(sp==MAX-1)
		return 1;
	return 0;
}
int Push(int a[],int &sp,int x)
{
	if(sp<MAX-1)
	{
		a[++sp]=x;
		return 1;
	}
	return 0;
}
int Pop(int a[],int &sp,int &x)
{
	if(sp!=-1)
	{
		x=a[sp--];
		return 1;
	}
	return 0;
}
void View()
{
	if(sp==-1)
		cout<<"EMPTY!"<<endl;
	else
	{
		for(int i=sp;i>=0;i--)
			cout<<a[i]<<endl;
		cout<<endl;
	}
}
int Convert(int tp,int cs)
{
	init(a,sp);
	int kq=0;
	while(tp!=0)
	{
		int du=tp%cs;
		if(Push(a,sp,du))
			tp/=cs;
		else
			break;
	}
	while(!isEmpty(a,sp))
	{
		int x;
		if(Pop(a,sp,x))
			kq=kq*10+x;
		else
			break;
	}
	return kq;
}
int main()
{
	int x,i,cs,tp;
	int choice=0;
	system("cls");
	cout<<"1.Khoi tao Stack"<<endl;
	cout<<"2.Kiem tra Stack rong"<<endl;
	cout<<"3.Kiem tra Stack day"<<endl;
	cout<<"4.Them 1 phan tu co gia tri x vao Stack"<<endl;
	cout<<"5.Xoa phan tu trong Stack"<<endl;
	cout<<"6.Danh sach Stack hien tai"<<endl;
	cout<<"7.Chuyen so tu he thap phan sang he nhi phan"<<endl;
	cout<<"8.Thoat"<<endl;
	do{
		cout<<"Nhap lua cho de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				init(a,sp);
				cout<<"Khoi tao thanh cong!!"<<endl;
				break;
			case 2:
				i=isEmpty(a,sp);
				if(i!=0)
					cout<<"Danh sach rong!!"<<endl;
				else
					cout<<"Danh sach da nhap du lieu!!"<<endl;
				break;
			case 3:
				i=isFull(a,sp);
				if(i!=0)
					cout<<"Danh sach da day!!"<<endl;
				else
					cout<<"Danh sach con trong!!"<<endl;
				break;
			case 4:
				cout<<"Nhap gia tri can them vao Stack: ";
				cin>>x;
				i=Push(a,sp,x);
				if(i!=1)
					cout<<"Stack da day!!"<<endl;
				else
				{
					cout<<"Da them "<<x<<" vao Stack!!"<<endl;
				}
				break;
			case 5:
				i=Pop(a,sp,x);
				if(i!=1)
					cout<<"Stack dang rong!!"<<endl;
				else
				{
					cout<<"Da xoa phan tu ra kho Stack!"<<endl;
				}
				break;
			case 6:
				cout<<"Danh sach hien tai cua Stack: "<<endl;
				View();
				break;
			case 7:
				int np;
				cout<<"Nhap gia tri he thap phan can chuyen: ";
				cin>>tp;
				cout<<"Nhap co so can chuyen: ";
				cin>>cs;
				cout<<"Gia tri nhi phan tuong ung la: "<<Convert(tp,cs)<<endl;
				break;
			case 8:
				cout<<"EXIT!!"<<endl;
				break;
			default:
				break;
		}
	}while(choice!=8);
	system("pause");
	return 0;
}