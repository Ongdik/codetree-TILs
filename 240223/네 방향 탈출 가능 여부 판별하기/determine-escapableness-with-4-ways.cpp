#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int graph[101][101]{ 0 };
bool visited[101][101]{ 0 };
int n, m;
int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };
bool check = false;

void bfs(int x, int y) {
    queue<pair<int, int>> q;
    q.push({ x,y });

    while (!q.empty()) {
        int nextX = q.front().first;
        int nextY = q.front().second;
        q.pop();

        if (visited[nextY][nextX] || graph[nextY][nextX] == 0) continue;
        visited[nextY][nextX] = true;
        if (nextY == n-1 && nextX == m-1) check = true;

        for (int i = 0; i < 4; i++) {
            int nx = nextX + dx[i];
            int ny = nextY + dy[i];

            if (nx >= 0 && ny >= 0 && nx < m && ny < n) {
                if (!visited[ny][nx] && graph[ny][nx] != 0) q.push({ nx,ny });
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> graph[i][j];
        }
    }

    bfs(0, 0);
    if (check) cout << 1;
    else cout << 0;

    return 0;
}