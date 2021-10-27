//二叉树遍历 
//利用后序和中序 输出层序遍历序列
#include<cstdio>
#include<cstring>
#include<queue>
#include<algorithm>
using namespace std;
const int maxn = 50;
struct node
{
    int data;
    node *lchild;
    node *rchild;
};
int pre[maxn],in[maxn],post[maxn];
int n;
//[postL,postR]后序 【in】 中序
node *creat(int postL,int postR,int inL,int inR){
    if(postL>postR){
        return NULL;
    }
    node*root = new node;//存放根节点
    root->data = post[postR];
    int k;
    for(k=inL;k<inR;k++){
        if(in[k] == post[postR]){
            break;//中序找到in[k] == post[posrR]的节点
        }
    }
    int numLeft = k-inL;//左子节点个数
    //赋给 root 左右
    root->lchild = creat(postL,postL+numLeft-1,inL,inR-1);
    root->rchild = creat(postL+numLeft,postR-1,k+1,inR);
    return root;
}
int num=0;//已输出节点个数
void BFS(node *root){
    queue<node*>q;
    q.push(root);
    //使用队列输出
    while (!q.empty())
    {
        node *now =q.front();
        q.pop();
        printf("%d",now->data);
        num++;
        if(num<n)printf(" ");
        if(now->lchild!=NULL)q.push(now->lchild);
        if(now->rchild!=NULL)q.push(now->rchild);
    }
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&post[i]);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    node *root = creat(0,n-1,0,n-1);
    BFS(root);//层序遍历
    return 0;
}