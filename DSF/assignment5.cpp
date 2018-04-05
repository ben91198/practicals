#include<iostream>
#include<stdlib.h>
using namespace std;

struct node
{
	int data;
	node *l,*r;
};

class queue
{
	node *data[10];
	int f,r;
	public:
	void init()
	{
		f=r=-1;
	}
	
	int isempty()
	{
		if(f==-1)
		return 1;
		return 0;
	}
	
	void enq(node *x)
	{
		if(isempty())
		f=r=0;
		else
		r++;
		data[r]=x;
	}
	
	node *deq()
	{
		node *x;
		x=data[f];
		if(f==r)
		f=r=-1;
		else
		f++;
		
		return x;
		
	}
	
	
};

class bst
{
	node *root;
	public:
	bst()
	{
		root=NULL;
	}
	
	void create()
	{
		int i,n,x;
		cout<<"\n\nEnter number of elements in BST : ";
		cin>>n;
		for(i=0;i<n;i++)
		{
			cout<<"\n\nEnter data : ";
			cin>>x;
			insert(x);
		}
	}
	
	void insert(int x)
	{
		node *n,*p,*T;
		n=new node;
		n->l=n->r=NULL;
		n->data=x;
		if(root==NULL)
		root=n;
		else
		{
			T=root;
			while(T!=NULL)
			{
				p=T;
				if(x < T->data)
				T=T->l;
				else
				T=T->r;
			}
			if(x< p->data)
			p->l=n;
			else
			p->r=n;
		}
	}
	
	void display(node *T)
	{
		
		if(T!=NULL)
		{
			display(T->l);
			cout<<"\t"<<T->data;
			display(T->r);
		}
	}
	
	void display1()
	{
		display(root);
	}
	
	int search(int x)
	{
		node *T=root;
		while(T!=NULL)
		{
			if(x==T->data)
			return 1;
			else if(x< T->data)
			T=T->l;
			else
			T=T->r;
		}
	   return 0;
	}
	
	void mirror(node *T)
	{
		node *temp;
		if(T!=NULL)
		{
			temp=T->l;
			T->l=T->r;
			T->r=temp;
			mirror(T->l);
			mirror(T->r);
			
		}
	
	}
	void mirror1()
	{
		mirror(root);
	}
	
	void levelwise()
	{
		queue q1,q2;
		node *t;
		int i=0;
		q1.init();
		q1.enq(root);
		while(!q1.isempty())
		{
			q2.init();
			cout<<"\n\nLevel "<<i++<<":";
			while(!q1.isempty())
			{
				t=q1.deq();
				cout<<"\t"<<t->data;
				if(t->l!=NULL)
				q2.enq(t->l);
				if(t->r!=NULL)
				q2.enq(t->r);
			}
			q1=q2;
		}
	}
	void delete1(int x)
	{
		node *t=root,*p=NULL,*tsucc;
		if(root==NULL)
 		{
			cout<<"\nTREE IS EMPTY!!!";
			return;
		}
		while(t!=NULL&&t->data!=x)
		{
			p=t;
			if(x<t->data)
			t=t->l;
			else
			t=t->r;
			if(t==NULL)
			{
				cout<<"\nDATA NOT FOUND";
				return;
			}
			//case 1:both children null
			if(t->l==NULL&&t->r==NULL)
			{
				if(root->data==x)
				root=NULL;
				else if(p->l==t)
				p->l=NULL;
				else if(p->r==t)
				p->r=NULL;
				delete t;
			}
			//case 2:if left child present
			else if(t->l==NULL&&t->r==NULL)
			{
				if(root->data==x)
				root=root->l;
				else if(p->r==t)
				p->r=t->l;
				else 
				p->l=t->l;
				delete t;
			}
			//case 3:if right child present
			else if(t->l==NULL&&t->r!=NULL)
			{
				if(root->data==x)
				root=root->l;
				else if(p->r==t)
				p->r=t->r;
				else 
				p->l=t->r;
				delete t;
			}
			else
			{
				p=t;
				tsucc=t->r;
				while(tsucc->l!=NULL)
				{
					p=tsucc;
					tsucc=tsucc->l;
				}
				t->data=tsucc->data;
				if(p->l=tsucc)
				p->l=tsucc->r;
				else
				p->r=tsucc->r;
			        delete tsucc;
			}
		}
}	
};


int main()
{
	int ch,r,c,x;
	bst b;
	queue q;
	while(1)
	{
		cout<<"\n\n*****MENU****\n1.Create\n2.Display(ascending)\n3.Insert\n4.Search\n5.Mirror Image\n6.Levelwise display(descending)\n7.Delete\n8.Exit";
		cout<<"\nEnter your choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				b.create();
				break;
			case 2:
				b.display1();
				break;
			case 3:
				cout<<"\n\nEnter the elements to insert : ";
				cin>>x;
				b.insert(x);
				break;
			case 4:
				cout<<"\n\nEnter element to search : ";
				cin>>x;
				r=b.search(x);
				if(r==1)
				cout<<"\n\nData Found !!!";
				else
				cout<<"\n\nData not found !!!";
				break;
			case 5:
				cout<<"\n\nMirror image is : ";
				b.mirror1();
				b.display1();
				break;
			case 6:
				b.levelwise();
				break;
			case 7:
				cout<<"\nenter element to delete :";
				cin>>x;
				b.delete1(x);
				break;
			case 8:
				exit(0);
				break;
			default:
				cout<<"\n\nInvalid choice !!!!";
				break;
			
		}
	}
return 0;
}
