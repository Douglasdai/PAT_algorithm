/*
 * @Author: Douglas 
 * @Date: 2021-08-02 21:33:17 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-08-02 21:45:00
 */

//反转链表 有点看不懂  查看其他解析

#include<cstdio>
#include<algorithm>
using namespace std;
const int maxn = 100010;
struct Node
{
    int address,data,next;
    int order;
}node[maxn];

bool cmp(Node a,Node b){
    return a.order<b.order;
}
int main(){
    for(int i=0;i<maxn;i++){
        node[i].order = maxn;
    }
    int begin,n,K,address;
    scanf("%d%d%d",&begin,&n,&K);
    for(int i=0;i<n;i++){
        scanf("%d",&address);
        scanf("%d%d",&node[address].data,&node[address].next);
        node[address].address = address;
    }
    int p = begin,count = 0;
    while (p!=-1)
    {
        node[p].order = count++;
        p  =node[p].next;
    }
    sort(node,node+maxn,cmp);
    n = count;
    for(int i=0;i<n/K;i++){
        for(int j=(i+1)*K-1;j>i*K;j--){
            printf("%05d %d %05d\n",node[j].address,node[j].data,node[j-1].address );

        }
        printf("%05d %d ",node[i*K].address,node[i*K].data);
        if(i<n/K-1){
            printf("%05d\n",node[(i+2)*K-1].address);
        }else{
            printf("%05d\n",node[(i+1)*K].address);
            for(int i=n/K*K;i<n;i++){
                printf("%05d %d ",node[i].address,node[i].data);
                if(i<n-1){
                    printf("%05d\n",node[i+1].address);
                }
                else{
                    printf("-1\n");
                }
            }
        }
        
    }
    return 0;
}