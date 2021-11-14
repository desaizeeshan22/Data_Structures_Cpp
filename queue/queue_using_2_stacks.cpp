#include<iostream>

struct Node{
    int data;
    Node *next;
};

class Stack{        
    public:
        Node *top;
        Stack(){top=NULL;}
        ~Stack(){delete top;}
        void push(int x){
            Node *t;
            t->data=x;
            if(!t){
                printf("stack full\n");
                return;
            }
            t->next=top;
            top=t;
        } 
        int pop(){
            int x=-1;
            if(!top){
                printf("stack is empty\n");
                return x;
            }
            Node *p=top;
            x=p->data;
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
        int isEmpty(){
            if(!top){
                return false;
            }
            return true;
        }
};

class Queue{
    public:
        Stack *s1;
        Stack *s2;
        Queue(){s1=new Stack;s2=new Stack;}
        ~Queue(){delete s1;delete s2;}
        void enqueue(int x){
            s1->push(x);
        }
        int dequeue(){
            int x{-1};
            if(s2->isEmpty()){
                if(s1->isEmpty()){
                    printf("Queue is empty");
                    return x;
                }
                while(!s1->isEmpty()){
                    s2->push(s1->pop());
                }
            }
            return s2->pop();
        }
};