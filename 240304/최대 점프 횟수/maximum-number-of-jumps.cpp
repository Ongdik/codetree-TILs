#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001]{ 0 };
int dp[1001]{ 0 };

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    dp[1] = 0;

    for (int i = 1; i < n; i++) {
        int cnt = arr[i];
        if (cnt == 0) continue;
        bool check = false;
        for (int j = 1; j <= cnt; j++) {
            if (i + j > n) break;
            if (arr[i + j] != 0) {
                dp[i + j] = max(dp[i + j], dp[i] + 1);
                check = true;
            }
        }
        if (!check) break;
    }

    int ans = 1;
    for (int i=1; i<=n; i++) ans = max(ans, dp[i]);
    cout << ans;


    return 0;
}