
#include<iostream>

#include "linked_list.cpp"


void concatenate_ll(Node *p,Node *q){
    // third=p;
    while(p->next){
        p=p->next;
    }
    p->next=q;

}

void merge_ll(Node *p,Node *q){
    Node *last;
    if(p->data<q->data){
        third=last=p;
        p=p->next;
        third->next=NULL;
    }
    else{
        third=last=q;
        q=q->next;
        third->next=NULL;
    }
    while(p&&q){
        if(p->data<q->data){
            last->next=p;
            last=p;
            p=p->next;
            last->next=NULL;
        }
        else{
            last->next=q;
            last=q;
            q=q->next;
            last->next=NULL;
        }
    }
    if(p){
        last->next=p;
    }
    else{
         last->next=q;
    }
    }
int main(){

    int A[]={3,5,7,19,15,20,40};
    int B[]={1,2,3,4,5};
    create(A,7);
    create_second(B,5);
    
    // concatenate_ll(first,second);
    // display(first);
    // display(second);
    merge_ll(first,second);
    display(third);

    return 0;

}