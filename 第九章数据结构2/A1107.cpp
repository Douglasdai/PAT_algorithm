//并查集
//N个人 如果两人任意活动相同处于同一网络 求N个人形成了多少个社交网络
#include<cstdio>
#include<algorithm>
using namespace std;
const int N = 1010;
int father[N]; 
int isRoot[N] ={0};
int course[N] ={0};
int findFather(int x){
    int a = x;
    while (x!=father[x])
    {
        x=  father[x];
    }
    //路精压缩
    while(a!=father[a]){
        int z = a;
        a  =father[a];
        father[z] = x;
    }
    return x;
}
void Union(int a,int b){
    int faA = findFather(a);
    int faB = findFather(b);
    if(faA!=faB){
        father[faA] = faB;
    }
}
void init(int n){
    for(int i=1;i<=n;i++){
        father[i] = i;
        isRoot[i] = false;
    }
}
bool cmp(int a,int b){
    return a>b;
}
int main(){
    int n,k,h;
    scanf("%d",&n);
    init(n);
    for(int i=1;i<=n;i++){
        scanf("%d:",&k);
        for(int j=0;j<k;j++){
            scanf("%d",&h);
            if(course[h] ==0){
                course[h] = 1;
            }
            Union(i,findFather(course[h]));
        }
    }
    for(int i=1;i<=n;i++){
        isRoot[findFather(i)]++;//人数+1
    }
    int ans=0;
    for(int i=1;i<=n;i++){
        if(isRoot[i]!=0){
            ans++;//只统计 isroot 不为 0
        }
    }
    printf("%d\n",ans);
    sort(isRoot+1,isRoot+n+1,cmp);
    for(int i=1;i<=ans;i++){
        printf("%d",isRoot[i]);//输出每个集合人数
        if(i<ans)printf(" ");
    }
    return 0;
}