#include<iostream>


class Node {
    public:
        int data;
        struct Node *next;};
// }*first = NULL,*second=NULL,*third=NULL; 

class linked_list{
    private:
        Node * first;
    public:
        linked_list():first{NULL}{};
        linked_list(int A[],int n);
        ~linked_list();
        void display();
        void Insert(int index,int x );
        int Delete(int index);
        int length();
};

void linked_list::display(){    
    Node *p=this->first;
    while (p) { 
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}

linked_list::linked_list(int A[],int n){
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

linked_list::~linked_list(){
    Node *p=first;
        while(first){
            first=first->next;
            delete p;
            p=first;
        }
}

int linked_list::length(){
    Node *p=first;
    int count{0};
    while(p){
        count++;
        p=p->next;
    }
    return count;
}

void linked_list::Insert(int index,int x ){
    Node *p=first;
    if(index<0||index >length()){
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
    int A[] = {3,5,7,10,15};
    linked_list l(A,5);
    l.display();
    return 0;
}