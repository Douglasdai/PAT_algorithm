#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//题解
// struct Student
// {
//     char id[10];
//     int de,cai,sum;
//     int flag;
// }st[100010];
// bool cmp(Student a, Student b){
//     if(a.flag!=b.flag)return a.flag<b.flag;
//     else if(a.sum!=b.sum)return a.sum>b.sum;
//     else if(a.de!=b.de)return a.de>b.de;
//     else return strcmp(a.id,b.id)<0;
// }
// int main(){
//     int n,l,h;
//     scanf("%d%d%d",&n,&l,&h);
//     int m = n;
//     for(int i=0;i<n;i++){
//         scanf("%s%d%d",&st[i].id,&st[i].de,&st[i].cai);
//         st[i].sum = st[i].de+st[i].cai;
//         if(st[i].de<l ||st[i].cai<l){
//             st[i].flag = 5;m--;
//         }
//         else if(st[i].de>=h &&st[i].cai>=h)st[i].flag = 1;
//         else if(st[i].de>=h &&st[i].cai <h)st[i].flag = 2;
//         else if(st[i].de>=st[i].cai)st[i].flag = 3;
//         else st[i].flag = 4;
//     }
//     sort(st,st+n,cmp);
//     printf("%d\n",m);
//     for(int i=0;i<m;i++){
//         printf("%s %d %d\n",st[i].id,st[i].de,st[i].cai);
//     }
//     return 0;
// }



//23分 不知道哪里错了
struct decai{
    int id;
    int ds;
    int cs;
    int all;
};
bool cmp(decai a,decai b){
    if(a.all!=b.all)return a.all>b.all;
    else if(a.ds!=b.ds)return a.ds>b.ds;
    else return a.id<b.id;
}
int main(){
    int n,l,h;
    scanf("%d %d %d",&n,&l,&h);
    decai de[n],de1[n],de2[n],de3[n],de4[n];
    for(int i=0;i<n;i++){
        scanf("%d %d %d",&de[i].id,&de[i].ds,&de[i].cs);
        de[i].all=de[i].ds+de[i].cs;
        de1[i].all = -1;
        de2[i].all = -1;
        de3[i].all = -1;
        de4[i].all = -1;
    }
    //排序 然后输出
    int count =0;
    for(int i=0;i<n;i++){
        if (de[i].ds<l || de[i].cs<l){
            continue;
        }
        else if(de[i].ds >= h &&de[i].cs>=h){
            de1[i] =de[i];
            count++;
        }
        else if(de[i].ds >= h && de[i].cs< h){
            de2[i] = de[i];count++;
        }
        else if(de[i].ds< h &&de[i].cs< h && de[i].ds>=de[i].cs){
            de3[i] = de[i];count++;
        }
        else {
            de4[i] = de[i];count++;
        }
    }
    sort(de1,de1+n,cmp);
    sort(de2,de2+n,cmp);
    sort(de3,de3+n,cmp);
    sort(de4,de4+n,cmp);
    printf("%d\n",count);
    for(int i=0;de1[i].all!=-1;i++){
        printf("%d %d %d\n",de1[i].id,de1[i].ds,de1[i].cs);
    }
    for(int i=0;de2[i].all!=-1;i++){
        printf("%d %d %d\n",de2[i].id,de2[i].ds,de2[i].cs);
    }
    for(int i=0;de3[i].all!=-1;i++){
        printf("%d %d %d\n",de3[i].id,de3[i].ds,de3[i].cs);
    }
    for(int i=0;de4[i].all!=-1;i++){
        printf("%d %d %d\n",de4[i].id,de4[i].ds,de4[i].cs);
    }
    return 0;
}