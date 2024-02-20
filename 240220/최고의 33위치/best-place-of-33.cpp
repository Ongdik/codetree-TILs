#include <iostream>
#include <algorithm>
using namespace std;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int n;
    cin >> n;

    int arr[21][21]{0};

    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> arr[i][j];
        }
    }

    int ans = 0;

    for (int i=0; i<n-2; i++) {
        for (int j=0; j<n-2; j++) {
            int val = 0;
            val += arr[i][j]+arr[i][j+1]+arr[i][j+2];
            val += arr[i+1][j]+arr[i+1][j+1]+arr[i+1][j+2];
            val += arr[i+2][j]+arr[i+2][j+1]+arr[i+2][j+2];
            ans = max(ans, val);
        }
    }

    cout << ans;
    return 0;
}