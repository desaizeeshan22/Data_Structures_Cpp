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
        void enqueue_back(int x){
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
         void enqueue_front(int x){
            Node *t=new Node;
            if(!t){
                printf("Queue is full\n");
            }
            else{
                t->data=x;     
                if(!front){
                    front=rear=t;
                    t->next=NULL;
                }
                else{
                     t->next=front;
                     front=t;
                }
            }
        }
        int dequeue_front(){
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
        int dequeue_back(){
            int x=-1;
            if(!front){
                printf("Queue is empty \n");
            }
            else{
                x=rear->data;
                Node *p=front;
                if(front!=rear){
                while(p->next!=rear)
                    p=p->next;
                p->next=NULL;
                delete rear;
                rear=p;
                }
                else{
                    x=rear->data;
                    Node *p=rear;
                    rear=rear->next;
                    delete p;
                    }
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
    q1.enqueue_front(3);
    q1.enqueue_front(4);
    q1.enqueue_back(5);
    q1.enqueue_back(6);
    q1.display();
    q1.dequeue_back();
    // q1.dequeue();
    q1.display();
    return 0;

}