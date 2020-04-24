#include <bits/stdc++.h>
using namespace std;

long long dp[11];
int n;

int main(){

    dp[1] = 1;
    dp[2] = 2;
    dp[3] = 4;
    for(int i = 4;i<11;i++){
        dp[i] = dp[i-1]+dp[i-2]+dp[i-3];
    }
    int t;
    cin >> t;
    for(t;t>0;t--){
        cin >>n;
        cout << dp[n]<<"\n";
    }
}
