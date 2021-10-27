/*
 * @Author: Douglas 
 * @Date: 2021-07-14 13:23:46 
 * @Last Modified by:   Douglas 
 * @Last Modified time: 2021-07-14 13:23:46 
 */

#include<cstdio>
using namespace std;
//火星颜色
//16进制转换
int main(){
    int a,b,c;
    char res[13]={'0','1','2','3','4','5','6','7','8','9','A','B','C'};
    scanf("%d%d%d",&a,&b,&c);
    printf("#");
    printf("%c%c",res[a/13],res[a%13]);
    printf("%c%c",res[b/13],res[b%13]);
    printf("%c%c",res[c/13],res[c%13]);
    return 0;
}