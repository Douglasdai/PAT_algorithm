#include<cstdio>
using namespace std;
struct Poly
{
    int exp;//指数
    double cof;//系数
}Poly[1001];
// const int MAXN =1111;
//多项式相乘
int main(){
    int n,b1;
    double b2;
    // Poly Poly[MAXN];
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%d %lf",&Poly[i].exp,&Poly[i].cof);
    }
    //存放结果
    double ans[2001]={0};
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %lf",&b1,&b2);
        for(int j=0;j<n;j++){
            ans[Poly[j].exp+b1] +=(b2*Poly[j].cof);
        }
    }
    int count1=0;
    for(int i =0;i<2001;i++){
        if(ans[i]!=0.0)count1++;
    }
    printf("%d",count1);
    for(int i=2000;i>=0;i--){
        if(ans[i]!=0.0){
            printf(" %d %.1f",i,ans[i]);
        }
    }
    return 0;
}