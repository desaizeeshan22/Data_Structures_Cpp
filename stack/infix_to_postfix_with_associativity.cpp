#include <iostream>
#include <string.h>
#include<math.h>

struct Stack{
    int size;
    int top;
    char *s;
};


void push_stack(char x,Stack &st){
    if(st.top==st.size-1){
        printf("Size already full \n");
        return ;
    }
    st.top++;
    st.s[st.top]=x;

}

char stacktop(Stack &st){
    return st.s[st.top];
}
char pop_stack(Stack &st){
    if(st.top==-1){
        printf("Stack is empty \n");
        return -1 ;
    }
    char top_elem=st.s[st.top];
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
    s.s=new char[s.size];
}

void display_stack(Stack &st){
    printf("[");
    int i{st.top};
    while(i>-1){
        printf(" %d ",st.s[i--]);
    }
     printf("] ");
}

char peek(Stack &st,char pos){
    if(st.top-pos+1<0){
        printf("Position out of bounds");
        return -1;
    }
    return st.s[st.top-pos+1];
}
int out_pre(char x){
    if(x=='+'||x=='-'){
        return 1;
    }
    else if(x=='*'||x=='/'){
        return 3;
    }
    else if(x=='^'){
        return 6;
    }
    else if(x=='('){
        return 7;
    }
    else if(x==')'){
        return 0;
    }
    return 0;
}
int in_pre(char x){
    if(x=='+'||x=='-'){
        return 2;
    }
    else if(x=='*'||x=='/'){
        return 4;
    }
    else if(x=='^'){
        return 5;
    }
    else if(x=='('){
        return 0;
    }
    else if(x==')'){
        return 0;
    }
    return 0;
}


int is_operand(char x){
    if(x=='+'||x=='-'||x=='*'||x=='/'||x=='^'||x=='('||x==')'){
        return 0;
    }
    else{
        return 1;
    }
}
char * infix_to_postfix(char *s){
    Stack st;
    st.top=-1;
    st.size=strlen(s);
    st.s=new char[st.size];
    char *postfix=new char[strlen(s)+1];
    int i{0},j{0};
    while(s[i]!='\0'){
        if (is_operand(s[i])){
            postfix[j++]=s[i++];
        }
        else{
            if(out_pre(s[i])>in_pre(st.s[st.top])){
                push_stack(s[i++],st);
            }
            else if(out_pre(s[i])<in_pre(st.s[st.top])){
                postfix[j++]=pop_stack(st);
            }
            else {
                pop_stack(st);
                i++;
            }
        }
        }
        while(st.top!=-1){
            if(st.s[st.top] != '('){
				postfix[j++] =  pop_stack(st);
            }
		    else{ 
			 pop_stack(st);
            }
	}
	postfix[j] = '\0';
    
    return postfix;
    }
int eval_postfix(char * postfix){
    Stack st;
    st.top=-1;
    st.size=strlen(postfix);
    st.s=new char[st.size+1];

    int i{0};
    int r;
    while(postfix[i]!='\0'){
        if (is_operand(postfix[i])){
            push_stack((postfix[i]-'0'),st);
        }
        else{
            int second_elem{pop_stack(st)};
            int first_elem{pop_stack(st)};
            switch(postfix[i]){
                case '+': r=first_elem+second_elem;break;
                case '-':r=first_elem-second_elem;break;
                case '*':r=first_elem*second_elem;break;
                case '/':r=first_elem/second_elem;break;
                case '^':r=pow(first_elem,second_elem);break;
            }
            push_stack(r,st);
        }
        i++;
    }
    return st.s[st.top];
}
int main(){
    // char * infix="((a+b)*c)-d^e^f";
    // char * postfix;
    // postfix=infix_to_postfix(infix);
    // char i{0};
    // while(postfix[i]!='\0'){
    //     printf("%c",postfix[i++]);
    // }
    char * postfix="234*+82/-";
    std::cout<<eval_postfix(postfix)<<std::endl;
    return 0;
}