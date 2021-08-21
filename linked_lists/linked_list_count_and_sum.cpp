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

int recursive_count(Node *p){
    int count{0};
    if(p){
        return 1+recursive_count(p->next);
    }
    return 0;
}
int sum_linked_list(Node *p){
    int sum=0;
    while(p){
        sum+=p->data;
        p=p->next;
    }
    return sum;
}
int R_sum(Node *p){
    static int sum=0;
    if(p){
        sum+=p->data;
        R_sum(p->next);
    }
    return sum;
    
}
int main(){
    int A[]={3,5,7,10,15};

    create(A,5);
    // printf("The number of nodes are : ");
    // std::cout<<recursive_count(first)<<std::endl;
    printf("The sum of the nodes is : ");
    std::cout<<R_sum(first)<<std::endl;
    return 0;
}