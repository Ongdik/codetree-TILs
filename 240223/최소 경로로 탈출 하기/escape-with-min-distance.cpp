#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int n,m;
int graph[101][101]{0};
bool visited[101][101]{false};

int dx[4]{1,-1,0,0};
int dy[4]{0,0,1,-1};

bool check = true;

void bfs(int x, int y) {
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y},0});

    while(!q.empty()) {
        int nextX = q.front().first.first;
        int nextY = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (visited[nextY][nextX] || graph[nextY][nextX] == 0) continue;
        visited[nextY][nextX] = true;
        if (nextX == m && nextY == n) {
            cout << dist;
            check = true;
            return;
        }

        for (int i=0; i<4; i++) {
            int nx = nextX+dx[i];
            int ny = nextY+dy[i];

            if (nx>0 && ny>0 && nx<=m && ny<=n) {
                if (!visited[ny][nx] && graph[ny][nx]!=0) q.push({{nx,ny},dist+1});
            }
        }
    }

}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=1; i<=n; i++) {
        for (int j=1; j<=m; j++) {
            cin >> graph[i][j];
        }
    }

    bfs(1,1);

    if (!check) cout << -1;

    return 0;
}