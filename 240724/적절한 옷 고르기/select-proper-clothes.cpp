#include <iostream>
#include <climits>
#include <algorithm>
#include <cstdlib>

#define MAX_N 200
#define MAX_M 200

using namespace std;

int dp[MAX_M + 1][MAX_N + 1];

int n, m;

int s[MAX_N + 1], e[MAX_N + 1], v[MAX_N + 1];

int main() {
    cin >> n >> m;

    for (int j = 1; j <= n; j++)
        cin >> s[j] >> e[j] >> v[j];

    for (int i = 1; i <= m; i++)
        for (int j = 1; j <= n; j++)
            dp[i][j] = INT_MIN;

    for (int j = 1; j <= n; j++)
        if (s[j] == 1)
            dp[1][j] = 0;

    for (int i = 2; i <= m; i++) {

        for (int j = 1; j <= n; j++) {
            for (int k = 1; k <= n; k++) {

                if (s[k] <= i - 1 && i - 1 <= e[k] && s[j] <= i && i <= e[j])
                    dp[i][j] = max(dp[i][j], dp[i - 1][k] + abs(v[j] - v[k]));
            }
        }
    }

    int ans = 0;

    for (int j = 1; j <= n; j++)
        ans = max(ans, dp[m][j]);

    cout << ans;
}