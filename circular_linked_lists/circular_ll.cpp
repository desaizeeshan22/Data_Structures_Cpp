#include <iostream>


struct Node{
    int data;
    Node *next;
}*head;


void create(int A[],int n){
    int i;
    Node *t,*last;
    head=new Node;
    head->data=A[0];
    head->next=head;
    last=head;
    for(i=1;i<n;i++){
        t=new Node;
        t->data=A[i];
        t->next=last->next;
        last->next=t;
        last=t;
    }

}

void display_circular_ll(Node *h){
    Node *p=h;
    do{
        printf("%d ",p->data);
        p=p->next;
    }while(p!=h);
    printf("\n");
}
void R_display_circular(Node *p){
    static int flag=0;
    if(p!=head || flag==0){
        flag=1;
        printf("%d ",p->data);
        R_display_circular(p->next);
    }
    flag=0;
}

int length_ll(Node *p){
    int i{0};
    do{
        i++;
        p=p->next;
        
    }while(p!=head);
    return i;
}
// int main(){

//     int A[]={2,3,4,5,6};
//     create(A,5);
//     R_display_circular(head);
//     return 0;
// }