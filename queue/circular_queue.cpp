#include <iostream>


class Queue{
    private:
        int front;
        int rear;
        int size;
        int *Q;
    public:
        Queue(){front=rear=0;size=10;Q=new int[size];}
        Queue(int size){front=rear=0;this->size=size;Q=new int[size];}
        ~Queue(){delete []Q;}
        void enqueue(int x){
            if((rear+1)%size==front){
                printf("Queue is full\n");}
            else{
            rear=(rear+1)%size;this->Q[this->rear]=x;
                }
        }
        int dequeue(){
            int x=-1;
            if(front==rear){
                printf("The queue is empty");
            }
            else{
                front=(front+1)%size;
                x=Q[front];
                return x;
            }
            return x;
        }
        
    void display(){
        int i{front+1};
        do{
            printf("%d ",Q[i]);
            i=(i+1)%size;
        }while(i!=(rear+1)%size);
        printf("\n");
    }
    int isempty(){
        return front==rear;
    }
};

int main(){

    Queue q2(5);
    q2.enqueue(2);
    q2.enqueue(3);
    q2.enqueue(4);
    q2.enqueue(5);
    printf("%d \n",q2.dequeue());
    q2.display();

    return 0;

}