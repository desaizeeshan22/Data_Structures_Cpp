

#include<iostream> 

struct Node {
    int data;
    struct Node *next;
}*first = NULL,*second=NULL,*third=NULL; 

void create(int A[], int n) {
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = last->next;
        last->next = t;
        last = t;
    }
}

void create_second(int A[], int n) {
    struct Node *t, *last;
    second = new Node;
    second->data = A[0];
    second->next = NULL;
    last = second;
    
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}
void create_third(int A[], int n) {
    struct Node *t, *last;
    third = new Node;
    third->data = A[0];
    third->next = NULL;
    last = third;
    
    for (int i = 1; i < n; i++) {
        t = new Node;
        t->data = A[i];
        t->next = NULL;
        last->next = t;
        last = t;
    }
}


void display(struct Node *p) {
    
    while (p) { 
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

void rec_display(struct Node *p) {
    if(p){
    printf("%d ",p->data);
    rec_display(p->next);
    }
}
// int main() {
//     int A[] = {3,5,7,10,15};
//     create(A,5);
//     display(first);
//     printf("\n");
//     return 0;

// }