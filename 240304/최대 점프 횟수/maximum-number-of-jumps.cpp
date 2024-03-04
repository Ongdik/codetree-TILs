#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001]{ 0 };
int dp[1001]{ 0 };
bool visited[1001]{ false };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[1] = 0;
    visited[1] = true;

    for (int i = 1; i < n; i++) {
        if (!visited[i]) break;
        int cnt = arr[i];
        if (cnt == 0) continue;
        for (int j = 1; j <= cnt; j++) {
            if (i + j > n) break;
            dp[i + j] = max(dp[i + j], dp[i] + 1);
            visited[i + j] = true;
        }
    }

    int ans = 1;
    for (int i = 1; i <= n; i++) ans = max(ans, dp[i]);
    cout << ans;


    return 0;
}