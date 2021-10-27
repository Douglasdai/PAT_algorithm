/*
 * @Author: Douglas 
 * @Date: 2021-07-14 16:00:38 
 * @Last Modified by:   Douglas 
 * @Last Modified time: 2021-07-14 16:19:38 
 */

#include<iostream>
using namespace std;
int abs1(int a){
    if(a<0)return -a;
    else return a ;
}

int main(){
    int a,b;
    cin>>a>>b;
    int sum = a+b;
    if(sum<1000 &&sum>-1000)printf("%d",sum);
    else if((sum>=1000 && sum<=1000000)||(sum<=-1000 && sum>=-1000000))printf("%d,%3d",sum/1000,abs1(sum%1000));
    //两个逗号
    else printf("%d,%3d,%3d",sum/1000/1000,abs1(sum/1000%1000),abs1(sum%1000));
    return 0;
}