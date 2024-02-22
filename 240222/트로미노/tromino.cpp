#include <iostream>
#include <algorithm>
using namespace std;

int n, m;
int arr[201][201]{ 0 };

int ans = 0;

void solve1(int x, int y) {
    int up = y - 1;
    int down = y + 1;
    int right = x + 1;
    int left = x - 1;

    if (up >= 0) {
        if (left >= 0) {
            int tmp = arr[y][x] + arr[up][x] + arr[y][left];
            ans = max(ans, tmp);
        }

        if (right <= m) {
            int tmp = arr[y][x] + arr[up][x] + arr[y][right];
            ans = max(ans, tmp);
        }
    }

    if (down <= n) {
        if (left >= 0) {
            int tmp = arr[y][x] + arr[down][x] + arr[y][left];
            ans = max(ans, tmp);
        }

        if (right <= m) {
            int tmp = arr[y][x] + arr[down][x] + arr[y][right];
            ans = max(ans, tmp);
        }
    }
}

void solve2(int x, int y) {
    int up = y - 1;
    int down = y + 1;
    int right = x + 1;
    int left = x - 1;

    if (up >= 0 && down <= n) {
        int tmp = arr[y][x] + arr[up][x] + arr[down][x];
        ans = max(ans, tmp);
    }

    if (left >= 0 && right <= m) {
        int tmp = arr[y][x] + arr[y][left] + arr[y][right];
        ans = max(ans, tmp);
    }
}

// 중간 기준으로 위 -> 왼쪽 오른쪽
// 중간 기준으로 아래 -> 왼쪽 오른쪽

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);


    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            solve1(j, i);
            solve2(j, i);
        }
    }
    cout << ans;
}