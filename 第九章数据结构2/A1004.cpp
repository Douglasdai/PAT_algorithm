/*
 * @Author: Douglas 
 * @Date: 2021-08-07 14:22:11 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-08-07 15:13:08
 */
//数叶子
//邻接表实现
//DFS
#include<iostream>
#include<cstdio>
#include<vector>
#include<algorithm>
#include<queue>
using namespace std;
const int N = 110;
vector<int> G[N];
int leaf[N] = {0};
int max_h =1;
void DFS(int index,int h){
    max_h = max(h,max_h);
    if(G[index].size()==0){
        leaf[h]++;
        return ;
    }
    for(int i=0;i<G[index].size();i++){
        DFS(G[index][i],h+1);
    }
}
int main(){
    int n,m,parent,child,k;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        scanf("%d%d",&parent,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&child);
            G[parent].push_back(child);
        }
    }
    DFS(1,1);
    printf("%d",leaf[1]);
    for(int i=2;i<max_h;i++){
        printf(" %d",leaf[i]);
    }
    return 0;
}
//BFS
int h[N] = {0};
int max_h=0;
void BFS(){
    queue<int>Q;
    Q.push(1);
    while(!Q.empty()){
        int id = Q.front();
        Q.pop();
        max_h = max(h[id],max_h);
        if(G[id].size()==0){
            leaf[h[id]]++;
        }
        for(int i=0;i<G[id].size();i++){
            h[G[id][i]] = h[id]+1;
            Q.push(G[id][i]);
        }
    }
}
int main2(){
    int n,m;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;i++){
        int parent,k,child;
        scanf("%d%d",&parent,&k);
        for(int j=0;j<k;j++){
            scanf("%d",&child);
            G[parent].push_back(child);
        }
    }
    h[1] =1;
    BFS();
    for(int i=1;i<max_h;i++){
        if(i==1)printf("%d",leaf[1]);
        else printf(" %d",leaf[i]);
    }
    return 0;
}