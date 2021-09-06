#include <iostream>

struct Stack{
    int size;
    int top;
    int *s;
};

void push_stack(int x,Stack &st){
    if(st.top==st.size-1){
        printf("Size already full \n");
        return ;
    }
    st.top++;
    st.s[st.top]=x;

}
int stacktop(Stack &st){
    return st.s[st.top];
}
int pop_stack(Stack &st){
    if(st.top==-1){
        printf("Stack is empty \n");
        return -1 ;
    }
    int top_elem=st.s[st.top];
    st.top--;
    return top_elem;  
}

bool stack_is_empty(Stack &s1){
    return s1.top==-1;
}

bool stack_is_full(Stack &s1){
    if(s1.top==s1.size-1){
        return true;
    }
    return false;
}

void create_stack(Stack &s){
    s.top=-1;
    printf("Enter the size of the stack : ");
    std::cin>>s.size;
    s.s=new int[s.size];
}

void display_stack(Stack &st){
    printf("[");
    int i{st.top};
    while(i>-1){
        printf(" %d ",st.s[i--]);
    }
     printf("] ");
}

int peek(Stack &st,int pos){
    if(st.top-pos+1<0){
        printf("Position out of bounds");
        return -1;
    }
    return st.s[st.top-pos+1];
}

int main(){
    Stack st;
    create_stack(st);
    push_stack(1,st);
    push_stack(2,st);
    display_stack(st);
    std::cout<<std::endl;
    std::cout<<stack_is_empty(st);
    delete [ ] st.s;
    return 0;
}