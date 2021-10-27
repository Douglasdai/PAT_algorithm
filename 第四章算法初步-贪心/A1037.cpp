/*
 * @Author: Douglas 
 * @Date: 2021-07-29 10:45:57 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-29 12:16:02
 */

#include<iostream>
#include<algorithm>
using namespace std;
int n,m;
const int maxn =100010;
long a[maxn]={0},b[maxn]={0},fua[maxn]={0},fub[maxn]={0};
bool cmp(long a,long b){
    if(a!=b)return a>b;
}
bool cmpfu(long a,long b){
    if(a!=b)return a<b;
}
int main(){
    scanf("%d",&n);
    long in;
    int alen=0,blen=0,fualen=0,fublen=0;
    long long res=0;
    for(int i=0;i<n;i++){
        scanf("%ld",&in);
        if(in>0){
            a[i] = in;alen++;
        }else{fua[i]=in;fualen++;}
    }
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%ld",&in);
        if(in>0){
            b[i] = in;blen++;
        }else{fub[i]=in;fublen++;}
    }
    sort(a,a+n,cmp);
    sort(fua,fua+n,cmpfu);
    sort(fub,fub+m,cmpfu);
    sort(b,b+m,cmp);
    int len =min(alen,blen);
    int fulen = min(fualen,fublen);
    for(int i=0;i<len;i++){
        res+=a[i]*b[i];
    }
    for(int i=0;i<fulen;i++){
        res+=fua[i]*fub[i];
    }
    printf("%lld",res);
    return 0;
}