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
struct node* create_ll();
struct node* copy_ll(struct node*);
struct node* concat_ll(struct node* , struct node*);
void split_ll(struct node **,struct node **, int );
struct node* reverse_ll(struct node*);
void display(struct node *);

int main()
{
	int choice;
	int cont = 1;
	struct node *myList, *myList2;
	myList = myList2 = NULL;
	while(cont == 1){
		//Display the Menu to user
		printf("\n1. Create a linked list.");
		printf("\n2. Copy linked list");
		printf("\n3. Concatenate 2 Linked List ");
		printf("\n4. Split a linked list into 2 ");
		printf("\n5. Reverse a linked list ");
		printf("\n7. Display Linked List. ");
		printf("\nEnter your choice. ");
		scanf("%d",&choice);
		
		switch(choice){
		case 1:
			myList = create_ll(NULL);
			display(myList);
			break;
			
		case 2:
			myList2 = copy_ll(myList);
			display(myList2);
			break;
		
		case 3:
			myList = concat_ll(myList, myList2);
			display(myList);
			break;
			
		case 4:
			split_ll(&myList,&myList2, 5);
			display(myList);
			break;
		
		case 5:
			myList = reverse_ll(myList);
			display(myList);
			break;
		
		case 6: 
			display(myList);
			break;
		
		default:
			break;
		}
		printf("Do you want to continue? 1/0");
		scanf("%d",&cont);
	}
	return 0;
}

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

struct node* copy_ll(struct node* head)
{
	return head;
}

struct node* concat_ll(struct node* head, struct node* head2)
{
	if(head == NULL){
		return head;
	}
	struct node* temp = head;
	
	while(temp->next != NULL){
		temp=temp->next;
	}
	temp->next = head2;
	return head;
}

void split_ll(struct node** head, struct node** head2, int n)
{	
	struct node* temp = *head;
	while(temp->next != NULL && n > 1){
		temp=temp->next;
		n--;
	}
	*head2 = temp->next;
}

struct node* reverse_ll(struct node* head)
{
	struct node* nextNode;
	struct node* prevNode = NULL;
	
	while(head != NULL){
		nextNode = head->next;
		head->next = prevNode;
		prevNode = head;
		head = nextNode;
	}
	return head;
}

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