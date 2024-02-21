#include <iostream>
#include <algorithm>
using namespace std;

int arr[101][101]{0};
int n,m;
int ans=0;

void solve(){
    for (int i=0; i<n; i++) {
        int cnt1=0;
        int cnt2=0;
        int val1=arr[i][0];
        int val2=arr[0][i];

        for (int j=0; j<n; j++) {
            if (val1 == arr[i][j]) {
                cnt1++;
                if (cnt1 == m) {
                    ans++;
                    break;
                }
                
            }
            else {
                cnt1=1;
                val1=arr[i][j];
            }

        }

        for (int j=0; j<n; j++) {
            if (val2 == arr[j][i]) {
                cnt2++;
                if (cnt2==m) {
                    ans++;
                    break;
                }
            }
            else {
                cnt2=1;
                val2=arr[j][i];
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin>>n>>m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin>>arr[i][j];
        }
    }

    solve();

    cout << ans;

    return 0;
}