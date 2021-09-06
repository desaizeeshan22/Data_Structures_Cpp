#include <iostream>


class Node{
    public:
        int data;
        Node *next;
};
class Stack{
    private:
        Node *top;
    public:
        Stack(){top=NULL;}
        void push_stack(int x){
            Node *t=new Node;
            if(!t){
                printf("Stack full");
                }
            else{
                t->data=x;
                t->next=top;
                top=t;
                }
         }
         
        int pop(){
            if(!top){
                printf("Stack underflow");
                 return -1;
                }
            Node *p=top;
            int x=p->data;
            top=top->next;
            delete p;
            return x;
            }

        int Peek(int pos){
            Node *p=top;
            for(int i{0};i<pos-1;i++){
                    p=p->next;
                }
            if(!p){
                printf("Stack pos out of bounds");
                 return -1;
                }
            return p->data;    
            }

        void display(){
            Node *p=top;
            while(p){
              printf("%d ",p->data);
                p=p->next;
                }
            printf("\n");
        }

};

int main(){

    Stack s;
    s.push_stack(10);
    s.push_stack(20);
    s.push_stack(30);
    s.display();
    std::cout<<s.pop()<<std::endl;
    }