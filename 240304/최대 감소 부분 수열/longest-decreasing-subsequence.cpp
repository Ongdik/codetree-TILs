#include <iostream>
#include <algorithm>
using namespace std;

int n;
int arr[1001]{0};
int dp[1001]{0};

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;

    for (int i=1; i<=n; i++) {
        cin >> arr[i];
    }

    for (int i=1; i<=n; i++) {
        dp[i] = 1;
        for (int j=1; j<i; j++) {
            if (arr[i] < arr[j]) {
                dp[i] = max(dp[i], dp[j]+1);
            }
        }
    }

    int ans = dp[1];

    for (int i=2; i<=n; i++) {
        ans = max(ans, dp[i]);
    }

    cout << ans;

    
    return 0;
}