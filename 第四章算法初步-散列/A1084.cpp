#include<iostream>
#include<cstring>
using namespace std;

int main(){
    char str1[100],str2[100];
    //散列表
    bool HashTable[128] = {false};
    cin.getline(str1,100);
    cin.getline(str2,100);
    int len1 = strlen(str1);
    int len2 = strlen(str2);
    for(int i=0;i<len1;i++){
        int j;
        char c1,c2;
        for(int j=0;j<len2;j++){
            c1 = str1[i];
            c2 = str2[j];
            if(c1>='a' && c1<='z')c1-=32;//a-z 小写 转大写
            if(c2>='a' && c2<='z')c2-=32;
            if(c1==c2)break;
        }
        if(j ==len2 && HashTable[c1]==false){
            printf("%c",c1);
            HashTable[c1]==true;
        }
    }
    return 0;
}