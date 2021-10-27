/*
 * @Author: Douglas 
 * @Date: 2021-07-30 16:21:53 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-30 16:32:33
 */
#include<iostream>
#include<algorithm>
using namespace std;
const int maxn = 100010;
const int inf = 0x3fffffff;
int a[maxn],leftMax[maxn],rightmin[maxn];
int ans[maxn],num=0;
int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    leftMax[0] =0;
    for(int i=1;i<n;i++){
        leftMax[i] =max(leftMax[i-1],a[i-1]);
    }
    rightmin[n-1] =inf;
    for(int i=n-2;i>=0;i--){
        rightmin[i] = min(rightmin[i+1],a[i+1]);
    }
    for(int i=0;i<n;i++){
        if(leftMax[i]<a[i] && rightmin[i]>a[i]){
            ans[num++] =a[i];
        }
    }
    printf("%d\n",num);
    for(int i=0;i<num;i++){
        printf("%d",ans[i-1]);
        if(i<num-1){printf(" ");}
    }
    printf("\n");
    return 0;
}