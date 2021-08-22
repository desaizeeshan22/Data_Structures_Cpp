
#include<iostream>

#include "linked_list.cpp"


bool is_Loop(Node *f){
     Node *p,*q;
     p=q=f;
     do{
         p=p->next;
         q=q->next;
         q=q?q->next:q;
     }while(p&&q&&p!=q);
     if(p==q){
         return true;
     }
     else{
         return false;
     }
}






int main(){

    int A[]={10,20,30,40,50};
    Node *t1,*t2;
    create(A,5);
    // t1=first->next->next;
    // t2=first->next->next->next->next;
    // t2->next=t1;
    if(is_Loop(first)){
        printf("linked list has a loop \n");
        
    }
    else{
        printf("linked list does not have a loop \n");
    }

    return 0;


}