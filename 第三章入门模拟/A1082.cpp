/*
 * @Author: Douglas 
 * @Date: 2021-07-15 14:22:20 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-15 15:01:53
 */

#include<iostream>
#include<cstring>
using namespace std;
//数字中文读法
//TODO 不会
int main(){
    char n[15];
    char danwei[5][5]={"Shi","Bai","Qian","Wan","Yi"};
    char num[10][5]={"ling","yi","er","san","si","wu","liu","qi","ba","jiu"};
    cin.getline(n,15);
    //复数处理
    int left=0,right = strlen(n)-1;
    if(n[0]=='-'){
        printf("Fu");
        left++;   
    }
    while(left+4<=right){
        right-=4;   //将right 每次左移4位，直到left 和right 在同一节
    }
    while(left<strlen(n)){
        bool flag =false;
        bool isPrint = false;
        while(left<=right){
            if(left>0 && n[left]=='0'){
                flag = true;
            }
            else{
                if(flag ==true){
                    printf(" ling");
                    flag = false;
                }
                if(left>0)printf(" ");
                printf("%s",num[n[left]-'0']);
                isPrint = true;
                if(left!=right){
                    printf(" %s",danwei[right-left-1]);
                }   
            }
            left++;
        }
        if(isPrint==true && right!=strlen(n)-1){
            printf(" %s",danwei[(strlen(n)-1-right)/4+2]);
        }
        right+=4;
    }
    return 0;
}