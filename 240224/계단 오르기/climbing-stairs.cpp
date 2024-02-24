#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int dp[1001]{0,0,1,1,1,2};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i=5; i<=n; i++) {
        dp[i] = dp[i-3]+dp[i-2];
    }

    cout << dp[n];
    return 0;
}