//用栈模拟二叉树前序和中序遍历过程，求后序遍历
#include<algorithm>
#include<cstdio>
#include<stack>
#include<cstring>
using namespace std;
const int maxn =50;
struct node
{
    int data;
    node *lc;
    node *rc;
};
int pre[maxn],in[maxn],post[maxn];
int n;

node* create(int PreL,int PreR,int inL,int inR){
    if(PreL>PreR){
        return NULL;
    }
    node *root = new node;
    root->data = pre[PreL];
    int k;
    for(int k = inL;k<inR;k++){
        if(in[k]==pre[PreL]){
            break;  //找到相等的节点
        }
    }
    int numLeft = k-inL;
    root->lc = create(PreL+1,PreL+numLeft,inL,k-1);
    root->rc = create(PreL+numLeft,PreR,k+1,inR);
    return root;
}
int num =0;
void postorder(node *root){
    if(root =NULL){
        return ;
    }
    postorder(root->lc);
    postorder(root->rc);
    printf("%d",root->data);
    num++;
    if(num<n)printf(" ");
}
int main(){
    scanf("%d",&n);
    char str[5];
    stack<int> st;
    int x,preIndex = 0,inIndex= 0;
    for(int i=0;i<2*n;i++){
        scanf("%s",str);
        if(strcmp(str,"Push")==0){
            scanf("%d",&x);
            pre[preIndex++]=x;
            st.push(x);
        }else{
            //出
            in[inIndex++] = st.top();
            st.pop();
        }
    }
    node *root = create(0,n-1,0,n-1);
    postorder(root);
    return 0;
}