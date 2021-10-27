#include<cstdio>
using namespace std;
int main(){
    int n,b1;
    double b2;
    scanf("%d",&n);
    double a[1111] ={0};
    for(int i=0;i<n;i++){
        scanf("%d %lf",&b1,&b2);
        a[b1] += b2;
    }
    int m;
    scanf("%d",&m);
    for(int i=0;i<m;i++){
        scanf("%d %lf",&b1,&b2);
        a[b1] += b2;
    }
    int count=0;
    for(int i=0;i<1111;i++){
        if(a[i]!=0)count++;
    }
    printf("%d ",count);
    for(int i=1110;i>=0;i--){
        if(a[i]!=0)
        {printf("%d %.1f ",i,a[i]);
        }
    }
}