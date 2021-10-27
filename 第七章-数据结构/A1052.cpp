/*
 * @Author: Douglas 
 * @Date: 2021-08-07 00:16:54 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-08-07 00:27:28
 */

#include<iostream>
#include<algorithm>
using namespace std;
//链表排序
const int maxn = 100010;
struct NODE
{
    int address,data,next;
    bool flag;
}s[maxn];
bool cmp(NODE a,NODE b){
    if(a.flag ==false || b.flag ==false){
        return a.flag >b.flag;
    }else{
        return a.data<b.data;
    }
}
int main()
{   //init
    for(int i=0;i<maxn;i++){
        s[i].flag =false;
    }
    int n,begin,address;
    scanf("%d%d",&n,&begin);
    for(int i=0;i<n;i++){
        scanf("%d",&address);
        scanf("%d%d",&s[address].data,&s[address].next);
    }
    int count =0,p = begin;
    while(p!=-1){
        s[address].flag = true;
        count++;
        p = s[address].next;
    }
    if(count==0){
        printf("0 -1");
    }else{
        sort(s,s+maxn,cmp);
        printf("%d %05d\n",count,s[0].address);
        for(int i=0;i<count;i++){
            if(i!=count-1){
                printf("%05d %d %05d\n",s[i].address,s[i].data,s[i].next);
            }else{
                printf("%05d %d -1\n",s[i].address,s[i].data);
            }
        }
    }
    return 0;
}