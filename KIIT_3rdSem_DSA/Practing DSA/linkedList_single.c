// ----------------------------- SINGLE LINKED LIST -------------------------


#include <stdio.h>
#include <stdlib.h>

// declarations
void createnode();
int listLength();
void InsertAtBegin();
void InsertAtEnd();
void InsertAtPos();
void DeleteAtBegin();
void DeleteAtEnd();

// node structure definition
struct node
{
    /* data */
    int data;
    struct node *next;
};

typedef struct node node;
node *head=NULL;

// function to get the length of the linked list
int listLength(node *head){
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
        exit(1);
    }
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
    printf("Enter data element : ");
    scanf("%d", temp->data);
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
void InsertAtPos(node *head, int pos){
    int length = listLength(head);
    if (pos<=0 || pos>length+1){
        printf("Invaid Position. ");
        exit(1);
    }
    else if (pos==1) {
        printf("InsertAtBegin(head) INVOKED\n");
        InsertAtBegin(head);
    }
    else if (pos == length+1){
        printf("InsertAtEnd(head) INVOKED\n");
        InsertAtEnd(head);
    }
    else{
        node *p = head, *temp;
        int k=1;
        temp = (node*) malloc (sizeof(node));
        if (temp==NULL){
            exit(1);
        }
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
        /* code */
        printf("Memory Full : ");
        exit(1);
    }

    printf("Enter data element : ");
    scanf("%d",&temp->data);
    temp-> next=NULL;

    // if there is no linked list, then head will have address of the first node
    if (head==NULL)
    {
        /* code */
        head = temp;}

    else
    {
        node *p=head;
        while (p->next !=NULL)
        {
        /* code */
        p=p->next;
        }
        
        p->next = temp;
        p = NULL;
        temp = NULL;
    }
            
}

// WAP to find middle of the linked list without using listLength()
node* findMiddle_withoutListLength(node* head){
    node *slow=head, *fast=head;
    while (fast!=NULL && fast->next!=NULL && (fast->next)->next!=NULL){
        slow = slow->next;\
        fast = fast->next->next;
    }
    return slow;
}

// find the middle element of a single linked list
node* findMiddle_usingListLength(node* head){
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
int findCycle(node *head){
    node *slow=head, *fast=head;
    while (fast!=NULL && fast->next!=NULL && fast->next->next!=NULL){
        slow = slow->next;
        fast = fast->next->next;
        if (slow==fast){
            printf("Cycle exits");
            exit(1);
        }
    }
    printf("No Cycle exists.");
}

// WAP to delete the last node of a linked list
void DeleteAtEnd(node *head){
    // case when no linkedlist exist
    if (head==NULL){
        printf("No Linked list exist so no node to delete");
        exit(1);
    }
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
void DeleteAtBegin(node *head){
    if (head==NULL){
        printf("Deletion of node not possible. Linked list is empty.\n");
        exit(1);
    }
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
void DeleteAtPos(node *head, int pos){
    int length = listLength(head);
    if (pos<=0 || pos>length){
        printf("Invaid Position. ");
        exit(1);
    }
    else if (pos==1) {
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
void ReverseLinkedList(node *head){
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
    return head;
}

// WAP to find the merging  node of two linked lists
node *FindMergingNode(node *head1, node *head2){
    int l1=listLength(head1);
    int l2=listLength(head2);
    node *p; // stores head for larger link list
    node *q; // stores head for smaller link list
    int large, small;
    if (l1>l2 ? p=head1,q=head2,large=l1, small=l2 : p=head2, q=head1, large=l2, small=l1){
        int i=1;
        while (large-i>=small){
            p = p->next;
            i++;
        }
    }
    while (small>0){
        if (p->next == q->next){
            p=NULL;
            return p->next;
        }
        else {
            p = p->next;
            q = q->next;
        }
        small--;
    }
}

// WAP to iterate a single linked list and print all its elements
void PrintLinkedList(node* head){

}

// driver code
void main()
{
    int i,n;
    printf("Enter number of nodes : ");
    scanf("%d",&n);
    printf("Total no. of nodes in linked list : %d\n",listLength(head));
    for ( i = 0; i < n; i++) createnode();
    printf("Total no. of nodes in linked list : %d\n",listLength(head));
    InsertAtPos(head,2);
    printf("Total no. of nodes in linked list : %d\n",listLength(head));
    InsertAtPos(head,3);
    printf("Total no. of nodes in linked list : %d\n",listLength(head));

    node* middle = findMiddle_withoutListLength(head);
    printf("data in middle node : %d", middle->data);
}