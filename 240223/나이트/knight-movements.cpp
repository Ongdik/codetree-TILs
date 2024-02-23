#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int graph[101][101]{0};
bool visited[101][101]{false};
int n;
int r1,c1,r2,c2;
bool check = false;

int dx[8]{2,2,-2,-2,1,1,-1,-1};
int dy[8]{1,-1,1,-1,2,2,-2,-2};

void bfs(int x, int y) {
    queue<pair<pair<int,int>,int>> q;
    q.push({{x,y}, 0});

    while(!q.empty()) {
        int nextX = q.front().first.first;
        int nextY = q.front().first.second;
        int dist = q.front().second;
        q.pop();

        if (visited[nextY][nextX]) continue;
        visited[nextY][nextX] = true;

        if (nextX == c2 && nextY == r2) {
            cout << dist;
            check = true;
            return;
        }

        for (int i=0; i<8; i++) {
            int nx = nextX+dx[i];
            int ny = nextY+dy[i];

            if (nx>0 && ny>0 && nx<=n && ny<=n) {
                if (!visited[ny][nx]) q.push({{nx,ny},dist+1});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> r1 >> c1 >> r2 >> c2;

    bfs(c1,r1);

    if (!check) cout << 0;
    
    return 0;
}