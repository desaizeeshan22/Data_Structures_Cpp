#include <iostream>

bool is_palindrome(char c[]){
    int i{0};
    for (;c[i]!='\0';i++){
    }
    if(i>=2){
        int j=i-1;
        for(int i{0};i<j;i++,j--){
            if (c[i]!=c[j]){
                return 0;
                }
        }
    return 1;
    }
    else{
        printf("string should at least be 2 characters long \n");
        return 0;
    }
}
void display(const int *arr){
        printf("The elements of the array are: \n");
        printf("[ ");
        for(int i{0};i<=sizeof(arr)+1;i++){
            printf("%d ",arr[i]);
        }
        printf("] \n");
        
}



int main(){
    int n;
    std::cout<<"Enter string size: \n ";
    std::cin>>n;
    char A[n];
    std::cout<<"Enter string to check: \n";
    std::cin>>A;
    if(is_palindrome(A)){
        printf("string is a palindrome \n");
    }
    else{
        printf("string is not a palindrome\n");
    }

    
    // int *B=new int[6];
    // B[0]=1;
    // B[1]=2;
    // B[2]=3;
    // B[3]=4;
    // B[4]=5;
    // B[5]=6;
    // display(B);
    // delete []B;
    // char a{97+22};
    // std::cout<<a<<std::endl;
    return 0;

}