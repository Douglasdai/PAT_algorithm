/*
 * @Author: Douglas 
 * @Date: 2021-07-29 23:18:40 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-29 23:40:21
 */
#include<iostream>
using namespace std;
//TODO 二分需要加强 不会应用
//火星购物
int n,m;
int dia[100010];
int upperbound(int L,int R,int x){
    int left = L,right= R,mid;
    while(left<right){
        mid =(left+right)/2;
        if(dia[mid]>x)right =mid;
        else left = mid+1;
    }
    return left;
}

int main(){
    
    int near = 100000010;
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&dia[i]);
        dia[i] +=dia[i-1];
    }
    //er fen
    for(int i=1;i<=n;i++){
        int j= upperbound(i,n+1,dia[n-1]+m);
        if(dia[j-1] -dia[i-1] ==m){
            near = m;
            break;
        }else if(j<=n && dia[j] -dia[i-1] <near){
            near = dia[j]-dia[i-1];
        }
    }
    for(int i=1;i<=n;i++){
        int j= upperbound(i,n+1,dia[i-1]+near);
        if(dia[j-1] - dia[i-1] ==near){
            printf("%d-%d",i,j-1);
        }
    }
   return 0;
}