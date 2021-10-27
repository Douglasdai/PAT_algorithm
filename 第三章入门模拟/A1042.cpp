#include<cstdio>
//模拟扑克牌进行 数位转换
const int N =54;
char map[5] = {'S','H','C','D','J'};
int start[N+1],end[N+1],next[N+1];
int main(){
    int K;
    scanf("%d",&K);
    for(int i=0;i<=N;i++){
        start[i] = i;
    }
    for(int i=1;i<=N;i++){
        scanf("%d",&next[i]);
    }
    for(int i=0;i<K;i++){
        for(int j=0;j<N;j++){
            end[next[j]] = start[i];
        }
    }
    //循环结束 输出
    for (int i=1;i<=N;i++){
        start[i] =start[i];
    }
    for(int i=1;i<=N;i++){
        if(i!=1) printf(" ");
        start[i]--;
        printf("%c%d",map[start[i]]/13,start[i]%13+1);
    }
    return 0;
}