#include<iostream>
#include<stdio.h>
using namespace std;
struct node
{
    int roll;
	node *next;
};
node *root=NULL;

/// Insert on Link list

void append(int roll)
{
	if(root==NULL) //If the list is empty
	{
		root=new node();
		root->roll=roll;
		root->next=NULL;
	}
	else
	{
		node *current_node=root; //make a copy of root node
		while(current_node->next!=NULL) //Find the last node
		{
			current_node=current_node->next; //go to next address
		}
		node *newnode = new node(); //create a new node
		newnode->roll=roll;
		newnode->next=NULL;

		current_node->next=newnode; //link the last node with new node
	}
}

/// print funtion for show element on link list

void print()
{
		node *current_node=root;
		while(current_node!=NULL) //loop until you reach null
		{
			printf("%d\n",current_node->roll);
			current_node=current_node->next;
		}
}
int main(){

	append(1);
	append(2);
	append(6);
	print();
    return 0;
}
