#include<iostream>

int fib_iterative(int n){
    if(n<=2){
        return n-1;
    }
    int elem_1=0,elem_2=1,s=0;
    for (int i{3};i<=n;i++){
        s=elem_1+elem_2;
        elem_1=elem_2;
        elem_2=s;
    }
    return s;
}
int r_fib(int n){
    if(n<=2){
        return n-1;
    }
    return r_fib(n-2)+r_fib(n-1);
}

int main(){
    std::cout<<fib_iterative(6)<<std::endl;
    std::cout<<r_fib(6)<<std::endl;

}