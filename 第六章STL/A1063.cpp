/*
 * @Author: Douglas 
 * @Date: 2021-07-31 20:57:57 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-31 21:32:23
 */
//set的常见用法 详解

#include<cstdio>
#include<set>
using namespace std;
const int N=51;
set<int> st[N];
void compare(int x,int y){
    int totalNum = st[y].size(),sameNum =0;
    for(set<int>::iterator it = st[x].begin();it!=st[x].end();it++){
        if(st[y].find(*it) !=st[y].end()) sameNum++;
        else totalNum++;
    }
    printf("%.1f%%\n",sameNum*100.00/totalNum);
}
int main(){
    int n,k,q,v,st1,st2;
    scanf("%d",&n);
    for(int i=1;i<=n;i++){
        scanf("%d",&v);
        st[i].insert(v);
    }
    scanf("%d",&q);
    for(int i=0;i<q;i++){
        scanf("%d%d",&st1,&st2);
        compare(st1,st2);
    }
    return 0;
}