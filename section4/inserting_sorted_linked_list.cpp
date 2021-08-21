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

void sorted_insert(Node *p,int x){
    Node *t=new Node;
    
    t->data=x;
    if(!first){
        first=t;
        t->next=NULL;
    }
    else{
        Node *q=new Node;
        while(p&&p->data<x){
            q=p;
            p=p->next;
        }
        if(p==first){
            t->next=first;
            first=t;
        }
        else{
        t->next=q->next;
        q->next=t;
        }
        
    }
}


int main(){

    int A[]={10,20,30,40,50};

    create(A,5);
    sorted_insert(first,35);
    display(first);

    return 0;

}