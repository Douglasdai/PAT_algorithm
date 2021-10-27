//创建一个BST
#include<cstdio>
#include<algorithm>
#include<queue>
using namespace std;
const int maxn = 110;
struct node
{
    int data;
    int lchild,rchild;
}Node[maxn];
int n,in[maxn],num=0;
void inOrder(int root){
    if(root==-1){
        return;
    }
    inOrder(Node[root].lchild);
    Node[root].data = in[num++];
    inOrder(Node[root].rchild);
}
void BFS(int root){
    queue<int>Q;
    Q.push(root);
    num=0;
    while(!Q.empty()){
        int now = Q.front();
        Q.pop();
        printf("%d",Node[now].data);
        num++;
        if(num<n)printf(" ");
        if(Node[now].lchild!=NULL)Q.push(Node[now].lchild);
        if(Node[now].rchild!=NULL)Q.push(Node[now].rchild);
    }
}
int main(){
    int lchild,rchild;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d%d",&lchild,&rchild);
        Node[i].lchild = lchild;
        Node[i].rchild = rchild;
    }
    for(int i=0;i<n;i++){
        scanf("%d",&in[i]);
    }
    sort(in,in+n);
    inOrder(0);
    BFS(0);
    return 0;
}

