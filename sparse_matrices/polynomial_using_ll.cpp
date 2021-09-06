#include<iostream>
#include <math.h>
struct term{
    int coeff;
    int exp;
    term * next;
};
class Polynomial{
    public:
        int n;
        term **terms;
    Polynomial(int n){
        this->n=n;
        terms=new term*[n];
        for(int i{0};i<n;i++){
            terms[i]=NULL;
        }
        
    }
    void create(){
            term *last=NULL;
            for(int i{0};i<this->n;i++){
                printf("Enter the element numbered %d",i+1);
                term * t=new term;
                std::cin>>t->coeff>>t->exp;
                t->next=NULL;
                if(!terms[i]){
                    terms[i]=last=t;
                }
                else{
                    last->next=t;
                    last=t;
                }
                }
    }
    ~Polynomial(){
        delete []terms;
    }
    void display(){
        for (int i{0};i<n;i++){
            term *p=terms[i];
            while(p){
            printf("%dx%d+",p->coeff,p->exp);
            p=p->next;
            }
        }
        printf("\n");
    }
    int eval(int x){
        int res{0};
        for (int i{0};i<n;i++){
            term*p=terms[i];
            while(p){
                res+=p->coeff*std::pow(x,p->exp);
                p=p->next;
            }
        }
        return res;
    }
};



int main(){
    Polynomial p(3);
    p.create();
    p.display();
    printf("result of polynomial : %d",p.eval(2));
    std::cout<<std::endl;
    return 0;
}