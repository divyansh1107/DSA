#include<bits/stdc++.h>
using namespace std;

int ladders_topdown(int n,int k,int dp[]){
    if(n==0){
        return 1;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ways = 0;
    for(int i=1;i<=k;i++){
        if(n-i>=0){
            ways += ladders_topdown(n-i,k,dp);
        }
    }
    return dp[n]=ways;
}
int ladders_buttomup(int n, int k){
    int dp[100]={0};
    dp[0]=1;
    for(int i=1;i<=n;i++){
        dp[i]=0;
        for(int j=1;j<=k;j++){
            if(i-j>=0) {
                dp[i] += dp[i - j];
            }
        }
    }
    return dp[n];
}
int ladders_optimised(int n,int k){
    //Sliding window
    int dp[100]={0};

    dp[0] = dp[1] =1;
    for(int i=2;i<=k;i++){
        dp[i]= 2*dp[i-1];
    }
    for(int i=k+1;i<=n;i++){
        dp[i] = 2*dp[i-1]-dp[i-k-1];
    }
    for(int i=0;i<=n;i++){
        cout<<dp[i]<<", ";
    }
    return dp[n];

}
int main(){
    int n,k;
    int dp[100]={0};
    cin>>n>>k;
    cout<<ladders_optimised(n,k);
}