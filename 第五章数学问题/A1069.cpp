/*
 * @Author: Douglas 
 * @Date: 2021-07-30 16:33:16 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-30 20:00:05
 */

#include<iostream>
#include<algorithm>
using namespace std;
int n[4],m[4];
int count1 =0;
bool cmp(int a, int b){
    if (a!=b)return a>b;
}
int* to_array(int a,int b[]){
    int len = a;
    for(int i=0;i<4;i++){
        b[i] = len%10;
        len /=10;
    }
    return b;
}
int to_int(int b[]){
    int len =0;
    for(int i=3;i>=0;i--){
        len =len *10 +b[i];
    }
    return len;
}
int main(){
    int a;
    scanf("%d",&a);
    to_array(a,n);
    to_array(a,m);
    sort(n,n+4);
    sort(m,m+4,cmp);
    while(to_int(n) !=to_int(m) ){
        printf("%04d-%04d=%04d\n",to_int(n),to_int(m),to_int(n)-to_int(m));
        int res =to_int(n)-to_int(m);
        to_array(res,n);
        to_array(res,m);
        sort(n,n+4);
        sort(m,m+4,cmp);
        if(to_int(n)-to_int(m)==6174){
            printf("%04d-%04d=%04d\n",to_int(n),to_int(m),to_int(n)-to_int(m));
            break;
        }
    }
    if(to_int(n)==to_int(m)){
        printf("%04d-%04d=%04d\n",to_int(n),to_int(m),to_int(n)-to_int(m));
    }
    return 0;

}