#include <iostream>

struct Node{
    Node * prev;
    int data;
    Node* next;
}*first=NULL;


void create(int A[],int n){
    Node *t,*last;
    int i;
    first =new Node;
    first->data=A[0];
    first->next=first->prev=NULL;
    last=first;
    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        t->prev=last;
        last->next=t;
        last=t;

    }

}



void display(struct Node *p) {
    
    while (p) { 
        printf("%d ", p->data);
        p = p->next;
    }
    printf("\n");
}
int length(Node *p){

    int len{0};
    while(p){
        len++;
        p=p->next;
    }
    return len;
}

void insert(Node *p,int index,int x){
    Node *t;
    int i;
    if(index<0||index>length(p)){
        return;
    }
    if(index==0){
        t=new Node;
        t->data=x;
        t->prev=NULL;
        t->next=first;
        first->prev=t;
        first=t;
    }
    else{
        t=new Node;
        for(i=0;i<index-1;i++){
            p=p->next;
        }
        t->data=x;
        t->prev=p;
        t->next=p->next;
        if(p->next){
            p->next->prev=t;
        }
        p->next=t;
    }
}

int Delete(Node *p,int index){
    Node *q;
    int x=-1;
    if(index<1 || index>length(p)){
        return -1;
    }
    if(index==1){
        first=first->next;
        if(first)first->prev=NULL;
        x=p->data;
        delete p;
    }
    else{
        for(int i{0};i<index;i++){
            p=p->next;
        }
        p->prev->next=p->next;
        if(p->next){
            p->next->prev=p->prev;
        x=p->data;
        delete p;
        }
   
    }
     return x;
}

void reverse_double_ll(Node *p){
    Node *q=p;
    while(q){
        Node *temp=q->next;
        q->next=q->prev;
        q->prev=temp;
        q=q->prev;
        if(q&&!q->next){
            first=q;
        }
    }
}
int main() {
    int A[] = {3,5,7,10,15};
    create(A,5);
    // insert(first,2,25);
    reverse_double_ll(first);
    display(first);
    printf("\n");

    // printf("the length of array %d",length(first));
    std::cout<<std::endl;
    return 0;

}