/*
 * This code is written by Mitesh Shah.
 * Sem 3. C22-111.
 *
 * Code contains:
 *	Single Linked List:
 *		Insertion - Beg,End,AtN
 *		Deletion - Beg,End,AtN
 *		Create
 *		Display
 *
 * Compiled using 'gcc version 4.8.2'
 * 15th September, 2014.
 *
*/

#include<stdio.h>
#include<stdlib.h>

//Create a basic structure for NODE from which new nodes can be created.
struct node
{
	int data;
	struct node *next;
};

//Prototypes for various user defined functions.
struct node* create_ll(struct node*);
struct node* insert_front(struct node*);
struct node* insert_end(struct node*);
struct node* insert_atN(struct node*);
struct node* delete_front(struct node*);
struct node* delete_end(struct node*);
struct node* delete_atN(struct node*);
void display(struct node*);

int main()
{
	int choice;
	int cont = 1;
	struct node* myList;

	while(cont == 1){
		//Display menu to the user
		printf("\n1. Create a linked list.");
		printf("\n2. Insert at front");
		printf("\n3. Insert at end");
		printf("\n4. Insert at atN position");
		printf("\n5. Delete from front");
		printf("\n6. Delete from end");
		printf("\n7. Delete from anywhere");
		printf("\n8. Display linked list");
		printf("\nEnter your choice: ");
		scanf("%d", &choice);

		switch(choice){
		case 1: 
			myList = create_ll(myList);
			display(myList);
			break;
		case 2: 
			myList = insert_front(myList);
			display(myList);
			break;
		case 3:
			myList = insert_end(myList);
			display(myList);
			break;
		case 4: 
			myList = insert_atN(myList);
			display(myList);
			break;
		case 5:
			myList = delete_front(myList);
			display(myList);
			break;
		case 6:
			myList = delete_end(myList);
			display(myList);
			break;
		case 7:
			myList = delete_atN(myList);
			display(myList);
			break;
		case 8:
			display(myList);
			display(myList);
			break;
		}

		printf("\nDo you want to continue? (1 / 0): ");
		scanf("%d", &cont);
	}

	getchar();
	return 0;
}

//Function to create a single linked list.
struct node* create_ll(struct node *head)
{
	int val,n;
	printf("Enter number of elements to insert\n");
	scanf("%d",&n);
	while(n)
	{
		struct node *newNode=(struct node*)malloc(sizeof(struct node));
		printf("Enter the Data :");
		scanf("%d",&val);
		newNode->data=val;
		newNode->next=head;
		head=newNode;
		n--;
	}
	return head;
}
//Function to insert a node at the front of a single linked list.
struct node* insert_front(struct node * head)
{
	int data_value;
	struct node* newNode = NULL;
	printf("\nEnter data of the node: ");
	scanf("%d", &data_value);

	newNode = (struct node *) malloc(sizeof(struct node));
	newNode->data = data_value;
	
	if(head == NULL){ //If head is NULL, create link list.
	head = newNode;
	head->next = NULL;
	} else if(head != NULL){
	newNode->next = head;
	head = newNode;
	}
	return head;
}

//Function to insert a node at the end of a single linked list.
struct node* insert_end(struct node * head)
{
	int data_value;
	struct node* temp = NULL;
	struct node* newNode = NULL;
	
	printf("\nEnter data of the node: ");
	scanf("%d", &data_value);

	newNode = (struct node *) malloc(sizeof(struct node));
	newNode->data = data_value;
	newNode->next = NULL;

	if(head == NULL){
		head = newNode;
		return head;
	}
	temp = head;
	while(temp->next != NULL)
		temp = temp->next;
	temp->next = newNode;

	return head;
}

//Function to insert a node at atN position after a particular node.
struct node* insert_atN(struct node* head)
{
	int data_value, n;
	struct node* temp = NULL;
	struct node* curr = NULL;
	struct node* newNode = NULL;
	
	printf("\nEnter data of the node: ");
	scanf("%d", &data_value);
	printf("\nEnter position to insert node");
	scanf("%d", &n);

	newNode = (struct node *) malloc(sizeof(struct node));
	curr = head;
	//Traverse till key is found or end of the linked list is reached.
	while(curr->next != NULL && n > 1){
		temp = curr;
		curr = curr->next;
		n--;
	}
	temp->next=newNode;
	newNode->data = data_value;
	newNode->next = curr;
	
	return head;
}

//Function to delete a node from the front of a linked list.
struct node* delete_front(struct node* head)
{	
	if(head == NULL){
		printf("\nEmpty linked List. Deletion not possible.\n");
	}else{
		struct node *temp = NULL;
		temp=head;
		head=head->next;
		free(temp);
	}
	return head;
}

//Function to delete a node at the end of a single linked list.
struct node* delete_end(struct node * head)
{
	struct node* temp = head;
	struct node* curr = head;
	
	if(head == NULL)
		return head;
	
	//Traverse to the end of the linked list.
	while(curr->next != NULL){
		temp = curr;
		curr = curr->next;
	}
	temp->next = NULL;
	free(curr);	
	
	return head;
}
//Function to delete atN node from linked list.
struct node* delete_atN(struct node* head)
{
	int n;
	struct node* temp=head;
	struct node* curr=head;
	if(head == NULL)
		return head;
	while( curr->next!=NULL && n > 1){
		temp = curr;
		curr = curr-> next;		
		n--;
	}
	temp->next=curr->next;
	free(curr);
	return head;
}

//Function to display the contents of the linked list.
void display(struct node* head)
{
	struct node* temp = head;
	if(head==NULL){
		printf("Linked list is empty.");
	}
	else {
		printf("\nContents of the linked list are: \n");
		while(temp != NULL){
			printf("%d ", temp->data);
			temp = temp->next;
		}
	}
}

// End of Program.
