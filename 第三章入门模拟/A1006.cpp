#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
//签入签出 比较时间
// 题解
struct pNode{
    char id[20];
    int hh,mm,ss;
}temp,ans1,ans2;

bool great(pNode a,pNode b){
    if(a.hh !=b.hh) return a.hh>b.hh;
    else if(a.mm !=b.mm) return a.mm>b.mm;
    else return a.ss>b.ss;
}
int main(){
    int M;
    scanf("%d",&M);
    ans1.hh =24,ans1.mm = 60,ans1.ss=60;
    ans2.hh =0,ans2.mm = 0,ans2.ss=0;
    for(int i=0;i<M;i++){
        scanf("%s %d:%d:%d",&temp.id,&temp.hh,&temp.mm,&temp.ss);
        if(great(temp,ans1)==false)ans1 =temp;
        scanf("%d:%d:%d",ans2.hh,ans2.mm,ans2.ss);
        if(great(temp,ans2)==false)ans2 =temp;
    }
    printf("%s %s\n",ans1.id,ans2.id);
    return 0;
}


#include<cstdio>
#include<algorithm>
#include<string.h>
using namespace std;
struct ti{
    char id[15];
    int h;
    int m;
    int s;
};
bool cmp(ti a,ti b){
    if(a.h !=b.h) return a.h>b.h;
    else if(a.m !=b.m) return a.m>b.m;
    else return a.s>b.s;
}
//法二 结构体排序
int main(){
    int M;
    scanf("%d",&M);
    ti t[M],tl[M];
    for(int i=0;i<M;i++){
        scanf("%s %d:%d:%d %d:%d:%d",&t[i].id,&t[i].h,&t[i].m,&t[i].s,&tl[i].h,&tl[i].m,&tl[i].s);
        strncpy(tl[i].id,t[i].id,15);
    }
    sort(t,t+M,cmp);
    sort(tl,tl+M,cmp);
    printf("%s %s",t[M-1].id,tl[0].id);
    return 0;
}