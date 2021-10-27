#include<iostream>
using namespace std;

int main(){
    int n;
    cin>>n;
    char s[n][11],pass[n][11];
    for(int i=0;i<n;i++){
        scanf("%s %s",&s[i],&pass[i]);
    }
    bool flag[n] = {false};
    for(int i=0;i<n;i++){
        for(int j=0;j<11;j++){
            if( pass[i][j] == '1'){pass[i][j] = '@';flag[i] = true;}
            else if(pass[i][j]=='0'){pass[i][j]='%';flag[i]= true;}
            else if(pass[i][j]=='l') {pass[i][j]='L';flag[i]=true;}
            else if(pass[i][j]=='O'){pass[i][j]='o';flag[i]=true;}
        }
    }
    //替换完成
    int count=0;
    for(int i=0;i<n;i++){
        if(flag[i]==true)count++;
    }
    
    if(count==0){
        if(n==1){
            printf("There is 1 account and no account is modified\n");
        }
        else{
            printf("There are %d accounts and no account is modified\n",n);
        }
    }
    else{
        printf("%d\n",count);
        for(int i=0;i<n;i++){
        if(flag[i]==true)
            printf("%s %s\n",s[i],pass[i]);
    }
    }
    return 0;
}