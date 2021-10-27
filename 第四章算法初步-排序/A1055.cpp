/*
 * @Author: Douglas 
 * @Date: 2021-07-16 13:58:02 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-16 16:30:59
 */
#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//世界上的富豪
//排序
//TODO test
struct Person
{
    char name[9];
    int age;
    int money;
}per[100010],valid[100010];
bool cmp(Person a,Person b){
    if(a.money!=b.money)return a.money>b.money;
    else if(a.age!=b.age)return a.age <b.age;
    else return strcmp(a.name,b.name)<0;
}
//是否会超时
int main(){
    int n,k,count,mina,maxa;
    int Age[100010];
    scanf("%d%d",&n,&k);
    for(int i=0;i<n;i++){
        scanf("%s%d%d",&per[i].name,&per[i].age,&per[i].money);
    }
    sort(per,per+n,cmp);
    //预处理
    int validNum =0;
    for(int i=0;i<n;i++){
        if(Age[per[i].age]<100){
            Age[per[i].age]++;
            valid[validNum++] =per[i];
        }
    }

    for(int m=0;m<k;m++){
        scanf("%d%d%d",&count,&mina,&maxa);
        int j=0;
        printf("Case #%d:\n",m+1);
        
        for(int i=0;i<validNum && j<count;i++){
            if(valid[i].age >=mina &&valid[i].age<=maxa){
               printf("%s %d %d\n",valid[i].name,valid[i].age,valid[i].money); 
               j++;
            }
            
        }if(j==0){
            printf("None\n");
        }
        
    }
    return 0;
}
