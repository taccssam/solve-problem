#include <bits/stdc++.h>
using namespace std;

long long n,dp[91];

int main(){
    cin >> n;
    dp[1] = dp[2] = 1;
    for(int i = 3;i < 91;i++){
        dp[i] = dp[i-1] + dp[i-2];

    }
    cout << dp[n];



}
