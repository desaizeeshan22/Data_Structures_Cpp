#include<iostream>

void func1(int n){
    if (n>0){
        func1(n-1);
        std::cout<<n<<std::endl;
    }
}

int main(){
    int x{5};
    func1(x);
    return 0;
}