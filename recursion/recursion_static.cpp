#include<iostream>

int func(int n){
    static int x{0};
    if(n>0){
        x++;
        return func(n-1)+x; 
    }
    else{
    return 0;
    }
    
}

int main(){
    int a{0};
    a=func(5);
    std::cout<<a<<std::endl;
    return 0;
}