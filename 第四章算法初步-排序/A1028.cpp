/*
 * @Author: Douglas 
 * @Date: 2021-07-16 13:35:42 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-16 13:55:47
 */
#include<iostream>
#include<cstring>
#include<algorithm>
using namespace std;
struct Student
{
    int id;
    char name[8];
    int score;
}stu[100000];
bool cmp1(Student a,Student b){
    return a.id<b.id;
}
bool cmp2(Student a,Student b){
    if(a.name!=b.name)return strcmp(a.name,b.name)<0;
    else return a.id<b.id;
}
bool cmp3(Student a,Student b){
    if(a.score!=b.score)return a.score<b.score;
    else return a.id<b.id;
}
int main(){
    int n,c;
    scanf("%d%d",&n,&c);
    for(int i=0;i<n;i++){
        scanf("%d%s%d",&stu[i].id,&stu[i].name,&stu[i].score);
    }
    //三种情况
    if(c==1){
        sort(stu,stu+n,cmp1);
    }
    else if(c==2){
        sort(stu,stu+n,cmp2);
    }
    else{
        sort(stu,stu+n,cmp3);
    }
    for(int i=0;i<n;i++){
        printf("%d %s %d\n",stu[i].id,stu[i].name,stu[i].score);
    }
    return 0;
}
