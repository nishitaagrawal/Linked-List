#include<iostream> //Doubly Linked List
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Node
{
	public:
		int data;
		Node *next,*prev;
};
class List:public Node
{
	Node *dlistptr,*temp;
	public:
		List()
		{
			dlistptr=NULL;
			temp=NULL;
		}
		void create();
		void display();
		void insert_start();
		void insert_end();
		void insert_intermediate();
		void delete_start();
		void delete_end();
		void delete_intermediate();
		void reverse();
		void concatenate();
		
}lst;
void List::create()    // Create a new Node
{
	int n,x;
	cout<<"Enter the number of nodes : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		Node *newnode=new Node;
		cout<<"Enter data : ";
		cin>>x;
		newnode->data=x;
		newnode->prev=NULL;
		newnode->next=NULL;
		if(dlistptr==NULL)   //first node
		{
			dlistptr=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			newnode->prev=temp;
			temp=temp->next;
		}
	}
}
void List::display()   // Display Linked List
{
	temp=dlistptr;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<" <-> ";
		temp=temp->next;
	}
	cout<<temp->data<<" <-> "<<"NULL";
}
void List::insert_start()    //Insert node at begginning
{
	int x;
	Node *newnode=new Node;
	cout<<"enter data : ";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	newnode->prev=NULL;
	newnode->next=dlistptr;	
	dlistptr->prev=newnode;
	dlistptr=newnode;
}
void List::insert_end()   // Insert node at end
{
	int x;
	Node *newnode=new Node;
	cout<<"Enter the value : ";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	temp=dlistptr;
	while(temp->next!=NULL)  
	{
		temp=temp->next;
	}
	temp->next=newnode;
	newnode->prev=temp;
}
void List::insert_intermediate()  // Insert node at intermediate position
{
	int n=1,x,i;
	Node *newnode=new Node;
	cout<<"Enter data : ";
	cin>>x;
	newnode->data=x;
	newnode->prev=NULL;
	newnode->next=NULL;
	temp=dlistptr;
	cout<<"Enter the position : ";
	cin>>n;
	for(i=0;i<n-1;i++)
	{
		temp=temp->next;
	}
	
	newnode->next=temp->next;
	temp->next=newnode;
	newnode->prev=temp;
	newnode->next->prev=newnode;
}

void List::delete_start()    //Delete node at start
{
	temp=dlistptr;
	dlistptr=temp->next;
	dlistptr->prev=NULL;
	delete(temp);
}
void List::delete_intermediate()   //Delete Node at intermediate position
{
	int x,n;
	temp=dlistptr;
	cout<<"Enter position : ";
	cin>>n;
	for(int i=0;i<n;i++)
	{
		temp=temp->next;
	}
	temp->prev->next=temp->next;
	temp->next->prev=temp->prev;
	delete(temp);
}
void List::delete_end()     //delete Node at end
{
	Node *q;
	temp=dlistptr;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	delete(temp->next);
	temp->next=NULL;
}
void List::reverse()    //Reverse a Linked List
{
	cout<<temp->data<<" <-> ";
	while(temp->prev!=NULL)
	{
		temp=temp->prev;
		cout<<temp->data<<" <-> ";
	}
	cout<<"NULL";
	
}
void List::concatenate()
{
	List l;
	cout<<"List 1 : \n";
	lst.create();
	lst.display();
	cout<<"\nList 2 : \n";
	l.create();
	l.display();
	temp=dlistptr;
	while(lst.temp->next!=NULL)
	{
		lst.temp=lst.temp->next;
	}
	lst.temp->next=l.dlistptr;
	dlistptr->prev=temp;
	cout<<"\nConcatenated List is : ";
	lst.display();
}
int main()
{
	int choice;
	cout<<"** MENU DRIVEN PROGRAM ** \n\n";
	cout<<"Press 1 to create new node.\nPress 2 to display node \nPress 3 to insert data in begining ";
	cout<<"\nPress 4 to insert node in intermediate \nPress 5 to insert node at end ";
	cout<<"\nPress 6 to delete node in beggining.\nPress 7 to delete node in intermediate \nPress 8 to delete node at end ";
	cout<<"\nPress 9 to reverse the linked list \nPress 10 to Concatenate 2 linked list \nPress 11 to Exit";
	while(choice!=10)
	{
		cout<<"\n\nEnter your choice: ";
		cin>>choice;
		switch(choice)
		{
			case(1):lst.create();break;
			case(2):lst.display();break;
			case(3):lst.insert_start();break;
			case(4):lst.insert_intermediate();break;
			case(5):lst.insert_end();break;
			case(6):lst.delete_start();break;
			case(7):lst.delete_intermediate();break;
			case(8):lst.delete_end();break;
			case(9):lst.reverse();break;
			case(10):lst.concatenate();break;
			case(11):break;
			default:cout<<"Invalid choice";
		}
	}
}
