// #include<iostream>
// #include<cstdio>
// #include<cstring>
// #include<algorithm>
// using namespace std;
//不超时的
#include <iostream>
#include <map>
#include <vector>
#include <algorithm>
using namespace std;
struct node {
    string name;
    int status, month, time, day, hour, minute;
};
bool cmp(node a, node b) {
    return a.name != b.name ? a.name < b.name : a.time < b.time;
}
double billFromZero(node call, int *rate) {
    double total = rate[call.hour] * call.minute + rate[24] * 60 * call.day;
    for (int i = 0; i < call.hour; i++)
        total += rate[i] * 60;
    return total / 100.0;
}
int main() {
    int rate[25] = {0}, n;
    for (int i = 0; i < 24; i++) {
        scanf("%d", &rate[i]);
        rate[24] += rate[i];
    }
    scanf("%d", &n);
    vector<node> data(n);
    for (int i = 0; i < n; i++) {
        cin >> data[i].name;
        scanf("%d:%d:%d:%d", &data[i].month, &data[i].day, &data[i].hour, &data[i].minute);
        string temp;
        cin >> temp;
        data[i].status = (temp == "on-line") ? 1 : 0;
        data[i].time = data[i].day * 24 * 60 + data[i].hour * 60 + data[i].minute;
    }
    sort(data.begin(), data.end(), cmp);
    map<string, vector<node> > custom;
    for (int i = 1; i < n; i++) {
        if (data[i].name == data[i - 1].name && data[i - 1].status == 1 && data[i].status == 0) {
            custom[data[i - 1].name].push_back(data[i - 1]);
            custom[data[i].name].push_back(data[i]);
        }
    }
    for (auto it : custom) {
        vector<node> temp = it.second;
        cout << it.first;
        printf(" %02d\n", temp[0].month);
        double total = 0.0;
        for (int i = 1; i < temp.size(); i += 2) {
            double t = billFromZero(temp[i], rate) - billFromZero(temp[i - 1], rate);
            printf("%02d:%02d:%02d %02d:%02d:%02d %d $%.2f\n", temp[i - 1].day, temp[i - 1].hour, temp[i - 1].minute, temp[i].day, temp[i].hour, temp[i].minute, temp[i].time - temp[i - 1].time, t);
            total += t;
        }
        printf("Total amount: $%.2f\n", total);
    }
    return 0;
}

//超时的
// //电话资费问题
// //太麻烦 直接放弃 重新做
// const int maxn =1010;
// int toll[25];
// struct Record
// {
//     char name[25];
//     int month,dd,hh,mm;
//     bool status;
// }rec[maxn],temp;
// bool cmp(Record a ,Record b){
//     int s = strcmp(a.name,b.name);
//     if(s!=0)return s<0;
//     else if (a.month != b.month)return a.month <b.month;
//     else if (a.dd!= b.dd)return a.dd<b.dd;
//     else if (a.hh!= b.hh)return a.hh<b.hh;
//     else return a.mm<b.mm;
// }
// void get_ans(int on,int off,int &time,int&money){
//     temp =rec[on];
//     while(temp.dd <rec[off].dd || temp.hh <rec[off].hh|| temp.mm <rec[off].mm){
//         time++;
//         money+=toll[temp.hh];
//         if(temp.mm>=60){
//             temp.mm=0;
//             temp.hh++;
//         }
//         if(temp.hh>=24){
//             temp.hh=0;
//             temp.dd++;
//         }
//     }
// }

// int main(){
//     for(int i=0;i<24;i++){
//         scanf("%d",&toll[i]);
//     }
//     int n;
//     scanf("%d",&n);
//     char line[10];
//     for(int i=0;i<n;i++){
//         scanf("%s",&rec[i].name);
//         scanf("%d:%d:%d:%d",&rec[i].month,&rec[i].dd,&rec[i].hh,&rec[i].mm);
//         scanf("%s",&line);
//         if(strcmp(line,"on-line")==0){
//             rec[i].status = true;
//         }
//         else{
//             rec[i].status = false;
//         }
//     }
//     sort(rec,rec+n,cmp);
//     int on =0,off,next;
//     while(on<n){
//         int needPrint=0;
//         next =on;
//         while(next<n && strcmp(rec[next].name,rec[on].name)==0){
//             if(needPrint ==0 && rec[next].status ==true){
//                 needPrint =1;
//             }else if(needPrint ==1 && rec[next].status ==false){
//                 needPrint =2;
//             }
//             next++;
//         }
//         if(needPrint<2){
//             on =next;
//             continue;
//         }
//         int Allmoney =0;
//         printf("%s %02d\n",rec[on].name,rec[on].month);
//         while (on <next)
//         {
//             while (on<next-1 && !(rec[on].status ==true &&rec[on+1].status==false))
//             {
//                 on++;
//             }
//             off = on+1;
//             if(off ==next){
//                 on =next;break;
//             }
//             printf("%02d:%02d:%02d ",rec[on].dd,rec[on].hh,rec[on].mm);
//             printf("%02d:%02d:%02d ",rec[off].dd,rec[off].hh,rec[off].mm);
//             int time=0,money =0;
//             get_ans(on,off,time,money);
//             Allmoney +=money;
//             printf("%d $%.2f\n",time,money/100.0);
//             on = off+1;
//         }
//         printf("Total amount: $%.2f\n",Allmoney/100.0);
//     }
//     return 0;
// }

