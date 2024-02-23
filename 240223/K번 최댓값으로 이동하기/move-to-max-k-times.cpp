#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
using namespace std;

int graph[101][101]{ 0 };
bool visited[101][101]{ false };
int n, k, r, c;

int dx[4]{ 1,-1,0,0 };
int dy[4]{ 0,0,1,-1 };

int curX = 0;
int curY = 0;

bool check = false;

// 1. 시작 위치의 값 보다 작은 곳으로 이동가능
// 2. 이동가능한 값들 중 가장 큰 값으로 이동
// 3. 같은 값이 많을시 행이 작은 수
// 4. 행도 같을 시 열 작은 수

void bfs(int x, int y, int val) {
    queue<pair<int, int>> q;
    q.push({ x,y });

    int maxVal = 0;
    curX = x;
    curY = y;
    
    while (!q.empty()) {
        int nextX = q.front().first;
        int nextY = q.front().second;
        q.pop();

        if (visited[nextY][nextX] || graph[nextY][nextX] > val) continue;
        visited[nextY][nextX] = true;
        if (graph[nextY][nextX] < val) {
            check = true;
            if (maxVal < graph[nextY][nextX]) {
                maxVal = graph[nextY][nextX];
                curX = nextX;
                curY = nextY;
            }
            else if (maxVal == graph[nextY][nextX]) {
                if (nextY < curY) {
                    curX = nextX;
                    curY = nextY;
                }
                else if (nextY == curY) {
                    if (nextX < curX) {
                        curX = nextX;
                    }
                }
            }
        }

        for (int i = 0; i < 4; i++) {
            int nx = nextX + dx[i];
            int ny = nextY + dy[i];

            if (nx > 0 && ny > 0 && nx <= n && ny <= n) {
                if (!visited[ny][nx] && graph[ny][nx] < val) q.push({ nx,ny });
            }
        }
    }
}

void reset() {
    visited[curY][curX] = false;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (graph[i][j] < graph[curY][curX]) visited[i][j] = false;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);

    cin >> n >> k;
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= n; j++) {
            cin >> graph[i][j];
        }
    }
    cin >> r >> c;
    bfs(c, r, graph[r][c]);

    if (!check) {
        cout << curY << " " << curX;
        return 0;
    }

    for (int i = 1; i < k; i++) {
        reset();
        check = false;
        bfs(curX, curY, graph[curY][curX]);

        if (!check) {
            cout << curY << " " << curX;
            return 0;
        }
    }
    cout << curY << " " << curX;
    return 0;
}
