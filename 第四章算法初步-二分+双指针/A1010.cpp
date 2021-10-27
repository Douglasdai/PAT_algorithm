/*
 * @Author: Douglas 
 * @Date: 2021-07-29 22:17:40 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-29 23:18:21
 */

#include<iostream>
#include<cstring>
using namespace std;
//radix 
//进制转换
//暴力超时 二分 边界和时间
char map[256];
typedef long long LL;
LL inf = (1LL << 63)-1;
void init(){
    for(char i='0';i<='9';i++){
        map[i] = i-'0';
    }
    for(char i='a';i<='z';i++){
        map[i] = i-'a'+10;
    }
}

LL turn(char a[],LL radix,LL t){
    int len = strlen(a);
    long long res=0;
    for(int i=0;i<len;i++){
        res =res*radix + map[a[i]]; 
        if(res<0 || res>t){
            return -1;
        }
    }
    return res;
}
int cmp(char N2[],LL radix,LL t){
    int len = strlen(N2);
    LL num = turn(N2,radix,t);
    if(num<0)return 1;
    if(t>num)return -1;
    else if(t==num)return 0;
    else return 1;
}

LL bin(char N2[],LL left,LL right ,LL t){
    LL mid;
    while(left<=right){
        mid = (left+right)/2;
        int flag = cmp(N2,mid,t);
        if(flag==0)return mid;
        else if(flag==-1)return left = mid+1;
        else return right =mid-1;
    }
    return -1;
}

int findMaxD(char N2[]){
    int ans=-1,len =strlen(N2);
    for(int i=0;i<len;i++){
        if(map[N2[i]]>ans){
            ans = map[N2[i]];
        }
    } 
    return ans+1;//进制底线 ans+1
}

char N1[15],N2[15],temp[15];
long long tag,radix;
int main(){
    init();
    // printf("%d",'a'-'0');
    scanf("%s%s%lld%lld",&N1,&N2,&tag,&radix);
    long long res,ans=2;
    if(tag!=1){
        //swap
        strncpy(temp,N2,15);
        strncpy(N1,temp,15);
        strncpy(N2,N1,15);
    }
    LL t = turn(N1,radix,inf);
    LL low = findMaxD(N2);
    LL high = max(low,t)+1;
    LL ans = bin(N2,low,high,t);
    if(ans==-1)printf("Impossible\n");
    else{
        printf("%lld\n",ans);
    }
    return 0;
    
}