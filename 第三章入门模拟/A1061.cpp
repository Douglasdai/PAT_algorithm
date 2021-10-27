/*
 * @Author: Douglas 
 * @Date: 2021-07-14 14:49:07 
 * @Last Modified by:   Douglas 
 * @Last Modified time: 2021-07-14 14:49:07 
 */

#include<cstdio>
#include<cstring>
#include<string>
#include<iostream>
using namespace std;
//字符串处理
//太麻烦了 
int main(){
    char str[4][65];
    int a,b,c=0;
    char day2[7]={'A','B','C','D','E','F','G'};
    char day[7][5] ={"MON","TUE","WED","THU","FRI","SAT","SUN"};
    char time[24] ={'0','1','2','3','4','5','6','7','8','9','A','B','C','D','E','F','G'
                    ,'H','I','J','K','L','M','N'};
    // gets(str[0]);
    // gets(str[1]);
    // gets(str[2]);
    // gets(str[3]);
    scanf("%s\n%s\n%s\n%s",str[0],str[1],str[2],str[3]);
    int sum = min(strlen(str[0]),strlen(str[1]));
    int i=0;
    // cout<<sum<<endl;
    for(i=0;i<sum;i++){
        if(str[0][i] == str[1][i] && str[0][i]>='A' &&str[0][i] <='G'){
           printf("%s ",day[str[0][i]-'A']);
           break;
        }
    }
    for(i++;i<sum;i++){
        if(str[0][i] == str[1][i] ){
            if(str[0][i]>='0' &&str[0][i]<='9'){
                printf("%02d:",str[0][i]-'0');break;
            }
            else if(str[0][i]>='A' &&str[0][i]<='N'){
                printf("%02d:",str[0][i]-'A'+10);break;
            }
        }
    }
    sum = min(strlen(str[2]),strlen(str[3]));
    //分钟
    for(int i=0;i<sum;i++){
        if(str[2][i]==str[3][i]){
            if((str[2][i]>='A' && str[2][i]<='Z') || (str[2][i]>='a' && str[2][i]<='z')){
                printf("%02d",i);break;
            }  
        }
    }
    return 0;
}
