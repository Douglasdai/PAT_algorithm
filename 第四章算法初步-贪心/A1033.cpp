/*
 * @Author: Douglas 
 * @Date: 2021-07-29 00:27:02 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-29 00:40:19
 */
#include<iostream>
#include<algorithm>
using namespace std;
//贪心策略
int cmax,distan,per,num,dis;
double price;
bool flag;
int maxn=510;
const int INF =1000000000;
struct station
{
    double price;
    int dis;
};
bool cmp(station a,station b){
    return a.dis<b.dis;
}
int main(){
    scanf("%d%d%d%d",&cmax,&distan,&per,&num);
    station st[maxn];
    double res=0.0;
    for(int i=0;i<num;i++){
        scanf("%f%d",&st[i].price,&st[i].dis);
    }
    st[num].dis=distan;
    st[num].price=0;
    sort(st,st+num,cmp);
    if(st[0].dis!=0){
        printf("The maximum travel distance =0.00\n");
    }
    else{
        int now=0;
        double ans =0,nowTank=0,MAX = cmax*per;
        while(now<num){
            int k=-1;
            double priceMin = INF;
            for(int i=now+1;i<=num && st[i-1].dis-st[now].dis<=MAX;i++){
                if(st[i].price<priceMin){
                    priceMin = st[i].price;
                    k=i;
                    if(priceMin<st[now].price){
                        break;
                    }
                }
            }
            if (k==-1)break;
            double need=(st[k].dis-st[now].dis)/per;
            if(priceMin<st[now].price){
                if(nowTank<need){
                    ans+=(need-nowTank)*st[now].price;
                    nowTank=0;
                }else{
                    nowTank-=need;
                }
            }else{
                ans+=(cmax-nowTank)*st[now].price;
                nowTank=cmax-need;
            }
            now =k;
        }
        if(now==num){
            printf("%.2f",ans);
        }else{
            printf("The maximum travel distance =%.2f\n",st[now].dis+MAX);
        }
    }
    return 0;
}
//1 结构体
/*
0 的时候 取一部分 或取满
排序规则

看看够不够到下一个站

在这个会不会便宜 并且到下一个

最终能不能到终点

到不了
。。。





*/