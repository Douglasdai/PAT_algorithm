//最长回文子串
//字符串解决方法
#include<iostream>
#include<cstdio>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
typedef long long ll;
const ll MOD = 10000000007;
const ll P = 100000019;
const ll MAXN = 1010;
ll powp[MAXN],H1[MAXN],H2[MAXN];

void init(){
    powp[0] = 1;
    for(int i=1;i<MAXN;i++){
        powp[i] = (powp[i-1]*P)%MOD;
    }
}
//cal Hash
//cal 
void calH(ll H[],string &str){
    H[0] = str[0];
    for(int i=1;i<str.length();i++){
        H[i] = (H[i-1]*P+str[i]) %MOD;
    }
}

int calSingleSubH(ll H[],int i,int j){
    if(i==0)return H[j];
    return ((H[i]-H[i-1]*powp[j-i+1])%MOD+MOD)%MOD;
}
int binarySearch(int l,int r,int len,int i,int isEven){
    while (l<r)
    {
        int mid = (l+r)/2;
        int H1L=  i-mid+isEven,H1R = 1;
        int H2L= len-1-(i+mid),H2R = len-1-(i+isEven);
        int hashL = calSingleSubH(H1,H1L,H1R);
        int hashR = calSingleSubH(H2,H2L,H2R);
        if(hashL!=hashR)r= mid;
        else l = mid+1;
    }
    return l-1;
}
int main(){
    init();
    string str;
    getline(cin,str);
    calH(H1,str);
    reverse(str.begin(),str.end());
    calH(H2,str);
    int ans =0;
    //奇回文
    for(int i=0;i<str.length();i++){
        int maxLen = min(i,(int)str.length()-1-i)+1;
        int k =binarySearch(0,maxLen,str.length(),1,0);
        ans = max(ans,k*2+1);
    }
    for(int i=0;i<str.length();i++){
        int maxLen = min(i+1,(int)str.length()-1-i)+1;
        int k  = binarySearch(0,maxLen,str.length(),i,1);
        ans = max(ans,k*2);
    }
    printf("%d\n",ans);
    return 0;
}