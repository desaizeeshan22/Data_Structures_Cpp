#include<iostream>

#include "linked_list.cpp"

int count_node(Node *p){
    int count{0};
    while(p){
        count++;
        p=p->next;
    }
    return count;
}
void reverse_data_ll(Node *p){
    int *A=new int[count_node(p)];
    int i{0};
    Node *q=p;
    while(q){
        A[i++]=q->data;
        q=q->next;
    }
    i--;q=p;
    while(q){
        q->data=A[i--];
        q=q->next;
    }
}

void reverse_links_ll(Node *p){
    Node *q=NULL,*r=NULL;
    while(p!=NULL){
        r=q;
        q=p;
        p=p->next;
        q->next=r;
    }
    first=q;
}




int main(){

    int A[]={3,5,7,19,15,20,40};

    create(A,7);
    // reverse_data_ll(first);
    reverse_links_ll(first);
    display(first);

    return 0;

}