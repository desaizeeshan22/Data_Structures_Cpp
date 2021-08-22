#include<iostream>

#include "linked_list.cpp"

bool is_sorted(Node *p){

    while(p->next){
        if(p->data>(p->next)->data){
            return false;
        }
        p=p->next;
    }
    return true;
}



int main(){

    int A[]={3,5,7,19,15,20,40};

    create(A,7);
    if(is_sorted(first)){
        std::cout<<"The linked list is sorted"<<std::endl;
    }
    else{
        std::cout<<"The linked list is not sorted"<<std::endl;
    }
    // display(first);
    return 0;

}