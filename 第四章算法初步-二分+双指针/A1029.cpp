/*
 * @Author: Douglas 
 * @Date: 2021-07-30 00:04:41 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-30 00:13:54
 */

//双指针 序列中位数
#include<iostream>
#include<cstring>
using namespace std;
int n,m;
const int maxn = 1000010;
int S1[maxn],S2[maxn];
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",S1[i]);
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d",S2[i]);
    }
    S1[n] =S2[m] = 0x7fffffff;
    int mid = (n+m-1)/2;
    int i=0,j=0,count=0;
    while (count <mid)
    {
        if(S1[i]<S2[j])i++;
        else j++;
        count++;
    }
    if(S1[i]<S2[j]){
        printf("%d\n",S1[i]);
    }else{
        printf("%d\n",S2[j]);
    }
    return 0;
}
