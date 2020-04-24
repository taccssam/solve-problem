#include <bits/stdc++.h>
using namespace std;

int n,dp[301],s[301];

int main(){

    cin >> n;
    for(int i = 1;i<= n;i++){
            cin >> s[i];
    }

    dp[0] = 0;
    dp[1] = s[1];
    dp[2] = s[1]+s[2];
    for(int  i = 3;i<= n;i++){
        dp[i] = max(dp[i-2], dp[i-3] + s[i-1]) +s[i];
    }
    cout << dp[n];

}
