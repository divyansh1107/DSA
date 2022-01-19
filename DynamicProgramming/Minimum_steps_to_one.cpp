#include<bits/stdc++.h>
using namespace std;
//n->n/3,n/2,n-1;
// make n = 1 in min possible steps required

int minSteps_td(int n,int dp[]){
    //top_down time comp.O(N)

    if(n==1){
        return 0;
    }
    if(dp[n]!=0){
        return dp[n];
    }

    int op1,op2,op3;
    op1 = op2 =op3 = INT_MAX;
    if(n%3==0){
        op1= minSteps_td(n/3,dp) + 1;
    }
    if(n%2==0){
        op2= minSteps_td(n/2,dp) + 1;
    }
    op3= minSteps_td(n-1,dp) + 1;

    int ans = min(min(op1,op2),op3);
    return dp[n]=ans;
}

int minSetupsBU(int n){
    //Bottom Up Approach O(N)
    int dp[100] = {0};
    dp[1]=0;
    for(int i=2;i<=n;i++){
        int op1,op2,op3;
        op1=op2=op3=INT_MAX;
        if(n%3==0){
            op1=dp[i/3];
        }
        if(n%2==0){
            op2=dp[i/2];
        }
        op3=dp[i-1];
        dp[i]=min(min(op1,op2),op3)+1;
    }
    return dp[n];

}


int main(){
    int n;
    cin>>n;
    int dp[100]={0};
    cout<<minSteps_td(n,dp)<<endl;
    cout<<minSetupsBU(n);
    return 0;
}