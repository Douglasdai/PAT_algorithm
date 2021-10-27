//二叉树反转 层序遍历+中序遍历
#include<queue>
#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn =110;
struct Node //二叉树静态写法
{
    int lchild,rchild;
}node[maxn];
bool notRoot[maxn] ={false};
int n,num=0;
void print(int id){
    printf("%d",id);
    num++;
    if(num<n)printf(" ");
    else printf("\n");
}
void inOrder(int root){
    if(root= -1){
        return;
    }
    inOrder(node[root].lchild);
    print(root);
    inOrder(node[root].rchild);
}
void BFS(int root){
    queue<int> q;
    q.push(root);
    while (!q.empty())
    {
        int now = q.front();
        q.pop();
        print(now);
        if(node[now].lchild!=-1)q.push(node[now].lchild);
        if(node[now].rchild!=-1)q.push(node[now].rchild);
    }
}
void PostOrder(int root){
    //用于反转二叉树
    if(root =-1){
        return;
    }
    PostOrder(node[root].lchild);
    PostOrder(node[root].rchild);
    swap(node[root].lchild,node[root].rchild);
}
int strToNum(char c){
    if(c=='-')return -1;
    else{
        notRoot[c-'0'] = true;
        return c-'0';
    }
}
int findRoot(){
    for(int i=0;i<n;i++){
        if(notRoot[i]==false){
            return i;
        }
    }
}
int main(){
    char lchild,rchild;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%*c%c %c",&lchild,&rchild);
        node[i].lchild = strToNum(lchild);
        node[i].rchild = strToNum(rchild);
    }
    int root = findRoot();
    PostOrder(root);
    BFS(root);
    num=0;
    inOrder(root);
    return 0;
}