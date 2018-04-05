#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	char data;
	node *l,*r;
};

class stack
{
	node *data[10];
	int top;
	public:
	stack()
	{
		top=-1;
	}
	int isempty()
	{
		if(top==-1)
		return 1;
		return 0;
	}
	void push(node *p)
	{
		data[++top]=p;
	}
	node *pop()
	{
		return data[top--];
	}
};

class exptree
{
	public:
	node *root;
	exptree()
	{
		root=NULL;
	}
	void create()
	{
		int i;
		char post[10];
		node *p;
		stack s;
		cout<<"\n\nEnter postfix expression : ";
		cin>>post;
		for(i=0;post[i]!='\0';i++)
		{
			p=new node;
			p->data=post[i];
			p->l=p->r=NULL;
			if(isalnum(p->data))
			{
				s.push(p);
			}
			else
			{
				p->r=s.pop();
				p->l=s.pop();
				s.push(p);
			}
		}
		root=s.pop();
	}

	void recin(node *t)
	{
		if(t!=NULL)
		{
			recin(t->l);
			cout<<t->data;
			recin(t->r);
		}
	}
	
	void recpre(node *t)
	{
		if(t!=NULL)
		{
			cout<<t->data;
			recin(t->l);
			recin(t->r);
		}
	}
	
	void nonrecin()
	{
		node *t=root;
		stack s;
		while(t!=NULL||!s.isempty())
		{
			if(t!=NULL)
			{
				s.push(t);
				t=t->l;
			}
			else
			{
				t=s.pop();
				cout<<t->data;
				t=t->r;
			}
		}
	}
	
	
	void nonrecpre()
	{
		node *t=root;
		stack s;
		while(t!=NULL||!s.isempty())
		{
			if(t!=NULL)
			{
				s.push(t);
				cout<<t->data;
				t=t->l;
			}
			else
			{
				t=s.pop();
				t=t->r;
			}
		}
	}
};




int main()
{
	exptree e;
	int ch;
	system("clear");
	while(1)
	{
		cout<<"\n\n*****MENU****\n1.Create\n2.Inoreder recursion\n3.preorder recursion\n4.inorder non recursion\n5.preorder non recursion\n6.Exit";
		cout<<"\nEnter you choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				e.create();
				break;
			case 2:
				e.recin(e.root);
				break;
			case 3:
				e.recpre(e.root);
				break;
			case 4:
				e.nonrecin();
				break;
			case 5:
				e.nonrecpre();
				break;
			case 6:
				exit(0);
				break;
			default:
				cout<<"\n\nInvalid choice !!!!";
		}
	}
return 0;
}
