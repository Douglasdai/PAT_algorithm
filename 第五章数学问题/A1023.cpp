/*
 * @Author: Douglas 
 * @Date: 2021-07-31 15:30:04 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-31 19:01:21
 */
//大数运算

#include<cstdio>
#include<cmath>
#include<string.h>
using namespace std;

struct bign
{
    int d[21];
    int len;
    bign(){
        memset(d,0,sizeof(d));
        len=0;
    }
};
//倒序
bign change(char str[]){
    bign a;
    a.len = strlen(str);
    for(int i=0;i<a.len;i++){
        a.d[i] = str[a.len-i-1] -'0';
    }
    return a;
}
bign multi(bign a,int b){
    bign c;
    int carry =0;
    for(int i=0;i<a.len;i++){
        int temp = a.d[i]*b+carry;
        c.d[c.len++] = temp%10;
        carry = temp/10;
    }
    while (carry!=0)
    {
        c.d[c.len++] =carry%10;
        carry/=10;
    }
    return c;
}
bool Judge(bign a,bign b){
    if(a.len !=b.len)return false;
    int count[10] ={0};
    for(int i=0;i<a.len;i++){
        count[a.d[i]]++;
        count[b.d[i]]--;
    }
    for(int i=0;i<10;i++){
        if(count[i]!=0){
            return false;
        }
    }
    return true;
}
void print(bign a){
    for(int i=a.len-1;i>=0;i--){
        printf("%d",a.d[i]);
    }
}
int main(){
    char str[21];
    scanf("%s",str);
    bign a = change(str);
    bign mul =multi(a,2);
    if(Judge(a,mul))printf("Yes\n");
    else printf("No\n");
    print(mul);
    return 0;
}