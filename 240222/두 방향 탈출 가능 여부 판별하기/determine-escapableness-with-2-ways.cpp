#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int n,m;
int graph[101][101]{0};
bool visited[101][101]{false};
int dx[2]{1, 0};
int dy[2]{0, 1};
bool check = false;

void dfs(int x, int y) {
    if (visited[y][x]) return;

    visited[y][x] = true;
    if (y == n-1 && x == n-1) check = true;

    for (int i=0; i<2; i++) {
        int nx = x+dx[i];
        int ny = y+dy[i];
        if (nx>=0 && ny>=0 && nx<n && ny<n) {
            if (!visited[ny][nx] && graph[ny][nx] != 0) dfs(ny,nx);
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
    dfs(0,0);
    
    if (check) cout << 1;
    else cout << 0;


    return 0;
}