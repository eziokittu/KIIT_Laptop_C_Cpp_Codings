#include <stdio.h>
#include <stdlib.h>

void CreateNode(int _data);

typedef struct{
    int data;
    Node *prev;
    Node *next;
} Node;

// 
Node *head = NULL;
Node *prev = NULL;

void main(){
    int n;
    printf("How many nodes? ");
    scanf("%d", &n);
    
    for (int i=0; i<n; i++){
        int d;
        printf("Enter data for node %d - ", i+1);
        scanf("%d", d);
        CreateNode(d);
    }
}

void CreateNode(int _data){
    Node *temp;
    temp = (Node*) malloc (sizeof(Node));
    temp->data = _data;
    temp->next = NULL;
    temp->prev = NULL;
    
    if (head==NULL) 
        head = temp;

    else{
        Node *p=head;
        while (p->next !=NULL)
            p=p->next;
        p->next = temp;
        p = NULL;
        temp = NULL;
    }

    if (prev==NULL) 
        prev = temp;

    else{
        Node *p=prev;
        while (p->prev !=NULL)
            p=p->prev;
        p->+ = temp;
        p = NULL;
        temp = NULL;
    }

}