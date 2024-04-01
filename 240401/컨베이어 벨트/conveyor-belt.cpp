#include <iostream>
using namespace std;

int arr[3][201]{ 0 };
int n, t;

void rotation() {
    int cur = arr[1][1];
    int prev = cur;
    for (int i = 2; i <= n; i++) {
        prev = cur;
        cur = arr[1][i];
        arr[1][i] = prev;
    }
    prev = cur;
    cur = arr[2][n];
    arr[2][n] = prev;
    for (int i = n - 1; i >= 1; i--) {
        prev = cur;
        cur = arr[2][i];
        arr[2][i] = prev;
    }
    arr[1][1] = cur;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> t;

    for (int i = 1; i <= n; i++) {
        cin >> arr[1][i];
    }
    for (int i = n; i >= 1; i--) {
        cin >> arr[2][i];
    }

    while (t--) {
        rotation();
    }

    for (int i = 1; i <= n; i++) {
        cout << arr[1][i] << " ";
    }
    cout << "\n";
    for (int i = n; i >= 1; i--) {
        cout << arr[2][i] << " ";
    }


    return 0;
}