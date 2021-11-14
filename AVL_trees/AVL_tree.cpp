#include<iostream>

struct Node{
    int data;
    Node* lchild;
    Node *rchild;
    int height;

}*root=NULL;
int NodeHeight(Node *p){
    int hr{0},hl{0};
    hl=p&&p->lchild?p->lchild->height:0;
    hr=p&&p->rchild?p->rchild->height:0;
    return hr>hl?hr+1:hl+1;
}

int BalanceFactor(Node* p){
    int hr{0},hl{0};
    hl=p&&p->lchild?p->lchild->height:0;
    hr=p&&p->rchild?p->rchild->height:0;
    return hl-hr;
}

Node* LL_Rotation(Node *p){
    Node *pl=p->lchild;
    Node *plr=p->lchild->rchild;
    pl->rchild=p;
    p->lchild=plr;
    p->height=NodeHeight(p);
    pl->height=NodeHeight(pl);

    if(root=p){
        root=pl;
    }
    return pl;
}

Node* RR_Rotation(Node *p){
    Node *pr=p->rchild;
    Node *prl=p->rchild->lchild;
    pr->lchild=p;
    p->rchild=prl;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);

    if(root==p){
        root=pr;
    }
    return pr;
}
Node *LR_Rotation(Node *p){
    Node *plr=p->lchild->rchild;
    Node *pl=p->lchild;
    pl->rchild=plr->lchild;
    p->lchild=plr->rchild;
    plr->lchild=pl;
    plr->rchild=p;
    pl->height=NodeHeight(pl);
    p->height=NodeHeight(p);
    plr->height=NodeHeight(plr);
    if(root==p){
        root=plr;
    }
    return plr;

}
Node *RL_Rotation(Node *p){
    Node *pr=p->rchild;
    Node *prl=p->rchild->lchild;
    pr->lchild=prl->rchild;
    p->rchild=prl->lchild;
    prl->lchild=p;
    prl->rchild=pr;
    p->height=NodeHeight(p);
    pr->height=NodeHeight(pr);
    prl->height=NodeHeight(prl);
    if(root==p){
        root=prl;
    }
    return prl;
}
Node *Recursive_insert(Node *p,int value){
    if(p==NULL){
        Node*t=new Node;
        t->data=value;
        t->height=1;
        t->lchild=t->rchild=NULL;
        return t;
    }
    if(value<p->data){
        p->lchild=Recursive_insert(p->lchild,value);
    }
    else if(value>p->data){
        p->rchild=Recursive_insert(p->rchild,value);
    }
    else{
        printf("Node already exists ");
        return NULL;
    }
    p->height=NodeHeight(p);

    if(BalanceFactor(p)==2 &&BalanceFactor(p->lchild)==1){
        return LL_Rotation(p);
    }
    else if(BalanceFactor(p)==-2 &&BalanceFactor(p->rchild)==-1){
        return RR_Rotation(p);
    }
    else if(BalanceFactor(p)==2 &&BalanceFactor(p->lchild)==-1){
        return LR_Rotation(p);
    }
    else if(BalanceFactor(p)==-2 &&BalanceFactor(p->rchild)==1){
        return RL_Rotation(p);
    }
    return p;
}

int main(){
    root=Recursive_insert(root,20);
    Recursive_insert(root,10);
    Recursive_insert(root,15);
    printf("%d",root->data);
    return 0;
}