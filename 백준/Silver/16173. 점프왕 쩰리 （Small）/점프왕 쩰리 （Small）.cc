#include<iostream>
#include<queue>
using namespace std;

int n;
int arr[3][3];
bool visited[3][3] = { false };

// 큐에 삽입되는 것은 최대 n ^ n개의 위치,  시간 복잡도: O(n^2)
string BFS() {
    queue<pair<int, int>> q;
    q.push({0, 0});
    visited[0][0] = true;

    while (!q.empty()) {
        int x = q.front().first;
        int y = q.front().second;
        int step = arr[x][y];   // 현재 칸의 숫자
        q.pop();

        if (step == -1)
            return "HaruHaru";
        if (step == 0)  // 이동할 수 없으므로 다음 탐색으로 넘어감
            continue;

        if (x + step < n) {   // 범위를 벗어나지 않도록 체크
            q.push({ x + step, y });
            visited[x + step][y] = true;
        }
        if (y + step < n){
            q.push({ x, y + step });
            visited[x][y + step] = true;
        }
    }

    return "Hing";
}

int main() {
    cin >> n;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> arr[i][j];
        }
    }

    cout << BFS() << endl;
    return 0;
}

// 총 시간 복잡도: O(n^2)

// arr, q, visited 배열 모두 O(n^2) 공간 사용
// 총 공간 복잡도 : O(n ^ 2)