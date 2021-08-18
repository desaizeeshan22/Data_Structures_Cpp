#include <iostream>

class Lower_triangle{
    friend std::ostream & operator <<(std::ostream &out,Lower_triangle &d);
    private:
        int *A;
        int n;
    public:
    Lower_triangle(){
        this->n=2;
        A=new int[(2*(2+1))/2];
    }
    Lower_triangle(int n){
            this->n=n;
            A=new int[(n*(n+1))/2];
        }
    void Set(int i,int j,int x){
            if(i>=j){
                A[(i*(i-1))/2+j-1]=x;
            }
    }
    int Get(int i,int j){
             if(i>=j){
                return A[(i*(i-1))/2+j-1];
            }
            return 0;
    }
    

    ~Lower_triangle(){
        delete [] A;
    }


};

std::ostream & operator <<(std::ostream &out,Lower_triangle &d){
        for(int i{1};i<=d.n;i++){
            for(int j{1};j<=d.n;j++){
                if(i>=j){
                out<<d.A[(i*(i-1))/2+j-1]<<" ";
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
    Lower_triangle d(4);
    for(int i{1};i<=4;i++){
            for(int j{1};j<=4;j++){
                    d.Set(i,j,1);
            }
    }
    std::cout<<d;


    return 0;
}