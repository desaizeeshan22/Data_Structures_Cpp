#include <iostream>

struct Queue{
    int front;
    int rear;
    int size;
    int *Q;
};

void create(Queue *q,int size){
    q->front=q->rear=-1;
    q->size=size;
    q->Q=new int[size];
}

void enqueue(Queue *q,int x){
    if(q->rear==q->size-1){
        printf("Queue is full \n");
    }
    else{
    q->rear++;
    q->Q[q->rear]=x;
    }
}
int dequeue(Queue *q){
    int x{-1};
    if(q->front==q->rear){
        printf("queue empty\n");
        return x;
    }
    q->front++;
    x=q->Q[q->front];
    return x;
}

void display(Queue *q){
    for(int i{q->front+1};i<=q->rear;i++){
        printf("%d ",q->Q[i]);
    }
    printf("\n");
}

int main(){

    Queue q1;
    create(&q1,5);
    enqueue(&q1,2);
    enqueue(&q1,3);
    display(&q1);
    dequeue(&q1);
    display(&q1);
    return 0;
}