/*
 * @Author: Douglas 
 * @Date: 2021-07-28 22:35:12 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-28 22:54:23
 */
//TODO
//string subtracion
#include<iostream>
#include<cstring>
using namespace std;
char str1[10010],str2[10010];
bool hasht[128];
int main(){
    int a=0;
    while(true){
        str1[a++] = getchar();
        if(str1[a-1]=='\n')break;
    }
    int len = a-1;
    int i=0;
    a=0;
    while(true){
        str2[a++] = getchar();
        if(str2[a-1]=='\n')break;
    }
    int len2 = strlen(str2);
    for(i=0;i<len2;i++){
        hasht[str2[i]] =true;
    }
    for(i=0;i<len;i++){
        if(hasht[str1[i]]==false){
            printf("%c",str1[i]);
        }
    }
    return 0;
}


