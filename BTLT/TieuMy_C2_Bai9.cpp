

#include<stdio.h>
#include<iostream>
#include<math.h>
using namespace std;
struct n1
{
    int a;
    n1 *next1;
}*top1 = NULL, *p1 = NULL, *np1 = NULL;

struct n2
{
    int b;
    n2 *next2;
}*top2 = NULL, *p2 = NULL, *np2 = NULL;

struct n3
{
    int c;
    n3 *next3;
}*top3 = NULL, *p3 = NULL, *np3 = NULL;

void push1 ( int d )
{
    np1 = new n1;
    np1-> a = d ;
    np1->next1 = NULL;
    if (top1 == NULL)
    {
        top1 = np1;
    }
    else
    {
        np1->next1 = top1;
        top1 = np1;
    }
}

int pop1 ()
{
    int b = 999;
    if (top1 == NULL)
    {
        return b;
    }
    else
    {
        p1 = top1;
        top1 = top1->next1;
        return ( p1 -> a );
        delete( p1 );
    }
}

void push2(int d )
{
    np2 = new n2;
    np2-> b = d;
    np2->next2 = NULL;
    if (top2 == NULL)
    {
        top2 = np2;
    }
    else
    {
        np2->next2 = top2;
        top2 = np2;
    }
}

int pop2()
{
    int b = 999;
    if (top2 == NULL)
    {
        return b;
    }
    else
    {
        p2 = top2;
        top2 = top2->next2;
        return(p2-> b);
        delete(p2);
    }
}

void push3(int d)
{
    np3 = new n3;
    np3-> c = d;
    np3->next3 = NULL;
    if (top3 == NULL)
    {
        top3 = np3;
    }
    else
    {
        np3->next3 = top3;
        top3 = np3;
    }
}

int pop3()
{
    int b = 999;
    if (top3 == NULL)
    {
        return b;
    }
    else
    {
        p3 = top3;
        top3 = top3->next3;
        return(p3-> c );
        delete(p3);
    }
}

int TS ()
{
    if (top1 != NULL && top1 -> a == 1 )
    {
        return 1;
    }
    else if (top2 != NULL && top2 -> b == 1)
    {
        return 2;
    }
    else if (top3 != NULL && top3 -> c == 1)
    {
        return 3;
    }
}

void d1()
{
    cout << "\n" ;
    n1 *p1;
    p1 = top1;
    cout<< " ThapA -> " << " t " ;
    while ( p1 != NULL ) 
    {
        cout << p1 -> a <<" t " ;
        p1 = p1 -> next1 ;
    }
    cout << "\n" ;
}
void d2()
{
    n2 *p2;
    p2 = top2;
    cout << " ThapB -> " << " t " ;
    while (p2 != NULL)
    {
        cout<< p2 -> b << " t " ;
        p2 = p2 -> next2;
    }
    cout<< "\n" ;
}
void d3()
{
    n3 *p3;
    p3 = top3;
    cout<<" ThapC -> " << " t " ;
    while (p3 != NULL)
    {
        cout<< p3 -> c << " t " ;
        p3 = p3 -> next3;
    }
    cout << "\n" ;
    cout << "\n" ;
}
void toh ( int n )
{
    int i, x, a, b;
    for (i = 0; i < (pow(2,n)); i++)
    {
        d1();
        d2();
        d3();
        x = TS ();
        if (i % 2 == 0)
        {
            if (x == 1)
            {
                push3(pop1());
            }
            else if (x == 2)
            {
                push1(pop2());
            }
            else if (x == 3)
            {
                push2(pop3());
            }
        }
        else
        {
            if (x == 1)
            {
                a = pop2();
                b = pop3();
                if (a < b && b != 999)
                {
                    push3(b);
                    push3(a);
                }
                else if (a > b && a != 999)
                {
                    push2(a);
                    push2(b);
                }
                else if (b == 999)
                {
                    push3(a);
                }
                else if (a == 999)
                {
                    push2(b);
                }
            }
            else if (x == 2)
            {
                a = pop1();
                b = pop3();
                if (a < b && b != 999)
                {
                    push3(b);
                    push3(a);
                }
                else if (a > b && a != 999)
                {
                    push1(a);
                    push1(b);
                }
                else if (b == 999)
                {
                    push3(a);
                }
                else if (a == 999)
                {
                    push1(b);
                }
            }
            else if (x == 3)
            {
                a = pop1();
                b = pop2();
                if (a < b && b != 999)
                {
                    push2(b);
                    push2(a);
                }
                else if (a > b && a != 999)
                {
                    push1(a);
                    push1(b);
                }
                else if (b == 999)
                {
                    push2(a);
                }
                else if (a == 999)
                {
                    push1(b);
                }
            }
        }
    }
}
int main()
{
    int n, i;
    cout << " Nhap so dia cho bai toan : ";
    cin>> n ;
    for (i = n; i >= 1; i--)
    {
        push1(i);
    }
    toh(n);
    return 0;
}

