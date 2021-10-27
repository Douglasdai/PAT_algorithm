/*
 * @Author: Douglas 
 * @Date: 2021-07-30 00:30:25 
 * @Last Modified by:   Douglas 
 * @Last Modified time: 2021-07-30 00:30:25 
 */

//几个pat
#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int maxn = 100010;
const int Mod = 1000000007;
char str[maxn];
int leftNumP[maxn] = {0};
int main(){
    cin>>str;
    int len = strlen(str);
    for(int i=0;i<len;i++){
        if(i>0){
            leftNumP[i] = leftNumP[i-1];
        }
        if(str[i]=='P'){
            leftNumP[i]++;
        }
    }
    int ans = 0,right = 0;
    for(int i=len-1;i>=0;i--){
        if(str[i]=='T'){
            right++;
        }else if(str[i]=='A'){
            ans = (ans+leftNumP[i]*right) %Mod;
        }    
    }
    printf("%d",ans);
    return 0;
}