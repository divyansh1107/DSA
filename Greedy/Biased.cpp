#include<bits/stdc++.h>
#include<cmath>
#include<cstring>
int abs(int i,int j){
    if(i-j>0){
        return i-j;

    }
    else{
        return j;
    }
}
using namespace std;
int main(){
    int arr[100000]={0};
    int t;
    cin>>t;
    while(t--){
        memset(arr,0,sizeof arr);
        string name;
        int n,rank;
        cin>>n;
        for(int i=0;i<n;i++){
            cin>>name>>rank;
            arr[rank]++;
        }
        int actual_rank = 1;
        int sum = 0;
        for(int i=1;i<n;i++){
            while(arr[i]){
                sum+=abs(actual_rank,i);
                arr[i]--;
                actual_rank++;

            }
        }
        cout<<sum<<endl;
    }
}