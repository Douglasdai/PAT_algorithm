#include<iostream>
#include<algorithm>
using namespace std;
struct person
{
    char name[15];
    char id[15];
    int score;
}M,F,temp;
void init(){
    M.score= 101;
    F.score =-1;
}
int main(){
    init();
    int n;
    char gender;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
         scanf("%s %c %s %d",&temp.name,&gender,&temp.id,&temp.score);
        if(gender=='M' && temp.score<M.score){
            M=temp;
        }
        else if(gender =='F' && temp.score>F.score){
            F = temp;
        }

    }
    if(F.score==-1)printf("Absent\n");
    else printf("%s %s\n",F.name,F.id);
    if(M.score==101)printf("Absent\n");
    else printf("%s %s\n",M.name,M.id);
    if(F.score==-1 ||M.score==101)printf("NA\n");
    else printf("%d\n",F.score-M.score);
    return 0;
}

//输出男生最低分 女性最高分 和相差值
//使用结构体
//只能得20分 最后一个得不到
// struct student
// {
//     char name[20];
//     char sex;
//     char id[20];
//     int score;
// };
// //降序排序
// bool cmp(student a,student b){
//     return a.score>b.score;
// }
// int main(){
//     int n;
//     scanf("%d",&n);
//     student stu[n];
//     for(int i=0;i<n;i++){
//         scanf("%s %c %s %d",&stu[i].name,&stu[i].sex,&stu[i].id,&stu[i].score);
//     }
//     sort(stu,stu+n,cmp);int m=0,fe=0;
//     for(int i=0;i<n;i++){
//         //遍历出男性女性等
//         if(stu[i].sex=='M')m++;
//         else fe++;
//     }
//     // printf("%d %d",m,fe);
//     if(m!=0 && fe!=0){
//         student me[m],f[fe];
//         int b=0;
//         while(b<n){
//             int i=0,j=0;
//             if(stu[b].sex=='M')
//             {   me[i]=stu[b];
//                 i++;
//             }
//             else {
//                 f[j] = stu[b];j++;
//             }
//             b++;
//         }
//         printf("%s %s\n",f[fe-1].name,f[fe-1].id);
//         printf("%s %s\n",me[0].name,me[0].id);
//         printf("%d",f[fe-1].score-me[0].score);

//     }
//     else if(m ==0){
//         //全女
//         printf("%s %s\n",stu[0].name,stu[0].id);
//         printf("Absent\nNA\n");
//     }
//     else if(fe==0){
//         //全男
//         printf("Absent\n");
//         printf("%s %s\nNA\n",stu[n-1].name,stu[n-1].id);
//     }
//     return 0;
// }
