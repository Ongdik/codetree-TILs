#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n;
vector<int> v;
int cnt = 0;

void BT() {
    if (v.size() == n) {
        for (int i = 0; i < n; i++) {
            int val = v[i];
            for (int j = i; j < i + val; j++) {
                if (j < n && val != v[j]) return;
            }
            i += val;
            if (i > n) return;
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