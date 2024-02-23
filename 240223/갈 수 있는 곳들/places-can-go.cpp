#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int graph[101][101]{0};
bool visited[101][101]{false};
int n, m;
int cnt = 0;
int dx[4]{1,-1,0,0,};
int dy[4]{0,0,1,-1};

void bfs(int x, int y) {
    queue<pair<int,int>> q;
    q.push({x,y});

    while(!q.empty()) {
        int nextX = q.front().first;
        int nextY = q.front().second;
        q.pop();

        if (visited[nextY][nextX] || graph[nextY][nextX]==1) continue;
        visited[nextY][nextX] = true;
        cnt++;

        for (int i=0; i<4; i++) {
            int nx = nextX+dx[i];
            int ny = nextY+dy[i];

            if (nx>=0 && ny>=0 && nx<n && ny<n) {
                if (!visited[ny][nx] && graph[ny][nx]!=1) q.push({nx,ny});
            }
        }
    }
}


int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> m;
    for (int i=0; i<n; i++) {
        for (int j=0; j<n; j++) {
            cin >> graph[i][j];
        }
    }

    int r,c;
    for (int i=0; i<m; i++) {
        cin >> r >> c;
        bfs(c,r);
    }

    cout << cnt;


    return 0;
}