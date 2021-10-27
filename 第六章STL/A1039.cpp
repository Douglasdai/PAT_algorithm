/*
 * @Author: Douglas 
 * @Date: 2021-07-31 20:02:43 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-31 20:42:00
 */

//只能用hash
//map string 不可行 超时
#include<cstdio>
#include<cstring>
#include<vector>
#include<algorithm>
using namespace std;
const int N =40010;
const int M = 26*26*26*10+1;
vector<int> selectCoures[M];

int getID(char name[]){
    int id=0;
    for(int i=0;i<3;i++){
        id = id*26+(name[i]-'A');
    }
    id =id*10+(name[3]-'0');
    return id;
}

int main(){
    char name[5];
    int n,k;
    scanf("%d%d",&n,&k);
    for(int i=0;i<k;i++){
        int course,x;
        scanf("%d%d",&course,&x);
        for(int j=0;j<x;j++){
            scanf("%s",name);
            int id = getID(name);
        selectCoures[id].push_back(course);
        }
        
    }
    for(int i=0;i<n;i++){
        scanf("%s",name);
        int id = getID(name);
        sort(selectCoures[id].begin(),selectCoures[id].end());
        printf("%s %d",name,selectCoures[id].size());
        for(int j=0;j<selectCoures[id].size();j++){
            printf(" %d",selectCoures[id][j]);
        }
        printf("\n");
    }
    return 0;
}
