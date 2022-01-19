#include<bits/stdc++.h>
using namespace std;

int fib_recursion(int n){
    //Recursion_O(2^N)
    if(n==0 or n==1){
        return n;
    }
    int ans;
    ans = fib_recursion(n-1)+fib_recursion(n-2);
    return ans;
}

int fib_td_dp(int n, int dp[]){
    //top_down_O(N)
    if(n==0 or n==1){
        return n;
    }
    if(dp[n]!=0){
        return dp[n];
    }
    int ans;
    ans = fib_td_dp(n-1,dp)+fib_td_dp(n-2,dp);
    return dp[n]=ans;
}
int fib_bu(int n){
    int dp[100]={0};
    dp[1]=1;
    for(int i=2;i<=n;i++){
        dp[i]=dp[i-1]+dp[i-2];
    }
    return dp[n];

}

int fibSpaceOpt(int n){
    if(n==0 or n==1){
        return n;
    }
    int a=0;
    int b=1;
    int c;
    for(int i=2;i<=n;i++){
        c=a+b;
        //as only last two values are needed to be added
        a=b;
        b=c;

    }
    return c;
}

//reduced space cop. to O(1)

int main(){
    int n;
    cin>>n;
    int dp[100]={0};
    cout<<fib_bu(n);
    return 0;
}
