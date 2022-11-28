// Name - Bodhisatta Bhattacharjee
// CSE-41 --- 22057025
// DSA LAB Sessional

// Question set - 5

// Q2) single linked list - creation, deletion of middle element / kth index
#include <stdio.h>
#include <stdlib.h>

// Defining the structure for a linked list
struct LinkedListADT{
	int data; // integer type linkled list
	struct LinkedListADT *next;
};
typedef struct LinkedListADT node;

// defining the head pointer
node* head = NULL;

// function to get the length of the linked list
int ListLength(node *head){
	int length=0;
	node *p = head;
	while (p!=NULL){
		p = p->next;
		length++;
	}
	return length;
}

// function to insert node at the begin
void InsertNodeAtBegin(int data){
	// creating a temporary node
	node* temp = (node*) malloc (sizeof(node));
	if (temp == NULL){
		printf("\nHeap Memory is full!");
		exit(1);
	}
	temp->data = data;
	temp->next = NULL;
    
	// If there exists no linked list
	if (head == NULL){
		head = temp;
        return;
	}
	// Linking the node to the linked list
	else {
		temp->next = head;
		head = temp;
	}
	printf("\nInserted %d at begin!", data);
}

// function to insert node at the begin
void InsertNodeAtEnd(int data){
	// creating a temporary node
	node* temp = (node*) malloc (sizeof(node));
	if (temp == NULL){
		printf("\nHeap Memory is full!");
		exit(1);
	}
	temp->data = data;
	temp->next = NULL;
		
	// If there exists no linked list
	if (head == NULL){
		head = temp;
	}
	// Linking the node to the linked list
	else {
		// iterating to the last node
		node *p;
		while (p!=NULL){
			p = p->next;
		}
		p->next = temp;
		head = temp;
	}
	printf("\nInserted %d at end!", data);
}

// function to insert node at the begin
void InsertNodeAtPosition(int data, int pos){
	// creating a temporary node
	node* temp = (node*) malloc (sizeof(node));
	if (temp == NULL){
		printf("\nHeap Memory is full!");
		exit(1);
	}
	temp->data = data;
	temp->next = NULL;
	
	// the no. of nodes in a linked list
	int size = ListLength(head);
	
	// position out of bounds	
	if (pos<1 && pos>size){
		printf("\nInvalid Position! Data cannot be inserted");
	}
	
	if (head==NULL && pos!=1){
		printf("\nNo Linked List exists!");
		exit(1);
	}
	
	// position = 1
	else if(pos == 1){
		InsertNodeAtBegin(data);
	}
	
	// position = lastnode + 1
	else if(pos == size+1){
		InsertNodeAtEnd(data);
	}
	
	// position of kth index
	else{
		int count = 1; // head node is 1st node, so count is 1
		node* p = head;
		while (p != NULL && pos>=count){
			p = p->next;
		}
		temp->next = p->next;
		p->next = temp;
	}
	
	printf("\nInserted %d at position %d!", data, pos);
}

// function to delete node at begin
int DeleteNodeAtBegin(){
	if (head == NULL){
		printf("\nNo Linked list exists!");
	}
	node *p = head;
	head = head->next;
	p->next = NULL;
	int data = p->data;
	free(p);
	p=NULL;
	return data;
}

// function to delete node at end
int DeleteNodeAtEnd(){
	if (head == NULL){
		printf("\nNo Linked list exists!");
	}
	
	// traversing the linked list using 2 pointers
	node *q,*p = head;
	while (p!=NULL){
		q = p;
		p = p->next;
	}
	q->next = NULL;
	int data = p->data;
	free(p);
	p=NULL; // freeing the memory
	return data;
}

// delete node in postion k
int DeleteNodeAtPosition(int pos){
	int count =1; // counting the number of nodes traversed
	int size = ListLength(head); // size of the linked list
	
	// out of bounds
	if (pos <1 || pos >=size){
		printf("\nInvalid Position!");
		exit(1);
	}
	
	// iterating the linked list
	node *q,*p = head;
	while (p!=NULL && count!=pos){
		q = p;
		p = p->next;
		count++;
	}
	// now p points to the node to be deleted
	// q points to the previos node
	
	q->next = p->next;
	p->next = NULL;
	int data = p->data;
	free(p);
	p=NULL;
	return data;
}

void Display(){
	node *p = head;
	printf("\nPrinting the Linked List : ");
	while (p!=NULL){
		printf("%d ", p->data);
		p=p->next;
	}
}

int main(){
	InsertNodeAtBegin(8);
	InsertNodeAtBegin(1);
	InsertNodeAtBegin(3);
	InsertNodeAtPosition(7,1);
    Display();
	DeleteNodeAtPosition(2);
	Display();
	
	return 0;
}