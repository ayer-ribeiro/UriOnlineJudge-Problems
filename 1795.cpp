#include <stdio.h>
#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>


using namespace std;


long long mat[100][100];
int N;
long long valor(int n, int k){
    if(k>n){
        mat[n][k] = 0;
        return 0;
    }
    if(mat[n][k] != 0) return mat[n][k];
    if(n == 0)
        if(k ==0) {
            mat[n][k] = 1;
            return mat[n][k];
        }else {
            mat[n][k] = 0;
            return mat[n][k];
        }
    if(n == 1)
        if(k == 0 || k == 1) {
            mat[n][k] = 1;
            return mat[n][k];
        }else {
            mat[n][k] = 0;
            return mat[n][k];

        }
    if(k!=0){
        mat[n][k] = valor(n-1,k) + valor(n-1,k-1) + valor(n-1,k+1);
        return mat[n][k];

    }else{

        mat[n][k] = valor(n-1,k) + 2*valor(n-1,k+1);
        return mat[n][k];
    }

}
int main(){
    long long soma = 0;
    for(int i =0;i<=20;i++)
        for(int j =0;j<=20;j++)
            mat[i][j] = 0;
    scanf("%d",&N);
    for(int K =0 ;K<=20;K++)soma = soma + 2*valor(N,K);
    //soma = soma + mat[N][0];
    cout << soma-mat[N][0] <<"\n";


    return 0;
}
