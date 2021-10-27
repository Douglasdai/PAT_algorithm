//给出作为N个结点和n-1条边 ，能否构成一个树，能 选出节点作为树根使得树高度最大，输出所有满足要求的根节点
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N = 100010;
vector<int> G[N];
bool isRoot[N];
int father[N];
int findfather(int x){
    int a = x;
    while(x!=father[x]){
        x= father[x];
    }
    while (a!= father[a])
    {
        int z = a;
        a = father[a];
        father[z] =x;
    }
    return x;
}
void Union(int a,int b){
    int faA = findfather(a);
    int faB = findfather(b);
    if(faA!=faB){
        father[faA] = faB;
    }
}
void init(int n){
    for(int i=1;i<=n;i++){
        father[i] =i;
    }
}
int calBlock(int n){
    int Block =0;
    for(int i=1;i<=n;i++){
        isRoot[findfather(i)] = true;
    }
    for(int i=1;i<=n;i++){
        Block+=isRoot[i];
    }
    return Block;
}
int maxH= 0;
vector<int>temp,Ans;
void DFS(int u,int Height,int pre){
    if(Height>maxH){
        temp.clear();
        temp.push_back(u);
        maxH = Height;
    }
    else if(Height ==maxH){
        temp.push_back(u);
    }
    for(int i=0;i<G[u].size();i++){
        if(G[u][i] ==pre)continue;
        DFS(G[u][i],Height+1,u);
    }
}
int main(){
    int a,b,n;
    scanf("%d",&n);
    init(n);
    for(int i=1;i<n;i++){
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);
        Union(a,b);
    }
    int Block = calBlock(n);
    if(Block!=1){
        printf("Error: %d components\n",Block);
    }
    else{
        DFS(1,1,-1);
        Ans = temp;
        DFS(Ans[0],1,-1);
        for(int i=0;i<temp.size();i++){
            Ans.push_back(temp[i]);
        }
        sort(Ans.begin(),Ans.end());
        printf("%d\n",Ans[0]);
        for(int i =1;i<Ans.size();i++){
            if(Ans[i]!= Ans[i-1]){//重复不输出
                printf("%d\n",Ans[i]);
            }
        }
    }
    return 0;
}
