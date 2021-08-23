#include <iostream>

#include "circular_ll.cpp"


void insert_circular_ll(Node *p,int index,int x){
    Node *t;
    if(index<0||index>length_ll(p)){
        return ;
    }
    if(index==0){
        if(!p){
            t=new Node;
            t->data=x;
            head=t;
            head->next=head;
        }
        else{
            while(p->next!=head){
                p=p->next;
            }
            p->next=t;
            t->next=head;
            head=t;
        }
    }
    else{
        for(int i{0};i<index-1;i++){
            p=p->next;
        }
        t=new Node;
        t->data=x;
        t->next=p->next;
        p->next=t;

    }
}


int main(){

    int A[]={2,3,4,5,6};
    create(A,5);
    insert_circular_ll(head,1,10);
    display_circular_ll(head);
    return 0;
}