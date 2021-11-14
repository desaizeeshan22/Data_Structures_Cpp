#include <iostream>
#include "C:\Users\desai\Clang_ds_algo\trees\binary_tree_creation.cpp"

  int Height(Node*p){
                        int x=0,y=0;
                             if(!p){
                            return 0;
                        }
                            x=Height(p->lchild);
                            y=Height(p->rchild);
                            if(x>y){
                                return x+1;
                            }
                            else{
                                return y+1;
                            }
                       
                    }
Node *Inpre(Node * p){
    while(p &&p->rchild){
        p=p->rchild;
    }
    return p;
}  
Node *InSucc(Node * p){
    while(p &&p->lchild){
        p=p->lchild;
    }
    return p;
}             

class Binary_Tree:public Tree{
    public :
        void insert(Node *t,int value){
            if(t==NULL){
                t=new Node;
                t->data=value;
                t->lchild=t->rchild=NULL;
                printf("Root node inserted call func again to form the entire BST \n");
                root=t;
                return ;
            }
            else{
                Node *r=NULL;
                while(t!=NULL){
                    r=t;
                    if(value<t->data){
                        t=t->lchild;
                    }
                    else if(value>t->data){
                        t=t->rchild;
                    }
                    else{
                        printf("Value cannot be inserted as it is already present");
                        return;
                    }
            }
            Node *temp=new Node;
            temp->lchild=temp->rchild=NULL;
            temp->data=value;
             if(value<r->data){
                        r->lchild=temp;
                    }
             else if(value>r->data){
                        r->rchild=temp;
                    }
            }
        }
        Node * Recursive_insert(Node *p,int value){
            Node *t=NULL;
            if(p==NULL){
                t=new Node;
                t->data=value;
                t->lchild=t->rchild=NULL;
                return t;
            }; 
            if(value<p->data){
                    p->lchild=Recursive_insert(p->lchild,value);
                    }
            else if(value>p->data){
                    p->rchild=Recursive_insert(p->rchild,value);
                    }
            return p;
                }

        Node* R_search(Node * t,int key){
            if(t==NULL){
                return NULL;
            }
            if (key==t->data){
                return t;
            }
            else if(key<t->data){
                return R_search(t->lchild,key);
            }
            else{
                return R_search(t->rchild,key);
            } 
        }
        Node *Delete(Node *p,int key){
            if(p==NULL){
                return NULL;
            }
            if(p->lchild==NULL && p->rchild==NULL){
                if (p==root){
                    root=NULL;
                }
                delete p;
                return NULL;
            }
            if(key<p->data){
                p->lchild=Delete(p->lchild,key);
            }
            else if(key>p->data){
                p->rchild=Delete(p->rchild,key);
            }
            else{
                if (Height(p->lchild)>height(p->rchild)){
                    Node *q=Inpre(p->lchild);
                    p->data=q->data;
                    p->lchild=Delete(p->lchild,q->data);
                }
                else if (Height(p->lchild)<height(p->rchild)){
                    Node *q=InSucc(p->rchild);
                    p->data=q->data;
                    p->rchild=Delete(p->rchild,q->data);
                }
            }
        }

        
};
        
// Node *root=NULL;
// void generate_BST_pre(int pre[],int n){
//             int i{0};
//             Stack st(30);
//             root=new Node;
//             root->data=pre[i++];
//             root->lchild=root->rchild=NULL;
//             Node* p=root;
//             while(i<n){
//                 if(pre[i]<p->data){
//                     Node *t=new Node;
//                     t->data=pre[i++];
//                     t->lchild=t->rchild=NULL;
//                     p->lchild=t;
//                     st.push_stack(p);
//                     p=t;
//                 }
//                 else{
//                     if(pre[i]>p->data&&pre[i]<(st.isempty()?INT_MAX:(st.stacktop())->data)){
//                             Node *t=new Node;
//                             t->data=pre[i++];
//                             t->lchild=t->rchild=NULL;
//                             p->rchild=t;
//                             p=t;
//                     }
//                     else{
//                         p=st.pop_stack();
//                     }
//                 }
//             }
//         }
// void generate_BST_post(int post[],int n){
//             int i{n};
//             Stack st(30);
//             root=new Node;
//             root->data=post[i--];
//             root->lchild=root->rchild=NULL;
//             Node* p=root;
//             while(i>0){
//                 if(post[i]>p->data){
//                     Node *t=new Node;
//                     t->data=post[i--];
//                     t->lchild=t->rchild=NULL;
//                     p->rchild=t;
//                     st.push_stack(p);
//                     p=t;
//                 }
//                 else{
//                     if(post[i]<p->data&&pre[i]<(st.isempty()?INT_MIN:(st.stacktop())->data)){
//                             Node *t=new Node;
//                             t->data=post[i--];
//                             t->lchild=t->rchild=NULL;
//                             p->lchild=t;
//                             p=t;
//                     }
//                     else{
//                         p=st.pop_stack();
//                     }
//                 }
//             }
//         }
//   void iterative_inorder(Node *p){
//                        Stack st;
//                        Node *t=p;
//                        while(!st.isempty()||t!=NULL){
//                             if(t!=NULL){
//                                 st.push_stack(t);
//                                 t=t->lchild;
//                             }
//                             else{
//                                 Node *x=st.pop_stack();
//                                 printf("%d ",x->data);
//                                 t=t->rchild;
//                             }
//                        }
//                    }
int main(){
    Binary_Tree BST;
    // int y{20};
    // BST.insert(BST.root,y);//Added root node
    // BST.insert(BST.root,10);
    // BST.insert(BST.root,30);
    // BST.insert(BST.root,40);
    // BST.root=BST.Recursive_insert(BST.root,y);//Added root node
    // BST.Recursive_insert(BST.root,10);
    // BST.Recursive_insert(BST.root,30);
    // BST.Recursive_insert(BST.root,40);
    // BST.inorder(BST.root);
    // int a[]={30,20,10,15,25,40,50,45};
    // generate_BST_pre(a,8);
    // iterative_inorder(root);
    return 0;
}