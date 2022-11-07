// Finding the merging node of 2 linked lists
    node *head2=NULL;
    printf("For 2nd linked list- Enter number of nodes : ");
    scanf("%d",&n);
    printf("\n------ Creating the 2nd Linked List ------\n");
    for ( int i = 0; i < n; i++) createnode(&head2);
    node *p=head2;
    while (p->next!=NULL){
        p = p->next;
    } // p now holds the last node address
    p->next = head->next->next;
    // last node of 2nd Linked list merges with 2nd node of 1st linked list.
    free(p);
    p=NULL;



// WAP to find the merging node of two linked lists
node *FindMergingNode(node **head1, node **head2){
    int l1 = ListLength(head1);
    int l2 = ListLength(head2);
    node *p, *q;
    if ((l1>l2) ? (p=*head1, q=*head2) : (p=*head2, q=*head1));
    // p conatins head of bigger linked list, and q smaller
    node *temp = NULL;
    do {
        do {
            if (p==q){ // checking address in linear searching
                temp = p;
                free(p);
                free(q);
                p=NULL;
                q= NULL;
                break;
            }
        }
        while (p->next!=NULL);
    }
    while (q->next !=NULL);
    
    return temp;
}