#include <bits/stdc++.h>
using namespace std;


long long int s[501][501],n,dp[501][501];

int main(){
    cin >> n;
    for(int i = 0;i < n;i++){
        for(int j = 0; j<i+1;j++){
            cin >> s[i][j];
        }
    }
    dp[0][0] = s[0][0];
    for(int i = 1;i<n;i++){
        for(int j = 0;j<i+1;j++){
            if(j == 0)dp[i][j] = dp[i-1][j] +s[i][j];
            else if (j == i)dp[i][j] = dp[i-1][j-1] + s[i][j];
            else dp[i][j] = max(dp[i-1][j] + s[i][j] , dp[i-1][j-1]+s[i][j]);
        }
    }
    long long int ret = 0;
    for(int i = 0;i < n;i++)ret = max(ret,dp[n-1][i]);
    cout << ret;

}
