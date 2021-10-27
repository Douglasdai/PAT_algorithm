#include<cstdio>
// #include<math.h>
//图形题 hello world
//规律 n1 n3 =(N+2)/3 向下取整 所以n2 = N+2 -n1 -n3
int main(){
    char u[81];
    scanf("%s",&u);
    int N=0;
    while(u[N]!='\0'){
        N++;
    }
    // printf("%d",N);
    int n1,n2,n3=(N+2)/3;n1 =n3;
    n2 = N+2-n1-n3;
    char ans[n1][n2];
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            ans[i][j]=' ';
        }
    }
    int pos=0;
    for(int i=0;i<n1;i++){
        ans[i][0] = u[pos++];
    }
    for(int i=1;i<n2;i++){
        ans[n1-1][i] =u[pos++];
    }
    for(int i=n1-2;i>=0;i--){
        ans[i][n2-1] = u[pos++];
    }
    for(int i=0;i<n1;i++){
        for(int j=0;j<n2;j++){
            printf("%c",ans[i][j]);
        }
        printf("\n");
    }
    return 0;
}