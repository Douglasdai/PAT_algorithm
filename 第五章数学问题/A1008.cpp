/*
 * @Author: Douglas 
 * @Date: 2021-07-30 20:17:35 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-30 20:26:27
 */

//电梯问题
#include<iostream>
using namespace std;
int main(){
    int now=0,to=0,sum=0;
    int n;
    cin>>n;
    sum=n*5;
    for(int i=0;i<n;i++){
        scanf("%d",&to);
        if(to-now>0){
            sum+=(to-now)*6;
        }else{
            sum+=(now-to)*4;
        }
        now =to;
    }
    cout<<sum<<endl;
    return 0;
}