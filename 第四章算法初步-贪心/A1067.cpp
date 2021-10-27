/*
 * @Author: Douglas 
 * @Date: 2021-07-29 12:17:25 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-29 13:18:06
 */

#include<iostream>
using namespace std;
//排序交换
int n;
int sor[100010]={0};
int main(){
    scanf("%d",&n);
    int res=0;
    int left= n-1,num;
    for(int i=0;i<n;i++){
        scanf("%d",&num);
        //存放个数字 当前所处位置的编号
        sor[num]= i;
        if(num ==i && num!=0){
            left--;
        }
    }
    int k=1;
    while(left>0){
        if(sor[0]==0){
            while (k<n)
            {
                if(sor[k]!=k){
                    swap(sor[0],sor[k]);
                    res++;
                    break;
                }
            k++;
            }
        }
        while(sor[0]!=0){
            swap(sor[0],sor[sor[0]]);
            res++;
            left--;
        }
    }
    printf("%d",res);
    //下标移动
    //要和下标一样
    //不一样移动
    return 0;
}