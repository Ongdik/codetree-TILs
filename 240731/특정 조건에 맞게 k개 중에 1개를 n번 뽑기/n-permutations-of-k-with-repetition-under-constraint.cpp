#include <iostream>
#include <vector>
using namespace std;

int k, n;
vector<int> v;
int cnt[9]{ 0 };

void bt() {
    if (v.size() == n) {
        for (int i : v) {
            cout << i << " ";
        }
        cout << "\n";
        return;
    }

    for (int i = 1; i <= k; i++) {
        cnt[i]++;
        
        if (cnt[i] == 3) {
            cnt[i]--;
            continue;
        }

        v.push_back(i);
        bt();
        cnt[v[v.size() - 1]]--;
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