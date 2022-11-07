// ----------------------------- SINGLE LINKED LIST -------------------------
// Header files
#include <stdio.h>
#include <stdlib.h>

// node structure definition
struct node
{
    /* data */
    int data;
    struct node *next;
};
typedef struct node node;

// function declarations
void ReverseLinkedList();
void createnode();
int listLength();
void InsertAtBegin();
void InsertAtEnd();
void InsertAtPos();
void DeleteAtBegin();
void DeleteAtEnd();

// making the first node which points to address NULL
node *head=NULL;
// NOTE : All the functions defined, don't have the necessary head node as parameter.
// Since head node is globally declared, we can access and modify the value of "head" 
// directly from any function. Otherwise, if head was not defined or was defined
// inside MAIN FUNCTION, then then we would vae to give the parameter like below ---
// return_type funtion_name (node **head, other parameters if any ....) {
//    .....
// }
// and we would call the fucntions as ---
// function_name (&head, ...);
// Note: we are passing the address of head pointer here.

// function to get the length of the linked list
int listLength(){
    int count = 1;
    node *temp = head;
    if (temp== NULL) return 0;
    else{
        while (temp->next != NULL){
            count++;
            temp = temp->next;
        }
        return count;
    }
}

// function to insert an element in the linked list at the begining
void InsertAtBegin(){
    node *temp;
    temp=(node*)malloc(sizeof(node));
    if (temp==NULL){
        printf("Memory Full! Cannot add node.");
        exit(1);
    }
    printf("\n----- Insert node at begin -----\n");
    printf("Enter data element : ");
    scanf("%d",&temp->data);
    if (head==NULL) head=temp;
    else{
        // the order of the next 2 lines is very important
        temp->next = head;
        head=temp;
    }
}

// function to insert an element in the linked list at the end
void InsertAtEnd(){
    node* temp;
    temp = (node*) malloc (sizeof(node));
    if (temp==NULL){
        printf("Memory Full! Cannot add node.");
        exit(1);
    }
    printf("\n----- Insert node at end -----\n");
    printf("Enter data element : ");
    scanf("%d", &temp->data);
    temp->next = NULL;
    if (head==NULL){
        head = temp;
    }
    else {
        node *p = head;
        while (p->next!=NULL){
            p = p->next;
        }
        p->next = temp;
        temp=NULL;
        p = NULL;
    }
}

// inseting a node in the given position
void InsertAtPos(int pos){
    int length = listLength(head);
    if (pos<=0 || pos>length+1){
        printf("Invaid Position. ");
        exit(1);
    }
    else if (pos==1) {
        printf("InsertAtBegin() INVOKED\n");
        InsertAtBegin(head);
    }
    else if (pos == length+1){
        printf("InsertAtEnd() INVOKED\n");
        InsertAtEnd(head);
    }
    else{
        node *p = head, *temp;
        int k=1;
        temp = (node*) malloc (sizeof(node));
        if (temp==NULL){
            printf("Memory Full! Cannot add node.");
            exit(1);
        }
        printf("\n----- Insert node at pos [%d] -----\n", pos);
        printf("Enter data : ");
        scanf("%d", &temp->data);
        temp->next = NULL;

        while (k<pos-1){
            p = p->next;
            k++;
        }
        temp->next = p->next;
        p->next = temp;
    }
}

// function to create a node to an existing linked list or create a node and add node
void createnode()
{
    node *temp;
    temp=(node*)malloc(sizeof(node));
    if (temp==NULL)
    {
        printf("\nCannot create Linked List! Memory Full!");
        exit(1);
    }

    printf("Enter data element : ");
    scanf("%d",&temp->data);
    temp-> next=NULL;

    // if there is no linked list, then head will have address of the first node
    if (head==NULL)
    {
        head = temp;}

    else
    {
        node *p=head;
        while (p->next !=NULL)
        {
        p=p->next;
        }
        
        p->next = temp;
        p = NULL;
        temp = NULL;
    }
}

// WAP to find middle of the linked list without using listLength()
node* FindMiddle_withoutListLength(){
    node *slow=head, *fast=head;
    while (fast!=NULL && fast->next!=NULL && (fast->next)->next!=NULL){
        slow = slow->next;\
        fast = fast->next->next;
    }
    return slow;
}

// find the middle element of a single linked list
node* FindMiddle_usingListLength(){
    int length = listLength(head);
    int k=0, mid = length/2;
    node *p = head;
    while (k<mid) {
        p = p->next;
        k++;
    }
    return p;
}

// WAP to find whether a cycle exist in singly linkedlist
void FindCycle(){
    node *slow=head, *fast=head;
    printf("\n----- FindCycle() function called! -----\n");
    while (fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast){
            printf("Cycle exits.");
            exit(1);
        }
    }
    printf("No Cycle exists.");
}

