#include <iostream>

struct Element{
    int i;
    int j;
    int x;
};

struct Sparse_matrix{
    int m;
    int n;
    int num;
    Element *ele;
};

void create(Sparse_matrix *s){
    printf("Enter the dimensions of the array :  ");
    scanf("%d%d",&s->m,&s->n);
    printf("Enter the number of non zero elements : ");
    scanf("%d",&s->num);

    s->ele=new Element[s->num];
    printf("Enter the non-zero elements:");
    for(int i{0};i<s->num;i++){
        scanf("%d%d%d",&s->ele[i].i,&s->ele[i].j,&s->ele[i].x);
    }
}

void Display(const Sparse_matrix s){
    int i,j,k=0;
    for(int i{0};i<s.m;i++){
        for(int j{0};j<s.n;j++){
            if(i==s.ele[k].i&&j==s.ele[k].j){
                printf("%d ",s.ele[k++].x);
            }
            else{
                printf("0 ");
            }
        }
        printf("\n");
    }
}

Sparse_matrix * add(Sparse_matrix *s1,Sparse_matrix *s2){
      Sparse_matrix *sum;
      int i,j,k;
      i=j=k=0;
      sum=new Sparse_matrix;
     
      sum->ele=new Element[s1->num+s2->num];
      while(i<s1->num && j<s2->num){
          if(s1->ele[i].i<s2->ele[j].i){
              sum->ele[k++]=s1->ele[i++];
          }
          else if(s1->ele[i].i>s2->ele[j].i){
              sum->ele[k++]=s2->ele[j++];
          }
          else{
              if(s1->ele[i].j<s2->ele[j].j){
                  sum->ele[k++]=s1->ele[i++];
              }
              else if(s1->ele[i].j>s2->ele[j].j){
                  sum->ele[k++]=s2->ele[j++];
              }
              else{
                  sum->ele[k]=s1->ele[i];
                  sum->ele[k++].x=s1->ele[i++].x+s2->ele[j++].x;
              }
          }
      }
      for(;i<s1->num;i++){sum->ele[k++]=s1->ele[i++];}
      for(;j<s2->num;j++){sum->ele[k++]=s2->ele[j++];}
      sum->m=s1->m;
      sum->n=s1->n;
      return sum;

    }
int main(){

Sparse_matrix s1,s2,*s3;
create(&s1);
printf("First matrix \n: ");
Display(s1);
create(&s2);
printf("Second matrix \n: ");
Display(s2);

printf("Sum matrix \n: ");
s3=add(&s1,&s2);
Display(*s3);
return 0;
}