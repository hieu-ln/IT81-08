#include <iostream>
#include <conio.h>
#include <math.h>
using namespace std;

struct DonThuc
{
    float hs;
    int sm;
};

struct node
{
    DonThuc info;
    node *next;
};

struct DaThuc
{
    node *head;
    node *tail;
};

node* getnode(DonThuc x)
{
    node *p;
    p=new node;
    if(p==NULL)
    {
        cout<<"\n Khong du bo nho! Thu lai! ";
        return NULL;
    }
    p->info=x;
    p->next=NULL;
    return p;
}

void KhoiTao(DaThuc &L)
{
    L.head=NULL;
    L.tail=NULL;
}

void addhead(DaThuc &L,node *p)
{
    if(L.tail==NULL)
    {
        L.head=p;
        L.tail=p;
    }
    else
    {
        p->next=L.head;
        L.head=p;
    }

}

void ThemDau(DaThuc &L,DonThuc x)
{
    node *p;
    p=getnode(x);
    addhead(L,p);
}

void Nhap(DonThuc &x)
{
    cout<<"\n Nhap Vao Don Thuc";
    cout<<"\n Nhap vao he so: ";
    cin>>x.hs;
    cout<<"\nNhap so mu: ";
    cin>>x.sm;
}

void NhapDaThuc(DaThuc &L)
{
    int n;
    DonThuc x;
    node *p;
    p=L.head;
    cout<<"\n Nhap Da Thuc";
    cout<<"\n Nhap vao so luong don thuc: ";   
    cin>>n;
    for(int i=0;i<n;i++)
    {
        cout<<"\n Don Thuc "<<i+1 <<" = ";
        Nhap(x);
        ThemDau(L,x);
    }
}

void CongDaThuc (DaThuc L,DaThuc L1,DaThuc &T)
{
    node *p,*q;
    int flag;
    p=L.head;
    while(p!=NULL)
    {
        ThemDau(T,p->info);
        p=p->next;
    }
    p=L1.head;
    q=T.head;   
    while (q!=NULL)
    {
        p=L1.head;
        while (p!=NULL)
        {
            if(p->info.sm==q->info.sm)
            q->info.hs+=p->info.hs; 
            p=p->next;
        }
        q=q->next;
    }
    p=L1.head;
    while (p!=NULL) 
    {
        flag=0;
        q=T.head;
        while (q!=NULL)
        {
            if(q->info.sm==p->info.sm)
            flag=1;
            q=q->next;
        }
        if(flag==0)
        ThemDau(T,p->info);
        p=p->next; 
    }
}

void TruDaThuc(DaThuc &L,DaThuc &L1,DaThuc &H)
{
    node *p,*q;
    int flag;
    p=L.head;
    while(p!=NULL)
    {
        ThemDau(H,p->info);
        p=p->next;
    }
    p=L1.head;
    q=H.head;
    while (q!=NULL)
    {
        p=L1.head;
        while (p!=NULL)
        {
            if(p->info.sm==q->info.sm)
            q->info.hs-=p->info.hs; 
            p=p->next;
        }
        q=q->next;
    }
    p=L1.head;
    while (p!=NULL) 
    {
        flag=0;
        q=H.head;
        while (q!=NULL)
        {
            if(q->info.sm==p->info.sm)
            flag=1;
            q=q->next;
        }
        if(flag==0)
        {
            p->info.hs*=-1;
            ThemDau(H,p->info);
            p->info.hs*=-1;
        }
        p=p->next; 
    }   

}

void NhanDaThuc(DaThuc &L,DaThuc &L1,DaThuc &Ti)
{
    node *p,*q;
    int flag;
    p=L.head;
    while(p!=NULL)
    {
        ThemDau(Ti,p->info);
        p=p->next;
    }
    p=L1.head;
    q=Ti.head;
    while (q!=NULL)
    {
        p=L1.head;
        while (p!=NULL)
        {
            q->info.hs*=p->info.hs; 
            q->info.sm+=p->info.sm; 
            p=p->next;
        }
        q=q->next; 
    }
}

void XuatDaThuc(DaThuc L)
{
    cout<<"\n";
    node *p;
    p=L.head;
    while(p!=NULL)
    {
        cout<<(p->info).hs<<"x^"<<(p->info).sm;
        if(p->next!=NULL)
        cout<<"+";
        p=p->next;
    }
}

int main()
{
    DaThuc L,L1,T,H,Ti;
    KhoiTao(L);
    KhoiTao(L1);
    KhoiTao(T);
    KhoiTao(H);
    KhoiTao(Ti);
    DonThuc x;
    NhapDaThuc(L);
    cout<<"\n Da thuc can cong ";
    NhapDaThuc(L1);
    cout<<"\n Hai da thuc ";
    XuatDaThuc(L);cout<<"\n";
    XuatDaThuc(L1);
    CongDaThuc(L,L1,T);
    XuatDaThuc(T);
    cout<<"\nDa thuc 1 tru da thuc 2";
    TruDaThuc(L,L1,H);
    XuatDaThuc(H);
    cout<<"\n Da thuc tich \n";
    NhanDaThuc(L,L1,Ti);
    XuatDaThuc(Ti);
    getch();
}
