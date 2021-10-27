/*
 * @Author: Douglas 
 * @Date: 2021-07-29 13:43:11 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-29 15:12:10
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
int n;
bool cmp(string a,string b){
    return a+b<b+a;
}
int main(){
    scanf("%d",&n);
    string str[10010];
    for(int i=0;i<n;i++){
        cin>>str[i];
    }
    sort(str,str+n,cmp);
    string ans ="";
    for(int i=0;i<n;i++){
        ans+=str[i];
    }
    while(ans.size()!=0 && ans[0] =='0'){
        ans.erase(ans.begin());
    }
    if(ans.size()==0)cout<<0;
    else cout<<ans;
    return 0;
}
