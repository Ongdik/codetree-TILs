#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

bool cmp(pair<int, int> a, pair<int, int> b) {
    if (a.second == b.second) return a.first > b.first;
    return a.second < b.second;
}

int n, m;
int graph[51][51]{ 0 };
bool visited[51][51]{ false };
vector<int> v;
vector<pair<int, int>> ans;

int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };

int cnt = 0;


void dfs(int x, int y, int height) {
    if (visited[y][x] || graph[y][x] <= height) return;

    visited[y][x] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];

        if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
            if (!visited[ny][nx] && graph[ny][nx] > height) {
                dfs(nx, ny, height);
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    int maxHeight = 0;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
            maxHeight = max(maxHeight, graph[i][j]);
        }
    }

    for (int i = 1; i < maxHeight; i++) {
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                dfs(k, j, i);
                if (cnt != 0) v.push_back(cnt);
                cnt = 0;
            }
        }
        ans.push_back({ i, v.size() });
        while (!v.empty()) {
            v.pop_back();
        }
        for (int j = 0; j < n; j++) {
            for (int k = 0; k < m; k++) {
                visited[j][k] = false;
            }
        }
    }

    sort(ans.begin(), ans.end(), cmp);
    cout << ans[ans.size() - 1].first << " " << ans[ans.size() - 1].second;


    return 0;
}