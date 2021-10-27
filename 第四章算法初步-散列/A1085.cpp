/*
 * @Author: Douglas 
 * @Date: 2021-07-29 23:47:22 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-30 00:00:40
 */

//完美数列
//双指针
#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
long long in[100010];
int main(){
    scanf("%d%d",&n,&m);
    for(int i=0;i<n;i++){
        scanf("%lld",&in[i]);
    }
    sort(in,in+n);
    //two pointer 有点类似快慢指针
    int l=0,r=0,count=1;
    while (l < n && r<n)
    {   
        while(r<n && in[r]<=in[l]*m){
            count = max(count,r-l+1);
            r++;
        }
        l++;
    }
    printf("%d\n",count);
    return 0;
}