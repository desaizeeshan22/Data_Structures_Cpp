#include <iostream>

class Queue{
    private:
        int front;
        int rear;
        int size;
        int *Q;
    public:
        Queue(){front=rear=-1;size=10;Q=new int[size];}
        Queue(int size){front=rear=-1;this->size=size;Q=new int[size];}
        ~Queue(){delete []Q;}
        void enqueue(int x){
            if(this->rear==this->size-1){
                printf("Queue is full\n");}
            else{
            this->rear++;this->Q[this->rear]=x;
                }
        }
        int dequeue(){
            int x=-1;
            if(front==rear){
                printf("The queue is empty");
            }
            else{
                front++;
                x=Q[front];
                return x;
            }
            return x;
        }
        
    void display(){
        for(int i{front+1};i<=rear;i++){
             printf("%d ",Q[i]);
            }
        printf("\n");
    }
};

int main(){

    Queue q2(5);
    q2.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(4);
    q2.enqueue(5);
    q2.dequeue();
    q2.display();

    return 0;

}