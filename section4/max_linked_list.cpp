#include<iostream>

#include "linked_list.cpp"

int max_(Node * p){
    int max=INT16_MIN;
    while(p){
        if (p->data>max){
            max=p->data;
        }
        p=p->next;
    }
    return max;
}

int R_max(Node * p){
    int x=0;
    if(!p){
        return INT16_MIN;
    }
    x=R_max(p->next);
    return x>p->data?x:p->data;
}

int main(){
    int A[]={3,5,7,10,15,20,40};

    create(A,7);
    std::cout<<R_max(first)<<std::endl;
    return 0;

}