#include<iostream>

#include "linked_list.cpp"


Node * find_middle(Node *p){
    Node *q=first;
    while(q){
        q=q->next;
        if(q){q=q->next;}
        if(q){p=p->next;}
    }
    return p;
}

int main() {
    int A[] = {3,5,7,10,15};
    create(A,5);
    // display(first);
    Node *mid=find_middle(first);
    printf("The data in the middle node : %d \n",mid->data);
    return 0;

}