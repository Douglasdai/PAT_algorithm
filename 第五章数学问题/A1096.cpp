/*
 * @Author: Douglas 
 * @Date: 2021-07-31 14:40:59 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-31 14:54:05
 */

//质因子分解
//连续整数乘积
#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
typedef long long ll;
int main(){
    ll n,anslen =0,ansI=0;
    scanf("%lld",&n);
    ll sqr = (ll )sqrt(n);
    for(ll i=2;i<sqr;i++){
        ll temp = 1,j=i;
        while (1)
        {
            temp *=j;
            if(n%temp!=0)break;
            if(j-i+1>anslen){
                ansI = i;
                anslen = j-i+1;
            }
            j++;
        }
    }
    if(anslen==0){
        printf("1\n%lld",n);
    }else{
        printf("%lld\n",anslen);
        for(ll i=0;i<anslen;i++){
            printf("%lld",ansI+i);
            if(i<anslen-1){
                printf("*");
            }
        }
    }

    return 0;
}