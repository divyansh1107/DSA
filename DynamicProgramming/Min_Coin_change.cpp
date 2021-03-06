#include<bits/stdc++.h>
using namespace std;

int minCoins(int n,int coins[],int T,int dp[]){
    if(n==0){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans=INT_MAX;
    for(int i=0;i<T;i++){
        if(n-coins[i]>=0){
            int subprob = minCoins(n-coins[i],coins,T,dp);
            ans = min(ans,subprob+1);
        }
    }
    dp[n]=ans;
    return dp[n];

}
//Bottom up approach O[N.T]
int minCoinBU(int N,int coins[],int T){
    int dp[100]={0};
    for(int n=1;n<=N;n++){
        dp[n]=INT_MAX;
        for(int i=0;i<T;i++){
            if(n-coins[i]>=0){
                int subprob = dp[n-coins[i]];
                dp[n]=min(dp[n],subprob+1);
            }
        }

    }
    return dp[N];

}

int main(){
    int N;
    int coins[]={1,7,10};
    int dp[100]={0};
    int T = sizeof(coins)/sizeof(int);
    cin>>N;


    cout<<minCoins(N,coins,T,dp)<<endl;
    cout<<minCoinBU(N,coins,T);

    return 0;

}