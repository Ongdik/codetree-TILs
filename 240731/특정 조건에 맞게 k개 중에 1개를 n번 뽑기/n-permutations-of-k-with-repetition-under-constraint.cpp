#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> v;

void bt() {
    if (v.size() == n) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= k; i++) {
        int idx = v.size();
        if (v.size() >= 2) {
            if (v[idx - 2] == i && v[idx - 1] == i) {
                continue;
            }
        }
        v.push_back(i);
        bt();
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;
    bt();

    return 0;
}