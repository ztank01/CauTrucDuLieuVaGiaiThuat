#include <iostream>
#include <fstream>
using namespace std;

ifstream fin;

struct SV
{
	double DiemTB;
	struct SV* next;
};
SV* CreateSV(double x)
{
	SV* p= new SV;
	p->DiemTB=x;
	p->next=NULL;
	return p;
};
struct LinkedList
{
	 SV* head;
	 SV* tall;
};
void addFirst(LinkedList &myList, SV* p)
{
	if ( myList.head == NULL )
	{
		myList.head = p;
		myList.tall=p;
	}
	else
	{
		p->next=myList.head;
		myList.head=p;
	}
}

void addLast(LinkedList &myList, SV* p)
{
	if ( myList.tall == NULL )
	{
		myList.head = p;
		myList.tall=p;
	}
	else
	{
		myList.tall->next=p;
		myList.tall=p;
	}
}
void NhapDS(LinkedList &myList)
{
	fin.open("19110492_TrinhCongTruong_C_3_1-Input.txt");
	do
	{
		SV *p=new SV;
		fin >> p->DiemTB;
		p->next=NULL;
		addLast(myList,p);
	}
	while(!fin.eof());
	fin.close();
}
void sortList(LinkedList &myList)
{
	SV* temp1=new SV;
	SV* temp2=new SV;
	SV* temp3=new SV;
	SV* head=new SV;
	head=myList.head;
	while ( head->next!=NULL )
	{
		temp1=head->next;;
		SV* min=new SV;
		min=head;
		while ( temp1!=NULL )
		{
			if ( min->DiemTB <= temp1->DiemTB )
				temp1=temp1->next;
			else
			{
				min=temp1;
				temp1=temp1->next;
			}
		}
		temp2=myList.head;
		while ( temp2->next!=min && min!=myList.head )
			temp2=temp2->next;
		temp3=myList.head;
		while ( temp3->next!=head && head!=myList.head)
			temp3=temp3->next;
		if ( head!=myList.head && min !=head )
		{
			temp2->next=temp2->next->next;
			temp3->next=min;
			min->next=head;
		}
		else
			if ( min == head )
				head=head->next;
			else
				{
					temp2->next=temp2->next->next;
					myList.head=min;
					min->next=head;
				}
	}
}
void main()
{
	LinkedList myList;
	myList.head=NULL;
	myList.tall=NULL;
	NhapDS(myList);
	SV* temp=myList.head;
	while (temp != NULL)
	{
		cout << temp->DiemTB << " ";
		temp=temp->next;
	}
	cout << "\n";
	sortList(myList);
	cout << "\n";
	temp=myList.head;
	while (temp != NULL)
	{
		cout << temp->DiemTB << " ";
		temp=temp->next;
	}
}