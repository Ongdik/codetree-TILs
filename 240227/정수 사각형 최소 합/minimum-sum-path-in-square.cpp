#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[101][101]{ 0 };
int dp[101][101]{ 0 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> arr[i][j];
        }
    }

    dp[1][n] = arr[1][n];

    for (int i=n-1; i>=1; i--) {
        dp[1][i] = arr[1][i]+dp[1][i+1];
    }
    for (int i=2; i<=n; i++) {
        dp[i][n] = arr[i][n] + dp[i-1][n];
    }

    for (int i=2; i<=n; i++) {
        for (int j=n-1; j>=1; j--) {
            dp[i][j] = min (dp[i][j+1], dp[i-1][j]) + arr[i][j];
        }
    }

    cout << dp[n][1];

    return 0;
}