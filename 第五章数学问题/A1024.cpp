/*
 * @Author: Douglas 
 * @Date: 2021-07-31 19:01:33 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-31 19:30:40
 */

#include<stdio.h>
#include<string.h>
#include<algorithm>
#include<iostream>
using namespace std;
struct bign{
    char d[21];
    int len;
    bign(){
    memset(d,0,sizeof(d));
    len=0;

}
};

bool Judge(bign a){
    for(int i=0;i<a.len/2;i++){
        if(a.d[i]!=a.d[a.len-1-i])return false;
    }
    return true;
}
bign change(bign a){
    for(int i=0;i<a.len/2;i++){
        swap(a.d[i],a.d[a.len-1-i]);
    }
    return a;
}
bign convert(char str[]){
    bign a;
    a.len = strlen(str);
    for(int i=0;i<a.len;i++){
        a.d[i] = str[a.len-i-1] -'0';
    }
    return a;
}
bign add(bign a,bign b){
    bign c;
    int carry =0;
    for(int i=0;i<a.len;i++){
        int temp = a.d[i]+b.d[i]+carry;
        c.d[c.len++] = temp%10;
        carry = temp/10;
    }
    while (carry!=0)
    {
        c.d[c.len++] =carry%10;
        carry/=10;
    }
    cout<<"add"<<endl;
    return c;

}

int main(){
    int m;char n[11];
    scanf("%s%d",&n,&m);
    bign a = convert(n);
    bool flag;
    for(int i=0;i<m;i++){
        bign b = change(a);        
        a = add(a,b);
        if(Judge(a)){
            flag =true;
            for(int i=a.len-1;i>=0;i--){
                printf("%d",a.d[i]);
             }
            printf("\n%d\n",i+1);
            break;
        }
    }
    if(!flag){
        for(int i=a.len-1;i>=0;i--){
                printf("%d",a.d[i]);
             }
        printf("\n%d\n",m);
    }
    return 0;
}