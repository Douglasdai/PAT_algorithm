/*
 * @Author: Douglas 
 * @Date: 2021-07-14 16:20:51 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-14 16:57:12
 */
#include<iostream>
#include<cstring>
using namespace std;

int main(){
    int sum=0,num=0;
    string n;
    cin>>n;
    for(int i=0;i<n.size();i++){
        sum +=n[i]-'0';
    }
    int a[100]={-1};
    char dict[10][6] ={"zero","one","two","three","four","five","six","seven","eight","nine"};
    if(sum==0){
        printf("%s",dict[0]);
    }
    else{
        while(sum!=0){
            a[num++] = sum%10;
            sum/=10;
        }
    }
    for(num--;num>=0;num--){
        printf("%s",dict[a[num]]);
        if(num!=0)printf(" ");
    }
    
    return 0;
}
//另一种方法
// #include<iostream>
// #include<string>
// #include<sstream>
// using namespace std;
// int main(){
//     string s1;
//     cin>>s1;
//     long long sum = 0;
//     for(int i=0;i<s1.size();i++){
//         sum +=(s1[i]-'0');
//     }
//     //cout<<sum<<endl;
//     //算完了
//     string word[10] = {"zero","one","two","three","four","five","six","seven","eight","nine"};
//     int n,count=0,num =sum;
//     stringstream ss;ss<<num;
//     string s2 = ss.str();
//     string ans;
//     for(int i=0;i<s2.length()-1;i++){
//         ans+=word[int(s2[i]-'0')]+" ";
//     }
//     ans+=word[int(s2[s2.length()-1]-'0')];
//     cout<<ans<<endl;
//     return 0;
    
// }