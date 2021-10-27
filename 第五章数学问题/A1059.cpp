/*
 * @Author: Douglas 
 * @Date: 2021-07-31 14:55:24 
 * @Last Modified by: Douglas
 * @Last Modified time: 2021-07-31 15:29:56
 */

//素数因素
#include<cstdio>
#include<cmath>
#include <iostream>
using namespace std;


 
const int max_n = 100010;
 
bool is_prime(int n){
	if(n == 1) return false;
	int sqr = (int) sqrt(1.0*n);
	for(int i = 2; i <= sqr ;i++){
		if(n % i == 0) return false;
	}
	return true;
}
 
int prime[max_n], pnum = 0;
 
void Find_prime(){
	for(int i =1; i <= max_n;i++){
		if(is_prime(i) == true){
			prime[pnum++] = i;
		} 
	}
} 
 
struct factor{
	int x,cnt;
} fac[10];
 
int main(){
	Find_prime();
	int n, num =0;
	cin>>n;
	if(n == 1) cout<<"1=1";
	else{
		cout<<n<<"=";
		int sqr = (int)sqrt(1.0 * n);
		for(int i = 0;prime[i] <= sqr ; i++){
			if(n % prime[i] == 0){
				fac[num].x = prime[i];
				fac[num].cnt = 0;
				while(n % prime[i] == 0){
					fac[num].cnt++;
					n /= prime[i];
				}
				num++;	
			}
			if(n == 1) break;
		}
		if(n != 1){
			fac[num].x = n;
			fac[num++].cnt = 1;
		}
		for(int i = 0; i < num; i++){
			if(i > 0 ) cout<<"*";
			cout<<fac[i].x;
			if(fac[i].cnt > 1) cout<<"^"<<fac[i].cnt;
		}
	}
	return 0;
}
// int n;
// int prime[1000];
// bool isPrime(int a){
//     if(a==1)return false;
//     for(int i=2;i<=sqrt(a*1.0);i++){
//         if(a%i==0)return false;
//     }
//     return true;
// }
// void init(){
//     //素数表
//     int i=0;
//     for(int j=1;j<100010;j++){
//         if(isPrime(j)==true){
//             prime[i++]=j;
//         }
//     }
// }

// int main(){
//     init();
//     int n;int count[1000]={0},j=0;
//     scanf("%d",&n);int m=n;
//     if(n==1){printf("1");}
//     else{
//        for(int i=0;i<1000 &&n!=1;i++){
//            if(n%prime[i]==0)j++;
//             while (n%prime[i]==0)
//             {   count[i]++;
//                 n/=prime[i];
//             }
//         } 
//     for(int i=0;i<1000;i++){
//         if(count[i]==0){
//             continue;
//         }
//         else{
//         printf("%d",prime[i]);
//         if(count[i]>1){
//             printf("^%d",count[i]);
//         }
//         j--;
//         if(j>0)printf("*");
//         }
//     }
//     }
//     return 0;
// }
