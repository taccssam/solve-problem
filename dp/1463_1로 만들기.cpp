#include <bits/stdc++.h>
using namespace std;

int n,dp[1000001];


int main(){

    cin >> n;
    for(int i = 2;i<=n;i++){
        dp[i] = 987654321;
        if(i%3 == 0){
            dp[i] = min(dp[i],dp[i/3]+1);
        }
        if(i%2 == 0){
            dp[i] = min(dp[i],dp[i/2]+1);

        }
        dp[i] = min(dp[i],dp[i-1]+1);

    }
    cout << dp[n];

}
