#include<iostream>
using namespace std;
class node
{
	public:
		int val;
		node* next;
		node(int value)
		{
			val=value;
			next=NULL;
		}//Insertion at start or head
		void insert_head(node* &head,int val)
		{
			node* new_node = new node(val);
			new_node->next = head;
			head = new_node;
		}//Insertion at tail or end
		void insert_tail(node* &head,int val)
		{
			node* new_node = new node(val);
            node* temp=head;
            while(temp->next!=NULL)
            {
            	temp=temp->next;
			}
			temp->next=new_node;
		}//Specific Point insertion operation
	    void insert_nth(node* &head,int val,int pos)
		{
			node* new_node = new node(val);
			if(pos==0)
			{
                new_node->next = head;
                head = new_node;
                return;
            }
			node* temp=head;
			int temp_pos=0;
			while(temp_pos!=pos-1 && temp != NULL)
			{
				temp=temp->next;
				temp_pos++;
			}
			if (temp == NULL)
            {
                cout<<"Position out of bounds."<<endl;
                delete new_node; // Deleting the created node
                return;
            }
			new_node->next = temp->next;
			temp->next = new_node;	
		}//Update OPeration
		void update(node* head,int val,int pos)
		{
			if(pos<0)
			{
				cout<<"Position out of bound..."<<endl;
			}
			node* temp = head;
			int temp_pos=0;
			while(temp != NULL)
			{
				if(temp_pos==pos)
				{
					temp->val=val;
					return;
				}
				temp=temp->next;
				temp_pos++;
			}
			cout<<"Position out of bound..."<<endl;
		}//Delete Operation
		void Delete_nth(node* &head,int pos)
		{
		    if(pos==0)
			{
				node* temp = head;
                head = head->next;
                delete temp;
			}
			else if(pos<0)
			{
				cout<<"Position out of bound..."<<endl;
			}
			else
			{
			node* temp = head;
			int temp_pos=0;
			while(temp != NULL)
			{
				if(temp_pos==pos-1)
				{
					node* del=temp->next;
					temp->next=temp->next->next;
					delete del;
				    return;
				}
				temp=temp->next;
				temp_pos++;
			}
	        }	
		}//Search Operation
		bool search(node* head,int find)
		{
			node* temp = head;
			while(temp!=NULL)
			{
				if(temp->val==find)
				{
					return true;
				}
				temp=temp->next;
			}
			return false;
		}//Treverse  Operation
		void display(node* head)
		{
			node* temp=head;
			while(temp!=NULL)
			{
				cout<<temp->val<<" -> ";
				temp=temp->next;
			}
			cout<<endl;
		}
};
int main()
{
	node* b;
	node* head= NULL;
	int value,loc,choice;
	b->insert_head(head,14);
    b->insert_head(head,12);
    b->display(head);
    do{
	cout<<"Press 1 To insert at head.\nPress 2 to insert at Tail.\n";
	cout<<"Press 3 to insert at Specific Position.\nPress 4 to Update specific element.\n";
	cout<<"Press 5 to Delete Specific element.\nPress 6 to Search Element.\n";
	cout<<"Press 7 to Traverse List.\nPress 0 to exit.\n";
	cin>>choice;
    if(choice==1)
    {
        cout<<"Enter Value to insert...";
        cin>>value;
        b->insert_head(head,value);
        b->display(head);
    }
    else if(choice==2)
    {
        cout<<"Enter Value to insert...";
        cin>>value;
        b->insert_tail(head,value);
        b->display(head);
    }
    else if(choice==3)
    {
    	cout<<"Enter Value to insert...";
        cin>>value;
        cout<<"Enter Location such as (0,1,2,3-----)"<<endl;
        cin>>loc;
      	b->insert_nth(head,value,loc);
        b->display(head);
    }
    else if(choice==4)
    {
    	cout<<"Enter Value to update...";
        cin>>value;
        cout<<"Enter Location such as (0,1,2,3-----)"<<endl;
        cin>>loc;
        b->update(head,value,loc);
        b->display(head);
    }
    else if(choice==5)
    {
        cout<<"Enter Location such as (0,1,2,3-----)"<<endl;
        cin>>loc;
        b->Delete_nth(head,loc);
        b->display(head);
    }
    else if(choice==6)
    {
    	cout<<"Enter Value to search...";
        cin>>value;
        if(b->search(head,value) == 1)
		{
         	cout<<"Element Found..."<<endl;
     	}
    	else
		{
	     	cout<<"Elememt not found..."<<endl;
     	}
    }
    else if(choice==7)
    {
    	b->display(head);
	}
	else
	{
		cout<<"Invalid choice..."<<endl;
	}
    }while(choice!=0);
	return 0;
}
