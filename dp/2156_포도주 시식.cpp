#include <bits/stdc++.h>
using namespace std;

long long int n,dp[10001],ju[10001];
int main(){
    cin >> n;
    for(int i = 1;i <= n;i++)cin >> ju[i];
    dp[0] = 0;
    dp[1] = ju[1];
    dp[2] = ju[1] + ju[2];
    long long int ret = 0;
    ret = max(dp[1],dp[2]);
    for(int i = 3;i <= n;i++){
        dp[i] = max(dp[i-2] +ju[i],dp[i-3] + ju[i-1] +ju[i]);
        dp[i] = max(dp[i-1],dp[i]);
    }
    cout << dp[n];

}
