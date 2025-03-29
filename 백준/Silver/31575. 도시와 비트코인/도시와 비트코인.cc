#include<iostream>
#include<queue>
#include<cstring>
using namespace std;

int n, m;
int graph[301][301];
bool visit[301][301];

string BFS() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visit[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        q.pop();

        if (x == m - 1 && y == n - 1) {
            return "Yes";
        }

        if (x + 1 < m && graph[x + 1][y] == 1 && !visit[x + 1][y]) {
            q.push({ x + 1, y });
            visit[x + 1][y] = true;
        }
        if (y + 1 < n && graph[x][y + 1] == 1 && !visit[x][y + 1]) {
            q.push({ x, y + 1 });
            visit[x][y + 1] = true;
        }
    }

    return "No";
}

int main() {
    memset(visit, false, sizeof(visit));
    cin >> n >> m;

    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cin >> graph[i][j];
        }
    }

    cout << BFS() << "\n";
}