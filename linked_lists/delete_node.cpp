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
int delete_node(struct Node *p, int index) {
    struct Node *q = NULL; 
    int x = -1;
    
    
    if (index < 1 || index > count_node(p))
        return -1;
    
   
    if (index == 1) {
        first = first->next;
        x = p->data;
        delete p; 
        return x;
    }
    else {
        for (int i = 0; i < index-1; i++) {
            q = p;
            p = p->next;
        }
        q->next = p->next;
        x = p->data;
        delete p;
        return x;
    }
}


int main(){

    int A[]={3,5,7,10,15,20,40};

    create(A,7);
    delete_node(first,3);
    display(first);
    return 0;

}