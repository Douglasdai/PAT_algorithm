/*
 * @Author: Douglas 
 * @Date: 2021-07-30 23:02:55 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-30 23:53:00
 */

#include<cstdio>
#include<algorithm>
using namespace std;
//TODO
//有理数计算
typedef long long ll;
ll gcd(ll n,ll m){
    return m==0? m:gcd(m,n%m);
}
struct Fraction
{
    ll up,down;
}f1,f2;
Fraction reduction(Fraction a){
    
    if(a.down<0){
        a.up = -a.up;
        a.down =-a.down;
    }
    if(a.up==0)a.down=1;
    else{
        int d= gcd(abs(a.up),abs(a.down));
        a.up /=d;
        a.down/=d;
    }
    return a;
}

Fraction add(Fraction a,Fraction b){
    Fraction res;
    res.up = a.up*a.down+b.up*b.down;
    res.down = a.down *b.down;
    return reduction(res);
}
Fraction minu(Fraction a,Fraction b){
    Fraction res;
    res.up = a.up*a.down-b.up*b.down;
    res.down = a.down * b.down;
    return reduction(res);
}

Fraction multi(Fraction a,Fraction b){
    Fraction res;
    res.up = a.up*b.up;
    res.down = a.down * b.down;
    return reduction(res);
}
Fraction divide(Fraction a,Fraction b){
    Fraction res;
    res.up = a.up*b.down;
    res.down = a.down * b.up;
    return reduction(res);
}
void show(Fraction a){
    a = reduction(a);
    if(a.up<0)printf("(");
    if(a.down==1)printf("%lld",a.up);
    else if(abs(a.up)>abs(a.down)){
        printf("%lld %lld/%lld",a.up/a.down,abs(a.up)%a.down,a.down);
    }else{
        printf("%lld/%lld",a.up,a.down);
    }
    if(a.up<0)printf(")");
}
//不知道为啥 运行不起
int main(){
    scanf("%lld/%lld %lld/%lld",&f1.up,&f1.down,&f2.up,&f2.down);

    show(f1);
    printf(" + ");
    show(f2);
    printf(" = ");
    show(add(f1,f2));
    printf("\n");

    show(f1);
    printf(" - ");
    show(f2);
    printf(" = ");
    show(minu(f1,f2));
    printf("\n");

    show(f1);
    printf(" * ");
    show(f2);
    printf(" = ");
    show(multi(f1,f2));
    printf("\n");
    
    show(f1);
    printf(" / ");
    show(f2);
    printf(" = ");
    if(f2.up==0){
        printf("Inf");
    }else show(divide(f1,f2));
    printf("\n");
    return 0;
}