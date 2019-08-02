#include <iostream>
using namespace std;
int count=10;
struct Node{
	int info;
	Node *left;
	Node *right;
};
Node *root;
void tree_empty()
{
	root=NULL;
}
void out(Node *p,int space)
{
	if(p==NULL)
		return;
	space=space + count;
	out(p->right,space);
	cout<<endl;
	for(int i=count;i<space;i++)
		cout<<" ";
	cout<<p->info<<endl;
	out(p->left,space);
}
void process_out()
{
	out(root,0);
}
Node *search (Node *p,int x)
{
	while(p!=NULL)
	{
		if(p->info==x)
			return p;
		else
			if(p->info>x)
				p=p->left;
			else
				p=p->right;
	}
	return NULL;
}
void insert( Node *&p, int x)
{
	if(p==NULL)
	{
		p=new Node;
		p->info=x;
		p->left=NULL;
		p->right=NULL;
	}
	else
	{
		if(p->info==x)
			return;
		else if(p->info>x)
			return insert(p->left,x);
		else
			return insert(p->right,x);
	}
}
void timphantuthemangphainhatcaycontrai(Node *&p, Node *&q)
{
	if (q->right != NULL)
	{
		timphantuthemangphainhatcaycontrai(p, q->right);
	}
	else
	{
		p->info = q->info;
		p = q;
		q = q->left;
	}
}
void xoanode(Node *&t, int x)
{
	if (t == NULL)
	{
		return;
	}
	else
	{
		if (t->info > x)
		{
			xoanode(t->left, x);
		}
		else if(t->info<x)
		{
			xoanode(t->right, x);
		}
		else
		{
			Node *p = t;
			if (t->left == NULL)
			{
				t = t->right;
			}
			else if(t->right==NULL)
			{
				t = t->left;
			}
			else
			{

				// cách 1 tìm phần tử trái nhất cây con phải 
				//timphantuthemangtrainhatcayconphai(p, t->pright);
				//cách 2 tìm pahn62 tử thế mạng phải nhất cây con trái
				timphantuthemangphainhatcaycontrai(p, t->left);
			}

			delete p;
       }
   }

}
int main()
{
	int x,i;
	int choice;
	cout<<"1.Khoi tao cay nhi phan"<<endl;
	cout<<"2.Them phan tu vao cay nhi phan"<<endl;
	cout<<"3.Xoa 1 phan tu trong cay nhi phan"<<endl;
	do{
		cout<<"\nNhap lua chon de thuc hien: ";
		cin>>choice;
		switch(choice)
		{
			case 1:
				cout<<"Khoi tao cay nhi phan";
				tree_empty();
				break;
			case 2:
				cout<<"Nhap phan tu can them: ";
				cin>>x;
				insert(root,x);
				cout<<"Da them vao cay"<<endl;
				break;
			case 3:
				cout<<"Cay nhi phan tim kiem: ";
				process_out();
			case 4:
				cout<<"Nhap phan thu can xoa: ";
				cin>>x;
				xoanode(root,x);
				cout<<"Da xoa phan tu "<<x<<" ra khoi cay"<<endl;
				break;
			case 5:
				cout<<"exit"<<endl;
				break;
			default:
				break;
		}
	}while(choice!=5);
	system("pause");
	return 0;
}