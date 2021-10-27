#include<cstdio>
#include<algorithm>
using namespace std;
//自己的方法
// int main(){
//     double max_1;char chr[3];double ans=1;
//     double a[3][3];
//     for(int i=0;i<3;i++){
//         scanf("%lf %lf %lf",&a[i][0],&a[i][1],&a[i][2]);
//         max_1 = a[i][0]>a[i][1] ? max(a[i][0],a[i][2]): max(a[i][1],a[i][2]);
//         if (max_1== a[i][0])chr[i] ='W';
//         else if(max_1== a[i][1])chr[i] ='T';
//         else chr[i]='L';
//         ans *=max_1;
//     }
//     for(int i=0;i<3;i++){
//         printf("%c ",chr[i]);
//     }
//     printf("%.2f",(ans*0.65-1)*2);
    
// }

//题解
char S[3] = {'W','T','L'};
int main(){
    double ans =1.0,tmp,a;
    int idx;
    for(int i=0;i<3;i++){
        tmp =0.0;
        for(int j=0;j<3;j++){
            scanf("%lf",&a);
            if(a>tmp){
                tmp= a;
                idx =j;
            }
        }
        ans *=tmp;
        printf("%c ",S[idx]);
    }
    printf("%.2f",2*(ans*0.65-1));
    return 0;
}