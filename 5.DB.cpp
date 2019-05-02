#include<iostream>
#define MAX 30
using namespace std;

class graph
{
	int n;
	int adjmat[MAX][MAX];
	int visited[MAX];
	public:
		graph()
		{
			for(int i=0;i<MAX;i++)
			{
				for(int j=0;j<MAX;j++)
				{
					adjmat[i][j]=0;
				}
			}
			for(int i=0;i<MAX;i++)
				visited[i]=0;
		}

		void create();
		void dfs();
		void bfs();
		void initialize_visited();
};

class stack
{
	int item[MAX];
	int top;
	public:
		stack()
		{




top=-1;
		}





		int pop();
		int isEmpty();
		int isFull();
		int push(int);
};

class queue
{
	int item[MAX];
	int front,rear;
	public:
		queue()
		{
			front = rear = -1;
		}
		int dequeue();
		int isEmpty();
		int isFull();
		void enqueue(int);
};

void graph::create()
{
	int ch;
	cout<<"Enter the number of vertices in the graph"<<endl;
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			cout<<"Enter the edge between "<<i<<" and "<<j<<" (1/0)"<<endl;
			cin>>ch;
			if(ch==1)
				adjmat[i][j] = adjmat[j][i] = 1;
		}
	}
}

void graph::dfs()



{
	stack s;
	int chars;
	cout<<"Enter the starting vertex"<<endl;
	cin>>chars;
	s.push(chars);
	while(!s.isEmpty())
	{





		chars=s.pop();
		if(visited[chars]==1)
			continue;
		cout<<" "<<chars;
		visited[chars]=1;
		for(int l=0;l<n;l++)
		{
			if(adjmat[chars][l]==1 && visited[l]==0)
				s.push(l);
		}
	}
}

void graph :: bfs()
{
	queue q;
	int chars;
	cout<<"Enter the starting vertex"<<endl;
	cin>>chars;
	q.enqueue(chars);
	while(!q.isEmpty())
	{
		chars=q.dequeue();
		if(visited[chars]==1)
			continue;
		cout<<" "<<chars;
		visited[chars]=1;
		for(int l=0;l<n;l++)
		{
			if(adjmat[chars][l]==1 && visited[l]==0)
				q.enqueue(l);
		}
	}
}




int stack::pop()
{
	int x;
	if(isEmpty())
		cout<<"Stack is empty"<<endl;
	else
	{
		x=item[top];
		top--;
	}
	return x;
}





int stack::isEmpty()
{
	if(top==1)
		return 1;
	else
		return 0;
}

int stack::isFull()
{
	if(top==MAX)
		return 1;
	else
		return 0;
}

int stack::push(int x)
{
	if(isFull())
		cout<<"Stack is full"<<endl;
	else
	{
		top++;
		item[top]=x;
	}
}

int queue::dequeue()
{



int x;
	if(isEmpty())
		cout<<"Queue is empty"<<endl;
	else
	{
		x=item[front];
		front++;
	}
	return x;
}

int queue::isEmpty()
{
	if(front==-1 || front>rear)
		return 1;
	else
		return 0;
}





int queue::isFull()
{
	if(front==MAX)
		return 1;
	else
		return 0;
}

void queue::enqueue(int x)
{
	if(isFull())
		cout<<"Queue is full"<<endl;
	else
	{
		if(front==-1)
			front++;
		item[++rear]=x;
	}
}

void graph::initialize_visited()
{
	for(int i=0;i<MAX;i++)
		visited[i]=0;



}

int main()
{
	graph obj;
	int choice;
	char ch;
	obj.create();
	do
	{
		cout<<endl<<"1. BFS\n2. DFS\n3. Exit"<<endl;
		cin>>choice;
		switch(choice)
		{
			case 1:
				obj.initialize_visited();
				obj.bfs();
				break;

			case 2:
				obj.initialize_visited();
				obj.dfs();
				break;







			case 3:
				return 0;

			default:
				cout<<"Wrong input"<<endl;
		}
		cout<<endl<<"Do you want to continue (y/n)"<<endl;
		cin>>ch;
	}while(ch=='y' || ch=='Y');
	return 0;
}
