#include<iostream>
#include<fstream>
#include<cstdio>
using namespace std;
class Employee
{
public:
int empno;
char name[50];
char desig[50];
long salary;
void getData()
{
cout<<"Enter employee id : ";
cin>>empno;
cout<<"Enter employee name : ";
cin>>name;
cout<<"Enter employee's designation : ";
cin>>desig;
cout<<"Enter his salary : ";
cin>>salary;
}
void showData()
{
cout<<"ID : "<<empno;
cout<<"\tName : "<<name;
cout<<"\tDesignation : "<<desig;
cout<<"\tSalary : "<<salary<<endl;
}
int retempno()
{
return empno;
}
};
void write_record()
{
ofstream outFile;
outFile.open("employee.dat",ios::binary | ios::app);
Employee obj;
obj.getData();
outFile.write((char*)&obj, sizeof(obj));
outFile.close();
}
void display()
{
ifstream inFile;
inFile.open("employee.dat", ios::binary);
Employee obj;
while(inFile.read((char*)&obj, sizeof(obj)));
{
obj.showData();
}
inFile.close();
}
void search(int n)
{
ifstream inFile;
inFile.open("employee.dat", ios::binary);
Employee obj;
while(inFile.read((char*)&obj, sizeof(obj)))
{
if(obj.retempno() == n)
{
obj.showData();
break;
}
}
inFile.close();
}
void delete_record(int n)
{
Employee obj;
ifstream inFile;
inFile.open("employee.dat", ios::binary);
ofstream outFile;
outFile.open("temp.dat", ios::out | ios::binary);
while(inFile.read((char*)&obj, sizeof(obj)))
{
if(obj.retempno() != n)
{
outFile.write((char*)&obj, sizeof(obj));
}
}
inFile.close();
outFile.close();
remove("employee.dat");
rename("temp.dat","employee.dat");
}
void modify_record(int n)
{
fstream file;
file.open("employee.dat", ios::in | ios::out);
Employee obj;
while(file.read((char*)&obj, sizeof(obj)))
{
if(obj.retempno() == n)
{
cout<<"Enter new details of employee"<<endl;
obj.getData();
long int pos = (-1) * sizeof(obj);
file.seekp(pos, ios::cur);
file.write((char*)&obj, sizeof(obj));
break;
}
}
file.close();
}
int main()
{
int choice;
char ch='y';
do
{
cout<<"-----------------MENU-----------------"<<endl;
cout<<"1. Write record"<<endl;
cout<<"2. Display record"<<endl;
cout<<"3. Search record"<<endl;
cout<<"4. Delete record"<<endl;
cout<<"5. Modify record"<<endl;
cout<<"Enter your choice"<<endl;
cin>>choice;
switch(choice)
{
case 1:
int n;
cout<<"Enter number of records you want to add"<<endl;
cin>>n;
for(int i=0; i<n; i++)
write_record();
break;
case 2:
cout<<"List of Records"<<endl;
display();
break;
case 3:
int s;
cout<<"Enter employee ID to be searched"<<endl;
cin>>s;
search(s);
break;
case 4:
int d;
cout<<"Enter employee ID to be deleted"<<endl;
cin>>d;
delete_record(d);
cout<<"Record deleted"<<endl;
break;
case 5:
int m;
cout<<"Enter employee ID to be modified"<<endl;
cin>>m;
modify_record(m);
break;
default:
cout<<"Wrong input"<<endl;
}
cout<<"Do you want to continue"<<endl;
cin>>ch;
}while(ch=='y' || ch=='Y');
return 0;
}

