#include <iostream>

#include "circular_ll.cpp"

int Delete(Node *p,int index){
    Node *q;
    int x;
    if(index<0 || index>length_ll(head)){
            return -1;
    }
    if(index==1){
        while(p->next!=head){
            p=p->next;
        }
         x=head->data;
        if(head==p){
            delete head;
            head=NULL;
        }
        else{
        p->next=head->next;
        delete head;
        head=p->next;
        }
    }
    else{
        for(int i{0};i<index-2;i++){
            p=p->next;
        }
        q=p->next;
        p->next=q->next;
        x=q->data;
        delete q;
       
    }
     return x;
}

int main(){

    int A[]={2,3,4,5,6};
    create(A,5);
    Delete(head,2);
    R_display_circular(head);
    return 0;
}