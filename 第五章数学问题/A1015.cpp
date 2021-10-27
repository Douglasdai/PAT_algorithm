/*
 * @Author: Douglas 
 * @Date: 2021-07-30 23:53:31 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-31 00:04:48
 */

#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
bool isPrime(int b){
    if(b<=1)return false;
    int sqr = (int )sqrt( b);
    for(int i=2;i<=sqr;i++){
        if (b%i==0)return false;
    }
    return true;
}
int d[111];
int main(){
    int n,radix;
    while(scanf("%d",&n)!=EOF){
        if(n<0)break;
        scanf("%d",&radix);
        if(isPrime(n)==false){
            printf("No\n");
        }else{
            int len =0;
            do{
                d[len++] =n%radix;
                n/=radix;
            }while(n!=0);
            //颠倒
            for(int i=0;i<len;i++){
                n = n*radix +d[i];
            }
            if(isPrime(n)){
                printf("Yes\n");
            }else printf("No\n");
        }
    }
    return 0;
}