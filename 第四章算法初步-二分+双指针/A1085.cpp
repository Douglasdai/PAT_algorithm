/*
 * @Author: Douglas 
 * @Date: 2021-07-29 15:12:56 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-29 23:56:46
 */

#include<iostream>
#include<algorithm>
using namespace std;
int n,p;
int a[100010]={0};
//TODO 没用二分 是错的。。。
int main()
{   scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    sort(a,a+n);
    int res=n;long long sum =a[0]*p ;
    for(int i=n-1;i>0 && a[i]>sum;i--){
        res--;
    }
    cout<<res<<endl;
    return 0;
}

int main2(){
    scanf("%d%d",&n,&p);
    for(int i=0;i<n;i++){
        scanf("%d",&a[i]);
    }
    int ans =1;
    for(int i=0;i<n;i++){
        int j =upper_bound(a+i+1,a+n,(long long)a[i]*p)-a;
        ans = max(ans,j-i);
    }
    printf("%d\n",ans);
    return 0;
}