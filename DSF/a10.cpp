#include<iostream>
#include<stdlib.h>
using namespace std;
#define inf 999;
class prim
{
	int g[10][10],parent[10];
	int n,e,i,j,u,v,w;
	public:
		//initialization
		void init()
		{
			for(i=0;i<n;i++)
			{
				//parent[i]=0;
				for(j=0;j<n;j++)
				{
					g[i][j]=inf;
				}
			}
		}
		void accept()
		{
			cout<<"\nENTER NO OF VERTICES : ";
			cin>>n;
			cout<<"\nENTER NO OF EDGES : ";
			cin>>e;
			init();
			cout<<"\nENTER ADJACENCY NODES : ";
			for(j=0;j<e;j++)//loop to accept edges
			{
				cout<<"\nENTER STARTING NODE : ";
				cin>>u;
				cout<<"\nENTER ENDING NODE : ";
				cin>>v;
				cout<<"\nENTER WEIGHT : ";
				cin>>w;
				
				g[u][v] = g[v][u]=w;
			}
			
		}
		void display()
		{
			for(i=0;i<n;i++)
			{
				for(j=0;j<n;j++)
				{
					cout<<"\t"<<g[i][j];

				}
			cout<<"\n";
			}
		}
		void prims()
		{
			int cost=0,u,v,min=inf;
			int visited[10],dist[10],from[10];
			cout<<"\nENTER STARTING VERTEX : ";
			cin>>u;
			for(v=0;v<n;v++)
			{
				visited[v]=0;
				from[v]=u;
				dist[v]=g[u][v];
			}
			visited[u]=1;
			for(i=1;i<n;i++)
			{
				min = inf;
				for(v=0;v<n;v++)
				{
					if(!visited[v] && dist[v]<min)
					{
						min = dist[v];
						u=v;
					}
				}
				
				visited[u]=1;
				for(v=0;v<n;v++)
				{
					if(!visited[v] && g[u][v]<dist[v])
					{
						dist[v]=g[u][v];
						from[v]=u;
					}
				}
				cost = cost + min;
				cout<<"\n"<<from[u]<<"->"<<u<<"="<<dist[u];
			}
			cout<<"\nCOST OF GRAPH :  "<<cost;
		}	
			
		};
		
		


int main()
{
	prim k;
	int ch;
	
	while(1)
	{
		cout<<"\nMENU\n1.CREATE\n2.PRIMS \n3.EXIT\nENTER YOUR CHOICE\n";
		cin>>ch;
		switch(ch)
		{
			case 1:
				k.accept();
				k.display();
				break;
				
			case 2:
				k.prims();
				break;	
			
			case 3:
				default:exit(0);
					
		}
	}
	
}

