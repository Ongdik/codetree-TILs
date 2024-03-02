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

    dp[1][1] = arr[1][1];

    for (int i = 2; i <= n; i++) {
        dp[1][i] = min(arr[1][i], dp[1][i - 1]);
        dp[i][1] = min(arr[i][1], dp[i - 1][1]);
    }

    for (int i = 2; i <= n; i++) {
        for (int j = 2; j <= n; j++) {
            dp[i][j] = min(max(dp[i - 1][j], dp[i][j - 1]), arr[i][j]);
        }
    }

    cout << dp[n][n];

    return 0;
}