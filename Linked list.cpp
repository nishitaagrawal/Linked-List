#include<iostream> //Singlly Linked List
#include<conio.h>
#include<stdlib.h>
using namespace std;
class Node
{
	public:
		int data;
		Node *next;
};
class List:public Node
{
	Node *listptr,*temp; //TEMP- current node; listptr - head node;
	public:
		List()
		{
			listptr=NULL;
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
		newnode->next=NULL;
		if(listptr==NULL)   //first node
		{
			listptr=newnode;
			temp=newnode;
		}
		else
		{
			temp->next=newnode;
			temp=newnode;
		}
	}
}
void List::display()   // Display Linked List
{
	temp=listptr;
	while(temp->next!=NULL)
	{
		cout<<temp->data<<" -> ";
		temp=temp->next;
	}
	cout<<temp->data<<" -> "<<"NULL";
}
void List::insert_start()    //Insert node at begginning
{
	int x;
	Node *newnode=new Node;
	cout<<"enter data : ";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	newnode->next=listptr;	
	listptr=newnode;
}
void List::insert_end()   // Insert node at end
{
	int x;
	Node *newnode=new Node;
	cout<<"Enter the value : ";
	cin>>x;
	newnode->data=x;
	newnode->next=NULL;
	temp=listptr;
	while(temp->next!=NULL)  
	{
		temp=temp->next;
	}
	temp->next=newnode;
}
void List::insert_intermediate()  // Insert node at intermediate position
{
	int n=1,x,i;
	temp=listptr;
	cout<<"Enter the position : ";
	cin>>n;
	while(i!=n-1)
	{
		temp=temp->next;
		i++;
	}
	cout<<"Enter data : ";
	cin>>x;
	Node *newnode=new Node;
	newnode->next=temp->next;
	temp->next=newnode;
	newnode->data=x;
}
void List::delete_start()    //Delete node at start
{
	temp=listptr;
	listptr=temp->next;
	delete(temp);
}
void List::delete_intermediate()   //Delete Node at intermediate position
{
	int x,n;
	Node *q;
	temp=listptr;
	cout<<"Enter position : ";
	cin>>n;
	for(int i=0;i<n-1;i++)
	{
		temp=temp->next;
	}
	q=temp->next;
	temp->next=q->next;
	delete(q);
}
void List::delete_end()     //delete Node at end
{
	Node *q;
	temp=listptr;
	while(temp->next->next!=NULL)
	{
		temp=temp->next;
	}
	q=temp->next;
	temp->next=NULL;
	delete(q);
}
void List::reverse()    //Reverse a Linked List
{
	Node *forward, *curr, *back;
	forward=listptr;
	curr=NULL;
	while(forward!=NULL)
	{
		back=curr;
		curr=forward;
		forward=forward->next;  //move forward
		curr->next=back; //make back link
	}
	listptr=curr;
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
	temp=listptr;
	while(lst.temp->next!=NULL)
	{
		lst.temp=lst.temp->next;
	}
	lst.temp->next=l.listptr;
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
