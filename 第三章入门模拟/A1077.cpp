#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
//求公共后缀
//题解
int n ,minLen = 256,ans =0;
char s[100][256];
int main(){
    scanf("%d",&n);
    getchar();
    for(int i=0;i<n;i++){
        cin.getline(s[i],256);
        int len =strlen(s[i]);
        if(len<minLen)minLen =len;
        for(int j=0;j<len/2;j++){
            char temp = s[i][j];
            s[i][j]=s[i][len-j-1];
            s[i][len-j-1] = temp;
        }
    }
    for(int i=0;i<minLen;i++){
        char c = s[0][1];
        bool same = true;
        for(int j=1;j<n;j++){
        if(c!=s[j][i]){
            same =false;
            break;
        }
        }
        if(same) ans++;
        else break;
    }
    if(ans){
        for(int i= ans-1;i>=0;i--){
            printf("%c",s[0][i]);
        }
    }
    else{
        printf("nai");
    }
    return 0;
}


// int main(){
//     int n;
//     cin>>n;
//     getchar();
//     string str[n];
//     char ch[n][257];
//     string res="";
//     bool flag = false;
//     for(int i=0;i<n;i++){
//         cin.getline(ch[i],257);
//         str[i] = ch[i];
//     }
//     //检索 从后到前检索
//     //颠倒过来
//     int minl =str[0].size();
//     for(int i=0;i<n;i++){
//         if(str[i].size()<minl)minl = str[i].size();
//     }
//     for(int i=0;i<n;i++){
//         reverse(str[i].begin(),str[i].end());
//     }
//     // printf("%s",str[1]);
//     for(int j=0;j<minl;j++)
//     {   int count=0;
//         for(int i=0;i<n;i++){
//             if(str[0][j] == str[i][j])
//                count++;
//             else break;
//         }
//         if(count ==n){res+=str[0][j];flag = true;}
//         else break;
//     }
//     if(flag ==false){
//         cout<<"nai"<<endl;
//     }
//     else{
//         reverse(res.begin(),res.end());
//         cout<<res<<endl;
//     }
//     return 0;
// }