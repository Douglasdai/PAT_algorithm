#include<cstdio>
#include<cstring>
using namespace std;
//放弃了 算不动
//科学计数法
//自己要重写一遍
int main(){
    char input[10010];
    scanf("%s",&input);
    int len = strlen(input);
    // if(input[0]=='+')printf("+");
    if(input[0]=='-')printf("-");
    int pos =0;
    while(input[pos]!='E'){pos++;}

    int exp=0;
    for(int i=pos+2;i<len;i++){
        exp = exp*10+(input[i]-'0');
    }
    if (exp==0){
        for(int i=1;i<pos;i++)printf("%c",input[i]);
    }
    //指数为负
    if(input[pos+1]=='-'){
        printf("0.");
        for(int i=0;i<exp-1;i++){
            printf("0");
        }
        printf("%c",input[1]);
        for(int i=3;i<len;i++){
            printf("%c",input[i]);
        }
    }
    //为正
    else{
        for(int i=1;i<pos;i++){
            if(input[i]=='.')continue;
            printf("%c",input[i]);
            if(i==exp+2 && pos-3!=exp){
                printf(".");
            }
        }
        for(int i=0;i<exp-(pos-3);i++){
            printf("0");
        }
    }
    return 0;
}