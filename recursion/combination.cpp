#include<iostream>


int fact(int n){
    if (n==0){
        return 1;
    }
    int fac{1};
    for(int i{1};i<=n;i++){
        fac*=i;
    }
    return fac;
}
int nCr_fact(int n,int r){
    return fact(n)/(fact(r)*fact(n-r));
}
int nCr_rec(int n,int r ){
    if(n==r || r==0){
        return 1;
    }
    return nCr_rec(n-1,r-1)+nCr_rec(n-1,r);
}

int main(){
    std::cout<<nCr_fact(4,2)<<std::endl;
    std::cout<<nCr_rec(4,2)<<std::endl;
    return 0;
}