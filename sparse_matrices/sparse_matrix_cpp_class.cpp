#include<iostream>

class Element{
    public:
        int i;
        int j;
        int x;
};

class Sparse_matrix{
    friend std::istream& operator>>(std::istream &is,Sparse_matrix &s);
    friend std::ostream& operator<<(std::ostream &os,Sparse_matrix &s);
    private:
        int m;
        int n;
        int num;
        Element *ele;
    public:
        Sparse_matrix(int m,int n,int num){
            this->m=m;this->n=n;this->num=num;
            ele=new Element[this->num];
        }
        ~Sparse_matrix(){
            delete [] this->ele;
        }
        Sparse_matrix operator+(Sparse_matrix s2){
            int i,j,k;
            i=j=k=0;
            Sparse_matrix s3(m,n,this->num+s2.num);
            while(i<this->num&&j<s2.num){
                if(ele[i].i<s2.ele[j].i){
                    s3.ele[k++]=ele[i++];
                }
                if(ele[i].i>s2.ele[j].i){
                    s3.ele[k++]=s2.ele[j++];
                 }
                else{
                    if(ele[i].j<s2.ele[j].j){
                        s3.ele[k++]=ele[i++];
                    }
                    if(ele[i].j>s2.ele[j].j){
                    s3.ele[k++]=s2.ele[j++];
                    }
                    else{
                        s3.ele[k]=ele[i];
                        s3.ele[k++].x=ele[i++].x+s2.ele[j++].x;
                    }
                }
            } 
            for(;i<this->num;i++){s3.ele[k++]=this->ele[i++];}
            for(;j<s2.num;j++){s3.ele[k++]=s2.ele[j++];}
            s3.num=k;
             return s3;
        }      
        void read(){
            std::cout<<"Enter non zero elements:";
            for(int i{0};i<this->num;i++){
                scanf("%d%d%d",this->ele[i].i,this->ele[i].j,this->ele[i].x);
            }
        }

        void display(){
                    int i,j,k=0;
                    for(int i{0};i<m;i++){
                    for(int j{0};j<n;j++){
                        if(i==ele[k].i&&j==ele[k].j){
                        printf("%d ",ele[k++].x);
                        }
                         else{
                            printf("0 ");
                            }
                        }
                    printf("\n");
                    }
            }               
};

std::istream& operator>>(std::istream &is,Sparse_matrix &s){
            printf("Enter the non-zero elements:");
            for(int i{0};i<s.num;i++){
                std::cin>>s.ele[i].i>>s.ele[i].j>>s.ele[i].x;
            }
            return is;
        }
std::ostream& operator<<(std::ostream &os,Sparse_matrix &s){
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
        return os;
}   

int main() {
    Sparse_matrix s1(5,5,5);
    // s1.read();
    // s1.display();
    std::cin>>s1;
    std::cout<<"The first matrix is\n";
    std::cout<<s1;
    Sparse_matrix s2(5,5,5);
    std::cin>>s2;
    printf("Second matrix\n");
    std::cout<<s2;

    Sparse_matrix s3=s1+s2;
    printf("Sum matrix\n");
    std::cout<<s3;
    return 0;
}