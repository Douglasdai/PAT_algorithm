/*
 * @Author: Douglas 
 * @Date: 2021-07-14 13:50:06 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-14 13:57:24
 */

#include<cstdio>
using namespace std;
// A+B 哈利珀特
// 货币换算
int main(){
    int a[3],b[3],c[3];
    scanf("%d.%d.%d %d.%d.%d",&a[0],&a[1],&a[2],&b[0],&b[1],&b[2]);
    int carry =0;
    c[2] =(a[2]+b[2])%29;
    carry = (a[2]+b[2])/29;
    c[1] =(a[1]+b[1]+carry)%17;
    carry = (a[1]+b[1]+carry)/17;
    c[0] = a[0]+b[0]+carry;
    printf("%d.%d.%d",c[0],c[1],c[2]);
    return 0;

}

// 18分 注意有无进两位 所以用取余和 除法
// int main(){
//     int a,b,c;
//     int e,f,g;
//     int x=0,y=0;//,z=0;
//     long z=0;
//     scanf("%d.%d.%d %d.%d.%d",&a,&b,&c,&e,&f,&g);
//     int sum=0,flag=0;
//     // sum = (c+g)/29;
//     // x = (c+g)%29;
//     // y = (b+f+sum)%17;
//     // sum = (b+f+sum)/17;
//     // z = a+e+sum;

//     // if(c+g>29){sum++;x = c+g-29;}
//     // else{
//     //     x = c+g;
//     // }
//     // if(b+f+sum>17){flag++;
//     //     y = b+f+sum-17;
//     // }
//     // else{
//     //     y = b+f+sum;
//     // }
//     // z = a+e+flag;
//     printf("%d.%d.%d",z,y,x);
//     return 0;
// }