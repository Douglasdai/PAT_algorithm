//AVL 很难
//建树 输出根节点
#include<cstdio>
#include<algorithm>
using namespace std;
struct NODE
{
    int v,height;
    NODE *lchild,*rchild;
}*root;

NODE* newNode(int v){
    NODE *node = new NODE;
    node->v = v;
    node->height = 1;
    node->lchild=NULL;
    node->rchild=NULL;
    return node;
}
int getHeight(NODE* root){
    if(root==NULL)return 0 ;
    return root->height;
}
void updateHeight(NODE* root){
    root->height= max(getHeight(root->lchild),getHeight(root->rchild))+1;

}
int getBalanceFactor(NODE* root){
    return getHeight(root->lchild)-getHeight(root->rchild);
}
void L(NODE* &root){
    NODE* temp = root->rchild;
    root->rchild = temp->lchild;
    temp->lchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}
//右旋
void R(NODE* &root){
    NODE *temp = root->lchild;
    root->lchild = temp->rchild;
    temp->rchild = root;
    updateHeight(root);
    updateHeight(temp);
    root = temp;
}

void insert(NODE* &root,int v){
    if(root ==NULL){
        root = newNode(v);
        return;
    }
    if(v<root->v){
        insert(root->lchild,v);
        updateHeight(root);
        if(getBalanceFactor(root)==2){
            if(getBalanceFactor(root->lchild)==1){
                R(root);
            }else if(getBalanceFactor(root->lchild)==-1){
                L(root->lchild);
                R(root);
            }
        }
    }else{
        insert(root->rchild,v);
        updateHeight(root);
        if(getBalanceFactor(root)==-2){
            if(getBalanceFactor(root->rchild)==-1){
                L(root);
            }else if(getBalanceFactor(root->rchild)==1){
                R(root->rchild);
                L(root);
            }
        }
    }
}
//AVL树建立
NODE* Create(int data[],int n){
    NODE *root = NULL;
    for(int i=0;i<n;i++){
        insert(root,data[i]);
    }
    return root;
}
int main(){
    int n,v;
    scanf("%d",n);
    for(int i=0;i<n;i++){
        scanf("%d",&v);
        insert(root,v);
    }
    printf("%d\n",root->v);
    return 0;
}
