#include<iostream>

int fact(int n){
    int j{1};
    for(int i{1};i<=n;i++){
        j*=i;
    }
    return j;
}

int main(){
    int a=fact(6);
    std::cout<<a<<std::endl;
}