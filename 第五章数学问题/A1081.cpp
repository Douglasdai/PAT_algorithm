/*
 * @Author: Douglas 
 * @Date: 2021-07-30 22:03:17 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-30 23:02:25
 */

#include<cstdio>
#include<algorithm>
using namespace std;//TODO
//分数四则运算
typedef long long LL;
//最大公约数
LL gcd(LL m,LL n){
    return n==0 ? m :gcd(n,m%n);
}

struct Fraction
{
    LL up,down;    
};

Fraction reduction(Fraction a){
    if(a.down<0){
        a.up =-a.up;
        a.down =-a.down;
    }
    if(a.up==0){
        a.down =1;
    }else{
        LL res = gcd(abs(a.up),abs(a.down));
        a.up = a.up/res;
        a.down = a.down/res;
    }
    return a;
}
Fraction add(Fraction a,Fraction b){
    Fraction res;
    res.up = a.up*b.down + b.up*a.down;
    res.down = a.down*b.down;
    return reduction(res);
}
void showFraciton(Fraction a){
    int d=0;
    a = reduction(a);
    if(a.up > a.down){
        d= a.up/a.down;
        a.up = a.up%a.down;
        printf("%d",d);
        if(a.up==0){
            return;
        }
        printf(" %d/%d",a.up,a.down);
    }else {
        if(a.up==0){
            printf("0");return;
        }
        else{
            printf("%d/%d",a.up,a.down);
        }
    }
}
Fraction fra[110];Fraction sum;
int main(){
    int n;
    scanf("%d",&n);
    scanf("%d/%d",&sum.up,&sum.down);
    for(int i=1;i<n;i++){
        scanf("%d/%d",&fra[i].up,&fra[i].down);
        sum =add(sum,fra[i]);
    }
    showFraciton(sum);
    return 0;
}


