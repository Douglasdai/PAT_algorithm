/*
 * @Author: Douglas 
 * @Date: 2021-07-14 00:31:35 
 * @Last Modified by:   Douglas 
 * @Last Modified time: 2021-07-14 00:31:35 
 */
#include<cstdio>
using namespace std;
int main(){
    int n;
    long long a,b,sum;
    scanf("%d",&n);
    for (int i=0;i<n;i++){
        scanf("%lld%lld%lld",&a,&b,&sum);
        bool flag; 
        long long res = a+b;

        if(a<0 && b<0 &&res>=0)flag = false;
        else if(a>0 &&b>0 && res<0) flag = true;
        else if(res>sum)flag =true;
        else flag = false;
        if(flag){
            printf("Case#%d:true",n+1);
        }
        else{
            printf("Case#%d:false",n+1);
        }
    }
    return 0;
}