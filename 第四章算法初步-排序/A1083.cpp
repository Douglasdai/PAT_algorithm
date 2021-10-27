/*
 * @Author: Douglas 
 * @Date: 2021-07-16 17:19:34 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-16 17:38:23
 */
#include<iostream>
#include<algorithm>
using namespace std;

struct Student
{
    char name[11];
    char id[11];
    int score;
}stu[100010];
bool cmp(Student a,Student b){
    if(a.score!=b.score)return a.score>b.score;
}

int main(){
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++){
        scanf("%s%s%d",&stu[i].name,&stu[i].id,&stu[i].score);
    }
    int mi,ma;
    scanf("%d%d",&mi,&ma);
    sort(stu,stu+n,cmp);
    int count =0;
    for(int i=0;i<n;i++){
        if(stu[i].score >=mi && stu[i].score <=ma){
            printf("%s %s\n",stu[i].name,stu[i].id);
            count++;
        }
    }
    if(count ==0){
        printf("NONE\n");
    }
    return 0;
}

