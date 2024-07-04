#include <iostream>
#include <vector>
using namespace std;

int main() {
    int n, val, s, e;
    vector<int> v; vector<int> tmp; vector<int> ans;
    cin >> n;
    
    for(int i=0; i<n; i++) {
        cin >> val;
        v.push_back(val);
    }

    cin >> s >> e;

    for (int i=0; i<v.size(); i++) {
        if (i >= s-1 && i <= e-1) continue;
        tmp.push_back(v[i]);
    }

    cin >> s >> e;
    for (int i=0; i<tmp.size(); i++) {
        if (i >= s-1 &&  i <= e-1) continue;
        ans.push_back(tmp[i]);
    }

    cout << ans.size() << "\n";
    for (int i:ans) cout << i << "\n";

    return 0;
}