#include<iostream>
#include<fstream>
#include<stdlib.h>
using namespace std;

struct stud
{
	int rn;
	char name[20];
};

class file
{
	fstream f;
	char fname[20];
	public:
	file()
	{
		cout<<"\n\nEnter file name : ";
		cin>>fname;
	}
	void create()
	{
		int n,i;
		stud s;
		f.open(fname,ios::out);
		cout<<"\n\nEnter number of student : ";
		cin>>n;
		for(i=0;i<n;i++)
		{
			cout<<"\n\nEnter roll no and name : ";
			cin>>s.rn>>s.name;
			f.write((char *)&s,sizeof(stud));
		}
		f.close();
	}
	
	void display()
        {
                stud s;
                int i=0;
                f.open(fname, ios::in);
                cout<<"\nSr no\tRoll no\tName\n";
                while(f.read((char *)&s,sizeof(stud)))
                {
                        cout<<i++<<"\t"<<s.rn<<"\t"<<s.name<<"\n";
                        
                }
                f.close();
                
        }
        
   	void append()
   	{
   		stud s;
   		f.open(fname,ios::out|ios::app);
   		cout<<"\n\nEnter roll no and name : ";
   		cin>>s.rn>>s.name;
   		f.write((char *)&s,sizeof(stud));
   		f.close();
   	}
   	
   	int search(int x)
	{
			stud s;
			f.open(fname,ios::in);
			while(f.read((char *)&s,sizeof(stud)))
			{
				if(x==s.rn)
				{
					cout<<"\nRoll NO\t Name";
					cout<<"\n"<<s.rn<<"\t"<<s.name;
					f.close();
					return 1;
				}
			}
			f.close();
			return 0;
	}
	
	
};

int main()
{
	file f;
	int ch,i,x,p;
	system("clear");
	while(1)
	{
		cout<<"\n\n****MENU****\n1.Create\n2.Display\n3.Add record\n4.Search record\n5.Modify record\n6.Delete record\n7.Exit";
		cout<<"\n\nEnter the choice : ";
		cin>>ch;
		switch(ch)
		{
			case 1:
				f.create();
				break;
			case 2:
				f.display();
				break;
			case 3:
				f.append();
				f.display();
				break;
			case 4:
				cout<<"\n\nEnter roll no : ";
				cin>>x;
				p=f.search(x);
				if(p==1)
				cout<<"\n\nData found !!!";
				else
				cout<<"\n\nData not found!!!!";
				break;
			
			case 7:
				exit(0);
		}
	}
return 0;
}
