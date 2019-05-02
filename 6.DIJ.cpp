#include<iostream>
using namespace std;
#define INFINITY 9999
#define MAX 10
class Djik
{
public:
void dijkstra(int G[MAX][MAX],int n,int startnode);
};
void Djik::dijkstra(int G[MAX][MAX],int n,int startnode)
{

int cost[MAX][MAX],distance[MAX],pred[MAX]; int visited[MAX],count,mindistance,nextnode,i,j; for(i=0;i<n;i++)
for(j=0;j<n;j++)
if(G[i][j]==0)
cost[i][j]=INFINITY;
else
cost[i][j]=G[i][j];

for(i=0;i<n;i++)
{
distance[i]=cost[startnode][i]; pred[i]=startnode; visited[i]=0;
}
distance[startnode]=0; visited[startnode]=1; count=1; while(count<n-1)
{
mindistance=INFINITY; for(i=0;i<n;i++)

if(distance[i]<mindistance&&!visited[i])
{
mindistance=distance[i]; nextnode=i;
}

visited[nextnode]=1; for(i=0;i<n;i++)
if(!visited[i])
if(mindistance+cost[nextnode][i]<distance[i])
{




count++;
}

distance[i]=mindistance+cost[nextnode][i]; pred[i]=nextnode;
}

for(i=0;i<n;i++)
if(i!=startnode)
{
cout<<"\nDistance of node"<<i<<"="<<distance[i]; cout<<"\nPath="<<i;


j=i; do
{




j=pred[j]; cout<<"<-"<<j;

}while(j!=startnode);
}
}

int main()
{
Djik obj;
int G[MAX][MAX],i,j,n,u; cout<<"Enter no. of vertices:"<<endl; cin>>n;
cout<<"\nEnter the adjacency matrix:\n"; for(i=0;i<n;i++)
{
for(j=0;j<n;j++)
{
cout<<"From Edge "<<i+1<<" to "<<j+1<<": "; cin>>G[i][j];
}

}

cout<<"\nEnter the starting node: "; cin>>u;
obj.dijkstra(G,n,u); return 0;
}

