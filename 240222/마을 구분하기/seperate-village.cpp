#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int graph[26][26]{ 0 };
bool visited[26][26]{ false };
int n;
vector<int> v;

int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };

int cnt = 0;

void dfs(int x, int y) {
    if (visited[y][x] || graph[y][x] == 0) return;

    visited[y][x] = true;
    cnt++;

    for (int i = 0; i < 4; i++) {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if (nx >= 0 && ny >= 0 && nx < n && ny < n) {
            if (!visited[ny][nx] && graph[ny][nx] != 0) {
                dfs(nx, ny);
            }
        }
    }
}



int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            dfs(j, i);
            if (cnt != 0) v.push_back(cnt);
            cnt = 0;
        }
        
    }
    sort(v.begin(), v.end());
    cout << v.size() << "\n";
    for (int i : v) {
        cout << i << "\n";
    }

    return 0;
}