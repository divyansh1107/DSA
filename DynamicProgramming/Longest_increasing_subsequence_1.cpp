#include<bits/stdc++.h>
using namespace std;

int main (){
    int n;
    cin>>n;
    int a[n];
    for(int i=0;i<n;i++){
        cin>>a[i];
    }
    int dp[n];
    for(int i=0;i<n;i++){
        dp[i]=1;
        for(int j=0;j<i;j++){
            if(a[j]<a[i]) {dp[i]= max(dp[i],dp[j]+1);}

        }


    }
    for(int i=0;i<n;i++){
        cout<<dp[i]<<" ";
    }
}