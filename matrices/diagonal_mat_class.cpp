#include <iostream>

class Diagonal{
    friend std::ostream & operator <<(std::ostream &out,Diagonal &d);
    private:
        int *A;
        int n;
    public:
    Diagonal(){
        this->n=2;
        A=new int[2];
    }
    Diagonal(int n){
            this->n=n;
            A=new int[n];
        }
    void Set(int i,int j,int x){
            if(i==j){
                A[i-1]=x;
            }
    }
    int Get(int i,int j){
            if(i==j){
                return A[i-1];
            }
            return 0;
    }
    

    ~Diagonal(){
        delete [] A;
    }


};

std::ostream & operator <<(std::ostream &out,Diagonal &d){
        for(int i{0};i<d.n;i++){
            for(int j{0};j<d.n;j++){
                if(i==j){
                out<<d.A[i]<<" ";
                }
            else{
                out<<"0 ";
                }   
        }
        out<<std::endl;
        }
        return out;
    }

int main(){
    Diagonal d(4);
    d.Set(1,1,5);
    d.Set(2,2,8);
    d.Set(3,3,9);
    d.Set(4,4,12);
    std::cout<<d;

    return 0;
}