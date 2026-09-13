#include <cstdio>
#include <iostream>
#include <bits/stdc++.h>
using namespace std;

int pao[100000];
int m, n;

bool tomada(int x){
    int sum = 0;

for(int i = 0; i < m; i++){
    sum += pao[i]/x;
}
    return (sum >= n);
} 
int findx(){

    int start = 0;
    int end = 10000;
    int mid;
    int ans;
    while(start <= end){
        mid = (start + end)/2;
        if(tomada(mid)){
            ans = mid;
            start  = mid +1;
        }
        else{
            end = mid -1;
        }
    }
    return ans;

}

int main(){
    scanf("%d %d", &m, &n);

    for(int i = 0; i < m; i++){
        scanf("%d", &pao[i]);
    }
    printf("%d", findx());
}