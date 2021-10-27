/*
 * @Author: Douglas 
 * @Date: 2021-07-29 00:07:22 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-29 00:26:50
 */

#include<iostream>
#include<algorithm>
using namespace std;
struct mooncake
{
    int num;
    float price;
};
bool cmp(mooncake a,mooncake b){
    return a.price>b.price;
}
int n,m;
int main(){
    scanf("%d%d",&n,&m);
    mooncake cake[n];int price;
    for(int i=0;i<n;i++){
        scanf("%d",&cake[i].num);
    }
    for(int i=0;i<n;i++){
        scanf("%d",&price);
        cake[i].price = price/float(cake[i].num);
    }
    sort(cake,cake+n,cmp);
    //printf("%d %f",cake[0].num,cake[0].price);
    float res=0.0;
    for(int i=0;i<n;i++){
        if(cake[i].num>m){
            res+=cake[i].price*m;
            break;
        }
        else{
            m-=cake[i].num;
            res+=cake[i].price*cake[i].num;
        }
    }
    printf("%.2f",res);
    return 0;
}