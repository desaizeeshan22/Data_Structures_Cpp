#include <iostream>

struct Node{
    int data;
    Node *next;
};

class Queue{
    private:
        Node *front;
        Node *rear;
    public:
        Queue(){front=rear=NULL;}
        ~Queue(){delete front;delete rear;}
        void enqueue(int x){
            Node *t=new Node;
            if(!t){
                printf("Queue is full\n");
            }
            else{
                t->data=x;
                t->next=NULL;
                if(!front){
                    front=rear=t;
                }
                else{
                     rear->next=t;
                     rear=t;
                }
            }
        }
        int dequeue(){
            int x=-1;
            if(!front){
                printf("Queue is empty \n");
            }
            else{
                x=front->data;
                Node *p=front;
                front=front->next;
                delete p;
            }
            return x;
        }
        void display(){
            Node *p=front;
            while(p){
                printf("%d ",p->data);
                p=p->next;
            }
            printf("\n");
        }
};

int main(){
    Queue q1;
    q1.enqueue(3);
    q1.enqueue(4);
    q1.enqueue(5);
    q1.enqueue(6);
    q1.display();
    q1.dequeue();
    q1.dequeue();
    q1.display();
    return 0;

}