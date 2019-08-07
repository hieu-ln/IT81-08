#include <stdio.h>
#include <iostream>
using namespace std;

struct Node
{
	int info;
	Node *left;
	Node *right;
};

Node *CreateNode(int x)
{
	Node *p = new Node();
	p->info = x;
	p->left = p->right = NULL;
	return p;
}

void CreateTree(Node *&root,int a[],int n)
{
	for(int i=0;i<n;i++)
	{
		InsertNode(root, a[i]);
	}
}

void inOrder(struct Node *root)
{
	stack<Node*> s;
	Node *curr = root;
	while(curr != NULL || s.empty() == false)
	{
		while(curr != NULL)
		{
			s.push(curr);
			curr = curr->left;
		}
		curr = s.top();
		s.pop();
		cout << curr->info << " ";
		curr = curr->right;
	}
}

int main()
{
	Node *root = NULL;
	int a[] = {3,2,1,4,5,6,8,9,7};
	int n = 9;
	CreateTree(root, a, n);
	inOrder(root);
	system("pause");
	return 0;
}
