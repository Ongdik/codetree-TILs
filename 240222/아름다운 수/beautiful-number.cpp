#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int cnt = 0;

bool check(int idx, int num) {
    int val = v[idx];

    for (int i = idx; i < idx + num; i++) {
        if (i >= n) return false;
        if (val != v[i]) return false;
    }

    return true;
}

void BT() {
    if (v.size() == n) {
        for (int i = 0; i < n; i++) {
            int tmp = v[i];
            if (!check(i, tmp)) return;
            int nextI = i + tmp - 1;
        }
        cnt++;
        return;
    }

    for (int i = 1; i <= 4; i++) {
        v.push_back(i);
        BT();
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    BT();
    cout << cnt;

    return 0;
}