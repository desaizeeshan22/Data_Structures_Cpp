#include<iostream>


struct Term{
    int coeff;
    int exp;
};

struct Poly{
    int n;
    Term *terms;
};

void create(Poly *p){
    
    printf("Number of terms:");
    std::cin>>p->n;
    p->terms=new Term[p->n];
    for(int i{0};i<p->n;i++){
        scanf("Enter the element numbered %d",i+1);
        std::cin>>p->terms[i].coeff>>p->terms[i].exp;
    }
}

void display(Poly p){
    for (int i{0};i<p.n;i++){
        printf("%dx%d+",p.terms[i].coeff,p.terms[i].exp);
    
    }
    printf("\n");
}

Poly * add(Poly *p1,Poly *p2){
    Poly *p3=new Poly;
    p3->terms=new Term[p1->n+p2->n];
    int i=0,j=0,k=0;
    while(i<p1->n&&j<p2->n){
        if(p1->terms[i].exp>p2->terms[j].exp){
            p3->terms[k++]=p1->terms[i++];
        }
        else if(p1->terms[i].exp<p2->terms[j].exp){
            p3->terms[k++]=p2->terms[j++];
        }
        else{
            p3->terms[k].exp=p1->terms[i].exp;
            p3->terms[k++].coeff=p1->terms[i++].coeff+p2->terms[j++].coeff;
        }
    }
    for(;i<p1->n;i++){
         p3->terms[k++]=p1->terms[i++];
    }
      for(;j<p2->n;j++){
         p3->terms[k++]=p2->terms[j++];
    }
    p3->n=k;
    return p3;
}
int main(){
    Poly p1;
    Poly p2;
    create(&p1);
    display(p1);
    std::cout<<std::endl;
    create(&p2);
    display(p2);
    std::cout<<std::endl;
    Poly *p3=add(&p1,&p2);
    display(*p3);

}