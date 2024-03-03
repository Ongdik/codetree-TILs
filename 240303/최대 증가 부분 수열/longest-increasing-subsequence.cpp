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

    for (int i=1; i<=n; i++) cin >> arr[i];
    dp[1] = 1;

    for (int i=2; i<=n; i++) {
        if (arr[i] > arr[i-1]) {
            dp[i] = dp[i-1] + 1;
        }
        else {
            arr[i] = arr[i-1];
            dp[i] = dp[i-1];
        }
    }

    cout << dp[n];



    return 0;
}