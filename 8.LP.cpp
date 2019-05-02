#include<iostream>
using namespace std;

int MAX=10;

class hashing
{
	public:
		int id;
		string name;
};

class table
{
	public:
		int i;
		hashing obj[10];
		void initialize();
		int hash_fxn(int);
		void insert_wo(int,string);
		void insert_w(int,string);
		void display();
		table()
		{
			for(i=0; i<MAX; i++)
			{
				obj[i].id=-1;
				obj[i].name="-";
			}
		}
};

void table :: initialize()
{
	for(i=0; i<MAX; i++)
	{
		obj[i].id=-1;
obj[i].name="-";
	}
}

int table :: hash_fxn(int key)
{
	int value;
	value=key%MAX;
	return value;
}

void table :: insert_wo(int key,string name)
{
	int value;
	value=hash_fxn(key);
	if(obj[value].id==-1)
	{
		obj[value].id = key;
		obj[value].name = name;
	}
	else
	{
		for(i=value+1;i<MAX;i++)
		{
			int val = i%MAX;
			if(obj[val].id==-1)
			{
				obj[val].id = key;
				obj[val].name = name;
				break;
			}
		}
	}
}

void table :: insert_w(int key, string name)
{
	int value;
	value=hash_fxn(key);
	if(obj[value].id==-1)
	{
		obj[value].id = key;
		obj[value].name = name;
	}
	else if((obj[value].id%MAX)==value)
	{
		for(i=value+1;i<MAX;i++)
        {
			int val = i%MAX;
			if(obj[val].id==-1)
			{
				obj[val].id = key;
				obj[val].name = name;
				break;
			}
		}
	}
	else
	{
		hashing temp;
		temp.id = obj[value].id;
		temp.name = obj[value].name;
		obj[value].id=key;
		obj[value].name=name;
		for(i=value+1;i<MAX;i++)
		{
			int val = i%MAX;
			if(obj[val].id==-1)
			{
				obj[val].id = temp.id;
				obj[val].name = temp.name;
				break;
			}
		}
	}
}

void table :: display()
{
	cout<<"Index	ID	Name"<<endl;
	for(i=0;i<MAX;i++)
	{
		if(obj[i].id!=-1)
		{
			if(obj[i].id%MAX == i)
			{
				cout<<i<<"	"<<obj[i].id<<"	"<<obj[i].name;
				cout<<"		present at home address"<<endl;
			}
			else
			{
				cout<<i<<"	"<<obj[i].id<<"	"<<obj[i].name;
				cout<<"		not present at home address" <<endl;
            }
		}
	}
}

int main()
{
	int key,choice;
	char ch='y';
	string name;
	table obj;
	while(ch=='y' || ch=='Y')
	{
		cout<<"1. Insert with replacement"<<endl;
		cout<<"2. Insert without replacement"<<endl;
		cout<<"3. Display"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;

		switch(choice)
		{
			case 1:
				cout<<"Enter the id"<<endl;
				cin>>key;
				cout<<"Enter the name"<<endl;
				cin>>name;
				obj.insert_w(key,name);
				break;

			case 2:
				cout<<"Enter the id"<<endl;
				cin>>key;
				cout<<"Enter the name"<<endl;
				cin>>name;
				obj.insert_wo(key,name);
				break;

			case 3:
				obj.display();
				break;

			default:
				cout<<"Wrong input"<<endl;
		}
		cout<<"Do you want to continue (y/n)"<<endl;
		cin>>ch;
}
	return 0;
}

