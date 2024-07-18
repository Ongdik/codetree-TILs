#include <iostream>
#include <vector>
using namespace std;

int arr[101][101]{0};
int dx[4]{0,0,-1,1};
int dy[4]{-1,1,0,0};
int n;
vector<int> ans;

void move(int x, int y, int curNum) {

    for (int i=0; i<4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 1 && ny >= 1 && nx <= n && ny <=n ) {
            if (curNum < arr[ny][nx]) {
                ans.push_back(arr[ny][nx]);
                move(nx, ny, arr[ny][nx]);
                break;
            }
        }
    }
    return;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    int r, c;
    cin >> n >> r >> c;

    for (int i=1; i<=n; i++) {
        for (int j=1; j<=n; j++) {
            cin >> arr[i][j];
        }
    }

    ans.push_back(arr[r][c]);

    move(c, r, arr[r][c]);

    for (int i : ans) {
        cout << i << " ";
    }

    return 0;
}