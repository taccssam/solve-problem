#include <bits/stdc++.h>
using namespace std;

int t,n,dp[41][2];

int main(){
    cin >>t;
    dp[0][0] = dp[1][1] = 1;
    dp[0][1] = dp[1][0] = 0;
    for(int i = 2;i<41;i++){
        dp[i][0] = dp[i-1][0] + dp[i-2][0];
        dp[i][1] = dp[i-1][1] + dp[i-2][1];

    }
    while(t--){
        cin >> n;
        cout <<dp[n][0] << ' ' << dp[n][1] <<'\n';
    }
}
