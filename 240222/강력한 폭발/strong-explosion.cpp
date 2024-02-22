#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
int arr[21][21]{ 0 };

vector<int> v;
vector<pair<int, int>> coordinate;

int ans = 0;
int cnt = 0;

//int dx1[4]{ 0,0,0,0 };
//int dy1[4]{ -2,-1,1,2 };

int dx2[4]{ 0,0,-1,1 };
int dy2[4]{ -1,1,0,0 };

int dx3[4]{ -1,1,-1,1 };
int dy3[4]{ -1,-1,1,1 };

void first(int x, int y) {
    for (int i = -2; i <= 2; i++) {
        int nextY = y + i;
        if (nextY >= 0 && nextY < n) {
            arr[nextY][x] = 1;
        }
    }
}

void second(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx2[i];
        int nextY = y + dy2[i];

        if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < n) {
            arr[nextY][nextX] = 1;
        }
    }
}

void third(int x, int y) {
    for (int i = 0; i < 4; i++) {
        int nextX = x + dx3[i];
        int nextY = y + dy3[i];

        if (nextX >= 0 && nextY >= 0 && nextX < n && nextY < n) {
            arr[nextY][nextX] = 1;
        }
    }
}

int checkCnt() {
    int tmpCnt = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (arr[i][j] == 1) tmpCnt++;
        }
    }
    return tmpCnt++;
}

void reset() {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            arr[i][j] = 0;
        }
    }
    for (int i = 0; i < coordinate.size(); i++) {
        int x = coordinate[i].second;
        int y = coordinate[i].first;

        arr[y][x] = 1;
    }
}

void BT() {
    if (v.size() == cnt) {
        for (int i = 0; i < cnt; i++) {
            if (v[i] == 1) {
                first(coordinate[i].second, coordinate[i].first);
            }
            else if (v[i] == 2) {
                second(coordinate[i].second, coordinate[i].first);
            }
            else if (v[i] == 3) {
                third(coordinate[i].second, coordinate[i].first);
            }
        }

        int res = checkCnt();
        ans = max(ans, res);

        reset();
        return;
    }

    for (int i = 0; i < n; i++) {
        for (int j = 1; j <= 3; j++) {
            v.push_back(j);
            BT();
            v.pop_back();
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
            if (arr[i][j] == 1) { 
                coordinate.push_back({ i,j });
                cnt++;
            }
        }
    }

    BT();

    cout << ans;

    return 0;
}