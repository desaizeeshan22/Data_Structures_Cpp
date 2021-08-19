#include<iostream>

#include "linked_list.cpp"

Node *LSearch(Node *p,int key){
    Node *q;
    while(p){
        if(key==p->data){
            q->next=p->next;
            p->next=first;
            first=p;
            return p;
        }
        q=p;
        p=p->next;
    }
    return NULL;
}
Node *R_LSearch(Node *p,int key){
    if(!p){
        return NULL;
    }
    if(key==p->data){
        return p;
    }
    return R_LSearch(p->next,key);
}

int main(){

    int A[]={3,5,7,10,15,20,40};

    create(A,7);
    Node * temp=R_LSearch(first,10);
    if(temp){
        printf("The node is found and the data is : %d",temp->data);
        std::cout<<std::endl;
    }
    else{
        printf("The node is not found");
        std::cout<<std::endl;
    }
    display(first);
    return 0;
}