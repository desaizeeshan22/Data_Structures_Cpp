

#include<iostream> 

struct Node {
    int data;
    struct Node *next;
}*first = NULL; 

void create(int A[], int n) {
    struct Node *t, *last;
    first = new Node;
    first->data = A[0];
    first->next = NULL;
    last = first;
    
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
//     rec_display(first);
//     printf("\n");
//     return 0;

// }