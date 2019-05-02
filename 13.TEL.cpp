#include<iostream>
#include<iomanip>
#define MAX 100
using namespace std;

class hashing
{
	public:
		int id;
		string name;
		long int phone_no;
};

class phoneBook
{
	public:
		int i;
		hashing obj[MAX];
		int hash_fxn(string);
		void insert_wo(int,string,long int);
		void search(string);
		void display();
		phoneBook()
		{
			for(i=0; i<MAX; i++)
			{
				obj[i].id=-1;
				obj[i].name="-";
				obj[i].phone_no=-1;
			}
		}
};

int phoneBook :: hash_fxn(string name)
{




int value=0,val;
	for(i=0;i<name.length();i++)
	{
		value=value+name[i];
	}
	val=value%MAX;
	return val;
}

void phoneBook :: insert_wo(int key,string name,long int phone_no)
{
	int value;
	value=hash_fxn(name);
	if(obj[value].id==-1)
	{
		obj[value].id = key;
		obj[value].name = name;
		obj[value].phone_no = phone_no;
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
				obj[val].phone_no = phone_no;
				break;
			}
		}
	}
}

void phoneBook :: search(string name)
{
	int flag=0;
	int val=hash_fxn(name);
	if(obj[val].name==name)
	{
		cout<<obj[val].name<<" : "<<obj[val].phone_no<<endl;
		flag=1;
	}




else
	{
		for(int i=val+1;i<MAX;i++)
		{
			int v=i%MAX;
			if(obj[v].name==name)
			{
				cout<<obj[i].name<<" : "<<obj[i].phone_no<<endl;
				flag=1;
				break;
			}
		}
	}
	if(flag==0)
		cout<<"Record not present"<<endl;
}

void phoneBook :: display()
{
	cout<<"Index"<<setw(22)<<"Name"<<setw(30)<<"Phone Number"<<endl;
	for(i=0;i<MAX;i++)
	{
		if(obj[i].id!=-1)
		{
			cout<<i<<setw(25)<<obj[i].name<<setw(30)<<obj[i].phone_no<<endl;
		}
	}
}

int main()
{
	int key=0,choice,val;
	long int number;
	char ch='y';
	string name;
	phoneBook obj;
	while(ch=='y' || ch=='Y')
	{
		cout<<"1. Insert record"<<endl;
		cout<<"2. Search record "<<endl;
		cout<<"3. Display all records"<<endl;
		cout<<"Enter your choice"<<endl;
		cin>>choice;





switch(choice)
		{
			case 1:
				cout<<"Enter the name"<<endl;
				cin.ignore();
				getline(cin,name);
				cout<<"Enter the phone number"<<endl;
				cin>>number;
				obj.insert_wo(key,name,number);
				key=key+1;
				break;

			case 2:
				cout<<"Enter the name you want to search"<<endl;
				cin.ignore();
				getline(cin,name);
				obj.search(name);
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
