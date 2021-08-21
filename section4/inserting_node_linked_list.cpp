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

void insert(Node *p,int index,int x){

    if(index<0||index >count_node(p)){
        return ;
    }
    Node *t=new Node;
    t->data=x;
    if(index==0){
        t->next=first;
        first=t;
    }
    else{
        for (int i{0};i<index-1;i++){
            p=p->next;
        }
        t->next=p->next;
        p->next=t;
    }

}





int main(){

    int A[]={3,5,7};

    create(A,3);
    insert(first,0,10);
    display(first);

    return 0;

}
    