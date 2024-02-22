#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int k, n;
vector<int> v;

void BT() {
    if (v.size() == n) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= k; i++) {
        v.push_back(i);
        BT();
        v.pop_back();
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> k >> n;

    BT();
    return 0;
}