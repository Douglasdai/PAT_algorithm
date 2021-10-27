/*
 * @Author: Douglas 
 * @Date: 2021-07-16 23:16:34 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-16 23:27:06
 */

//到底买不买
#include<cstdio>
#include<algorithm>
#include<cstring>
//TODO 未检验
using namespace std;
int hashtable[80] = {0};
int main(){
    char str[1010],str2[1010];
    scanf("%s",&str);int len = strlen(str);
    for(int i=0;i<len;i++){
        hashtable[int(str[i]-'0')]++; 
    }
    scanf("%s",&str2);
    len = strlen(str2);
    bool flag =true;
    for(int i=0;i<len;i++){
        hashtable[str2[i]]--;
        if(hashtable[str2[i]]==0){
            flag =false; 
        }
    }
    if(flag){
        printf("Yes ");
    }else {
        printf("No ");
    }
    int num=0;
    for(int i=0;i<80;i++){
        num +=hashtable[i];
    }
    printf("%d",num);
    //计数
    return 0;
}