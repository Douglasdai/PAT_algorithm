/*
 * @Author: Douglas 
 * @Date: 2021-07-28 22:23:42 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-28 22:35:08
 */

#include<cstdio>
#include<iostream>
using namespace std;
//未
//be unique
int n,in;
int hashtable[1010] = {0};
int main(){
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d",&in);
        hashtable[in]++;
    }
    int num=1;
    for(int i=1;i<=1000;i++){
        if(hashtable[i]==1){
            printf("%d\n",i);
            break;
        }
        num++;
        if(num==1000){
            printf("None");
        }
    } 
    return 0;
}
