#include<iostream>
#include<string.h>
#include<iomanip>
#include<stdlib.h>
#define MAX 10

using namespace std;

struct stud
{
	long mobile;
	char name[10];
	int chain;
};

class hashing
{
	stud data[MAX];
	int i;
	public:
	void init()
	{
		for(i=0;i<MAX;i++)
		{
			data[i].mobile=-1;
			strcpy(data[i].name,"");
			data[i].chain=-1;
		}
	}
	
	int hash(long x)
	{
		return(x%MAX);
	}
	
	int isfull()
	{
		for(i=0;i<MAX;i++)
		{
			if(data[i].mobile==-1)
			return 0;
		}
		return 1;
	}
	
	void display()
	{
		int i;
		cout<<"\nLocation\tMobile\tName\tChain";
		for(i=0;i<MAX;i++)
		{
			cout<<"\n"<<i<<"\t"<<setw(15)<<data[i].mobile<<"\t"<<setw(15)<<data[i].name<<"\t"<<setw(15)<<data[i].chain;
		}
	}
	
	void insert_wo()
	{
		stud s;
		int loc,pred;
		if(isfull())
		{
			cout<<"\nTable is full !!!";
			return;
		}
		cout<<"\nEnter mobile no : ";
		cin>>s.mobile;
		cout<<"\nEnter name  : ";
		cin>>s.name;
		s.chain=-1;
		loc=hash(s.mobile);
		
		if(data[loc].mobile==-1)
		{
			data[loc]=s;
		}
		else if(loc==hash(data[loc].mobile))
		{
			while(data[loc].chain==-1)
			loc=data[loc].chain;
			pred=loc;
			while(data[loc].mobile!=-1)
			loc=(loc+1)%MAX;
			data[loc]=s;
			data[pred].chain=loc;
		}
		else
		{
			while(data[loc].mobile!=-1)
			loc=(loc+1)%MAX;
			data[loc]=s;
		}
	}
	
	void insert_with()
	{
		stud s;
		int loc,pred;
		if(isfull())
		{
			cout<<"\nTable is full !!!";
			return;
		}
		cout<<"\nEnter mobile no : ";
		cin>>s.mobile;
		cout<<"\nEnter name  : ";
		cin>>s.name;
		s.chain=-1;
		loc=hash(s.mobile);
		
		if(data[loc].mobile==-1)
		{
			data[loc]=s;
		}
		else if(loc==hash(data[loc].mobile))
		{
			while(data[loc].chain==-1)
			loc=data[loc].chain;
			pred=loc;
			while(data[loc].mobile!=-1)
			loc=(loc+1)%MAX;
			data[loc]=s;
			data[pred].chain=loc;
		}
		else
		{
			stud old;
			old=data[loc];
			data[loc]=s;
			pred=hash(old.mobile);
			while(data[loc].mobile!=-1)
			loc=(loc+1)%MAX;
			data[loc]=old;
			data[pred].chain=loc;
		}
	}
	
};

int main()
{
	hashing h;
	int ch;
	//system("clear");
	h.init();
	cout<<"\n\n-----Initial hash table is ----";
	h.display();
	while(1)
	{
		cout<<"\n\n***MENU***\n1.Hashing without replacement\n2.Hashing with replacement\n3.Exit";
		cout<<"\n\nEnter the choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				h.insert_wo();
				cout<<"\n\n------Hash Table without replacement------";
				h.display();
				break;
			case 2:
				h.insert_with();
				cout<<"\n\n------Hash Table with replacement------";
				h.display();
				break;
			case 3:
				exit(0);
				break;
		}
	}
return 0;
	
}
