#include <iostream>

double taylor_iterative(int x,int n){
    static double p=1,f=1;
    double res{1};
    for (int i{1};i<=n;i++){
        p=p*x;
        f=f*i;
        res+=p/f;
    }
    return res;
}

double taylor_recursive(int x,int n){
    if(n==0){
        return 1;
    }
    static double p=1,f=1;
    double res{1};
    res=taylor_recursive(x,n-1);
    p*=x;
    f*=n;
    return res+p/f;
}
int main(){
    double e=taylor_recursive(4,1);
    std::cout<<e<<std::endl;
}