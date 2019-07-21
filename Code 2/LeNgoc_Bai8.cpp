//#include <iostream>
//#define MAX 100
//using namespace std;
//int a[MAX];
//int sp;
//void init(int a[],int &sp)
//{
//	sp=-1;
//}
//int isEmpty(int a[],int sp)
//{
//	if(sp==-1)
//		return 1;
//	return 0;
//}
//int isFull(int a[], int sp)
//{
//	if(sp==MAX-1)
//		return 1;
//	return 0;
//}
//int Push(int a[],int &sp,int x)
//{
//	if(sp<MAX-1)
//	{
//		a[++sp]=x;
//		return 1;
//	}
//	return 0;
//}
//int Pop(int a[],int &sp,int &x)
//{
//	if(sp!=-1)
//	{
//		x=a[sp--];
//		return 1;
//	}
//	return 0;
//}
//int Convert(int so)
//{
//	init(a,sp);
//	int np=0;
//	int he;
//	while(so!=0)
//	{
//		int du=so%he;
//		if(Push(a,sp,du))
//			so=so/he;
//		else
//			break;
//	}
//	while(!isEmpty(a,sp))
//	{
//		int k;
//		if(Pop(a,sp,k))
//			np=np*10+k;
//		else
//			break;
//	}
//	return np;
//}
//int main()
//{
//	int x,np,he;
//	cout<<"Nhap gia tri thap phan can chuyen: ";
//	cin>>np;
//	cout<<"Nhap co so: ";
//	cin>>he;
//	cout<<"Gia tri nhi phan tuong ung la: "<<Convert(np)<<endl;
//	system("pause");
//	return 0;
//}