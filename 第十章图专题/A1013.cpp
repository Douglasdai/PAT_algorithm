//给定一个无向图并规定，当删除图中的某个顶点时，将会同时把与之相连的边删除
//给出k个查询，每个查询给出一个欲删除的顶点编号，求删除该顶点后需要增加多少条边才能使图变为连通
//2种方法
//DFS
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
const int N = 1111;
vector<int> G[N];
bool vis[N];
int currentPoint;
void dfs(int v){
    if(v== currentPoint)return ;
    vis[v] = true;
    for(int i=0;i<G[v].size();i++){
        if(vis[G[v][i]] == false){
            dfs(G[v][i]);
        }
    }
}
int n,m,k;
int main(){
    scanf("%d%d%d",&n,&m,&k);
    for(int i=0;i<m;i++){
        int a,b;
        scanf("%d%d",&a,&b);
        G[a].push_back(b);
        G[b].push_back(a);//建图
    }
    for(int query = 0;query<k;query++){
        scanf("%d",&currentPoint);
        memset(vis,false,sizeof(vis));
        int block = 0;//连通块个数
        for(int i=1;i<=n;i++){//每个顶点
            if(i!=currentPoint  && vis[i]==false){//如果没有删除，且没有被访问
                dfs(i);//遍历连通块 
                block++;//个数加1
            }
        }
        printf("%d\n",block-1);//表示需要增加的边
    }
    return 0;
}
