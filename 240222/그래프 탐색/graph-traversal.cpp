#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

vector<int> graph[1001];
bool visited[1001]{false};

int n,m;
int cnt = 0;

void dfs(int a) {
	if (visited[a]) return;

    visited[a] = true;
    cnt++;

	for (auto k : graph[a]) {
		dfs(k);
	}
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0; i<m; i++) {
        int u,v;
        cin >> u >> v;
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    dfs(1);
    cout << cnt-1;

    return 0;
}