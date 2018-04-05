#include<iostream>
#include<stdlib.h>
#include<string.h>
using namespace std;

struct node
{
	int data;
	struct node *next;
};

class stack
{
	node *top;
	
	public:
	stack()
	{
		top=NULL;
	}
	
	int isempty()
	{
		if(top==NULL)
		return 1;
		return 0;
	}
	
	void push(int x)
	{
		node *p;
		p=new node;
		p->data=x;
		p->next=top;
		top=p;
	}
	
	int pop()
	{
		int x;
		node *temp;
		x=top->data;
		temp=top;
		top=top->next;
		return x;
	}
	
	void display()
	{
		node *temp;
		temp=top;
		while(temp!=NULL)
		{
			cout<<temp->data<<"\t";
			temp=temp->next;
		}
	}
	
	int post(char str[20])
	{
		int i,op2,op1,x,res=0,val,n1;
		
		for(i=0;str[i]!='\0';i++)
		{
			x=str[i];
			if(isdigit(x))
			{	
				push(x-48);
			}
			else if(isalpha(x))
			{
				cout<<"\n\nEnter the value for alphabets : ";
				cin>>n1;
				push(n1);
			}
			else
			{
				op2=pop();
				op1=pop();
				val=eval(op1,op2,x);
				push(val);
			}
			
		}
		res=pop();
		return(res);
	}
	
	int eval(int op1,int op2,char x)
	{
		
		switch(x)
		{
			case '+': return(op1+op2);
				   break;
			case '-': 
				   return(op1-op2);
				   break;
			case '*':return(op1*op2);
				   break;
			case '/':return(op1/op2);
				   break;
			
		}
	}
	
	 int preeval(char exp[20])
         {
                int i,op2,op1,res=0,val,n1;
                char x;
               // cout<<"\nlength:";
              cout<<"\nlength:"<<strlen(exp);
              for(i=strlen(exp)-1;i>=0;i--)
                {
					x=exp[i];
	
                        if(isdigit(x))
                        {
                                push(x-48);
                        }
                        else if(isalpha(x))
			{
				cout<<"\n\nEnter the value for : "<<x;
				cin>>n1;
				push(n1);
			}
                        else
                        {
                                op1=pop();
                                op2=pop();
                                val=eval(op1,op2,x);
                                push(val);
                        }
                }
                res=pop();
		return(res);
	}
	
	int topdata()
	{
		return(top->data);
	}
	
	void intopo(char inf[],char pof[],int c)
	{
		stack s1;
		int i,j=0;
		for(i=0;inf[i]!='\0';i++)
		{
			int x=inf[i];
			if(isalnum(x))    //if alphanumeric
			{
				pof[j++]=x;
			}
			else if(x=='(')
			{
				s1.push(x);
			}
			else if(x==')')
			{
				while((x=s1.pop())!='(')
				pof[j++]=x;
			}
			else
			{
			    if(c==1)
			    {
				    while(!s1.isempty()&&icp(x)<=isp(s1.topdata()))	
				    {
					   pof[j++]=s1.pop();
				    }
				    s1.push(x);
				}
				else
				{
					while(!s1.isempty()&&icp(x)<isp(s1.topdata()))	
				    {
					   pof[j++]=s1.pop();
				    }
				    s1.push(x);
				}
			}
		}//end of for
	    while(!s1.isempty())
	    {
	        pof[j++]=s1.pop();
	    }
	    pof[j]='\0';
	
    }
    
    int icp(char x)
    {
        switch(x)
        {
            case '+':
            case '-':return 1;
            case '*':
            case '/':
            case '%':return 2;
            case '^':return 3;
            case '(':return 4;
            
        }
        return 5;
    }
    
    int isp(char x)
    {
        switch(x)
        {
            case '+':
            case '-':return 1;
            case '*':
            case '/':
            case '%':return 2;
            case '^':return 3;
            case '(':return 0;
            
        }
        return 4;
    }
    
    void intopre(char inf[],char pre[])
    {
        strrev(inf);
        for(int i=0;inf[i]!='\0';i++)
        {
            if(inf[i]=='(')
            inf[i]=')';
            else if(inf[i]==')')
            inf[i]='(';
        }
    intopo(inf,pre,0);
    strrev(pre);
    } 
    
    void strrev(char inf[])
    {
    	int i=0,j;
    	j=strlen(inf)-1;
    	char temp;
    	while(i<j)
    	{
    		temp=inf[i];
    		inf[i]=inf[j];
    		inf[j]=temp;
    		i++,j--;
    	}
    }
    
    
                
};

int main()
{
	system("clear");
	int n,ch,x,temp,res;
	char exp[20],op[20];
	stack s1;

	
	do
	{
	    cout<<"\n\n****MENU****\n1.Display\n2.Push operation\n3.Pop operation\n4.post operation\n5.Pre operation\n6.Infix to postfix\n7.Infix to prefix\n8.Exit";
	    cout<<"\n\nEnter your choice : ";
	    cin>>ch;
	    switch(ch)
	    {
	        case 1:
	               
	                s1.display();
	                break;
	                
	        case 2:
	                
	                cout<<"\n\nEnter number for push : ";
	                cin>>x;
	                s1.push(x);
	                break;
	                
	        case 3:
	                cout<<"\n\n----Pop operation-----";
	                if(s1.isempty()==0)
	                {
	                     temp=s1.pop();
	                    cout<<"\n Popped element : "<<temp;
	                    cout<<"\n Stack contains : ";
	                    s1.display();
	                }
	                else
	                {
	                    cout<<"\n\nStack is empty !!!!";
	                }
	                break;
	                
	        case 4:
	                cout<<"\n\nEnter postfix expression : ";
	                cin>>exp;
	                cout<<"\n\nExpression = "<<exp;
	                res= s1.post(exp);
	                cout<<"\n\nResult : "<<res;
	                break;
	               
	        case 5:
	        		 cout<<"\n\nEnter prefix expression : ";
	                cin>>exp;
	                cout<<"\n\nExpression = "<<exp;
	                res= s1.preeval(exp);
	                cout<<"\n\nResult : "<<res;
	                break;
	                
	        case 6 : 
	                cout<<"\n\nEnter infix to postfix expression : ";
	                cin>>exp;
	                cout<<"\n\nExpression = "<<exp;
	                s1.intopo(exp,op,1);
	                cout<<"\n\nResult : "<<op;
	                break;
	              
	       case 7:
	       		 cout<<"\n\nEnter infix to prefix expression : ";
	                cin>>exp;
	                cout<<"\n\nExpression = "<<exp;
	                s1.intopre(exp,op);
	                cout<<"\n\nResult : "<<op;
	                break;
	       case 8:
	       		 exit(0);
	       		 break;
	                
	       default :
	       			cout<<"\n\nInvalid Choice !!!!!!";
	       			break;
	        			
	    }
	}while(ch!=9);
	
return 0;
}
































