/*
 * @Author: Douglas 
 * @Date: 2021-07-30 20:27:01 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-30 20:41:03
 */
//数一
#include<iostream>
using namespace std;
int n;
int countone(int a,int count){
    while(a!=0){
        int c = a%10;
        a/=10;
        if(c==1){
            count++;
        }
    }
    return count;
}
int main(){
    cin>>n;long sum=1;int ans=0;
    int left,right,now;
    while(n/sum !=0){
        left =n /(sum*10);
        now = n/sum%10;
        right = n%sum;
        if(now ==0)ans+=left*sum;
        else if(now==1)ans+=left*sum +right+1;
        else ans+=(left+1)*sum;
        sum*=10;
    }
    cout<<ans<<endl;
    // if(n<10)printf("1\n");
    // else{
    //     //遍历超时
    //     for(int i=10;i<=n;i++){
    //         int count=0;
    //         sum+=countone(i,count);
    //     }
    //     cout<<sum<<endl;
    // }
    return 0;
}