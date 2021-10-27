/*
 * @Author: Douglas 
 * @Date: 2021-07-28 23:46:41 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-29 23:46:31
 */

//找硬币
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
int a[100010];
int bin(int l,int r,int x){
    int mid;
    while (l<=r)
    {
        mid = (l+r)/2;
        if(a[mid]==x)return mid;
        else if(a[mid]<x) l =mid+1;
        else r = mid-1;
    }
    return -1;
}
int main(){
    //二分方法
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);int i;
    for(i=0;i<n;i++){
        int pos = bin(0,n-1,m-a[i]);
        if(pos!=-1 && i!=pos ){
            printf("%d %d",a[i],a[pos]);
            break;
        }
    }
    if(i==n)printf("No solution\n");
    // scanf("%d%d",&n,&m);
    // int coin[n];
    // for(int i=0;i<n;i++){
    //     scanf("%d",&coin[i]);
    // }
    // sort(coin,coin+n);
    // int l = 0;int r = n-1;bool flag =false;
    // while (l<r)
    // {
    //     if(coin[l]+coin[r]==m){printf("%d %d\n",coin[l],coin[r]);flag=true;break;}
    //     else if(coin[l]+coin[r]<m)l++;
    //     else r--;
    // }
    // if(!flag){
    //     printf("No solution");
    // }
    //散列方法
    // int hasht[1010] = {0};
    // for(int i=0;i<n;i++){
    //     hasht[coin[i]]++;
    // }
    // for(int i=1;i<=1000;i++){
    //     if(hasht[i]>0 && hasht[m-i]>0 && m-i>0){
    //         if(i==m-i){
    //             if(hasht[i]>=2){
    //                 printf("%d %d\n",i,i);
    //                 break;
    //             }
    //         }
    //         else{
    //             printf("%d %d\n",i,m-i);
    //             break;
    //         }
    //     }
    //     if(i==1000){
    //         printf("No Solution");
    //     }
    // }
    //双指针也能做
    
    
    return 0;
}
// 7 14
// 1 8 7 2 4 11 15

// 8 15 
// 1 2 8 7 2 4 11 15