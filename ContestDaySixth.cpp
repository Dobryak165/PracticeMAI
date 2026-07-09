// Задание 1 - Поиск в ширину

// #include <bits/stdc++.h>
// using namespace std;

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     int n, m, k;
//     cin >> n >> m >> k;

//     vector<vector<int>> g(n + 1);
//     for (int i = 0; i < m; ++i) {
//         int a, b;
//         cin >> a >> b;
//         g[a].push_back(b);
//         g[b].push_back(a);
//     }

//     vector<int> dist(n + 1, -1);
//     queue<int> q;
//     dist[k] = 0;
//     q.push(k);

//     while(!q.empty()) {
//         int b = q.front();
//         q.pop();
//         for (int to : g[b]) {
//             if (dist[to] == -1) {
//                 dist[to] = dist[b] + 1;
//                 q.push(to);
//             }
//         }
//     }

//     for (int i = 1; i <= n; ++i) {
//         cout << dist[i] << (i == n ? '\n' : ' ');
//     }

//     return 0;
// }

// Задание 2 - Поиск в ширину на клетчатом поле

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int N, M;
    cin >> N >> M;

    vector<string> grid(N);
    for (int i = 0; i < N; ++i) {
        cin >> grid[i];
    }

    int x, y;
    cin >> x >> y;
    --x; --y;

    vector<vector<int>> dist(N, vector<int>(M, -1));
    queue<pair<int, int>> q;

    dist[x][y] = 0;
    q.push({x, y});

    int dx[4] = {-1, 1, 0, 0};
    int dy[4] = {0, 0, -1, 1};

    while (!q.empty()) {
        int cx = q.front().first;
        int cy = q.front().second;
        q.pop();

        for (int d = 0; d < 4; ++d) {
            int nx = cx + dx[d];
            int ny = cy + dy[d];

            if (nx < 0 || nx >= N || ny < 0 || ny >= M) continue;
            if (grid[nx][ny] == '#') continue;
            if (dist[nx][ny] != -1) continue;

            dist[nx][ny] = dist[cx][cy] + 1;
            q.push({nx, ny});
        }
    }

    for (int i = 0; i < N; ++i) {
        for (int j = 0; j < M; ++j) {
            if (j) cout << ' ';
            cout << dist[i][j];
        }
        cout << '\n';
    }

    return 0;
}