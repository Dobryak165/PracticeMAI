// Задача A - Поиск в ширину

#include <bits/stdc++.h>
using namespace std;

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    int n, m, k;
    cin >> n >> m >> k;

    vector<vector<int>> g(n + 1);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        g[a].push_back(b);
        g[b].push_back(a);
    }

    vector<int> dist(n + 1, -1);
    queue<int> q;
    dist[k] = 0;
    q.push(k);

    while(!q.empty()) {
        int b = q.front();
        q.pop();
        for (int to : g[b]) {
            if (dist[to] == -1) {
                dist[to] = dist[b] + 1;
                q.push(to);
            }
        }
    }

    for (int i = 1; i <= n; ++i) {
        cout << dist[i] << (i == n ? '\n' : ' ');
    }

    return 0;
}