#include<iostream>

double horner_recursive(int x,int n){

    static double res{1};
    if(n==0){
        return res;
    }
    res=1+res*x/n;
    return horner_recursive(x,n-1);
}

double horner_iterative(int x,int n){

    static double res{1};
    for(;n>0;n--){
        res=1+res*x/n;
    }
    return res;
}

int main(){
    double e=horner_iterative(1,10);
    std::cout<<e<<std::endl;
}