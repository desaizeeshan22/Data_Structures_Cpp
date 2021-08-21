#include<iostream>

void func1(int n){
    if (n>0){
        std::cout<<n<<" ";
        func1(n-1);
        func1(n-1);
    }
    
}

int main(){
    func1(3);
    std::cout<<""<<std::endl;
    return 0;
}