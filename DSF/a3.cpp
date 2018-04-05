#include<iostream>
using namespace std;
#include<math.h>
#include<stdlib.h>

struct node
{
	int data;
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

class bt
{
	stack s;
	node *root;
	public:
	bt()
	{
		root=NULL;
	}


void create1()
{
	root=create();
}

node *create()
{
	node *p;
	int x;
	cout<<"\n Enter data:(-1 to end) : ";
	cin>>x;
	if(x==-1)
		return NULL;
	else
	{
		p=new node;
		p->l=p->r=NULL;
		p->data=x;
		cout<<"\nEnter left data of : "<<x;
		p->l=create();
		cout<<"\nEnter right data of : "<<x;
		p->r=create();
	}
	return p;
}

	void display(node *t)
	{
		if(t!=NULL)
		{
		        display(t->l);
		        cout<<"\t"<<t->data;
		        display(t->r);
		}

	}

	void display1()
	{
		display(root);
	}

void displeaf(node *t)
{
		if(t!=NULL)
		{
			if(t->l==NULL&&t->r==NULL)
			cout<<"\t"<<t->data;
			displeaf(t->l);
			displeaf(t->r);
		}
}
void displeaf1()
	{
	        if(root!=NULL)
	        {
	                displeaf(root);
	        }
	        else
		        cout<<"THE TREE IS EMPTY!!!!!!!!";
	}
int depth(node *t)
{
	if(t==NULL)
	return 0;
	else if(t->l==NULL&&t->r==NULL)
	return 0;
	else 
	return(max(depth(t->l),depth(t->r))+1);	
}
int depth1()
{
	return depth(root);
}

node *copy(node *t)
{
	node *p=NULL;
	if(t!=NULL)
	{
		p=new node;
		p->data=t->data;
		p->l=p->r=NULL;
		p->l=copy(t->l);
		p->r=copy(t->r);
	}
	return p;
}
void copy1()
{
	node *t;
	t=copy(root);
	cout<<"\nCopied tree : ";
	display(t);
}
node *search(node *t,int x)
{
        while(t!=NULL||!s.isempty())
        {
                if(t!=NULL)
                {
                        if(x==t->data)
                        {
                                return t;
                        }
                        else 
                        {
                                s.push(t);
                                t=t->l;
                        }
               }
               else 
               {
                        s.pop();
                        t=t->r;
               }
        }
        return NULL;
}
void insert(int x)
{
	node *t,*p;
	int n;
	cout<<"\nEnter node after which new node is to be inserted : ";
	cin>>n;
	t=search(root,n);
	if(t==NULL)
	{
		cout<<"\n data not found";
	}
	else
	{
		if(t->l==NULL||t->r==NULL)
		{
			p=new node;
			p->l=p->r=NULL;
			p->data=x;
			if(t->l==NULL)
			t->l=p;
			else
			t->r=p;
		}
		else
		cout<<"INSERTION NOT POSSIBLE !!!!!!!!!!!";
	}
}					
};

int main()
{
         bt b;
         int ch,x;
	system("clear");
         while(1)
         {
                
                cout<<"\n\n****MENU****\n1.CREATE\n2.DISPLAY\n3.DEPTH OF TREE\n4.DISPLAY LEAF NODE\n5.INSERT\n6.CREATE COPY\n";
                cout<<"ENTER YOUR CHOICE:";
                cin>>ch;
                
                switch(ch)
                {
                        case 1:
                                b.create1();
                                break;
                                
                        case 2:
                                cout<<"\nTREE ELEMENTS ARE : ";
                                b.display1();
                                break;
                                
                         case 3:
                                x=b.depth1();
                                cout<<"\nDEPTH OF TREES : "<<x;
                                break;
                                
                        case 4:
                                cout<<"\nLEAF NODES : ";
                                b.displeaf1();
                                break;
                                
                        case 5:
                                cout<<"ENTER DATA TO INSERT : ";
                                cin>>x;
                                b.insert(x);
                                cout<<"AFTER INSERT : ";
                                b.display1();
                                break;
                                
                        case 6:
                                b.copy1();
                                break;
                                
                        default:
                                cout<<"INVALID CHOICE!!!";
                                
                }
         }
         return 0;
}
