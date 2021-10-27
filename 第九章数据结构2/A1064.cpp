//建立一个完全二叉树 //输出层序遍历
#include<cstdio>
#include<vector>
#include<algorithm>
using namespace std;
const int maxn=1010;
int n ,number[maxn],CBT[maxn],index=0;
//数组完全二叉树
void inOrder(int root){
    if(root>n)return;
    inOrder(root*2);
    CBT[root] = number[index++];
    inOrder(root*2+1);
}
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&number[i]);
    }
    sort(number,number+n);
    inOrder(1);
    for(int i=1;i<=n;i++){
        printf("%d",CBT[i]);
        if(i<n)printf(" ");
    }
    return 0;
}