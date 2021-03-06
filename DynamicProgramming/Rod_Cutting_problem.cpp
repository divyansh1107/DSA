#include<bits/stdc++.h>
using namespace std;

//Recursive Solution
int max_profit(int prices[],int n){
    if(n<=0){
        return 0;
    }
    int ans=INT_MIN;
    for(int i=0;i<n;i++){
        int cut=i+1;
        int current_ans = prices[i]+max_profit(prices,n-cut);
        ans=max(ans,current_ans);
    }
    return ans;
}
int max_profit_dp(int *price, int n){
    int dp[n+1];
    dp[0]=0;

    for(int len=1;len<=n;len++){
        int ans = INT_MIN;
        for(int i=0;i<len;i++){
            int cut=i+1;
            int current_ans=price[i]+dp[len-cut];
            ans=max(ans,current_ans);

        }
        dp[len]=ans;

    }
    return dp[n];
}

int main(){
    int price[]={1,5,8,9,10,17,17,20};
    int n=sizeof(price)/sizeof(int);
    cout<<max_profit_dp(price,n);
    return 0;
}