/*
 * @Author: Douglas 
 * @Date: 2021-07-30 20:00:33 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-30 20:17:00
 */
//数列片段和
#include<iostream>
#include<algorithm>
using namespace std;
//排列问题 数学规律 看出现了几次
int n;
const int maxn= 100010;
double a[maxn];
int main(){
    cin>>n;
    double sum=0; 
    for(int i=0;i<n;i++){
        scanf("%lf",&a[i]);
    }
    //2-n 个组合
    for(int i=1;i<=n;i++){
        sum += a[i-1]*i*(n+1-i);
    }
    printf("%.2f",sum);
    return 0;
}