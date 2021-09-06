#include <iostream>
template <typename T>
struct Node{
   T data;
   Node *next;
};
Node<int>*top=NULL;
Node<char>*TOP=NULL;
void push_stack(int x){
    Node<int> *t=new Node<int>;
    if(!t){
        printf("Stack overflow");
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
    Node<int> *p=top;
    int x=p->data;
    top=top->next;
    delete p;
    return x;
}

int Peek(int pos){
    Node<int> *p=top;
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
    Node<int> *p=top;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}


void push_char_stack(char x){
    Node<char> *t=new Node<char>;
    if(!t){
        printf("Stack overflow");
    }
    else{
    t->data=x;
    t->next=TOP;
    TOP=t;
    }
}

char pop_char(){
    if(!TOP){
        printf("Stack underflow");
        return -1;
    }
    Node<char> *p=TOP;
    char x=p->data;
    top=top->next;
    delete p;
    return x;
}

char Peek_char(char pos){
    Node<char> *p=TOP;
    for(int i{0};i<pos-1;i++){
        p=p->next;
    }
    if(!p){
        printf("Stack pos out of bounds");
        return -1;
    }
    return p->data;    
}

void display_char(){
    Node<char> *p=TOP;
    while(p){
        printf("%d ",p->data);
        p=p->next;
    }
    printf("\n");
}

int parenthesis_matching(char *exp){
    for(int i{0};i!='\0';i++){
        if(exp[i]=='('||exp[i]=='['||exp[i]=='{'){
            push_char_stack(exp[i]);
        }
        else  if(exp[i]==')'||exp[i]==']'||exp[i]=='}'){
            char elem=pop_char();
            if(elem==-1){
                return 0;
            }
        }
    }
    return !TOP;
}
int main(){
    // push_stack(10);
    // push_stack(20);
    // push_stack(30);

    // display();
    // printf("%d",pop());
    // printf("%d",Peek(2));
    char *exp= (char*)"{([a+b]*[c-d])/e}";
    if(parenthesis_matching(exp)){
        printf("Balanced\n");
    }
    else{
        printf("Imbalanced\n");
    }

    return 0;
}