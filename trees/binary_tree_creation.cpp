#include<iostream>


struct Node{
    Node *lchild;
    int data;
    Node *rchild;
};

class Stack{
    public:
        int size;
        int top;
        Node **Q;
        Stack(){
            top=-1;
            size=20;
            Q=new Node *[this->size];
            }
        Stack(int size){
            top=-1;
            this->size=size;
            Q=new Node *[this->size];
        }
        ~Stack(){
            for (int i{0};i<size;i++){
                delete Q[i];
            }
            delete [] Q;
        }
        int isfull(){
            return top==size-1;
        }
        int isempty(){
            return top==-1;
        }
        void push_stack(Node *t){
            if(this->isfull()){
                printf("Stack is full");
                return;
            }
            top++;
            Q[top]=t;
        }
         Node* pop_stack(){
            Node *t;
            if(this->isempty()){
                printf("Stack is full");
                t=NULL;
            }
            else{
            t=Q[top];
            top--;
             }
        return t;
         }
         Node* stacktop(){
            return Q[top];
}
};

class Queue{
    public:
        int front;
        int rear;
        int size;
        Node **Q;
        Queue(){front=rear=0;size=10;Q=new Node*[size];}
        Queue(int size){front=rear=0;this->size=size;Q=new Node*[size];}
        ~Queue(){delete []Q;}
        void enqueue(Node *x){
            if((rear+1)%size==front){
                printf("Queue is full\n");}
            else{
            rear=(rear+1)%size;this->Q[this->rear]=x;
                }
        }
        Node *dequeue(){
            Node * x=NULL;
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
    int isempty(){
        return front==rear;
    }
};
class Tree{
        public:
            Node *root;
            Tree(){root=NULL;}
            ~Tree(){delete root;}
            void tree_create(){
                     Node *p, *t;
                     int x{0};
                     Queue q(110); // create of queue of size 110
    
                     std::cout << "Enter the root value: ";
                     std::cin >> x;
    
                     root = new Node;
                     root->data = x;
                     root->lchild = root->rchild = NULL;
                     q.enqueue(root);
    
                    while (!q.isempty()) {
                          p = q.dequeue();
                          std::cout << "Enter left child of " << p->data << " (enter -1 if no left child): ";
                          std::cin >> x;
                          if (x != -1) {
                              t = new Node;
                              t->data = x;
                              t->lchild = t->rchild = NULL;
                              p->lchild = t;
                              q.enqueue(t);
                             }
                          std::cout << "Enter right child of " << p->data << " (enter -1 if no right child): ";
                          std::cin >> x;
                          if (x != -1) {
                          t = new Node;
                          t->data = x;
                          t->lchild = t->rchild = NULL;
                          p->rchild = t;
                          q.enqueue(t);
                         }
                      }
                   }
                   void preorder(Node *p){
                            if(p){
                            printf("%d ",p->data);
                            preorder(p->lchild);
                            preorder(p->rchild);
                              }
                      }
                   void iterative_preorder(Node *p){
                       Stack st;
                       st.push_stack(p);
                       while(!st.isempty()){
                            Node * q=st.pop_stack();
                            printf("%d ",q->data);
                            if(q->rchild){
                                st.push_stack(q->rchild);
                            }
                            if(q->lchild){
                                st.push_stack(q->lchild);
                            }
                       }
                   }
                   void iterative_inorder(Node *p){
                       Stack st;
                       Node *t=p;
                       while(!st.isempty()||t!=NULL){
                            if(t!=NULL){
                                st.push_stack(t);
                                t=t->lchild;
                            }
                            else{
                                Node *x=st.pop_stack();
                                printf("%d ",x->data);
                                t=t->rchild;
                            }
                       }
                   }
                //    void iterative_postorder(Node *t){
                //        Stack st;
                //        while(t||!st.isempty()){
                //            if(t){
                //                st.push_stack(t);
                //                t=t->lchild;
                //            }
                //            else{
                //                long int temp=st.pop_stack();
                //                if(temp>0){
                //                    st.push_stack(-temp);
                //                    t=(Node*)temp->rchild;
                //                }
                //                else{
                //                    printf("%d ",t->data);
                //                    t=NULL;
                //                }

                //            }
                //        }
                //    }

                   void inorder(Node *p){
                            if(p){
                             inorder(p->lchild);
                             printf("%d ",p->data);
                             inorder(p->rchild);
                             }
                        }
                   void postorder(Node *p){
                              if(p){
                                postorder(p->lchild);
                                postorder(p->rchild);
                                printf("%d ",p->data);
                                 }
                         }
                    void levelorder(Node *p){
                        Queue q(100);
                        printf("%d ",p->data);
                        q.enqueue(p);
                        while(!q.isempty()){
                            p=q.dequeue();
                              if(p->lchild){
                                printf("%d ",p->lchild->data);
                                q.enqueue(p->lchild);
                            }
                            if(p->rchild){
                                printf("%d ",p->rchild->data);
                                q.enqueue(p->rchild);
                            }
                            
                        }
                    }
                    int count_nodes(Node *p){
                        int x,y;
                        if(p){
                            x=count_nodes(p->lchild);
                            y=count_nodes(p->rchild);
                            return x+y+1;
                        }
                        return 0;
                    }

                    int height(Node*p){
                        int x=0,y=0;
                             if(!p){
                            return 0;
                        }
                            x=height(p->lchild);
                            y=height(p->rchild);
                            if(x>y){
                                return x+1;
                            }
                            else{
                                return y+1;
                            }
                       
                    }
                    // int iterative_height(Node *t){
                    //     if (t==NULL){
                    //         return 0;
                    //     }
                    //     Queue q;
                    //     q.enqueue(t);
                    //     int height=0;
                    //     while(!q.isempty()){
                    //         height++;
                    //         int CountNode=q.rear;
                    //         while(CountNode>0){
                    //             Node *p=q.dequeue();
                    //             if(p->lchild){
                    //                 q.enqueue(p->lchild);
                    //             }
                    //             if(p->rchild){
                    //                 q.enqueue(p->rchild);
                    //             }
                    //             CountNode--;
                    //         }
                    //     }
                    //     return height;
                    // }
                    int count_leaf_nodes(Node *p){
                        int x=0,y=0;
                        if(p){
                            x=count_leaf_nodes(p->lchild);
                            y=count_leaf_nodes(p->rchild);
                            if(p->lchild==NULL&&p->rchild==NULL){
                                return x+y+1;
                            }
                        }
                        return 0;
                    }
};
// int main(){
//     Tree t;
//     t.tree_create();
    // t.iterative_height(t.root);
    // t.preorder(t.root);
    // t.iterative_preorder(t.root);
    // t.inorder(t.root);
    // t.iterative_inorder(t.root);
    // printf("height is %d ",t.height(t.root)-1);
    // t.postorder(t.root);
    // t.levelorder(t.root);
//     return 0;
// }