#include<iostream>

#include "linked_list.cpp"


void remove_duplicates(Node *p){
    Node *q=p->next;
    while(q){
        if(p->data!=q->data){
            p=q;
            q=q->next;
        }
        else{
            p->next=q->next;
            delete q;
            q=p->next;
        }
    }
}


int main(){

    int A[]={10,20,20,20,30,40};

    create(A,6);
    remove_duplicates(first);
    display(first);
    // std::string ac{"abcd"};
    // char ch;
    // int len=ac.length();
    // for(int i{0};i<len/2;i++){
    //     ch=ac[i];
    //     ac[i]=ac[len-1-i];
    //     ac[len-i-1]=ch;
    // }
    // std::cout<<ac;
    return 0;

}