#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[46]{0,1,1,2};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=4; i<=n; i++) {
        dp[i] = dp[i-1] + dp[i-2];
    }

    cout << dp[n];


    return 0;
}