/*
 * @Author: Douglas 
 * @Date: 2021-07-14 11:22:16 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-14 11:52:26
 */
#include<iostream>
using namespace std;
//判断是否是 几进制 回文数

int turnto(int a,int b,int res[]){
    int i=0;
    while(a!=0){
    int ans = a%b;
    // printf("%d",ans);
    res[i] = ans;
    a = a/b;
    i++;
    }
    return i;
}

int main(){
    int s,r,ans;int res[1000]={};
    scanf("%d%d",&s,&r);
    int sum = turnto(s,r,res);
    bool flag = true;
    
    for(int i=0;i<=sum/2;i++){
        if(res[i]!=res[sum-i-1])flag=false;
    }
    if(flag){
        printf("Yes\n");}
    else{
        printf("No\n");
    }
    for(int i=sum-1;i>0;i--){
     printf("%d ",res[i]);   
    }
    printf("%d",res[0]);
    return 0;
}