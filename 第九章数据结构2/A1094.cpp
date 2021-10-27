//输出一层中具有最多叶子的个数 和 层数
#include<cstdio>
#include<vector>
using namespace std;
const int maxn = 110;
vector<int> Node[maxn];
int hashTable[maxn] = {0};
void DFS(int index,int level){
    hashTable[level]++;//第level层的结点个数加1
    for(int j=0;j<Node[index].size();j++){
        DFS(Node[index][j],level+1);
    }
}
int main(){
    int n,m,parent,k,child;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&parent,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&child);
            Node[parent].push_back(child);
        }   
    }
    DFS(1,1);
    int maxlevel = -1,maxValue =0;
    for(int i=1;i<maxn;i++){
        if(hashTable[i]>maxValue){
            maxValue = hashTable[i];
            maxlevel= i;
        }
    } 
    printf("%d %d\n",maxValue,maxlevel);
    return 0;
}
    