// WAP to delete the last node of a linked list
void DeleteAtEnd(){
    // case when no linkedlist exist
    if (head==NULL){
        printf("No Linked list exist so no node to delete");
        exit(1);
    }
    printf("\n----- Deleting Node at END -----");
    // case when there is only 1 element in the linked list
    if (head->next==NULL){
        free(head);
        head=NULL;
        exit(1);
    }
    node *p, *q=head;
    while (q->next!=NULL){
        p=q;
        q=q->next;
    }
    p->next=NULL;
    free(q);
    p=NULL;
    q=NULL;
}

// WAP to lelete the beginning node of the linked list
void DeleteAtBegin(){
    if (head==NULL){
        printf("Deletion of node not possible. Linked list is empty.\n");
        exit(1);
    }
    printf("\n----- Deleting Node at BEGIN -----");
    if (head->next==NULL){
        free(head);
        head=NULL;
    }
    else {
        node *p=head;
        head = head->next;
        free(p);
        p=NULL;
    }
}

// WAP to delete a node at a given position
void DeleteAtPos(int pos){
    int length = listLength(head);
    if (pos<=0 || pos>length){
        printf("Invaid Position. ");
        exit(1);
    }
    printf("\n----- Deleting Node at pos [%d] -----", pos);
    if (pos==1) {
        printf("DeleteAtBegin(head) INVOKED\n");
        DeleteAtBegin(head);
    }
    else if (pos==length) {
        printf("DeleteAtEnd(head) INVOKED\n");
        DeleteAtEnd(head);
    }
    else{
        int k=1;
        node *p, *q=head;
        while (k<pos){
            p=q;
            q=q->next;
            k++;
        }
        p->next=q->next;
        free(q);
        p=NULL;
        q=NULL;
    }
}

// WAP to reverse a single linked list
void ReverseLinkedList(){
    if (head==NULL){
        printf("No linked list exists");
        exit(1);
    }
    node *p=NULL, *q=NULL, *r=head;
    while(r){
        q=r->next;
        r->next=p;
        p=r;
        r=q;
    }
    head=p;
}

// // WAP to find the merging  node of two linked lists
// node *FindMergingNode(node **head1, node **head2){
//     int l1=listLength(head1);
//     int l2=listLength(head2);
//     node *p; // stores head for larger link list
//     node *q; // stores head for smaller link list
//     int large, small;
//     if (l1>l2 ? p=head1,q=head2,large=l1, small=l2 : p=head2, q=head1, large=l2, small=l1){
//         int i=1;
//         while (large-i>=small){
//             p = p->next;
//             i++;
//         }
//     }
//     while (small>0){
//         if (p->next == q->next){
//             p=NULL;
//             return p->next;
//         }
//         else {
//             p = p->next;
//             q = q->next;
//         }
//         small--;
//     }
// }

// WAP to iterate a single linked list and print all its elements
void PrintLinkedList(){
    if (head==NULL){
        printf("The linked List is empty.");
        exit(1);
    }
    printf("\nPrinting the Linked List with Current size [%d] :\n", listLength());
    node *p=head;
    do {
        printf("Address [%p] : data = [%d], next = [%p]\n", p, p->data, p->next);
        p = p->next;
    }
    while (p!=NULL);
}

// driver code
void main()
{
    // Creating the linked list and printing
    int n;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    printf("Total no. of nodes in linked list : %d\n",listLength(head));
    printf("\n------ Creating the Linked List ------\n");
    for ( int i = 0; i < n; i++) createnode();
    PrintLinkedList();

    // Adding nodes and printing
    InsertAtEnd();
    PrintLinkedList();
    InsertAtBegin();
    PrintLinkedList();
    printf("\nEnter position to insert new node: ");
    int pos1; scanf ("%d", &pos1);
    InsertAtPos(pos1); // at position 2
    PrintLinkedList();

    // printing middle element of linked list
    printf("\n----- Finding Middle Element witout using ListLength() -----\n");
    node *mid = FindMiddle_withoutListLength();
    printf("Address [%p] : data = [%d], next = [%p]\n", mid, mid->data, mid->next);

    // Deleting nodes and printing
    DeleteAtEnd();
    PrintLinkedList();
    DeleteAtBegin();
    PrintLinkedList();
    printf("\nEnter position to delete node: ");
    int pos2; scanf ("%d", &pos2);
    DeleteAtPos(pos2);
    PrintLinkedList();

    // printing middle element of linked list
    printf("\n----- Finding Middle Element using ListLength() -----\n");
    mid = FindMiddle_usingListLength();
    printf("Address [%p] : data = [%d], next = [%p]\n", mid, mid->data, mid->next);


    // Using Find Cycle function
    FindCycle();
    node *p=head;
    while (p->next!=NULL){
        p = p->next;
    } // p now holds the last node address, now we create the cycle
    p->next = head;
    free(p);
    p=NULL;
    printf("\n----- After creating the cycle -----");
    FindCycle();
}