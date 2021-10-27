/*
 * @Author: Douglas 
 * @Date: 2021-08-07 00:27:54 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-08-07 00:28:36
 */
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
//链表
//去除相同元素
const int maxn = 100010;
const int table = 1000010;
struct NODE
{   
    int address,data,next;
    int order;
}node[maxn];
bool exist[table] = {false};
bool cmp(NODE a,NODE b){
    return a.order<b.order;
}

int main(){
    memset(exist,false,sizeof(exist));
    for(int i=0;i<maxn;i++){
        node[i].order = 2*maxn;
    }
    int begin,n,address;
    scanf("%d%d",&begin,&n);
    for(int i=0;i<n;i++){
        scanf("%d",&address);
        scanf("%d%d",&node[address].data,&node[address].next);
        node[address].address = address;
    }
    //未删除的有效节点个数 和已删除节点个数
    int countValid = 0,countRemoved = 0,p = begin;
    while (p!=-1)
    {
        if(!exist[abs(node[p].data)]){
            exist[abs(node[p].data)] =true;
            node[p].order = countValid++;
        }else{
            node[p].order = maxn+countRemoved++;
        }
        p = node[p].next;
    }
    sort(node,node+maxn,cmp);
    int count = countValid+countRemoved;
    for(int i=0;i<count;i++){
        if(i!= countValid-1 && i!=count -1){
            printf("%05d %d %05d\n",node[i].address,node[i].data,node[i].next);
        }else{
            printf("%05d %d -1\n",node[i].address,node[i].data);
        }
    }
    return 0;
}