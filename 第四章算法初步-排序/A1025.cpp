/*
 * @Author: Douglas 
 * @Date: 2021-07-15 23:20:52 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-15 23:23:50
 */

#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
//考场排序题
struct Student
{
    char id[15];
    int score;
    // int rank;//总排名
    int loc;//考场号
    int loc_rank;//考场排名

};

bool cmp(Student a,Student b){
    if(a.score!=b.score)return a.score>b.score;
    else return strcmp(a.id ,b.id)<0;
}

int main(){
    //考场
    int n,num;
    scanf("%d",&n);
    Student stu[30010];
    int count[n];
    for(int i=1;i<=n;i++){
        int k;//考场人数
        int loc = 1;
        scanf("%d",&k);
        for(int j=0;j<k;j++){
            scanf("%s %d",&stu[i].id,&stu[i].score);
            num++;
            stu[i].loc = i;
        }
        
        //考场内排名
        sort(stu+num-k,stu+num,cmp);
        stu[num-k].loc_rank = 1;
        for(int j=num-k+1;j<num;j++){
            if(stu[j].score ==stu[j-1].score)
                stu[j].loc_rank = stu[j-1].loc_rank;
            else stu[j].loc_rank = j+1-(num-k);
        }

    }
    printf("%d\n",num);
    sort(stu,stu+num,cmp);
    int r=1;
    for(int i=0;i<num;i++){
        if(i>0 && stu[i].score !=stu[i-1].score){
            r =i+1;
        }
        printf("%s ",stu[i].id);
        printf("%d %d %d\n",r,stu[i].loc,stu[i].loc_rank);
    }
    return 0;
}