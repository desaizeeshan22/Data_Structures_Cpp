#include <iostream>

void hanoi(int n,int A,int B,int C){
    if (n>0){
        hanoi(n-1,A,C,B);
        std::cout<<"( "<<A<<","<<C<< " )"<<std::endl;
        hanoi(n-1,B,A,C);
    }
}

int main(){
    hanoi(4,1,2,3);
    printf("%d",2);
    return 0;
}

